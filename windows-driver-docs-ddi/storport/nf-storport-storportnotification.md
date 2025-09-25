# StorPortNotification function

## Description

The miniport driver uses the **StorPortNotification** routine to notify the Storport driver of certain events and conditions.

**StorPortNotification** takes a variable number of parameters depending on the notification type specified.

## Parameters

### `NotificationType`

Specifies the notification type, which can be one of the following values.

| Notification type | Description |
| --- | --- |
| BufferOverrunDetected | This notification type has no arguments and gives the miniport driver an opportunity to bugcheck the system if it detects a corruption. |
| BusChangeDetected | Indicates that a target device might have been added or removed from a dynamic bus. To use this notification type, include an optional PathId parameter to indicate the SCSI port or bus where the change was detected.<br><br>```cpp VOID StorPortNotification( _In_ SCSI_NOTIFICATION_TYPE NotificationType, _In_ PVOID HwDeviceExtension, _In_opt_ UCHAR PathId ); ``` |
| IoTargetRequestServiceTime | Indicates to Storport the amount of time that was required to process a specified request.<br><br>```cpp VOID StorPortNotification( _In_ SCSI_NOTIFICATION_TYPE NotificationType, _In_ PVOID HwDeviceExtension, _In_ ULONGLONG Duration, _In_ PSCSI_REQUEST_BLOCK Srb ); ```<br><br>Duration [in]<br><br> The duration of the service time required for Srb in 100 nanosecond units.<br><br>Srb [in]<br><br> The request block to set the service time for. |
| LinkDown | Indicates that the link is down and will probably be down for some time. StorPort will pause the adapter in response to this notification. |
| LinkUp | Indicates that the link has been restored. StorPort restarts the adapter so that it can resume operation in response to this notification. Miniport drivers should not send this notification unless the link is down. |
| QueryTickCount | This notification type returns a LARGE_INTEGER that holds the value from [KeQueryTickCount](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-kequerytickcount). The value returned in TickCount is the count of the interval timer interrupts that have occurred since the system was booted<br><br>```cpp VOID StorPortNotification( _In_ SCSI_NOTIFICATION_TYPE NotificationType, _In_ PVOID HwDeviceExtension, _Inout_ PLARGE_INTEGER TickCount ); ``` |
| RequestComplete | Indicates that the given SRB has finished. After this notification is sent, the port driver owns the request. The Srb parameter represents a pointer to the completed SCSI request block. The miniport driver must not attempt to access the request in Srb, and it must not pass Srb to another routine.<br><br>```cpp VOID StorPortNotification( _In_ SCSI_NOTIFICATION_TYPE NotificationType, _In_ PVOID HwDeviceExtension, _In_ PSCSI_REQUEST_BLOCK Srb ); ``` |
| RequestTimerCall | Indicates that the miniport driver requires the port driver to call the miniport driver's [HwStorTimer](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nc-storport-hw_timer) routine in the requested number of microseconds.<br><br>```cpp VOID StorPortNotification( _In_ SCSI_NOTIFICATION_TYPE NotificationType, _In_ PVOID HwDeviceExtension, _In_ PHW_TIMER HwStorTimer, _In_ ULONG MiniportTimerValue ); ```<br><br>HwStorTimer [in]<br><br> A pointer to a timer routine that is called after the interval of time that is specified in MiniportTimerValue.<br><br>MiniportTimerValue [in]<br><br> Indicates the interval after which the timer routine pointed to by HwStorTimer is called. This is a positive value specified in microseconds. A value of 0 will cancel the timer. The system timer resolution is approximately 10 milliseconds. |
| ResetDetected | Indicates that the HBA has detected a reset on the bus. After this notification is sent, the miniport driver is still responsible for completing any active requests. The port driver will manage all required bus-reset delays. |
| WMIEvent | Indicates that the miniport driver has detected an event for which one or more WMI data consumers are registered. Note that the **WmiEvent** parameter is limited to a maximum of 128 bytes. If **WmiEvent** is larger than 128 bytes, it will be ignored.<br><br>```cpp VOID StorPortNotification( _In_ SCSI_NOTIFICATION_TYPE NotificationType, _In_ PVOID HwDeviceExtension, _In_ PWNODE_EVENT_ITEM WMIEvent, _In_ UCHAR PathId, _In_opt_ UCHAR TargetId, _In_opt_ UCHAR Lun ); ```<br><br>WMIEvent [in]<br><br> A pointer to event structures that have information about a WMI event that is detected by the miniport driver.<br><br>PathId [in]<br><br> Indicates the SCSI port or bus for the request. Set this parameter to 0xff for an adapter device. Otherwise, set to a valid path ID.<br><br>TargetId [in, optional]<br><br> Indicates the target controller or device on the bus. This parameter is not used when the event is for an adapter.<br><br>Lun [in, optional]<br><br> Indicates the logical unit number of the device. This parameter is not used when the event is for an adapter. |
| WMIReregister | Indicates that the miniport driver has changed the data items or the number of instances of a given data block that was previously registered by calling [IoWMIRegistrationControl](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iowmiregistrationcontrol).<br><br>```cpp VOID StorPortNotification( _In_ SCSI_NOTIFICATION_TYPE NotificationType, _In_ PVOID HwDeviceExtension, _In_ UCHAR PathId, _In_opt_ UCHAR TargetId, _In_opt_ UCHAR Lun ); ```<br><br>PathId [in]<br><br> Indicates the SCSI port or bus for the request. Set this parameter to 0xff for an adapter device. Otherwise, set to a valid path ID.<br><br>TargetId [in, optional]<br><br> Indicates the target controller or device on the bus. This parameter is not used when registration is for an adapter.<br><br>Lun [in, optional]<br><br> Indicates the logical unit number of the device. This parameter is not used when registration is for an adapter. |

### `HwDeviceExtension`

A pointer to the hardware device extension. This is a per HBA storage area that the port driver allocates and initializes on behalf of the miniport driver. Miniport drivers usually store HBA-specific information in this extension, such as the state of the HBA and the mapped access ranges for the HBA. This area is available to the miniport driver immediately after the miniport driver calls [StorPortInitialize](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportinitialize). The port driver frees this memory when it removes the device.

### `...`

Additional Parameters.

## Return value

None.

## Remarks

**StorPortNotification** is a polymorphic function that handles many different types of requests, making it difficult to annotate in a manner that would cover all possible uses.
Because **StorPortNotification** returns VOID, the scanning engine should assume the LockHandle was acquired as asked.

## See also

[StorPortInitialize](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportinitialize)