## Description

The IOCTL_GNSS_LISTEN_GEOFENCE_ALERT control code is used to start listening for geofence alerts from the driver.

Applies to GNSS DDI version 2 and later.

## Parameters

### Major code

### Input buffer

Set to NULL.

### Input buffer length

Set to 0.

### Output buffer

A pointer to a [GNSS_EVENT](https://learn.microsoft.com/windows-hardware/drivers/ddi/gnssdriver/ns-gnssdriver-gnss_event) structure.

The EventType must be set to **GNSS_Event_GeofenceAlertData** and the **GeofenceAlertData** member filled in.

### Output buffer length

Set to sizeof(GNSS_EVENT).

### Input/output buffer

### Input/output buffer length

### Status block

**Irp->IoStatus.Status** is set to STATUS_SUCCESS if the request is successful. Otherwise, **Status** to the appropriate error condition as a [NTSTATUS](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-ntstatus-values) code.

## Remarks

### GNSS adapter notes

The GNSS adapter keeps a pending request all the time.

When the driver completes the I/O call, the adapter issues another IOCTL to receive the next geofence alert.

The GNSS adapter may keep this IOCTL pending even if there are no geofences, or if geofence tracking operation has been reinitialized through the **GNSS_ResetGeofencesTracking** driver command. The GNSS driver must not treat this as an error condition.

### GNSS driver notes

Whenever the GNSS driver gets a geofence alert notification from the GNSS engine, it completes the I/O operation.

If the GNSS adapter is in the process of handling a previous alert and has not issued a pending IOCTL yet, the GNSS driver queues the alert locally and dequeues it whenever the adapter sends this IOCTL.

When a geofence is added for the first time, the initial state (as seen by HLOS) is passed in as a parameter. The GNSS engine should raise the first alert only when there is a change in state from the initial state. This must be handled natively by the GNSS engine itself, as opposed to the GNSS driver filtering out redundant alerts at the driver level, therefore defeating the purpose of unneeded application processor wake-up at initialization.

This IO request is kept pending until an alert is received from the GNSS engine. When the driver completes the IO call, the GNSS adapter issues another IOCTL to receive the next geofence alert. This IOCTL is kept pending even if there are no geofences or tracking operation has been reinitialized through the **GNSS_ResetGeofencesTracking** command. If a new pending IOCTL has not been issued and another geofence alert is received, it is queued locally until the next pending IO request is received.

## See also

[Creating IOCTL Requests in Drivers](https://learn.microsoft.com/windows-hardware/drivers/kernel/creating-ioctl-requests-in-drivers)

[WdfIoTargetSendInternalIoctlOthersSynchronously](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/nf-wdfiotarget-wdfiotargetsendinternalioctlotherssynchronously)

[WdfIoTargetSendInternalIoctlSynchronously](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/nf-wdfiotarget-wdfiotargetsendinternalioctlsynchronously)

[WdfIoTargetSendIoctlSynchronously](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/nf-wdfiotarget-wdfiotargetsendioctlsynchronously)