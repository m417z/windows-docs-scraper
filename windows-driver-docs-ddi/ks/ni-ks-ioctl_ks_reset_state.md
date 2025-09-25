# IOCTL_KS_RESET_STATE IOCTL

## Description

An application can use IOCTL_KS_RESET_STATE to return a pin to the state it was in at *Acquire*-time. The application passes IOCTL_KS_RESET_STATE with the parameters described below to the [KsSynchronousDeviceControl](https://learn.microsoft.com/windows-hardware/drivers/ddi/ksproxy/nf-ksproxy-kssynchronousdevicecontrol) function.

## Parameters

### Major code

### Input buffer

A client provides a buffer that contains the reset value (KSRESET_BEGIN, KSRESET_END) in the **InBuffer** parameter.

### Input buffer length

**InLength** specifies size, in bytes, of the input buffer contents.

### Output buffer

None.

### Output buffer length

None.

### Input/output buffer

### Input/output buffer length

### Status block

If the request is successful, the Status member is set to STATUS_SUCCESS.

## Remarks

Initiate a reset on a pin by sending IOCTL_KS_RESET_STATE with a value of KSRESET_BEGIN in the InBuffer parameter of [KsSynchronousDeviceControl](https://learn.microsoft.com/windows-hardware/drivers/ddi/ksproxy/nf-ksproxy-kssynchronousdevicecontrol).

When the reset state is initiated, existing read and write requests are canceled. While in the reset state, any new read or write requests are rejected with STATUS_DEVICE_NOT_READY.

To terminate the reset state, send IOCTL_KS_RESET_STATE with a value of KSRESET_END.

Note that the reset state is not canceled by changing the pin state.

When the reset state is terminated, the pin can again accept new data and pass data to other connections.

## See also

[AVStrMiniFilterReset](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nc-ks-pfnksfiltervoid)

[AVStrMiniPinReset](https://learn.microsoft.com/previous-versions/ff556354(v=vs.85))

[KSFILTER_DISPATCH](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_ksfilter_dispatch)

[KsAcquireResetValue](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksacquireresetvalue)