# IManipulationProcessor::ProcessMoveWithTime

## Description

Feeds movement data, including a time stamp, for the target object to its manipulation processor.

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
you should extract the time stamp from the [TOUCHINPUT](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-touchinput) structure when you process events.

#### Examples

```cpp

static void ProcessMove(TOUCHINPUT* pTouchInput, IManipulationProcessor* pManipulationProcessor){
  pManipulationProcessor->ProcessMoveWithTime(
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

[ProcessDownWithTime](https://learn.microsoft.com/windows/desktop/api/manipulations/nf-manipulations-imanipulationprocessor-processdownwithtime)

[ProcessMove](https://learn.microsoft.com/windows/desktop/api/manipulations/nf-manipulations-imanipulationprocessor-processmove)

[ProcessUpWithTime](https://learn.microsoft.com/windows/desktop/api/manipulations/nf-manipulations-imanipulationprocessor-processupwithtime)