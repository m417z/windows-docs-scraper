# SCardForgetCardTypeW function

## Description

The **SCardForgetCardType** function removes an introduced [smart card](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) from the [smart card subsystem](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly).

## Parameters

### `hContext` [in]

Handle that identifies the [resource manager context](https://learn.microsoft.com/windows/desktop/SecGloss/r-gly). The resource manager context is set by a previous call to
[SCardEstablishContext](https://learn.microsoft.com/windows/desktop/api/winscard/nf-winscard-scardestablishcontext). This parameter cannot be **NULL**.

### `szCardName` [in]

Display name of the card to be removed from the [smart card database](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly).

## Return value

This function returns different values depending on whether it succeeds or fails.

| Return code | Description |
| --- | --- |
| **Success** | SCARD_S_SUCCESS. |
| **Failure** | An error code. For more information, see [Smart Card Return Values](https://learn.microsoft.com/windows/desktop/SecAuthN/authentication-return-values). |

## Remarks

This function is not redirected, but calling the function **SCardForgetCardType** when inside a Remote Desktop session will not result in an error. It only means that the result will be from the remote computer instead of the local computer.

The **SCardForgetCardType** function is a database management function. For more information about other database management functions, see
[Smart Card Database Management Functions](https://learn.microsoft.com/windows/desktop/SecAuthN/smart-card-database-management-functions).

#### Examples

The following example removes the specified card type from the system. The example assumes that lReturn is a valid variable of type **LONG**, that *hContext* is a valid handle received from a previous call to the [SCardEstablishContext](https://learn.microsoft.com/windows/desktop/api/winscard/nf-winscard-scardestablishcontext) function, and that "MyCardName" was previously introduced by a call to the [SCardIntroduceCardType](https://learn.microsoft.com/windows/desktop/api/winscard/nf-winscard-scardintroducecardtypea) function.

```cpp

lReturn = SCardForgetCardType(hContext,
                              L"MyCardName");
if ( SCARD_S_SUCCESS != lReturn )
    printf("Failed SCardForgetCardType\n");

```

> [!NOTE]
> The winscard.h header defines SCardForgetCardType as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[SCardEstablishContext](https://learn.microsoft.com/windows/desktop/api/winscard/nf-winscard-scardestablishcontext)

[SCardForgetReader](https://learn.microsoft.com/windows/desktop/api/winscard/nf-winscard-scardforgetreadera)

[SCardForgetReaderGroup](https://learn.microsoft.com/windows/desktop/api/winscard/nf-winscard-scardforgetreadergroupa)

[SCardIntroduceCardType](https://learn.microsoft.com/windows/desktop/api/winscard/nf-winscard-scardintroducecardtypea)