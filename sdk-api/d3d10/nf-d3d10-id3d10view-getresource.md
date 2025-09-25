# ID3D10View::GetResource

## Description

Get the resource that is accessed through this view.

## Parameters

### `ppResource` [out]

Type: **[ID3D10Resource](https://learn.microsoft.com/windows/desktop/api/d3d10/nn-d3d10-id3d10resource)****

Address of a pointer to the resource that is accessed through this view. (See [ID3D10Resource](https://learn.microsoft.com/windows/desktop/api/d3d10/nn-d3d10-id3d10resource).)

## Remarks

This function increments the reference count of the resource by one, so it is necessary to call Release on the returned pointer when the application is done with it. Destroying (or losing) the returned pointer before Release is called will result in a memory leak.

## See also

[ID3D10View Interface](https://learn.microsoft.com/windows/desktop/api/d3d10/nn-d3d10-id3d10view)