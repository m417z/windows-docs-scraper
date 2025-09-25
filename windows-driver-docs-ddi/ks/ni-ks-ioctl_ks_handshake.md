# IOCTL_KS_HANDSHAKE IOCTL

## Description

A kernel-mode client can use IOCTL_KS_HANDSHAKE to negotiate an interface between unconnected AVStream pins. The client calls [KsSynchronousDeviceControl](https://learn.microsoft.com/windows-hardware/drivers/ddi/ksproxy/nf-ksproxy-kssynchronousdevicecontrol) with IOCTL_KS_HANDSHAKE and the parameters described below.

To attempt a protocol handshake with a pin that is already connected, call [KsPinHandshake](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-kspinhandshake).

## Parameters

### Major code

### Input buffer

The client places a pointer to a structure of type [KSHANDSHAKE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-kshandshake) in the **InBuffer** parameter.

### Input buffer length

**InLength** must be equal to sizeof(KSHANDSHAKE).

### Output buffer

The client places a pointer to a structure of type [KSHANDSHAKE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-kshandshake) in the **OutBuffer** parameter. If the request is successful, handshake information is placed in this location.

### Output buffer length

**OutLength** must be equal to sizeof(KSHANDSHAKE).

### Input/output buffer

### Input/output buffer length

### Status block

If the request is successful, IoStatus.Information is set to sizeof(KSHANDSHAKE).

This IOCTL can be sent from kernel-mode only. If the request is sent from user mode, the Status member is set to STATUS_INVALID_DEVICE_REQUEST.

If the **InLength** and **OutLength** parameters in the call to **KsSynchronousDeviceControl** are not both equal to sizeof(KSHANDSHAKE), the Status member is set to STATUS_INVALID_BUFFER_SIZE.

## See also

[AVStrMiniPinHandshake](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nc-ks-pfnkspinhandshake)

[KSHANDSHAKE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-kshandshake)

[KsPinHandshake](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-kspinhandshake)

[KsPinRegisterHandshakeCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-kspinregisterhandshakecallback)