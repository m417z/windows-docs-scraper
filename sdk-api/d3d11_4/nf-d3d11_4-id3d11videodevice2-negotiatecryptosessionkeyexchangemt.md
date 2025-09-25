## Description

Verifies that [ID3D11VideoContext::NegotiateCryptoSessionKeyExchange](https://learn.microsoft.com/windows/win32/api/d3d11/nf-d3d11-id3d11videocontext-negotiatecryptosessionkeyexchange) behaves as expected when called asynchronously.

## Parameters

### `pCryptoSession`

Type: \_In\_ **[ID3D11CryptoSession](https://learn.microsoft.com/windows/win32/api/d3d11/nn-d3d11-id3d11cryptosession)\***

A pointer to the **ID3D11CryptoSession** interface of the cryptographic session.

### `flags`

Type: \_In\_ **D3D11_CRYPTO_SESSION_KEY_EXCHANGE_FLAGS**

Flags.

### `DataSize`

Type: \_In\_ **[UINT](https://learn.microsoft.com/windows/win32/winprog/windows-data-type)**

The size of the *pData* byte array, in bytes.

### `pData`

Type: \_Inout\_updates\_bytes\_\(DataSize\) **[void](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)\***

A pointer to a byte array that contains the encrypted session key.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

If the function succeeds, it returns **S_OK**. Otherwise, it returns an [HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes) [error code](https://learn.microsoft.com/windows/desktop/com/com-error-codes-10).

## Remarks

## See also

* [ID3D11VideoDevice2](https://learn.microsoft.com/windows/win32/api/d3d11_4/nn-d3d11_4-id3d11videodevice2)