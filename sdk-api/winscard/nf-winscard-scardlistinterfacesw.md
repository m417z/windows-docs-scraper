# SCardListInterfacesW function

## Description

The **SCardListInterfaces** function provides a list of interfaces supplied by a given card.

The caller supplies the name of a [smart card](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) previously introduced to the subsystem, and receives the list of interfaces supported by the card.

## Parameters

### `hContext` [in]

Handle that identifies the [resource manager context](https://learn.microsoft.com/windows/desktop/SecGloss/r-gly) for the query. The resource manager context can be set by a previous call to [SCardEstablishContext](https://learn.microsoft.com/windows/desktop/api/winscard/nf-winscard-scardestablishcontext). This parameter cannot be **NULL**.

### `szCard` [in]

Name of the smart card already introduced to the [smart card subsystem](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly).

### `pguidInterfaces` [out]

Array of interface identifiers (GUIDs) that indicate the interfaces supported by the smart card. If this value is **NULL**, **SCardListInterfaces** ignores the array length supplied in *pcguidInterfaces*, returning the size of the array that would have been returned if this parameter had not been **NULL** to *pcguidInterfaces* and a success code.

### `pcguidInterfaces` [in, out]

Size of the *pcguidInterfaces* array, and receives the actual size of the returned array. If the array size is specified as SCARD_AUTOALLOCATE, then *pcguidInterfaces* is converted to a pointer to a GUID pointer, and receives the address of a block of memory containing the array. This block of memory must be deallocated with
[SCardFreeMemory](https://learn.microsoft.com/windows/desktop/api/winscard/nf-winscard-scardfreememory).

## Return value

This function returns different values depending on whether it succeeds or fails.

| Return code | Description |
| --- | --- |
| **Success** | SCARD_S_SUCCESS. |
| **Failure** | An error code. For more information, see [Smart Card Return Values](https://learn.microsoft.com/windows/desktop/SecAuthN/authentication-return-values). |

## Remarks

This function is not redirected, but calling the function when attempting a Remote Desktop session will not result in an error. It only means that the result will be from the remote computer instead of the local computer.

The **SCardListInterfaces** function is a database query function. For more information on other database query functions, see
[Smart Card Database Query Functions](https://learn.microsoft.com/windows/desktop/SecAuthN/smart-card-database-query-functions).

#### Examples

The following example shows listing the interfaces for a smart card.

```cpp
LPGUID          pGuids = NULL;
LONG            lReturn;
DWORD           cGuid = SCARD_AUTOALLOCATE;

// Retrieve the list of interfaces.
lReturn = SCardListInterfaces(NULL,
                              (LPCSTR) "MyCard",
                              (LPGUID)&pGuids,
                              &cGuid );
if ( SCARD_S_SUCCESS != lReturn )
{
    printf("Failed SCardListInterfaces\n");
    exit(1);   // Or other appropriate action
}

if ( 0 != cGuid )
{
    // Do something with the array of Guids.
    // Remember to free pGuids when done (by SCardFreeMemory).
    // ...
}

```

> [!NOTE]
> The winscard.h header defines SCardListInterfaces as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[SCardEstablishContext](https://learn.microsoft.com/windows/desktop/api/winscard/nf-winscard-scardestablishcontext)

[SCardFreeMemory](https://learn.microsoft.com/windows/desktop/api/winscard/nf-winscard-scardfreememory)

[SCardGetProviderId](https://learn.microsoft.com/windows/desktop/api/winscard/nf-winscard-scardgetproviderida)

[SCardListCards](https://learn.microsoft.com/windows/desktop/api/winscard/nf-winscard-scardlistcardsa)

[SCardListReaderGroups](https://learn.microsoft.com/windows/desktop/api/winscard/nf-winscard-scardlistreadergroupsa)

[SCardListReaders](https://learn.microsoft.com/windows/desktop/api/winscard/nf-winscard-scardlistreadersa)