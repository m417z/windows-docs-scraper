## Description

The **IOCTL_GNSS_LISTEN_GEOFENCES_TRACKINGSTATUS** control code is used to receive geofence tracking status from the driver.

Applies to GNSS DDI version 2 and later.

## Parameters

### Major code

### Input buffer

Set to NULL.

### Input buffer length

Set to 0.

### Output buffer

A pointer to a [GNSS_EVENT](https://learn.microsoft.com/windows-hardware/drivers/ddi/gnssdriver/ns-gnssdriver-gnss_event) structure.

The EventType must be set to **GNSS_Event_GeofencesTrackingStatus** and the **GeofencesTrackingStatus** member filled in.

### Output buffer length

Set to sizeof(GNSS_EVENT).

### Input/output buffer

### Input/output buffer length

### Status block

**Irp->IoStatus.Status** is set to STATUS_SUCCESS if the request is successful. Otherwise, **Status** to the appropriate error condition as a [NTSTATUS](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-ntstatus-values) code.

## Remarks

### GNSS adapter notes

The GNSS adapter keeps a pending request all the time.

When the driver completes the I/O call, the adapter issues another IOCTL to receive the next status change notification.

The GNSS adapter may keep this IOCTL pending even if there are no geofences, or if geofence tracking operation has been reinitialized through the **GNSS_ResetGeofencesTracking** driver command. The GNSS driver must not treat this as an error condition.

The HLOS reacts to the tracking failure alert by starting off its own standby application processor-based geofence tracking engine. The HLOS geofence tracking engine runs in parallel with the GNSS engine and tracks the exact same geofences that the GNSS engine has.

During this time, any changes in the geofence set (for example, addition of new geofences or deletion of existing geofences) are also communicated to the GNSS engine (although the GNSS engine is unable to track those due to the prevailing low-signal conditions).

The application processor-based geofence engine stays active for as long as the GNSS engine remains in the low-signal condition. Subsequently, when the GNSS engine is able to track geofences again by communicating a success tracking status alert through this IOCTL, the HLOS gracefully transfer full control back to the GNSS engine through the following steps.

On receipt of this success tracking status alert, the HLOS brings down it's application processor-based geofence tracking engine, issues a **GNSS_ResetGeofencesTracking** command to the GNSS engine, and re-adds the currently active geofences together with the current entry/exit status of each geofence. This reset operation is necessary so that the GNSS engine can re-synchronize the states of all the geofences and raise any needed geofence alert for any of them

### GNSS driver notes

There will be a pending IOCTL all the time. Whenever there is a tracking status change the I/O operation should be completed. When geofences are initially added to the GNSS engine, the HLOS optimistically assumes that the GNSS engine is able to track the geofences. Thus initially the IOCTL should be filled only when the GNSS engine is unable to track geofences, and the tracking status is a failure code. Subsequently, the adapter expects the IOCTL to be filled when the tracking status changes to success.

A failure tracking status implies that the GNSS engine is unable to reliably track geofences due to bad signal conditions or other transient reasons. This status applies to the overall ability to reliably track geofences, as opposed to specific to one or more geofence. Thus a failure status must be reported even when the GNSS engine can track most of the fences, but cannot do so for a smaller number.

When signal conditions degrade while geofences are being tracked, the GNSS engine must make allowances for several retries before declaring a failure status. This will prevent unneeded failovers when the signal degradation is due to transient conditions, for example, when a user enters a tunnel.

A success status is raised when the GNSS engine had previously raised a failure status, and is now able to track all the geofences again (due to improved signal conditions or other reasons).

If the GNSS engine had previously raised a failure status while geofences were being tracked, no further geofence alerts are expected till the GNSS engine can track all geofences again and has raised a subsequent success status.

When the GNSS engine is unable to track geofences, it may continue to monitor the tracking condition so that it can resume geofence tracking when signal conditions improve. Since the monitoring of tracking condition can be power-intensive, especially under low GNSS signal conditions, the GNSS engine must optimize this activity in an implementation-specific way. The GNSS engine must not keep on consuming power for a prolonged time if the tracking conditions do not improve.

Additionally, if geofence tracking is explicitly reset by the HLOS or the HLOS deletes all geofences, the tracking condition monitoring should immediately stop. When new geofences are subsequently added and the GNSS engine is still unable to track geofences, a subsequent failure status should be raised.

## See also

[Creating IOCTL Requests in Drivers](https://learn.microsoft.com/windows-hardware/drivers/kernel/creating-ioctl-requests-in-drivers)

[WdfIoTargetSendInternalIoctlOthersSynchronously](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/nf-wdfiotarget-wdfiotargetsendinternalioctlotherssynchronously)

[WdfIoTargetSendInternalIoctlSynchronously](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/nf-wdfiotarget-wdfiotargetsendinternalioctlsynchronously)

[WdfIoTargetSendIoctlSynchronously](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/nf-wdfiotarget-wdfiotargetsendioctlsynchronously)