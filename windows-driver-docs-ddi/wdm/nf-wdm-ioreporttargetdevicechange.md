# IoReportTargetDeviceChange function

## Description

The **IoReportTargetDeviceChange** routine notifies the PnP manager that a custom event has occurred on a device.

## Parameters

### `PhysicalDeviceObject` [in]

Pointer to the PDO of the device being reported.

### `NotificationStructure` [in]

Pointer to a caller-supplied [TARGET_DEVICE_CUSTOM_NOTIFICATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_target_device_custom_notification) structure describing the custom event. The PnP manager sends this structure to drivers that registered for notification of the event.

*NotificationStructure*.**FileObject** must be **NULL**. *NotificationStructure*.**Event** must contain the custom GUID for the event. The other fields of the *NotificationStructure* must be filled in as appropriate for the custom event.

The PnP manager fills in the *NotificationStructure*.**FileObject** field when it sends notifications to registrants.

## Return value

**IoReportTargetDeviceChange** returns STATUS_SUCCESS or an appropriate error status. Possible error status values include the following.

| Return code | Description |
| --- | --- |
| **STATUS_INVALID_DEVICE_REQUEST** | The caller specified a system PnP event, such as GUID_TARGET_DEVICE_QUERY_REMOVE. This routine is only for custom events. |

## Remarks

After **IoReportTargetDeviceChange** notifies the PnP manager that a custom event has occurred on a device, the PnP manager sends notification of the event to drivers that registered for notification on the device. Do not use this routine to report system PnP events, such as GUID_TARGET_DEVICE_REMOVE_COMPLETE.

A driver that defines a custom device event calls **IoReportTargetDeviceChange** to inform the PnP manager that the custom event has occurred. Custom notification can be used for events like a volume label change.

A driver should call the asynchronous form of this routine, [IoReportTargetDeviceChangeAsynchronous](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ioreporttargetdevicechangeasynchronous), instead of this routine, to prevent deadlocks.

Certain kernel-mode components can call this synchronous routine. For example, a file system can call **IoReportTargetDeviceChange** to report a "get off the volume" custom event when a component tries to open the volume for exclusive access. Clients that register for notification on file system volumes are careful to not request an exclusive open in a PnP notification callback routine.

The custom notification structure contains a driver-defined event with its own GUID. Driver writers can generate GUIDs with Uuidgen.exe or Guidgen.exe (which are included in the Microsoft Windows SDK).

Callers of **IoReportTargetDeviceChange** must be running at IRQL = PASSIVE_LEVEL in the context of a system thread. To report a target device change from IRQL > PASSIVE_LEVEL, call **IoReportTargetDeviceChangeAsynchronous**.

**IoReportTargetDeviceChange** is not supported on Windows 98/Me; it returns STATUS_NOT_IMPLEMENTED.

## See also

[IoReportTargetDeviceChangeAsynchronous](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ioreporttargetdevicechangeasynchronous)

[TARGET_DEVICE_CUSTOM_NOTIFICATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_target_device_custom_notification)