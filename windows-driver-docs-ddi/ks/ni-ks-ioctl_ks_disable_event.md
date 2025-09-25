# IOCTL_KS_DISABLE_EVENT IOCTL

## Description

An application can use IOCTL_KS_DISABLE_EVENT to rescind a previous request notification. The application specifies IOCTL_KS_DISABLE_EVENT in the **IoControl** parameter of a call to [KsSynchronousDeviceControl](https://learn.microsoft.com/windows-hardware/drivers/ddi/ksproxy/nf-ksproxy-kssynchronousdevicecontrol).

## Parameters

### Major code

### Input buffer

The application places a pointer to a structure of type [KSEVENTDATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-kseventdata) in the **InBuffer** parameter. This is the location of the original KSEVENTDATA structure that the application instantiated at the enabling of the event. To disable all active events, a client specifies a **NULL** pointer and length of zero in the **InBuffer** and **InLength** parameters.

### Input buffer length

Length of [KSEVENTDATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-kseventdata).

### Output buffer

None.

### Output buffer length

None.

### Input/output buffer

### Input/output buffer length

### Status block

If the request is successful, the Status member is set to STATUS_SUCCESS.

## See also

[IOCTL_KS_DISABLE_EVENT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ni-ks-ioctl_ks_disable_event)

[KSDPC_ITEM](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-ksdpc_item)

[KSEVENT](https://learn.microsoft.com/windows-hardware/drivers/stream/ksevent-structure)

[KSEVENTDATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-kseventdata)

[KSEVENT_ENTRY](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_ksevent_entry)

[KSEVENT_ITEM](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-ksevent_item)

[KSEVENT_SET](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-ksevent_set)

[KsDisableEvent](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksdisableevent)