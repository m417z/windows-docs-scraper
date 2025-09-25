# IInertiaProcessor::CompleteTime

## Description

Finishes the current manipulation at the given tick, stops inertia on the inertia processor, and raises the [ManipulationCompleted](https://learn.microsoft.com/windows/win32/api/manipulations/nf-manipulations-_imanipulationevents-manipulationcompleted) event.

## Parameters

### `timestamp` [in]

A parameter containing a timestamp (in milliseconds) to process.

## Return value

Returns **S_OK** on success, otherwise returns an error code such as **E_FAIL**.

## Remarks

The **CompleteTime** method raises the [ManipulationCompleted](https://learn.microsoft.com/windows/win32/api/manipulations/nf-manipulations-_imanipulationevents-manipulationcompleted) event on an [_IManipulationEvents](https://learn.microsoft.com/windows/win32/api/manipulations/nn-manipulations-_imanipulationevents) interface implementation.

## See also

[Complete](https://learn.microsoft.com/windows/desktop/api/manipulations/nf-manipulations-iinertiaprocessor-complete)

[IInertiaProcessor](https://learn.microsoft.com/windows/desktop/api/manipulations/nn-manipulations-iinertiaprocessor)

[Methods](https://learn.microsoft.com/windows/desktop/wintouch/imanipulationprocessor-methods)