# ID3D11View::GetResource

## Description

Get the resource that is accessed through this view.

## Parameters

### `ppResource` [out]

Type: **[ID3D11Resource](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11resource)****

Address of a pointer to the resource that is accessed through this view. (See [ID3D11Resource](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11resource).)

## Remarks

This function increments the reference count of the resource by one, so it is necessary to call **Release** on the returned pointer when the application is done with it. Destroying (or losing) the returned pointer before **Release** is called will result in a memory leak.

## See also

[ID3D11View](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11view)