# ID3D11VideoDevice::GetVideoDecoderProfile

## Description

Gets a profile that is supported by the driver.

## Parameters

### `Index` [in]

The zero-based index of the profile. To get the number of profiles that the driver supports, call [ID3D11VideoDevice::GetVideoDecoderProfileCount](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11videodevice-getvideodecoderprofilecount).

### `pDecoderProfile` [out]

Receives a GUID that identifies the profile.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[ID3D11VideoDevice](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11videodevice)