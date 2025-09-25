# NCryptTranslateHandle function

## Description

The **NCryptTranslateHandle** function translates a CryptoAPI handle into a CNG key handle.

## Parameters

### `phProvider` [out, optional]

A pointer to an **NCRYPT_PROV_HANDLE** variable that receives the handle of the CNG key storage provider that owns the CNG key placed in the *phKey* parameter. This parameter can be **NULL** if this handle is not needed.

### `phKey` [out]

A pointer to a **NCRYPT_KEY_HANDLE** variable that receives the CNG key handle.

### `hLegacyProv` [in]

The handle of the CryptoAPI provider that contains the key to translate. This function will translate the CryptoAPI key that is in the container in this provider.

### `hLegacyKey` [in, optional]

The handle of a CryptoAPI key to use to help determine the key specification for the returned key. This parameter is ignored if the *dwLegacyKeySpec* parameter contains a value other than zero.

If *hLegacyKey* is **NULL** and *dwLegacyKeySpec* is zero, this function will attempt to determine the key specification from the *hLegacyProv* handle.

### `dwLegacyKeySpec` [in, optional]

Specifies the key specification for the key. This can be one of the following values.

| Value | Meaning |
| --- | --- |
| 0 | The key is none of the types below. |
| **AT_KEYEXCHANGE**<br><br>1 | The key is a key exchange key. |
| **AT_SIGNATURE**<br><br>2 | The key is a signature key. |

If *hLegacyKey* is **NULL** and *dwLegacyKeySpec* is zero, this function will attempt to determine the key specification from the *hLegacyProv* handle.

### `dwFlags` [in]

A set of flags that modify the behavior of this function. No flags are defined for this function.

## Return value

Returns a status code that indicates the success or failure of the function.

Possible return codes include, but are not limited to, the following.

| Return code | Description |
| --- | --- |
| **ERROR_SUCCESS** | The function was successful. |
| **NTE_BAD_FLAGS** | The *dwFlags* parameter contains a value that is not valid. |
| **NTE_INVALID_PARAMETER** | One or more parameters are not valid. |
| **NTE_NO_MEMORY** | A memory allocation failure occurred. |

## Remarks

This is a helper function intended to help applications and system components that currently use the CryptoAPI to make a graceful transition to using CNG.

This function will only be successful if a CNG key storage provider is registered with a name or alias that is identical to the name of the [cryptographic service provider](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) (CSP) referred to by the *hLegacyProv* parameter.

This function will perform the following steps to translate the CSP handle into a CNG key handle:

1. Obtain the name of the CSP from the *hLegacyProv* handle.
2. Open the CNG provider whose name or alias is identical to the CSP name.
3. Obtain the name of the current key container in the CSP.
4. Obtain the CryptoAPI key, translate it into a CNG key, and return it in the *phKey* parameter.

A service must not call this function from its [StartService Function](https://learn.microsoft.com/windows/win32/api/winsvc/nf-winsvc-startservicea). If a service calls this function from its StartService function, a deadlock can occur, and the service may stop responding.