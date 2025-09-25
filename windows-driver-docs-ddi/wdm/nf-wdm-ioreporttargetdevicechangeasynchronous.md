## Description

The **IoReportTargetDeviceChangeAsynchronous** routine notifies the PnP manager that a custom event has occurred on a device.

## Parameters

### `PhysicalDeviceObject` [in]

Pointer to the PDO of the device being reported.

### `NotificationStructure` [in]

Pointer to a caller-supplied [**TARGET_DEVICE_CUSTOM_NOTIFICATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_target_device_custom_notification) structure describing the custom event. The PnP manager sends this structure to drivers that registered for notification of the event.

This caller-supplied structure can be freed once the routine returns, as the PnP manager makes a shallow copy and uses the copy to notify drivers. The copy is automatically freed by the PnP manager once it is no longer needed. See Remarks section about allocation pool requirements.

*NotificationStructure*.**FileObject** must be **NULL**. *NotificationStructure*.**Event** must contain the custom GUID for the event. The other fields of the *NotificationStructure* must be filled in as appropriate for the custom event.

The PnP manager fills in the *NotificationStructure*.**FileObject** field when it sends notifications to registrants.

### `Callback` [in, optional]

Optionally points to a caller-supplied routine that the PnP manager calls after it finishes notifying drivers that registered for this custom event.

The callback routine has the following type:

```cpp
typedef
VOID
(*PDEVICE_CHANGE_COMPLETE_CALLBACK)(
    IN PVOID Context
    );
```

A device-change-complete callback routine should not block and must not call synchronous routines that generate PnP events.

The PnP manager calls device-change-complete callback routines at IRQL = PASSIVE_LEVEL.

### `Context` [in, out]

Optionally points to a caller-supplied context structure that the PnP manager passes to the *Callback* routine. The caller must allocate this structure from nonpaged memory.

## Return value

| Return code | Description |
|---|---|
| **STATUS_INVALID_DEVICE_REQUEST** | The caller specified a system PnP event, such as GUID_TARGET_DEVICE_QUERY_REMOVE. This routine is only for custom events. |

## Remarks

After the **IoReportTargetDeviceChangeAsynchronous** routine notifies the PnP manager that a custom event has occurred on a device, the routine returns immediately; it does not wait while the PnP manager sends notification of the event to drivers that registered for notification on the device. Do not use this routine to report system PnP events, such as GUID_TARGET_DEVICE_REMOVE_COMPLETE.

A driver that defines a custom device event calls **IoReportTargetDeviceChangeAsynchronous** to inform the PnP manager that the custom event has occurred. Custom notification can be used for events like a volume label change.

The custom notification structure contains a driver-defined event with its own GUID. Driver writers can generate GUIDs with Uuidgen.exe or Guidgen.exe (which are included in the Microsoft Windows SDK).

When a driver calls this routine while handling an event, an [IRP_MN_REMOVE_DEVICE](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mn-remove-device), or an [IRP_MN_SURPRISE_REMOVAL](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mn-surprise-removal), the PnP manager calls the driver's *Callback* routine after the driver returns and the stack unwinds.

Callers of **IoReportTargetDeviceChangeAsynchronous** must be running at IRQL <= DISPATCH_LEVEL. If a driver writer calls this routine at IRQL = DISPATCH_LEVEL, the *NotificationStructure* must be allocated from nonpaged memory.

## See also

[IoReportTargetDeviceChange](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ioreporttargetdevicechange)

[**TARGET_DEVICE_CUSTOM_NOTIFICATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_target_device_custom_notification)