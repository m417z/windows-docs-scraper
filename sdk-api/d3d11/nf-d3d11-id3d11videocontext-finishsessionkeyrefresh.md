# ID3D11VideoContext::FinishSessionKeyRefresh

## Description

Switches to a new session key.

## Parameters

### `pCryptoSession` [in]

A pointer to the [ID3D11CryptoSession](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11cryptosession) interface.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

This function can only be called when the [D3D11_CONTENT_PROTECTION_CAPS_FRESHEN_SESSION_KEY](https://learn.microsoft.com/windows/desktop/api/d3d11/ne-d3d11-d3d11_content_protection_caps) cap is reported.

Before calling this method, call [ID3D11VideoContext::StartSessionKeyRefresh](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11videocontext-startsessionkeyrefresh). The **StartSessionKeyRefresh** method gets a random number from the driver, which is used to create a new session key. The new session key does not become active until the application calls **FinishSessionKeyRefresh**. After the application calls **FinishSessionKeyRefresh**, all protected surfaces are encrypted using the new session key.

## See also

[ID3D11VideoContext](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11videocontext)