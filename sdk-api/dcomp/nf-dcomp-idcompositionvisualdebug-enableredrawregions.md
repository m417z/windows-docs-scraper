# IDCompositionVisualDebug::EnableRedrawRegions

## Description

Enables highlighting visuals when content is being redrawn.

## Return value

If the function succeeds, it returns S_OK. Otherwise, it returns an **HRESULT** error code. See [DirectComposition Error Codes](https://learn.microsoft.com/windows/desktop/directcomp/directcomposition-error-codes) for a list of error codes.

## Remarks

Highlighting redraw regions can be enabled by calling **EnableRedrawRegions**. With this function, redrawn client areas are visually highlighted every frame the visual is updated. Redraw regions are drawn on the source of the VisualDebug and child visuals. Redraw is triggered when properties of a visual are updated. The updated visual does not necessarily need to visually change to trigger a redraw. The highlighting will cycle through Blue, Yellow, Pink and Green to provide an order of which content is being updated. The redraw regions are only visible while the window of the VisualDebug is being updated.

## See also

[IDCompositionDeviceDebug](https://learn.microsoft.com/windows/desktop/api/dcomp/nn-dcomp-idcompositiondevicedebug)

[IDCompositionVisualDebug](https://learn.microsoft.com/windows/desktop/api/dcomp/nn-dcomp-idcompositionvisualdebug)

[IDCompositionVisualDebug::DisableRedrawRegions](https://learn.microsoft.com/windows/desktop/api/dcomp/nf-dcomp-idcompositionvisualdebug-disableredrawregions)