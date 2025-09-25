# ID3D11VideoContext::StartSessionKeyRefresh

## Description

Gets a random number that can be used to refresh the session key.

## Parameters

### `pCryptoSession` [in]

A pointer to the [ID3D11CryptoSession](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11cryptosession) interface.

### `RandomNumberSize` [in]

The size of the *pRandomNumber* array, in bytes. The size should match the size of the session key.

### `pRandomNumber` [out]

A pointer to a byte array that receives a random number.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

To generate a new session key, perform a bitwise **XOR** between the previous session key and the random number. The new session key does not take affect until the application calls [ID3D11VideoContext::FinishSessionKeyRefresh](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11videocontext-finishsessionkeyrefresh).

To query whether the driver supports this method, call [ID3D11VideoDevice::GetContentProtectionCaps](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11videodevice-getcontentprotectioncaps) and check for the **D3D11_CONTENT_PROTECTION_CAPS_FRESHEN_SESSION_KEY** capabilities flag.

## See also

[ID3D11VideoContext](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11videocontext)