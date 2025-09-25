# IDirect3DDevice9Video::GetContentProtectionCaps

## Description

Queries the display driver for its content protection capabilities.

## Parameters

### `pCryptoType`

A pointer to a GUID that specifies the type of encryption to use. The following GUIDs are defined.

**D3DCRYPTOTYPE_AES128_CTR**

128-bit Advanced Encryption Standard CTR mode (AES-CTR) block cipher.

**D3DCRYPTOTYPE_PROPRIETARY**

Proprietary encryption algorithm.

### `pDecodeProfile`

A pointer to a GUID that specifies the DirectX Video Acceleration 2 (DXVA-2) decoding profile. For a list of possible values, see [IDirectXVideoDecoderService::GetDecoderDeviceGuids](https://learn.microsoft.com/windows/desktop/api/dxva2api/nf-dxva2api-idirectxvideodecoderservice-getdecoderdeviceguids). If DXVA-2 decoding will not be used, set this parameter to **NULL**.

### `pCaps`

A pointer to a [D3DCONTENTPROTECTIONCAPS](https://learn.microsoft.com/windows/desktop/api/d3d9caps/ns-d3d9caps-d3dcontentprotectioncaps) structure. The method fills in this structure with the driver's content protection capabilities.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[GPU-Based Content Protection](https://learn.microsoft.com/windows/desktop/medfound/gpu-based-content-protection)

[IDirect3DDevice9Video](https://learn.microsoft.com/windows/desktop/api/d3d9/nn-d3d9-idirect3ddevice9video)