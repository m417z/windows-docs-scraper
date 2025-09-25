## Description

Specifies the properties of a High Efficiency Image Format (HEIF) image.

## Constants

### `WICHeifOrientation:0x1`

[VT_UI2] Indicates the orientation of the image.

The value of this property uses the same numbering scheme as the [System.Photo.Orientation](https://learn.microsoft.com/windows/desktop/properties/props-system-photo-orientation) property. For example, a value of 1 (PHOTO_ORIENTATION_NORMAL) indicates a 0 degree rotation.

### `WICHeifLayeredImageCanvasColor:0x2`

WICColor (VT_UI4).

Specifies the background color of the layered image. If this property is present and not VT_EMPTY, then the image is a layered image.

### `WICHeifLayeredImageLayerPositions:0x3`

An array of POINT structures (containing X,Y coordinates), specifying the coordinates of each layer image in the canvas (VT_VECTOR | VT_UI8).

The coordinates specify the placement of each layer image on the canvas. The order of each element in the array directly corresponds to the order of each layer image in the [WICBitmapChainType_Layer](https://learn.microsoft.com/windows/win32/api/wincodec/ne-wincodec-wicbitmapchaintype) type of chain. The resulting layered image has the same size as the canvas; that is, the dimensions of the primary image. Layer images are cropped to fit the canvas.

### `WICHeifProperties_FORCE_DWORD:0x7fffffff`