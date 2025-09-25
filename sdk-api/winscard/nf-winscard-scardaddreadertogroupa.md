# SCardAddReaderToGroupA function

## Description

The **SCardAddReaderToGroup** function adds a [reader](https://learn.microsoft.com/windows/desktop/SecGloss/r-gly) to a [reader group](https://learn.microsoft.com/windows/desktop/SecGloss/r-gly).

## Parameters

### `hContext` [in]

Handle that identifies the [resource manager context](https://learn.microsoft.com/windows/desktop/SecGloss/r-gly). The resource manager context is set by a previous call to
[SCardEstablishContext](https://learn.microsoft.com/windows/desktop/api/winscard/nf-winscard-scardestablishcontext). This parameter cannot be **NULL**.

### `szReaderName` [in]

Display name of the reader that you are adding.

### `szGroupName` [in]

Display name of the group to which you are adding the reader.

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

**SCardAddReaderToGroup** automatically creates the reader group specified if it does not already exist.

The **SCardAddReaderToGroup** function is a database management function. For more information on other database management functions, see
[Smart Card Database Management Functions](https://learn.microsoft.com/windows/desktop/SecAuthN/smart-card-database-management-functions).

#### Examples

The following example demonstrates how to add a smart card reader to a group. The example assumes that lReturn is an existing variable of type **LONG**, that *hContext* is a valid handle received from a previous call to the [SCardEstablishContext](https://learn.microsoft.com/windows/desktop/api/winscard/nf-winscard-scardestablishcontext) function, and that "MyReader" and "MyReaderGroup" are known by the system through previous calls to the [SCardIntroduceReader](https://learn.microsoft.com/windows/desktop/api/winscard/nf-winscard-scardintroducereadera) and [SCardIntroduceReaderGroup](https://learn.microsoft.com/windows/desktop/api/winscard/nf-winscard-scardintroducereadergroupa) functions, respectively.

```cpp

lReturn = SCardAddReaderToGroup( hContext,
                                L"MyReader",
                                L"MyReaderGroup");
if ( SCARD_S_SUCCESS != lReturn )
    printf("Failed SCardAddReaderToGroup\n");

```

> [!NOTE]
> The winscard.h header defines SCardAddReaderToGroup as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[SCardEstablishContext](https://learn.microsoft.com/windows/desktop/api/winscard/nf-winscard-scardestablishcontext)

[SCardIntroduceReader](https://learn.microsoft.com/windows/desktop/api/winscard/nf-winscard-scardintroducereadera)

[SCardIntroduceReaderGroup](https://learn.microsoft.com/windows/desktop/api/winscard/nf-winscard-scardintroducereadergroupa)

[SCardRemoveReaderFromGroup](https://learn.microsoft.com/windows/desktop/api/winscard/nf-winscard-scardremovereaderfromgroupa)