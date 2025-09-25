# IDirectManipulationFrameInfoProvider::GetNextFrameInfo

## Description

Retrieves the composition timing information from the compositor.

## Parameters

### `time` [out]

The current time, in milliseconds.

### `processTime` [out]

The time, in milliseconds, when the compositor begins constructing the next frame.

### `compositionTime` [out]

The time, in milliseconds, when the compositor finishes composing and drawing the next frame on the screen.

## Return value

If the method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The system implementation of [IDirectManipulationFrameInfoProvider](https://learn.microsoft.com/previous-versions/windows/desktop/api/directmanipulation/nn-directmanipulation-idirectmanipulationframeinfoprovider) uses [DirectComposition](https://learn.microsoft.com/windows/desktop/directcomp/directcomposition-portal). [GetFrameStatistics](https://learn.microsoft.com/windows/desktop/api/dcomp/nf-dcomp-idcompositiondevice-getframestatistics) is used to calculate the parameter values for **GetNextFrameInfo**.

## See also

[IDirectManipulationCompositor](https://learn.microsoft.com/previous-versions/windows/desktop/api/directmanipulation/nn-directmanipulation-idirectmanipulationcompositor)

[IDirectManipulationFrameInfoProvider](https://learn.microsoft.com/previous-versions/windows/desktop/api/directmanipulation/nn-directmanipulation-idirectmanipulationframeinfoprovider)