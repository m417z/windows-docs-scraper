# SCardIntroduceReaderGroupW function

## Description

The **SCardIntroduceReaderGroup** function introduces a [reader group](https://learn.microsoft.com/windows/desktop/SecGloss/r-gly) to the [smart card](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) subsystem. However, the reader group is not created until the group is specified when adding a reader to the [smart card database](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly).

## Parameters

### `hContext` [in]

Supplies the handle that identifies the [resource manager context](https://learn.microsoft.com/windows/desktop/SecGloss/r-gly). The resource manager context is set by a previous call to
the [SCardEstablishContext](https://learn.microsoft.com/windows/desktop/api/winscard/nf-winscard-scardestablishcontext) function. If this parameter is **NULL**, the scope of the resource manager is SCARD_SCOPE_SYSTEM.

### `szGroupName` [in]

Supplies the display name to be assigned to the new reader group.

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

The **SCardIntroduceReaderGroup** function is provided for PC/SC specification compatibility. Reader groups are not stored until a reader is added to the group.

The **SCardIntroduceReaderGroup** function is a database management function. For a description of other database management functions, see
[Smart Card Database Management Functions](https://learn.microsoft.com/windows/desktop/SecAuthN/smart-card-database-management-functions).

To remove a reader group, use
[SCardForgetReaderGroup](https://learn.microsoft.com/windows/desktop/api/winscard/nf-winscard-scardforgetreadergroupa).

#### Examples

The following example shows introducing a smart card reader group.

```cpp
// Introduce the reader group.
// lReturn is of type LONG.
// hContext was set by a previous call to SCardEstablishContext.
lReturn = SCardIntroduceReaderGroup(hContext,
                                    L"MyReaderGroup");
if ( SCARD_S_SUCCESS != lReturn )
    printf("Failed SCardIntroduceReaderGroup\n");

```

> [!NOTE]
> The winscard.h header defines SCardIntroduceReaderGroup as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[SCardAddReaderToGroup](https://learn.microsoft.com/windows/desktop/api/winscard/nf-winscard-scardaddreadertogroupa)

[SCardEstablishContext](https://learn.microsoft.com/windows/desktop/api/winscard/nf-winscard-scardestablishcontext)

[SCardForgetReaderGroup](https://learn.microsoft.com/windows/desktop/api/winscard/nf-winscard-scardforgetreadergroupa)

[SCardIntroduceCardType](https://learn.microsoft.com/windows/desktop/api/winscard/nf-winscard-scardintroducecardtypea)

[SCardIntroduceReader](https://learn.microsoft.com/windows/desktop/api/winscard/nf-winscard-scardintroducereadera)