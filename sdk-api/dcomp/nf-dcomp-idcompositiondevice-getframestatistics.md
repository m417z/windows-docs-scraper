# IDCompositionDevice::GetFrameStatistics

## Description

Retrieves information from the composition engine about composition times and the frame rate.

## Parameters

### `statistics` [out]

Type: **[DCOMPOSITION_FRAME_STATISTICS](https://learn.microsoft.com/windows/desktop/api/dcomptypes/ns-dcomptypes-dcomposition_frame_statistics)***

A structure that receives composition times and frame rate information.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If the function succeeds, it returns S_OK. Otherwise, it returns an [HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types) error code. See [DirectComposition Error Codes](https://learn.microsoft.com/windows/desktop/directcomp/directcomposition-error-codes) for a list of error codes.

## Remarks

This method retrieves timing information about the composition engine that an application can use to synchronize the rasterization of bitmaps with independent animations.

## See also

[Composition Target Window](https://learn.microsoft.com/windows/desktop/directcomp/basic-concepts)

[IDCompositionDevice](https://learn.microsoft.com/windows/desktop/api/dcomp/nn-dcomp-idcompositiondevice)