## Description

The **IOCTL_GNSS_DELETE_GEOFENCE** control code is used by the GNSS adapter to delete a previously created geofence.

Applies to GNSS DDI version 2 and later.

## Parameters

### Major code

### Input buffer

A pointer to a [GNSS_GEOFENCE_DELETE_PARAM](https://learn.microsoft.com/windows-hardware/drivers/ddi/gnssdriver/ns-gnssdriver-gnss_geofence_delete_param) structure that defines the geofence to be deleted.

### Input buffer length

Set to sizeof(GNSS_GEOFENCE_DELETE_PARAM).

### Output buffer

Set to **NULL**.

### Output buffer length

Set to 0.

### Input/output buffer

### Input/output buffer length

### Status block

**Irp->IoStatus.Status** is set to STATUS_SUCCESS if the request is successful. Otherwise, **Status** to the appropriate error condition as a [NTSTATUS](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-ntstatus-values) code.

## Remarks

NTSTATUS with the following indications:

- STATUS_SUCCESS: The driver successfully removed the geofence.

- STATUS_UNSUCCESSFUL: Failed, the geofence cannot be deleted.

### GNSS adapter notes

The GNSS adapter does not expect this call to fail because there is no elegant way to handle the consequence of this failure. On failure, the GNSS adapter will issue the **GNSS_ResetGeofencesTracking** command and re-add the geofences.

### GNSS driver notes

If this is the last geofence, the GNSS driver should stop geofence tracking. If the GNSS engine was unable to track geofences (due to bad signal conditions or other transient errors) prior to the deletion of the last geofence, the monitoring activity should stop.

If the geofence is successfully removed, the driver returns STATUS_SUCCESS. If the geofence cannot be deleted, a failure code, STATUS_UNSUCCESSFUL, is returned. If a failure occurs, the GNSS adapter issues the GNSS_ResetGeofencesTracking command and recreates the desired geofences. If this command deletes the last defined geofence, the driver stops geofence tracking.

## See also

[Creating IOCTL Requests in Drivers](https://learn.microsoft.com/windows-hardware/drivers/kernel/creating-ioctl-requests-in-drivers)

[WdfIoTargetSendInternalIoctlOthersSynchronously](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/nf-wdfiotarget-wdfiotargetsendinternalioctlotherssynchronously)

[WdfIoTargetSendInternalIoctlSynchronously](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/nf-wdfiotarget-wdfiotargetsendinternalioctlsynchronously)

[WdfIoTargetSendIoctlSynchronously](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/nf-wdfiotarget-wdfiotargetsendioctlsynchronously)