# IDirect3DCryptoSession9::StartSessionKeyRefresh

## Description

Gets a random number that can be used to refresh the session key.

## Parameters

### `pRandomNumber`

A pointer to a byte array that receives a random number.

### `RandomNumberSize`

The size of the *pRandomNumber* array, in bytes. The size should match the size of the session key.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

To generate a new session key, perform a bitwise **XOR** between the previous session key and the random number. The new session key does not take affect until the application calls [IDirect3DCryptoSession9::FinishSessionKeyRefresh](https://learn.microsoft.com/windows/desktop/api/d3d9/nf-d3d9-idirect3dcryptosession9-finishsessionkeyrefresh).

If the driver supports this method, the driver sets the **D3DCPCAPS_FRESHENSESSIONKEY** capabilities flag in the [IDirect3DDevice9Video::GetContentProtectionCaps](https://learn.microsoft.com/windows/desktop/api/d3d9/nf-d3d9-idirect3ddevice9video-getcontentprotectioncaps) method.

## See also

[GPU-Based Content Protection](https://learn.microsoft.com/windows/desktop/medfound/gpu-based-content-protection)

[IDirect3DCryptoSession9](https://learn.microsoft.com/windows/desktop/api/d3d9/nn-d3d9-idirect3dcryptosession9)