# PREENUMERATE_SELF callback function

## Description

A *ReenumerateSelf* routine requests that a bus driver reenumerate a child device.

## Parameters

### `Context` [in]

A pointer to interface-specific context information. The caller passes the value that is passed as the **Context** member of the [REENUMERATE_SELF_INTERFACE_STANDARD](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_reenumerate_self_interface_standard) structure.

## Remarks

The [REENUMERATE_SELF_INTERFACE_STANDARD](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_reenumerate_self_interface_standard) interface structure supplies a pointer to the *ReenumerateSelf* routine.

If the bus driver can process the request at the time of the routine call, the bus driver asynchronously reports the device as missing in a subsequent [IRP_MN_QUERY_DEVICE_RELATIONS](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mn-query-device-relations) BusRelations query. This report causes the current device instance to receive [IRP_MN_SURPRISE_REMOVAL](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mn-surprise-removal) and [IRP_MN_REMOVE_DEVICE](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mn-remove-device) requests. After the surprise removal has been processed, a new instance of the device is enumerated and the driver's [AddDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-driver_add_device) routine is called to rebuild the device stack.

## See also

[IRP_MN_QUERY_DEVICE_RELATIONS](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mn-query-device-relations)

[IRP_MN_REMOVE_DEVICE](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mn-remove-device)

[IRP_MN_SURPRISE_REMOVAL](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mn-surprise-removal)

[REENUMERATE_SELF_INTERFACE_STANDARD](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_reenumerate_self_interface_standard)