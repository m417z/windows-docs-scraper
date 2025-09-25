# SCardSetCardTypeProviderNameA function

## Description

The **SCardSetCardTypeProviderName** function specifies the name of the module (dynamic link library) containing the provider for a given card name and [provider type](https://learn.microsoft.com/windows/desktop/SecGloss/p-gly).

## Parameters

### `hContext` [in]

Handle that identifies the [resource manager context](https://learn.microsoft.com/windows/desktop/SecGloss/r-gly). The resource manager context can be set by a previous call to
[SCardEstablishContext](https://learn.microsoft.com/windows/desktop/api/winscard/nf-winscard-scardestablishcontext). This value can be **NULL** if the call to **SCardSetCardTypeProviderName** is not directed to a specific [context](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly).

### `szCardName` [in]

Name of the card type with which this [provider name](https://learn.microsoft.com/windows/desktop/SecGloss/p-gly) is associated.

### `dwProviderId` [in]

Identifier for the provider associated with this card type.

| Value | Meaning |
| --- | --- |
| **SCARD_PROVIDER_PRIMARY**<br><br>1 | The function retrieves the name of the [smart card's](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) [primary service provider](https://learn.microsoft.com/windows/desktop/SecGloss/p-gly) as a GUID string. |
| **SCARD_PROVIDER_CSP**<br><br>2 | The function retrieves the name of the [cryptographic service provider](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) (CSP). |
| **SCARD_PROVIDER_KSP**<br><br>3 | The function retrieves the name of the smart card [key storage provider](https://learn.microsoft.com/windows/desktop/SecGloss/k-gly) (KSP). |
| **SCARD_PROVIDER_CARD_MODULE**<br><br>0x80000001 | The function retrieves the name of the card module. |

### `szProvider` [in]

A string that contains the provider name that is representing the CSP.

## Return value

This function returns different values depending on whether it succeeds or fails.

| Return code | Description |
| --- | --- |
| **Success** | SCARD_S_SUCCESS. |
| **Failure** | An error code. For more information, see [Smart Card Return Values](https://learn.microsoft.com/windows/desktop/SecAuthN/authentication-return-values). |

## Remarks

This function is not redirected, but calling the function when inside a Remote Desktop session will not result in an error. It only means that the result will be from the remote computer instead of the local computer.

This function sets the provider name, while
[SCardGetCardTypeProviderName](https://learn.microsoft.com/windows/desktop/api/winscard/nf-winscard-scardgetcardtypeprovidernamea) can be used to retrieve the provider name.

#### Examples

The following example shows how to specify the card type provider name.

```cpp
LPTSTR            szNewProvName = _T("My Provider Name");
LPTSTR            szCardName = _T("WindowsCard");
LONG              lReturn = SCARD_S_SUCCESS;

// Set the card type provider name.
// hContext was set by SCardEstablishContext.
lReturn = SCardSetCardTypeProviderName(hContext,
                                      szCardName,
                                      SCARD_PROVIDER_CSP,
                                      szNewProvName);
if ( SCARD_S_SUCCESS != lReturn )
{
    printf("Failed SCardSetCardTypeProviderName - %x\n", lReturn);
    exit(1);
}

```

> [!NOTE]
> The winscard.h header defines SCardSetCardTypeProviderName as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[SCardGetCardTypeProviderName](https://learn.microsoft.com/windows/desktop/api/winscard/nf-winscard-scardgetcardtypeprovidernamea)