# D3DDDICB_SIGNALFLAGS structure

## Description

The **D3DDDICB_SIGNALFLAGS** structure describes signaling behavior in a call to the [**pfnSignalSynchronizationObjectCb**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_signalsynchronizationobjectcb) or [**pfnSignalSynchronizationObject2Cb**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_signalsynchronizationobject2cb) functions.

## Members

### `SignalAtSubmission`

A UINT value that specifies whether a context should signal synchronization objects when the previously queued packet is submitted rather than completed (which is the default behavior).

Setting this member is equivalent to setting the first bit of the 32-bit **Value** member (0x00000001).

### `EnqueueCpuEvent`

A UINT value that modifies the behavior of the [**pfnSignalSynchronizationObject2Cb**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_signalsynchronizationobject2cb) function.

When this member is set:

* The event specified by the **CpuEventHandle** member of the [**D3DDDICB_SIGNALSYNCHRONIZATIONOBJECT2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddicb_signalsynchronizationobject2) structure is signaled when all contexts specified in **D3DDDICB_SIGNALSYNCHRONIZATIONOBJECT2** process the signal command.

* Members of the [**D3DDDICB_SIGNALSYNCHRONIZATIONOBJECT2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddicb_signalsynchronizationobject2) structure that the [**pfnSignalSynchronizationObject2Cb**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_signalsynchronizationobject2cb) function's **pData** parameter points to are restricted as follows:

  * **ObjectCount** must be zero.
  * **CpuEventHandle** must be a valid event handle.

Setting this member is equivalent to setting the second bit of the 32-bit **Value** member (0x00000002).

Supported starting with Windows 8.

### `AllowFenceRewind`

A UINT value that indicates whether an intentional fence rewind is allowed. When set TRUE, the fence can be rewound to a queued fence that is behind the current one.

Supported starting with Windows 10 (WDDM 2.0).

### `DXGK_SIGNAL_FLAG_INTERNAL0`

This member is reserved and should be set to zero.

### `Reserved`

This member is reserved and should be set to zero.

### `Value`

A member in the union that is contained in **D3DDDICB_SIGNALFLAGS** that can hold one 32-bit value that identifies signaling behavior.

## See also

[**D3DDDICB_SIGNALSYNCHRONIZATIONOBJECT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddicb_signalsynchronizationobject)

[**D3DDDICB_SIGNALSYNCHRONIZATIONOBJECT2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddicb_signalsynchronizationobject2)

[**pfnSignalSynchronizationObject2Cb**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_signalsynchronizationobject2cb)

[**pfnSignalSynchronizationObjectCb**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_signalsynchronizationobjectcb)