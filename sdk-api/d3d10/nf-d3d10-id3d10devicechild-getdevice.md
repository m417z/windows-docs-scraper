# ID3D10DeviceChild::GetDevice

## Description

Get a pointer to the device that created this interface.

## Parameters

### `ppDevice` [out]

Type: **[ID3D10Device](https://learn.microsoft.com/windows/desktop/api/d3d10/nn-d3d10-id3d10device)****

Address of a pointer to a device (see [ID3D10Device Interface](https://learn.microsoft.com/windows/desktop/api/d3d10/nn-d3d10-id3d10device)).

## Remarks

Any returned interfaces will have their reference count incremented by one, so be sure to call ::release() on the returned pointer(s) before they are freed or else you will have a memory leak.

## See also

[ID3D10DeviceChild Interface](https://learn.microsoft.com/windows/desktop/api/d3d10/nn-d3d10-id3d10devicechild)