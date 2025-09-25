# IOCTL_KS_WRITE_STREAM IOCTL

## Description

An application can use IOCTL_KS_WRITE_STREAM to write data to a pin. The application passes IOCTL_KS_WRITE_STREAM with the parameters described below to the [KsSynchronousDeviceControl](https://learn.microsoft.com/windows-hardware/drivers/ddi/ksproxy/nf-ksproxy-kssynchronousdevicecontrol) function.

## Parameters

### Major code

### Input buffer

A client provides a pointer to an array of [KSSTREAM_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-ksstream_header) structures in **InBuffer**. The stream data to write is contained in the buffers pointed to by the stream headers. The headers can also contain presentation time and duration.

### Input buffer length

The **InLength** parameter should specify the size, in bytes, of the input buffer contents.

### Output buffer

Kernel streaming provides the number of bytes written in the **BytesReturned** parameter.

### Output buffer length

### Input/output buffer

### Input/output buffer length

### Status block

If the request is successful, the Status member is set to STATUS_SUCCESS.

## See also

[IOCTL_KS_READ_STREAM](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ni-ks-ioctl_ks_read_stream)

[KsProbeStreamIrp](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksprobestreamirp)