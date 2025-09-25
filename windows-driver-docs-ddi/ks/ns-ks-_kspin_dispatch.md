# _KSPIN_DISPATCH structure

## Description

The KSPIN_DISPATCH structure describes the callbacks for which clients can register in order to receive notification of pin events.

## Members

### `Create`

A pointer to a minidriver-supplied [AVStrMiniPinCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nc-ks-pfnkspinirp) callback routine. Optional. Can be **NULL**.

### `Close`

A pointer to a minidriver-supplied [AVStrMiniPinClose](https://learn.microsoft.com/previous-versions/ff556329(v=vs.85)) callback routine. Optional. Can be **NULL**.

### `Process`

A pointer to a minidriver-supplied [AVStrMiniPinProcess](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nc-ks-pfnkspin) callback routine. Optional. Can be **NULL**.

### `Reset`

A pointer to a minidriver-supplied [AVStrMiniPinReset](https://learn.microsoft.com/previous-versions/ff556354(v=vs.85)) callback routine. Optional. Can be **NULL**.

### `SetDataFormat`

A pointer to a minidriver-supplied [AVStrMiniPinSetDataFormat](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nc-ks-pfnkspinsetdataformat) callback routine. Optional. Can be **NULL**.

### `SetDeviceState`

A pointer to a minidriver-supplied [AVStrMiniPinSetDeviceState](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nc-ks-pfnkspinsetdevicestate) callback routine. Optional. Can be **NULL**.

### `Connect`

A pointer to a minidriver-supplied [AVStrMiniPinConnect](https://learn.microsoft.com/previous-versions/ff556332(v=vs.85)) callback routine. Optional. Can be **NULL**.

### `Disconnect`

A pointer to a minidriver-supplied [AVStrMiniPinDisconnect](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nc-ks-pfnkspinvoid) callback routine. Optional. Can be **NULL**.

### `Clock`

A pointer to a [KSCLOCK_DISPATCH](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_ksclock_dispatch) structure. Specify this member for a pin that exposes a clock. Optional. Can be **NULL**.

### `Allocator`

A pointer to a [KSALLOCATOR_DISPATCH](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_ksallocator_dispatch) structure. Specify this member for a pin that is capable of performing kernel-level allocation. Optional. Can be **NULL**.

## Remarks

Any of the callback pointers can be **NULL**, indicating that the minidriver does not require to receive notification for this particular dispatch.

If the minidriver needs to determine whether it has been signaled to go to a specific state (for example KSSTATE_RUN), comparing the value of the **DeviceState** member of [KSPIN](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_kspin) to **KSSTATE_RUN** is not a reliable method of doing this. **DeviceState** refers to the state to which the pin has been signaled to go, not the pipe. To perform the above reliably, instead create a variable in the **SetDeviceState** callback of this structure and then check this variable to make the determination.

## See also

[KSALLOCATOR_DISPATCH](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_ksallocator_dispatch)

[KSCLOCK_DISPATCH](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_ksclock_dispatch)

[KSPIN](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_kspin)

[KsCompletePendingRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-kscompletependingrequest)