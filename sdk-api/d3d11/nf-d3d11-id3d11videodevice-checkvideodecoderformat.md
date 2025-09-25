# ID3D11VideoDevice::CheckVideoDecoderFormat

## Description

Given aprofile, checks whether the driver supports a specified output format.

## Parameters

### `pDecoderProfile` [in]

A pointer to a GUID that identifies the profile. To get the list of supported profiles, call [ID3D11VideoDevice::GetVideoDecoderProfile](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11videodevice-getvideodecoderprofile).

### `Format` [in]

A [DXGI_FORMAT](https://learn.microsoft.com/windows/desktop/api/dxgiformat/ne-dxgiformat-dxgi_format) value that specifies the output format. Typical values include **DXGI_FORMAT_NV12** and **DXGI_FORMAT_420_OPAQUE**.

### `pSupported` [out]

Receives the value **TRUE** if the format is supported, or **FALSE** otherwise.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

If the driver does not support the profile given in *pDecoderProfile*, the method returns **E_INVALIDARG**. If the driver supports the profile, but the DXGI format is not compatible with the profile, the method succeeds but returns the value **FALSE** in *pSupported*.

## See also

[ID3D11VideoDevice](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11videodevice)