# SCardRemoveReaderFromGroupA function

## Description

The **SCardRemoveReaderFromGroup** function removes a [reader](https://learn.microsoft.com/windows/desktop/SecGloss/r-gly) from an existing [reader group](https://learn.microsoft.com/windows/desktop/SecGloss/r-gly). This function has no effect on the reader.

## Parameters

### `hContext` [in]

Handle that identifies the [resource manager context](https://learn.microsoft.com/windows/desktop/SecGloss/r-gly). The resource manager context is set by a previous call to
[SCardEstablishContext](https://learn.microsoft.com/windows/desktop/api/winscard/nf-winscard-scardestablishcontext). This parameter cannot be **NULL**.

### `szReaderName` [in]

Display name of the reader to be removed.

### `szGroupName` [in]

Display name of the group from which the reader should be removed.

| Value | Meaning |
| --- | --- |
| **SCARD_ALL_READERS**<br><br>TEXT("SCard$AllReaders\000") | Group used when no group name is provided when listing readers. Returns a list of all readers, regardless of what group or groups the readers are in. |
| **SCARD_DEFAULT_READERS**<br><br>TEXT("SCard$DefaultReaders\000") | Default group to which all readers are added when introduced into the system. |
| **SCARD_LOCAL_READERS**<br><br>TEXT("SCard$LocalReaders\000") | Unused legacy value. This is an internally managed group that cannot be modified by using any reader group APIs. It is intended to be used for enumeration only. |
| **SCARD_SYSTEM_READERS**<br><br>TEXT("SCard$SystemReaders\000") | Unused legacy value. This is an internally managed group that cannot be modified by using any reader group APIs. It is intended to be used for enumeration only. |

## Return value

This function returns different values depending on whether it succeeds or fails.

| Return code | Description |
| --- | --- |
| **Success** | SCARD_S_SUCCESS. |
| **Failure** | An error code. For more information, see [Smart Card Return Values](https://learn.microsoft.com/windows/desktop/SecAuthN/authentication-return-values). |

## Remarks

When the last reader is removed from a group, the group is automatically forgotten.

The **SCardRemoveReaderFromGroup** function is a database management function. For information about other database management functions, see
[Smart Card Database Management Functions](https://learn.microsoft.com/windows/desktop/SecAuthN/smart-card-database-management-functions).

To add a reader to a reader group, use
[SCardAddReaderToGroup](https://learn.microsoft.com/windows/desktop/api/winscard/nf-winscard-scardaddreadertogroupa).

#### Examples

The following example shows how to remove a reader from the group.

```cpp
// Remove a reader from the group.
// lReturn is of type LONG.
// hContext was set by a previous call to SCardEstablishContext.
// The group is automatically forgotten if no readers remain in it.
lReturn = SCardRemoveReaderFromGroup(hContext,
                                     L"MyReader",
                                     L"MyReaderGroup");
if ( SCARD_S_SUCCESS != lReturn )
    printf("Failed SCardRemoveReaderFromGroup\n");

```

> [!NOTE]
> The winscard.h header defines SCardRemoveReaderFromGroup as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[SCardAddReaderToGroup](https://learn.microsoft.com/windows/desktop/api/winscard/nf-winscard-scardaddreadertogroupa)

[SCardEstablishContext](https://learn.microsoft.com/windows/desktop/api/winscard/nf-winscard-scardestablishcontext)

[SCardForgetCardType](https://learn.microsoft.com/windows/desktop/api/winscard/nf-winscard-scardforgetcardtypea)

[SCardForgetReader](https://learn.microsoft.com/windows/desktop/api/winscard/nf-winscard-scardforgetreadera)

[SCardForgetReaderGroup](https://learn.microsoft.com/windows/desktop/api/winscard/nf-winscard-scardforgetreadergroupa)