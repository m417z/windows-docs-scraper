# IOCTL_KS_METHOD IOCTL

## Description

An application can use IOCTL_KS_METHOD to execute a method on a KS object. The application passes IOCTL_KS_METHOD with the parameters described below to the [KsSynchronousDeviceControl](https://learn.microsoft.com/windows-hardware/drivers/ddi/ksproxy/nf-ksproxy-kssynchronousdevicecontrol) function.

## Parameters

### Major code

### Input buffer

The application places a pointer to a structure of type [KSMETHOD](https://learn.microsoft.com/windows-hardware/drivers/stream/ksmethod-structure) specifying the method to invoke in the **InBuffer** parameter, and the size of the method structure at **InLength**.

### Input buffer length

The size of the method structure at **InLength**.

### Output buffer

The client allocates and passes an output buffer if the method requires one. (This is determined by the flags set in the KSMETHOD structure.) For example, [KSMETHOD_STREAMALLOCATOR_ALLOC](https://learn.microsoft.com/windows-hardware/drivers/stream/ksmethod-streamallocator-alloc) provides an output buffer for the newly allocated frame.

### Output buffer length

Length of the output buffer.

### Input/output buffer

### Input/output buffer length

### Status block

If the request is successful, the Status member is set to STATUS_SUCCESS.

## See also

[KSFASTMETHOD_ITEM](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-ksfastmethod_item)

[KSMETHOD](https://learn.microsoft.com/windows-hardware/drivers/stream/ksmethod-structure)

[KSMETHOD_ITEM](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-ksmethod_item)

[KSMETHOD_SET](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-ksmethod_set)

[KsMethodHandler](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksmethodhandler)