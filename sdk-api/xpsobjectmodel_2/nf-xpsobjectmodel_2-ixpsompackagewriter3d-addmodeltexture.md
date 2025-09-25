# IXpsOMPackageWriter3D::AddModelTexture

## Description

Creates a new 3D model texture from the specified texture part and stream.

## Parameters

### `texturePartName` [in]

The Open Package Convention (OPC) name of the texture part. This part is added to the package and becomes a relationship target of the model part.

### `textureData` [in]

A readable stream which holds 3D model texture. When calling this method, you must provide PNG or JPEG data.

## Return value

Returns the appropriate HRESULT error code.

## Remarks

Each time this method is called, it creates a new part with a specified name, content and hardcoded content type “application/vnd.ms-package.3dmanufacturing-3dmodeltexture”. That part is linked from the model part with relationship type “http://schemas.microsoft.com/3dmanufacturing/2013/01/3dmodeltexture”.

## See also

[IXpsOMPackageWriter3D](https://learn.microsoft.com/windows/desktop/api/xpsobjectmodel_2/nn-xpsobjectmodel_2-ixpsompackagewriter3d)