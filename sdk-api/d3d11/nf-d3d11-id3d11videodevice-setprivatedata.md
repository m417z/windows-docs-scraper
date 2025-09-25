# ID3D11VideoDevice::SetPrivateData

## Description

Sets private data on the video device and associates that data with a GUID.

## Parameters

### `guid` [in]

The GUID associated with the data.

### `DataSize` [in]

The size of the data, in bytes.

### `pData` [in]

A pointer to the data.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[ID3D11VideoDevice](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11videodevice)