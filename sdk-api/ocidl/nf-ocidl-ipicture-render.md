# IPicture::Render

## Description

Renders (draws) a specified portion of the picture defined by the offset (*xSrc*,*ySrc*) of the source picture and the dimensions to copy (*cxSrc*,*xySrc*). This picture is rendered onto the specified device context, positioned at the point (*x*,*y*), and scaled to the dimensions (*cx*,*cy*). The *prcWBounds* parameter specifies the position of this rendering if the destination device context is itself a metafile. Such information is necessary to place one metafile in another. For more information, see the *prcWBounds* parameter of [IViewObject2::Draw](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-iviewobject-draw).

## Parameters

### `hDC` [in]

A handle of the device context on which to render the image.

### `x` [in]

The horizontal coordinate in *hdc* at which to place the rendered image.

### `y` [in]

The vertical coordinate in *hdc* at which to place the rendered image.

### `cx` [in]

The horizontal dimension (width) of the destination rectangle.

### `cy` [in]

The vertical dimension (height) of the destination rectangle

### `xSrc` [in]

The horizontal offset in the source picture from which to start copying.

### `ySrc` [in]

The vertical offset in the source picture from which to start copying.

### `cxSrc` [in]

The horizontal extent to copy from the source picture.

### `cySrc` [in]

The vertical extent to copy from the source picture.

### `pRcWBounds` [in]

A pointer to a rectangle containing the position of the destination within a metafile device context if *hdc* is a metafile DC. Cannot be **NULL** in such cases.

## Return value

This method supports the standard return values E_FAIL, E_INVALIDARG, and E_OUTOFMEMORY, as well as the following:

| Return code | Description |
| --- | --- |
| **S_OK** | The picture was rendered successfully. |
| **E_POINTER** | The address in *prcWBounds* is not valid when *hdc* contains a metafile device context. |
| **CTL_E_INVALIDPROPERTYVALUE** | The parameter *cx*, *cy*, *cxSrc*, or *cySrc* has a value of zero. |

## See also

[IPicture](https://learn.microsoft.com/windows/desktop/api/ocidl/nn-ocidl-ipicture)