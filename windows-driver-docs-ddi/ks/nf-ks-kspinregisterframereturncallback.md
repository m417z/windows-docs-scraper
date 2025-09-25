# KsPinRegisterFrameReturnCallback function

## Description

The **KsPinRegisterFrameReturnCallback** function registers a frame return callback with AVStream for a given pin.

## Parameters

### `Pin` [in]

A pointer to the AVStream [KSPIN](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_kspin) structure that you want to place into injection mode by registering a frame return callback.

### `FrameReturn` [in]

This parameter supplies the address of a minidriver-provided [AVStrMiniFrameReturn](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nc-ks-pfnkspinframereturn) routine.

## Remarks

If a pin has registered a frame return callback before transitioning from **KSSTATE_STOP** to KSSTATE_ACQUIRE, the pin is placed into injection mode. This indicates that the pin will not receive buffers and fill them, but rather manually inject data frames into the circuit using **KsPinSubmitFrame** or **KsPinSubmitFrameMdl**. When the data frame completes its travel around the circuit and returns to the pin on which it was submitted, AVStream recycles it by calling [AVStrMiniFrameReturn](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nc-ks-pfnkspinframereturn).

Minidrivers that call this function are directly responsible for injecting frames into the circuit; they do not receive buffers to fill and do not directly interact with the queue as do most minidrivers. Also note that the frame return callback should be registered before the kernel pipe section is created. The kernel pipe section is created when the pin transitions to KSSTATE_ACQUIRE. For more information, see [Frame Injection](https://learn.microsoft.com/windows-hardware/drivers/stream/frame-injection).

## See also

[AVStrMiniFrameReturn](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nc-ks-pfnkspinframereturn)

[KsPinSubmitFrame](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-kspinsubmitframe)

[KsPinSubmitFrameMdl](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-kspinsubmitframemdl)