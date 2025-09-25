# FsRtlNotifyVolumeEventEx function

## Description

The **FsRtlNotifyVolumeEventEx** routine notifies any registered applications that a volume event is occurring. Volume events include the volume being locked, unlocked, mounted, or made read-only.

## Parameters

### `FileObject` [in]

A pointer to a [FILE_OBJECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_file_object) that specifies a volume.

### `EventCode` [in]

An event code for the event that is occurring. For a table of event codes, see [FsRtlNotifyVolumeEvent](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-_fsrtl_advanced_fcb_header-fsrtlnotifyvolumeevent).

### `Event` [in]

A pointer to the initialized custom notification structure ([TARGET_DEVICE_CUSTOM_NOTIFICATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_target_device_custom_notification)) to use.

## Return value

Returns STATUS_SUCCESS on success or another relevant NTSTATUS value, such as STATUS_INVALID_PARAMETER, if the *EventCode* is not valid.

## Remarks

**Note** When you specify the *Event* parameter as a custom volume notification, set the following members of the TARGET_DEVICE_CUSTOM_NOTIFICATION object as follows:

Version to 1.

*FileObject* to **NULL**.

## See also

[FsRtlNotifyVolumeEvent](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-_fsrtl_advanced_fcb_header-fsrtlnotifyvolumeevent)

[IoRegisterPlugPlayNotification](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ioregisterplugplaynotification)

[IoUnregisterPlugPlayNotification](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iounregisterplugplaynotification)

[TARGET_DEVICE_CUSTOM_NOTIFICATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_target_device_custom_notification)