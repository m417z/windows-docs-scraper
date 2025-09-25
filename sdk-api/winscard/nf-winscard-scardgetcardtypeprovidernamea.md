# SCardGetCardTypeProviderNameA function

## Description

The **SCardGetCardTypeProviderName** function returns the name of the module (dynamic link library) that contains the provider for a given card name and [provider type](https://learn.microsoft.com/windows/desktop/SecGloss/p-gly).

## Parameters

### `hContext` [in]

Handle that identifies the [resource manager context](https://learn.microsoft.com/windows/desktop/SecGloss/r-gly). The resource manager context can be set by a previous call to
[SCardEstablishContext](https://learn.microsoft.com/windows/desktop/api/winscard/nf-winscard-scardestablishcontext). This value can be **NULL** if the call to **SCardGetCardTypeProviderName** is not directed to a specific [context](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly).

### `szCardName` [in]

Name of the card type with which this provider name is associated.

### `dwProviderId` [in]

Identifier for the provider associated with this card type.

| Value | Meaning |
| --- | --- |
| **SCARD_PROVIDER_PRIMARY**<br><br>1 | The function retrieves the name of the [smart card's](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) [primary service provider](https://learn.microsoft.com/windows/desktop/SecGloss/p-gly) as a GUID string. |
| **SCARD_PROVIDER_CSP**<br><br>2 | The function retrieves the name of the [cryptographic service provider](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly). |
| **SCARD_PROVIDER_KSP**<br><br>3 | The function retrieves the name of the smart card [key storage provider](https://learn.microsoft.com/windows/desktop/SecGloss/k-gly) (KSP). |
| **SCARD_PROVIDER_CARD_MODULE**<br><br>0x80000001 | The function retrieves the name of the card module. |

### `szProvider` [out]

String variable to receive the [provider name](https://learn.microsoft.com/windows/desktop/SecGloss/p-gly) upon successful completion of this function.

### `pcchProvider` [in, out]

Pointer to **DWORD** value. On input, *pcchProvider* supplies the length of the *szProvider* buffer in characters. If this value is SCARD_AUTOALLOCATE, then *szProvider* is converted to a pointer to a byte pointer and receives the address of a block of memory containing the string. This block of memory must be deallocated by calling
[SCardFreeMemory](https://learn.microsoft.com/windows/desktop/api/winscard/nf-winscard-scardfreememory).

On output, this value represents the actual number of characters, including the **null** terminator, in the *szProvider* variable.

## Return value

This function returns different values depending on whether it succeeds or fails.

| Return code | Description |
| --- | --- |
| **Success** | SCARD_S_SUCCESS. |
| **Failure** | An error code. For more information, see [Smart Card Return Values](https://learn.microsoft.com/windows/desktop/SecAuthN/authentication-return-values). |

## Remarks

This function is not redirected, but calling the function when inside a Remote Desktop session will not result in an error. It only means that the result will be from the remote computer instead of the local computer.

Upon successful completion of this function, the value in *szProvider* can be used as the third parameter in a call to
[CryptAcquireContext](https://learn.microsoft.com/windows/desktop/api/wincrypt/nf-wincrypt-cryptacquirecontexta).

#### Examples

The following example shows how to retrieve the provider name for the specified reader context. The example assumes that hContext is a valid handle obtained from a previous call to the [SCardEstablishContext](https://learn.microsoft.com/windows/desktop/api/winscard/nf-winscard-scardestablishcontext) function.

```cpp
LPTSTR szProvider = NULL;
LPTSTR szCardName = _T("WindowsCard");
DWORD  chProvider = SCARD_AUTOALLOCATE;
LONG   lReturn = SCARD_S_SUCCESS;

// Retrieve the provider name.
// hContext was set by SCardEstablishContext.
lReturn = SCardGetCardTypeProviderName(hContext,
                                       szCardName,
                                       SCARD_PROVIDER_CSP,
                                       (LPTSTR)&szProvider,
                                       &chProvider);
if (SCARD_S_SUCCESS == lReturn)
{
    BOOL fSts = TRUE;
    HCRYPTPROV hProv = NULL;

  // Acquire a Cryptographic operation context.
    fSts = CryptAcquireContext(&hProv,
                               NULL,
                               szProvider,
                               PROV_RSA_FULL,
                               0);
    // Perform Cryptographic operations with smart card
    // ...

    // Free memory allocated by SCardGetCardTypeProviderName.
    lReturn = SCardFreeMemory(hContext, szProvider);
}

```

> [!NOTE]
> The winscard.h header defines SCardGetCardTypeProviderName as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[SCardEstablishContext](https://learn.microsoft.com/windows/desktop/api/winscard/nf-winscard-scardestablishcontext)

[SCardFreeMemory](https://learn.microsoft.com/windows/desktop/api/winscard/nf-winscard-scardfreememory)

[SCardSetCardTypeProviderName](https://learn.microsoft.com/windows/desktop/api/winscard/nf-winscard-scardsetcardtypeprovidernamea)