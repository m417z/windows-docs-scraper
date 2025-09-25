# IDCompositionVisual::RemoveAllVisuals

## Description

Removes all visuals from the children list of this visual.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If the function succeeds, it returns S_OK. Otherwise, it returns an **HRESULT** error code. See [DirectComposition Error Codes](https://learn.microsoft.com/windows/desktop/directcomp/directcomposition-error-codes) for a list of error codes.

## Remarks

This method can be called even if this visual has no children.

## See also

[IDCompositionDevice::CreateVisual](https://learn.microsoft.com/windows/desktop/api/dcomp/nf-dcomp-idcompositiondevice-createvisual)

[IDCompositionVisual](https://learn.microsoft.com/windows/desktop/api/dcomp/nn-dcomp-idcompositionvisual)

[IDCompositionVisual::AddVisual](https://learn.microsoft.com/windows/desktop/api/dcomp/nf-dcomp-idcompositionvisual-addvisual)

[IDCompositionVisual::RemoveVisual](https://learn.microsoft.com/windows/desktop/api/dcomp/nf-dcomp-idcompositionvisual-removevisual)