# ID3D11VideoContext1::CheckCryptoSessionStatus

## Description

Checks the status of a crypto session.

## Parameters

### `pCryptoSession` [in]

Type: **ID3D11CryptoSession***

Specifies a [ID3D11CryptoSession](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11cryptosession) for which status is checked.

### `pStatus` [out]

Type: **[D3D11_CRYPTO_SESSION_STATUS](https://learn.microsoft.com/windows/desktop/api/d3d11_1/ne-d3d11_1-d3d11_crypto_session_status)***

A D3D11_CRYPTO_SESSION_STATUS that is populated with the crypto session status upon completion.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

This method returns one of the following error codes.

|  |  |
| --- | --- |
| S_OK | The operation completed successfully. |
| E_INVALIDARG | An invalid parameter was passed or this function was called using an invalid calling pattern. |
| E_OUTOFMEMORY | There is insufficient memory to complete the operation. |

## See also

[ID3D11VideoContext1](https://learn.microsoft.com/windows/desktop/api/d3d11_1/nn-d3d11_1-id3d11videocontext1)