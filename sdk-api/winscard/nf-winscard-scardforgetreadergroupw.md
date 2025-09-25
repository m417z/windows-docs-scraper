# SCardForgetReaderGroupW function

## Description

The **SCardForgetReaderGroup** function removes a previously introduced [smart card](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) [reader group](https://learn.microsoft.com/windows/desktop/SecGloss/r-gly) from the [smart card subsystem](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly). Although this function automatically clears all readers from the group, it does not affect the existence of the individual [readers](https://learn.microsoft.com/windows/desktop/SecGloss/r-gly) in the database.

## Parameters

### `hContext` [in]

Handle that identifies the [resource manager context](https://learn.microsoft.com/windows/desktop/SecGloss/r-gly). The resource manager context is set by a previous call to
[SCardEstablishContext](https://learn.microsoft.com/windows/desktop/api/winscard/nf-winscard-scardestablishcontext). This parameter cannot be **NULL**.

### `szGroupName` [in]

Display name of the reader group to be removed. System-defined reader groups cannot be removed from the database.

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

The **SCardForgetReaderGroup** function is a database management function. For more information on other database management functions, see
[Smart Card Database Management Functions](https://learn.microsoft.com/windows/desktop/SecAuthN/smart-card-database-management-functions).

#### Examples

The following example shows how to remove a reader group from the system. The example assumes that lReturn is an existing variable of type **LONG**, and that hContext is a valid handle to a resource manager context previously obtained from a call to the [SCardEstablishContext](https://learn.microsoft.com/windows/desktop/api/winscard/nf-winscard-scardestablishcontext) function.

```cpp

lReturn = SCardForgetReaderGroup(hContext,
                                 L"MyReaderGroup");
if ( SCARD_S_SUCCESS != lReturn )
    printf("Failed SCardForgetReaderGroup\n");

```

> [!NOTE]
> The winscard.h header defines SCardForgetReaderGroup as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[SCardEstablishContext](https://learn.microsoft.com/windows/desktop/api/winscard/nf-winscard-scardestablishcontext)

[SCardForgetCardType](https://learn.microsoft.com/windows/desktop/api/winscard/nf-winscard-scardforgetcardtypea)

[SCardForgetReader](https://learn.microsoft.com/windows/desktop/api/winscard/nf-winscard-scardforgetreadera)

[SCardIntroduceReaderGroup](https://learn.microsoft.com/windows/desktop/api/winscard/nf-winscard-scardintroducereadergroupa)