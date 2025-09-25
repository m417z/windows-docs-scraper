# PFND3DDDI_SETASYNCCALLBACKSCB callback function

## Description

The **pfnSetAsyncCallbacksCb** function notifies the Microsoft Direct3D runtime whether the runtime will start or stop receiving calls to the runtime's callback functions from a worker thread.

## Parameters

### `hDevice`

A handle to the display device (graphics context).

### `Enable`

A Boolean value that specifies whether the runtime will start or stop receiving calls to the runtime's callback functions from a worker thread. **TRUE** indicates that the runtime will start receiving calls to its callback functions from a worker thread; **FALSE** indicates that the runtime will stop receiving calls to its callback functions from a worker thread.

## Return value

**pfnSetAsyncCallbacksCb** returns one of the following values:

|Return code|Description|
|--- |--- |
|S_OK|The Direct3D runtime was successfully notified.|
|E_INVALIDARG|Parameters were validated and determined to be incorrect.|

This function might also return other HRESULT values.

## Remarks

If a user-mode display driver implements its own multiple-processor optimizations (that is, the driver creates a worker thread and processes commands in that thread), the driver must call **pfnSetAsyncCallbacksCb** to notify the Direct3D runtime whether the runtime will start or stop receiving calls to the runtime's callback functions from the worker thread. Additionally, such drivers must not implement the [LockAsync](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_lockasync), [UnlockAsync](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_unlockasync), and [Rename](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_rename) functions. This ensures that the runtime does not attempt to use its own multiple-processor optimizations.

The user-mode display driver can call **pfnSetAsyncCallbacksCb** only on the main application thread (that is, the thread that called into the driver). The driver's worker thread cannot call **pfnSetAsyncCallbacksCb**. At any point in time, only one thread that references a particular rendering device can run in any of the runtime's callback functions.

Before the user-mode display driver calls any of the runtime's callback functions on a thread other than the main application thread, the driver must pass **TRUE** to the *Enable* parameter in a call to **pfnSetAsyncCallbacksCb**. Before the user-mode display driver calls any of the runtime's callback functions on the main application thread, the driver must pass **FALSE** to the *Enable* parameter in a call to **pfnSetAsyncCallbacksCb**.

Within the implementation of [Flush](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfworkitem-flush) for each rendering device, the driver calls **pfnSetAsyncCallbacksCb** and passes **FALSE** to the *Enable* parameter.

When the driver passes **TRUE** to the *Enable* parameter in a call to **pfnSetAsyncCallbacksCb**, the runtime puts itself in a state where it does not immediately respond to device-lost situations in its callback functions. Instead, when the runtime detects a device lost in a callback function while in this state, it sets a bit that indicates that the event occurred. When the driver passes **FALSE** to the *Enable* parameter in a call to **pfnSetAsyncCallbacksCb**, the runtime checks the bit to determine if a device lost occurred. If the bit is set, the runtime performs its typical device-lost handling. After this point, the driver no longer receives most calls to its functions from the runtime.

Only DirectX 9 and DirectX 9L versions of the runtime support **pfnSetAsyncCallbacksCb**. DirectX 10 and later versions of the runtime set the **pfnSetAsyncCallbacksCb** member of the [D3DDDI_DEVICECALLBACKS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddi_devicecallbacks) structure to **NULL** when the runtime calls the user-mode display driver's [CreateDevice(D3D10)](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_createdevice) function to create a rendering device.

**Note** DirectX versions earlier than 9 do not support multiple-processor optimizations.

Drivers can call the runtime's callback functions only from a worker thread if the runtime previously set the **pfnSetAsyncCallbacksCb** member of D3DDDI_DEVICECALLBACKS to non-**NULL** in a call to the driver's [CreateDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_createdevice) function.

## See also

[CreateDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_createdevice)

[CreateDevice(D3D10)](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_createdevice)

[D3DDDI_DEVICECALLBACKS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddi_devicecallbacks)

[Flush](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfworkitem-flush)

[LockAsync](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_lockasync)

[Rename](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_rename)

[UnlockAsync](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_unlockasync)