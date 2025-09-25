# IDCompositionVisual::RemoveVisual

## Description

Removes a child visual from the children list of this visual.

## Parameters

### `visual` [in]

Type: **[IDCompositionVisual](https://learn.microsoft.com/windows/desktop/api/dcomp/nn-dcomp-idcompositionvisual)***

The child visual to remove from the children list. This parameter must not be NULL.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If the function succeeds, it returns S_OK. Otherwise, it returns an **HRESULT** error code. See [DirectComposition Error Codes](https://learn.microsoft.com/windows/desktop/directcomp/directcomposition-error-codes) for a list of error codes.

## Remarks

The child visual is removed from the list of children. The order of the remaining child visuals is not changed.

This method fails if *visual* is not a child of the parent visual.

## See also

[IDCompositionDevice::CreateVisual](https://learn.microsoft.com/windows/desktop/api/dcomp/nf-dcomp-idcompositiondevice-createvisual)

[IDCompositionVisual](https://learn.microsoft.com/windows/desktop/api/dcomp/nn-dcomp-idcompositionvisual)

[IDCompositionVisual::AddVisual](https://learn.microsoft.com/windows/desktop/api/dcomp/nf-dcomp-idcompositionvisual-addvisual)

[IDCompositionVisual::RemoveAllVisuals](https://learn.microsoft.com/windows/desktop/api/dcomp/nf-dcomp-idcompositionvisual-removeallvisuals)