# PFNKSPINVOID callback function

## Description

An AVStream minidriver's callback routine is called when:

* The relevant [KSPIN](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_kspin) is serving as a sink pin and this sink pin is disconnected from an AVStream source pin.
* A [KSPIN](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_kspin) structure's reset state is changed due to the arrival of an IOCTL_KS_RESET_STATE device control. This routine is also called when the queue associated with the given pin is flushed.

## Parameters

### `Pin` [in]

Pointer to the relevant [KSPIN](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_kspin), serving as a sink pin.

## Remarks

**About AVStrMiniPinDisconnect**

The minidriver specifies this routine's address in the **Disconnect** member of its [KSPIN_DISPATCH](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_kspin_dispatch) structure.

This routine is optional.

Also see [KS Pins](https://learn.microsoft.com/windows-hardware/drivers/stream/ks-pins).

**About AVStrMiniPinReset**

For more information, see [Pin-Centric Processing](https://learn.microsoft.com/windows-hardware/drivers/stream/pin-centric-processing).

The minidriver specifies this routine's address in the **Reset** member of its [KSPIN_DISPATCH](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_kspin_dispatch) structure.

Typically, this routine is provided by minidrivers that must flush hardware buffers. The filter control mutex may be held during this function. See [Filter Control Mutex in AVStream](https://learn.microsoft.com/windows-hardware/drivers/stream/filter-control-mutex-in-avstream).

This routine is optional.

## See also

[KSPIN_DISPATCH](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_kspin_dispatch)