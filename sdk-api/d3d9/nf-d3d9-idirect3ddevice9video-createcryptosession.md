# IDirect3DDevice9Video::CreateCryptoSession

## Description

Creates a cryptographic session to encrypt video content that is sent to the display driver.

## Parameters

### `pCryptoType`

Pointer to a GUID that specifies the type of encryption to use. The following GUIDs are defined.

**pDecodeProfile**

Type: **GUID**

A pointer to a GUID that specifies the DirectX Video Acceleration 2 (DXVA-2) decoding profile. For a list of possible values, see IDirectXVideoDecoderService::GetDecoderDeviceGuids. If DXVA-2 decoding will not be used, set this parameter to NULL.

**pCaps**

Type: **D3DCONTENTPROTECTIONCAPS**

 A pointer to a D3DCONTENTPROTECTIONCAPS structure. The method fills in this structure with the driver's content protection capabilities.

### `pDecodeProfile`

Pointer to a GUID that specifies the DirectX Video Acceleration 2 (DXVA-2) decoding profile. For a list of possible values, see [IDirectXVideoDecoderService::GetDecoderDeviceGuids](https://learn.microsoft.com/windows/desktop/api/dxva2api/nf-dxva2api-idirectxvideodecoderservice-getdecoderdeviceguids). If DXVA-2 decoding will not be used, set this parameter to **NULL**.

### `ppCryptoSession`

Receives a pointer to the [IDirect3DCryptoSession9](https://learn.microsoft.com/windows/desktop/api/d3d9/nn-d3d9-idirect3dcryptosession9) interface. The caller must release the interface.

### `pCryptoHandle`

Receives a handle for the session.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[GPU-Based Content Protection](https://learn.microsoft.com/windows/desktop/medfound/gpu-based-content-protection)

[IDirect3DDevice9Video](https://learn.microsoft.com/windows/desktop/api/d3d9/nn-d3d9-idirect3ddevice9video)