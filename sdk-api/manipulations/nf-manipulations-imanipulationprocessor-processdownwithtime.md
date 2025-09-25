# IManipulationProcessor::ProcessDownWithTime

## Description

Feeds touch down data, including a timestamp, to the manipulation processor associated with a target.

## Parameters

### `manipulatorId`

The identifier for the touch contact to be processed.

### `x`

The horizontal coordinate data associated with the target.

### `y`

The vertical coordinate data associated with the target.

### `timestamp`

The time of the data event.

## Return value

If the method succeeds, it returns S_OK. If it fails, it returns an HRESULT error code such as **E_FAIL**.

## Remarks

It is possible to receive touch events out of the order they were produced. To fix this,
you should extract the timestamp from the [TOUCHINPUT](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-touchinput) structure when you process events.

#### Examples

```cpp
static void ProcessDown(TOUCHINPUT* pTouchInput, IManipulationProcessor* pManipulationProcessor){
  pManipulationProcessor->ProcessDownWithTime(
    pTouchInput->dwID,
    static_cast<float>(pTouchInput->x),
    static_cast<float>(pTouchInput->y),
    pTouchInput->dwTime
  );
}

```

## See also

[IManipulationProcessor](https://learn.microsoft.com/windows/desktop/api/manipulations/nn-manipulations-imanipulationprocessor)

[Methods](https://learn.microsoft.com/windows/desktop/wintouch/mtmethods)

[ProcessDown](https://learn.microsoft.com/windows/desktop/api/manipulations/nf-manipulations-imanipulationprocessor-processdown)

[ProcessMoveWithTime](https://learn.microsoft.com/windows/desktop/api/manipulations/nf-manipulations-imanipulationprocessor-processmovewithtime)

[ProcessUpWithTime](https://learn.microsoft.com/windows/desktop/api/manipulations/nf-manipulations-imanipulationprocessor-processupwithtime)