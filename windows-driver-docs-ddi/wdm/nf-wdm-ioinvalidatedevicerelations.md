# IoInvalidateDeviceRelations function

## Description

The **IoInvalidateDeviceRelations** routine notifies the PnP manager that the relations for a device (such as bus relations, ejection relations, removal relations, and the target device relation) have changed.

## Parameters

### `DeviceObject` [in]

Pointer to the PDO for the device.

### `Type` [in]

Specifies a **DEVICE_RELATION_TYPE** enumeration value that describes the type of relations that have changed. Possible values include **BusRelations**, **EjectionRelations**, **RemovalRelations**, and **TargetDeviceRelation**. Starting with Windows 7, the **PowerRelations** value is also supported.

## Remarks

For some relation types, such as **BusRelations**, this routine causes the PnP manager or power manager to gather updated relations information by sending an [IRP_MN_QUERY_DEVICE_RELATIONS](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mn-query-device-relations) request to the drivers for the device. For other relation types, such as **EjectionRelations**, the PnP manager does not need to gather new relation information immediately; the PnP manager queries drivers for ejection relations only when it is preparing to eject a device.

After a bus driver calls **IoInvalidateDeviceRelations** to inform the PnP manager that a device has disappeared, the bus driver must continue to handle PnP IRPs for that device until it receives an [IRP_MN_REMOVE_DEVICE](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mn-remove-device) request. In response to this IRP, the bus driver returns STATUS_NO_SUCH_DEVICE. Until the bus driver successfully completes the **IRP_MN_REMOVE_DEVICE** request, the bus driver can access the device extension to check its flags for the device.

## See also

[IRP_MN_QUERY_DEVICE_RELATIONS](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mn-query-device-relations)

[IRP_MN_REMOVE_DEVICE](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mn-remove-device)