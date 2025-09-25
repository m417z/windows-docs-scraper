# IManipulationProcessor::ProcessMove

## Description

The **ProcessMove** method feeds movement data for the target object to its manipulation processor.

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
cases where performance is degrading you should use the [ProcessMoveWithTime](https://learn.microsoft.com/windows/desktop/api/manipulations/nf-manipulations-imanipulationprocessor-processmovewithtime) method.

## See also

[IManipulationProcessor](https://learn.microsoft.com/windows/desktop/api/manipulations/nn-manipulations-imanipulationprocessor)

[Methods](https://learn.microsoft.com/windows/desktop/wintouch/mtmethods)

[ProcessDown](https://learn.microsoft.com/windows/desktop/api/manipulations/nf-manipulations-imanipulationprocessor-processdown)

[ProcessMoveWithTime](https://learn.microsoft.com/windows/desktop/api/manipulations/nf-manipulations-imanipulationprocessor-processmovewithtime)

[ProcessUp](https://learn.microsoft.com/windows/desktop/api/manipulations/nf-manipulations-imanipulationprocessor-processup)