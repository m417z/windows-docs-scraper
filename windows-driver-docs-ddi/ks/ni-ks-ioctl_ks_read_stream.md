# IOCTL_KS_READ_STREAM IOCTL

## Description

An application can use IOCTL_KS_READ_STREAM to read data from a pin. The application passes IOCTL_KS_READ_STREAM with the parameters described below to the [KsSynchronousDeviceControl](https://learn.microsoft.com/windows-hardware/drivers/ddi/ksproxy/nf-ksproxy-kssynchronousdevicecontrol) function.

## Parameters

### Major code

### Input buffer

The application places a pointer to an array of [KSSTREAM_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-ksstream_header) structures in the **InBuffer** parameter. Each describes a packet of data to be read. The headers can also contain the presentation time and duration.

### Input buffer length

The **InLength** parameter specifies the size, in bytes, of the input buffer contents.

### Output buffer

Stream data is returned in the buffers pointed to by the stream headers. Upon return, **BytesReturned** contains the number of bytes read.

### Output buffer length

**OutLength** specifies the size, in bytes, of the output buffer contents.

### Input/output buffer

### Input/output buffer length

### Status block

If the request is successful, the Status member is set to STATUS_SUCCESS.

## See also

[IOCTL_KS_WRITE_STREAM](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ni-ks-ioctl_ks_write_stream)

[KsProbeStreamIrp](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksprobestreamirp)