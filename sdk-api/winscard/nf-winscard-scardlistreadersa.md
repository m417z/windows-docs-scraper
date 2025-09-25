# SCardListReadersA function

## Description

The **SCardListReaders** function provides the list of [readers](https://learn.microsoft.com/windows/desktop/SecGloss/r-gly) within a set of named [reader groups](https://learn.microsoft.com/windows/desktop/SecGloss/r-gly), eliminating duplicates.

The caller supplies a list of reader groups, and receives the list of readers within the named groups. Unrecognized group names are ignored. This function only returns readers within the named groups that are currently attached to the system and available for use.

## Parameters

### `hContext` [in]

Handle that identifies the [resource manager context](https://learn.microsoft.com/windows/desktop/SecGloss/r-gly) for the query. The resource manager context can be set by a previous call to [SCardEstablishContext](https://learn.microsoft.com/windows/desktop/api/winscard/nf-winscard-scardestablishcontext).

If this parameter is set to **NULL**, the search for readers is not limited to any context.

### `mszGroups` [in, optional]

Names of the reader groups defined to the system, as a multi-string. Use a **NULL** value to list all readers in the system (that is, the SCard$AllReaders group).

| Value | Meaning |
| --- | --- |
| **SCARD_ALL_READERS**<br><br>TEXT("SCard$AllReaders\000") | Group used when no group name is provided when listing readers. Returns a list of all readers, regardless of what group or groups the readers are in. |
| **SCARD_DEFAULT_READERS**<br><br>TEXT("SCard$DefaultReaders\000") | Default group to which all readers are added when introduced into the system. |
| **SCARD_LOCAL_READERS**<br><br>TEXT("SCard$LocalReaders\000") | Unused legacy value. This is an internally managed group that cannot be modified by using any reader group APIs. It is intended to be used for enumeration only. |
| **SCARD_SYSTEM_READERS**<br><br>TEXT("SCard$SystemReaders\000") | Unused legacy value. This is an internally managed group that cannot be modified by using any reader group APIs. It is intended to be used for enumeration only. |

### `mszReaders` [out]

Multi-string that lists the card readers within the supplied reader groups. If this value is **NULL**, **SCardListReaders** ignores the buffer length supplied in *pcchReaders*, writes the length of the buffer that would have been returned if this parameter had not been **NULL** to *pcchReaders*, and returns a success code.

### `pcchReaders` [in, out]

Length of the *mszReaders* buffer in characters. This parameter receives the actual length of the multi-string structure, including all trailing **null** characters. If the buffer length is specified as SCARD_AUTOALLOCATE, then *mszReaders* is converted to a pointer to a byte pointer, and receives the address of a block of memory containing the multi-string structure. This block of memory must be deallocated with [SCardFreeMemory](https://learn.microsoft.com/windows/desktop/api/winscard/nf-winscard-scardfreememory).

## Return value

This function returns different values depending on whether it succeeds or fails.

| Return code/value | Description |
| --- | --- |
| **Success**<br><br>0 (0x0) | SCARD_S_SUCCESS |
| **Group contains no readers**<br><br>2148532270 (0x8010002E) | SCARD_E_NO_READERS_AVAILABLE |
| **Specified reader is not currently available for use**<br><br>2148532247 (0x80100017) | SCARD_E_READER_UNAVAILABLE |
| **Other** | An error code. For more information, see [Smart Card Return Values](https://learn.microsoft.com/windows/desktop/SecAuthN/authentication-return-values). |

## Remarks

The **SCardListReaders** function is a database query function. For more information on other database query functions, see
[Smart Card Database Query Functions](https://learn.microsoft.com/windows/desktop/SecAuthN/smart-card-database-query-functions).

#### Examples

The following example shows listing the readers.

```cpp
LPTSTR          pmszReaders = NULL;
LPTSTR          pReader;
LONG            lReturn, lReturn2;
DWORD           cch = SCARD_AUTOALLOCATE;

// Retrieve the list the readers.
// hSC was set by a previous call to SCardEstablishContext.
lReturn = SCardListReaders(hSC,
                           NULL,
                           (LPTSTR)&pmszReaders,
                           &cch );
switch( lReturn )
{
    case SCARD_E_NO_READERS_AVAILABLE:
        printf("Reader is not in groups.\n");
        // Take appropriate action.
        // ...
        break;

    case SCARD_S_SUCCESS:
        // Do something with the multi string of readers.
        // Output the values.
        // A double-null terminates the list of values.
        pReader = pmszReaders;
        while ( '\0' != *pReader )
        {
            // Display the value.
            printf("Reader: %S\n", pReader );
            // Advance to the next value.
            pReader = pReader + wcslen((wchar_t *)pReader) + 1;
        }
        // Free the memory.
        lReturn2 = SCardFreeMemory( hSC,
                                   pmszReaders );
        if ( SCARD_S_SUCCESS != lReturn2 )
            printf("Failed SCardFreeMemory\n");
        break;

default:
        printf("Failed SCardListReaders\n");
        // Take appropriate action.
        // ...
        break;
}

```

> [!NOTE]
> The winscard.h header defines SCardListReaders as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[SCardEstablishContext](https://learn.microsoft.com/windows/desktop/api/winscard/nf-winscard-scardestablishcontext)

[SCardFreeMemory](https://learn.microsoft.com/windows/desktop/api/winscard/nf-winscard-scardfreememory)

[SCardGetProviderId](https://learn.microsoft.com/windows/desktop/api/winscard/nf-winscard-scardgetproviderida)

[SCardListCards](https://learn.microsoft.com/windows/desktop/api/winscard/nf-winscard-scardlistcardsa)

[SCardListInterfaces](https://learn.microsoft.com/windows/desktop/api/winscard/nf-winscard-scardlistinterfacesa)

[SCardListReaderGroups](https://learn.microsoft.com/windows/desktop/api/winscard/nf-winscard-scardlistreadergroupsa)