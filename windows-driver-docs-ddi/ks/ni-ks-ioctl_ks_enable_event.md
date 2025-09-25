# IOCTL_KS_ENABLE_EVENT IOCTL

## Description

An application can use IOCTL_KS_ENABLE_EVENT to request notification of a KS event type, or to determine the events supported by a KS object. The application specifies IOCTL_KS_ENABLE_EVENT in the **IoControl** parameter of a call to [KsSynchronousDeviceControl](https://learn.microsoft.com/windows-hardware/drivers/ddi/ksproxy/nf-ksproxy-kssynchronousdevicecontrol).

## Parameters

### Major code

### Input buffer

The application places a pointer to a structure of type [KSEVENT](https://learn.microsoft.com/windows-hardware/drivers/stream/ksevent-structure) in the **InBuffer** parameter and the size of this structure at **InLength**.

### Input buffer length

Length of [KSEVENT](https://learn.microsoft.com/windows-hardware/drivers/stream/ksevent-structure).

### Output buffer

The application places a pointer to a structure of type [KSEVENTDATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-kseventdata) in the **OutBuffer** parameter and the size of this structure at **OutLength**.

### Output buffer length

Length of [KSEVENTDATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-kseventdata).

### Input/output buffer

### Input/output buffer length

### Status block

If the request is successful, the Status member is set to STATUS_SUCCESS.

## Remarks

To determine events supported by a KS object, specify **NULL** and 0 respectively for **InBuffer** and **InLength**.

## See also

[IOCTL_KS_DISABLE_EVENT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ni-ks-ioctl_ks_disable_event)

[KSDPC_ITEM](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-ksdpc_item)

[KSEVENT](https://learn.microsoft.com/windows-hardware/drivers/stream/ksevent-structure)

[KSEVENTDATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-kseventdata)

[KSEVENT_ENTRY](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_ksevent_entry)

[KSEVENT_ITEM](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-ksevent_item)

[KSEVENT_SET](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-ksevent_set)

[KsDisableEvent](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksdisableevent)