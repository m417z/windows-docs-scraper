# IManipulationProcessor::ProcessUp

## Description

The **ProcessUp** method feeds data to a target's manipulation processor for touch up sequences.

## Parameters

### `manipulatorId`

The identifier for the touch contact that you want to process.

### `x`

The horizontal coordinate data associated with the target.

### `y`

The vertical coordinate data associated with the target.

## Return value

Returns **S_OK** on success, otherwise returns an error code such as **E_FAIL**.

## Remarks

This method takes a timestamp using system time rather than from the touch hardware. To improve the experience in
cases where performance is degrading you should use the [ProcessUpWithTime](https://learn.microsoft.com/windows/desktop/api/manipulations/nf-manipulations-imanipulationprocessor-processupwithtime) method.

## See also

[IManipulationProcessor](https://learn.microsoft.com/windows/desktop/api/manipulations/nn-manipulations-imanipulationprocessor)

[Methods](https://learn.microsoft.com/windows/desktop/wintouch/mtmethods)

[ProcessDown](https://learn.microsoft.com/windows/desktop/api/manipulations/nf-manipulations-imanipulationprocessor-processdown)

[ProcessMove](https://learn.microsoft.com/windows/desktop/api/manipulations/nf-manipulations-imanipulationprocessor-processmove)

[ProcessUpWithTime](https://learn.microsoft.com/windows/desktop/api/manipulations/nf-manipulations-imanipulationprocessor-processupwithtime)