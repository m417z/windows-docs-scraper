# SCardListReaderGroupsW function

## Description

The **SCardListReaderGroups** function provides the list of [reader groups](https://learn.microsoft.com/windows/desktop/SecGloss/r-gly) that have previously been introduced to the system.

## Parameters

### `hContext` [in]

Handle that identifies the [resource manager context](https://learn.microsoft.com/windows/desktop/SecGloss/r-gly) for the query. The resource manager context can be set by a previous call to [SCardEstablishContext](https://learn.microsoft.com/windows/desktop/api/winscard/nf-winscard-scardestablishcontext).

If this parameter is set to **NULL**, the search for reader groups is not limited to any context.

### `mszGroups` [out]

Multi-string that lists the reader groups defined to the system and available to the current user on the current [terminal](https://learn.microsoft.com/windows/desktop/SecGloss/t-gly). If this value is **NULL**, **SCardListReaderGroups** ignores the buffer length supplied in *pcchGroups*, writes the length of the buffer that would have been returned if this parameter had not been **NULL** to *pcchGroups*, and returns a success code.

| Value | Meaning |
| --- | --- |
| **SCARD_ALL_READERS**<br><br>TEXT("SCard$AllReaders\000") | Group used when no group name is provided when listing readers. Returns a list of all readers, regardless of what group or groups the readers are in. |
| **SCARD_DEFAULT_READERS**<br><br>TEXT("SCard$DefaultReaders\000") | Default group to which all readers are added when introduced into the system. |
| **SCARD_LOCAL_READERS**<br><br>TEXT("SCard$LocalReaders\000") | Unused legacy value. This is an internally managed group that cannot be modified by using any reader group APIs. It is intended to be used for enumeration only. |
| **SCARD_SYSTEM_READERS**<br><br>TEXT("SCard$SystemReaders\000") | Unused legacy value. This is an internally managed group that cannot be modified by using any reader group APIs. It is intended to be used for enumeration only. |

### `pcchGroups` [in, out]

Length of the *mszGroups* buffer in characters, and receives the actual length of the multi-string structure, including all trailing **null** characters. If the buffer length is specified as SCARD_AUTOALLOCATE, then *mszGroups* is converted to a pointer to a byte pointer, and receives the address of a block of memory containing the multi-string structure. This block of memory must be deallocated with
[SCardFreeMemory](https://learn.microsoft.com/windows/desktop/api/winscard/nf-winscard-scardfreememory).

## Return value

This function returns different values depending on whether it succeeds or fails.

| Return code | Description |
| --- | --- |
| **Success** | SCARD_S_SUCCESS. |
| **Failure** | An error code. For more information, see [Smart Card Return Values](https://learn.microsoft.com/windows/desktop/SecAuthN/authentication-return-values). |

## Remarks

A group is returned only if it contains at least one [reader](https://learn.microsoft.com/windows/desktop/SecGloss/r-gly). This includes the group [SCard$DefaultReaders](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly). The group [SCard$AllReaders](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) cannot be returned, since it only exists implicitly.

The **SCardListReaderGroups** function is a database query function. For more information on other database query functions, see
[Smart Card Database Query Functions](https://learn.microsoft.com/windows/desktop/SecAuthN/smart-card-database-query-functions).

#### Examples

The following example shows listing the reader groups.

```cpp
LPTSTR          pmszReaderGroups = NULL;
LPTSTR          pReaderGroup;
LONG            lReturn;
DWORD           cch = SCARD_AUTOALLOCATE;

// Retrieve the list the reader groups.
// hSC was set by a previous call to SCardEstablishContext.
lReturn = SCardListReaderGroups(hSC,
                                (LPTSTR)&pmszReaderGroups,
                                &cch );
if ( SCARD_S_SUCCESS != lReturn )
    printf("Failed SCardListReaderGroups\n");
else
{
    // Do something with the multi string of reader groups.
    // Output the values.
    // A double-null terminates the list of values.
    pReaderGroup = pmszReaderGroups;
    while ( '\0' != *pReaderGroup )
    {
        // Display the value.
        printf("%S\n", pReaderGroup );
        // Advance to the next value.
        pReaderGroup = pReaderGroup + wcslen((wchar_t *) pReaderGroup) + 1;
    }

    // Remember to free pmszReaderGroups by a call to SCardFreeMemory.
    // ...
}

```

> [!NOTE]
> The winscard.h header defines SCardListReaderGroups as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[SCardEstablishContext](https://learn.microsoft.com/windows/desktop/api/winscard/nf-winscard-scardestablishcontext)

[SCardFreeMemory](https://learn.microsoft.com/windows/desktop/api/winscard/nf-winscard-scardfreememory)

[SCardGetProviderId](https://learn.microsoft.com/windows/desktop/api/winscard/nf-winscard-scardgetproviderida)

[SCardListCards](https://learn.microsoft.com/windows/desktop/api/winscard/nf-winscard-scardlistcardsa)

[SCardListInterfaces](https://learn.microsoft.com/windows/desktop/api/winscard/nf-winscard-scardlistinterfacesa)

[SCardListReaders](https://learn.microsoft.com/windows/desktop/api/winscard/nf-winscard-scardlistreadersa)