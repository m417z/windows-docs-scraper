# IoWMIRegistrationControl function

## Description

The **IoWMIRegistrationControl** routine registers or unregisters the caller as a WMI data provider for a specified device object.

## Parameters

### `DeviceObject` [in]

A pointer to a device object. This object is a [DEVICE_OBJECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_device_object) system structure.

### `Action` [in]

The action that WMI should take. The requested action is indicated by one of the following values.

| Action value | Meaning |
| --- | --- |
| WMIREG_ACTION_REGISTER | Specifies that WMI should register the caller as a WMI provider for *DeviceObject*. This will result in WMI sending an [IRP_MN_REGINFO](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mn-reginfo) or [IRP_MN_REGINFO_EX](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mn-reginfo-ex) request to the driver. |
| WMIREG_ACTION_DEREGISTER | Specifies that WMI should remove the caller from its list of WMI providers for *DeviceObject*. |
| WMIREG_ACTION_REREGISTER | Specifies that WMI should unregister the driver and then register (reregister) the driver. Reregistering the driver results in WMI sending an **IRP_MN_REGINFO** or **IRP_MN_REGINFO_EX** request to the driver. |
| WMIREG_ACTION_UPDATE_GUIDS | Specifies that WMI should re-query the driver for a new list of GUID identifiers that it provides data for. This will result in WMI sending an **IRP_MN_REGINFO** or **IRP_MN_REGINFO_EX** request to the driver. |

## Return value

**IoWMIRegistrationControl** returns a status code from the following list:

| Return code | Description |
| --- | --- |
| **STATUS_SUCCESS** | Indicates that WMI completed the action requested without error. |
| **STATUS_INVALID_PARAMETER** | Indicates that the action, specified in *Action*, was invalid. |
| **STATUS_*XXX*** | Indicates that the request failed for the reason specified by the NTSTATUS value. See Ntstatus.h for detailed information for the actual status return code. |

## Remarks

After a driver calls **IoWMIRegistrationControl**, WMI sends the driver an [IRP_MN_REGINFO](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mn-reginfo) or [IRP_MN_REGINFO_EX](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mn-reginfo-ex) request so the driver can provide information to WMI. For more information, see [Registering as a WMI Data Provider](https://learn.microsoft.com/windows-hardware/drivers/kernel/registering-as-a-wmi-data-provider).

If the caller specifies WMIREG_ACTION_DEREGISTER for *Action*, **IoWMIRegistrationControl** causes the calling thread to block until all **IRP_MJ_SYSTEM_CONTROL** requests that were previously sent to the specified device object have completed. In such a case, if a driver calls **IoWMIRegistrationControl** within a dispatch routine for an **IRP_MJ_SYSTEM_CONTROL** request, the calling thread will deadlock.

If a device is removed suddenly (for example, in a surprise removal), causing the PnP manager to send an [IRP_MN_SURPRISE_REMOVAL](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mn-surprise-removal) IRP, the driver must call **IoWMIRegistrationControl** and specify WMIREG_ACTION_DEREGISTER in *Action* in the call. Note that if the driver calls **IoWMIRegistrationControl** with *Action* set to WMIREG_ACTION_DEREGISTER in response to an **IRP_MN_SURPRISE_REMOVAL** IRP, the driver must not make the same call to **IoWMIRegistrationControl** in response to an [IRP_MN_REMOVE_DEVICE](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mn-remove-device) IRP.

## See also

[IRP_MN_REGINFO](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mn-reginfo)

[IRP_MN_REGINFO_EX](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mn-reginfo-ex)

[IRP_MN_REMOVE_DEVICE](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mn-remove-device)

[IRP_MN_SURPRISE_REMOVAL](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mn-surprise-removal)