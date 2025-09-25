## Description

The **DDOVERLAYFX** structure passes overlay information to the [IDirectDrawSurface7::UpdateOverlay](https://learn.microsoft.com/windows/desktop/api/ddraw/nf-ddraw-idirectdrawsurface7-updateoverlay) method.

## Members

### `dwSize`

Size of the structure, in bytes. This member must be initialized before the structure is used.

### `dwAlphaEdgeBlendBitDepth`

Bit depth used to specify the constant for an alpha edge blend.

### `dwAlphaEdgeBlend`

Constant to use as the alpha for an edge blend.

### `dwReserved`

Reserved

### `dwAlphaDestConstBitDepth`

Bit depth used to specify the alpha constant for a destination.

### `DUMMYUNIONNAMEN.dwAlphaDestConst`

Constant to use as the alpha channel for a destination.

### `DUMMYUNIONNAMEN.lpDDSAlphaDest`

Address of a surface to use as the alpha channel for a destination.

### `dwAlphaSrcConstBitDepth`

Bit depth used to specify the alpha constant for a source.

### `DUMMYUNIONNAMEN`

See **Remarks**.

### `DUMMYUNIONNAMEN.dwAlphaSrcConst`

Constant to use as the alpha channel for a source.

### `DUMMYUNIONNAMEN.lpDDSAlphaSrc`

Address of a surface to use as the alpha channel for a source.

### `dckDestColorkey`

Destination color key for the overlay.

### `dckSrcColorkey`

Source color key for the overlay.

### `dwDDFX`

The following flags that specify overlay effects.

#### DDOVERFX_ARITHSTRETCHY

If stretching, use arithmetic stretching along the y-axis for this overlay.

#### DDOVERFX_MIRRORLEFTRIGHT

Mirror the overlay around the vertical axis.

#### DDOVERFX_MIRRORUPDOWN

Mirror the overlay around the horizontal axis.

### `dwFlags`

Currently not used and must be set to 0.

## Remarks

The unions in this structure have been updated to work with compilers that do not support nameless unions. If your compiler does not support nameless unions, define the NONAMELESSUNION token before including the Ddraw.h header file.