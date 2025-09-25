# ID3D11DeviceChild::GetDevice

## Description

Get a pointer to the device that created this interface.

## Parameters

### `ppDevice` [out]

Type: **[ID3D11Device](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11device)****

Address of a pointer to a device (see [ID3D11Device](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11device)).

## Remarks

Any returned interfaces will have their reference count incremented by one, so be sure to call ::release() on the returned pointer(s) before they are freed or else you will have a memory leak.

## See also

[ID3D11DeviceChild](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11devicechild)