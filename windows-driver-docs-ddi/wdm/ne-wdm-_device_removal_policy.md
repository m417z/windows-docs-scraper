# _DEVICE_REMOVAL_POLICY enumeration

## Description

The **DEVICE_REMOVAL_POLICY** enumeration describes a device's removal policy.

## Constants

### `RemovalPolicyExpectNoRemoval`

The device is not typically removed.

### `RemovalPolicyExpectOrderlyRemoval`

The device is typically removed in an orderly fashion. (Before the device is removed, the Plug and Play [PnP] manager sends an [IRP_MN_QUERY_REMOVE_DEVICE](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mn-query-remove-device) request to the device's driver.)

### `RemovalPolicyExpectSurpriseRemoval`

The device can be removed suddenly. (The driver receives no advance warning that the device will be removed. The Plug and Play [PnP] manager sends an [IRP_MN_SURPRISE_REMOVAL](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mn-surprise-removal) request when the device is removed.)

## Remarks

The [IoGetDeviceProperty](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iogetdeviceproperty) routine supplies a **DEVICE_REMOVAL_POLICY** enumeration value when a driver requests **DevicePropertyRemovalPolicy**. The operating system uses the value as a hint as to how the device is typically removed from the computer.

## See also

[IRP_MN_QUERY_REMOVE_DEVICE](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mn-query-remove-device)

[IRP_MN_SURPRISE_REMOVAL](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mn-surprise-removal)

[IoGetDeviceProperty](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iogetdeviceproperty)