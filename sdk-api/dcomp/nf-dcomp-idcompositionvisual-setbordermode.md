# IDCompositionVisual::SetBorderMode

## Description

Sets the BorderMode property, which specifies how to compose the edges of bitmaps and clips associated with this visual, or with visuals in the subtree rooted at this visual.

## Parameters

### `borderMode` [in]

Type: **[DCOMPOSITION_BORDER_MODE](https://learn.microsoft.com/windows/desktop/api/dcomptypes/ne-dcomptypes-dcomposition_border_mode)**

The border mode to use.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If the function succeeds, it returns S_OK. Otherwise, it returns an [HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types) error code. See [DirectComposition Error Codes](https://learn.microsoft.com/windows/desktop/directcomp/directcomposition-error-codes) for a list of error codes.

## Remarks

The border mode affects how the edges of a bitmap are composed when the bitmap is transformed such that the edges are not exactly axis-aligned and at precise pixel boundaries. It also affects how content is clipped at the corners of a clip that has rounded corners, and at the edge of a clip that is transformed such that the edges are not exactly axis-aligned and at precise pixel boundaries.

By default, a visual inherits the border mode of its parent visual, which may inherit the border mode of its parent visual, and so on. A visual uses the default border mode if this method is never called for the visual, or if this method is called with [DCOMPOSITION_BORDER_MODE_INHERIT](https://learn.microsoft.com/windows/desktop/api/dcomptypes/ne-dcomptypes-dcomposition_border_mode). If no visuals set the border mode, the default for the entire visual tree is aliased rendering, which offers the lowest visual quality but the highest performance.

If the *borderMode* parameter is anything other than [DCOMPOSITION_BORDER_MODE_INHERIT](https://learn.microsoft.com/windows/desktop/api/dcomptypes/ne-dcomptypes-dcomposition_border_mode), this visual's bitmap and clip are composed with the specified border mode. In addition, this border mode becomes the new default for the children of the current visual. That is, if the border mode of this visual's children is unchanged or explicitly set to **DCOMPOSITION_BORDER_MODE_INHERIT**, the bitmaps and clips of the child visuals are composed using the border mode of this visual.

## See also

[IDCompositionVisual](https://learn.microsoft.com/windows/desktop/api/dcomp/nn-dcomp-idcompositionvisual)