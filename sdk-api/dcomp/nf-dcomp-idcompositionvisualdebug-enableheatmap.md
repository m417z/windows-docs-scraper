# IDCompositionVisualDebug::EnableHeatMap

## Description

Enables a visual heatmap that represents overdraw regions.

## Parameters

### `color` [in]

## Return value

If the function succeeds, it returns S_OK. Otherwise, it returns an **HRESULT** error code. See [DirectComposition Error Codes](https://learn.microsoft.com/windows/desktop/directcomp/directcomposition-error-codes) for a list of error codes.

## Remarks

Heatmaps can be enabled by calling **EnableHeatMap**. The heatmaps are drawn on the source of the VisualDebug visual and child visuals. The heatmaps are represented in a specified color for all visual content. The heatmap color must have a transparency in order to see the overlaying overdraw regions. The colored surfaces are blended together to visually show all overdraw regions in a single view.

## See also

[IDCompositionDeviceDebug](https://learn.microsoft.com/windows/desktop/api/dcomp/nn-dcomp-idcompositiondevicedebug)

[IDCompositionVisualDebug](https://learn.microsoft.com/windows/desktop/api/dcomp/nn-dcomp-idcompositionvisualdebug)

[IDCompositionVisualDebug::DisableHeatMap](https://learn.microsoft.com/windows/desktop/api/dcomp/nf-dcomp-idcompositionvisualdebug-disableheatmap)