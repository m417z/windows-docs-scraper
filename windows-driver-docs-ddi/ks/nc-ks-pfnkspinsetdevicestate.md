# PFNKSPINSETDEVICESTATE callback function

## Description

An AVStream minidriver's *AVStrMiniPinSetDeviceState* routine is called when the state of a [KSPIN](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_kspin) structure is changed due to the arrival of a connection state property 'set' IOCTL. Typically, this will be provided by minidrivers that need to change the state of hardware.

## Parameters

### `Pin` [in]

Pointer to the [KSPIN](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_kspin) structure for which state is changing.

### `ToState` [in]

The target [KSSTATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ne-ks-ksstate) after receipt of the IOCTL.

### `FromState` [in]

The previous [KSSTATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ne-ks-ksstate).

## Return value

Return STATUS_SUCCESS or the error code that was returned from the attempt to set the state. Do not return STATUS_PENDING. The filter control mutex is held during this function. See [Filter Control Mutex in AVStream](https://learn.microsoft.com/windows-hardware/drivers/stream/filter-control-mutex-in-avstream).

## Remarks

The minidriver specifies this routine's address in the **SetDeviceState** member of its [KSPIN_DISPATCH](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_kspin_dispatch) structure.

Minidrivers will not receive a stop upon initial connection of the pin.

Pins that use the standard transport mechanism (standard interface/standard medium or an explicit use of KSPIN_FLAG_USE_STANDARD_TRANSPORT in [KSPIN_DESCRIPTOR_EX](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_kspin_descriptor_ex)) receive filtered state changes through the owning pipe through this routine. This means that no transition will be more than a single step. In other words, **KSSTATE_STOP** transitions to KSSTATE_ACQUIRE, **KSSTATE_ACQUIRE** transitions to KSSTATE_PAUSE, and so on. In addition, state changes received in this routine represent the state of the pipe as a whole, not the individual state of the pin as reported in the **DeviceState** member of the KSPIN structure.

Pins that do not use the standard transport mechanism (nonstandard interface, nonstandard medium, or an explicit use of KSPIN_FLAG_DO_NOT_USE_STANDARD_TRANSPORT in [KSPIN_DESCRIPTOR_EX](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_kspin_descriptor_ex)) receive nonfiltered state changes through this routine. As such, nonstandard transport pins must be prepared to deal with state changes that jump more than a single step. As an example, consider a jump from **KSSTATE_RUN** to **KSSTATE_STOP** without an intervening KSSTATE_PAUSE. In addition, the state reported to this routine will be identical to the state reported in the **DeviceState** member of the relevant KSPIN structure.

This routine is optional.

## See also

[KSPIN_DISPATCH](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_kspin_dispatch)