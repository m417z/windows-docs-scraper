# IDCompositionTableTransferEffect::SetClampOutput

## Description

Specifies whether the effect clamps color values to between 0 and 1 before the effect passes the values to the next effect in the graph.

## Parameters

### `clampOutput` [in]

Type: **BOOL**

A boolean value that specifies whether the effect clamps color values to between 0 and 1 before the effect passes the values to the next effect in the graph.
If you set this to TRUE the effect will clamp the values. If you set this to FALSE, the effect will not clamp the color values,
but other effects and the output surface may clamp the values if they are not of high enough precision.
The effect clamps the values before it premultiplies the alpha.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IDCompositionTableTransferEffect](https://learn.microsoft.com/windows/desktop/api/dcomp/nn-dcomp-idcompositiontabletransfereffect)