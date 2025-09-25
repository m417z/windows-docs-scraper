# SetupPersistentIScsiDevices function

## Description

The **SetupPersistentIscsiDevices** function builds the list of devices and volumes assigned to iSCSI targets that are connected to the computer, and saves this list in non-volatile cache of the iSCSI initiator service.

## Return value

Returns ERROR_SUCCESS if the operation succeeds. Otherwise, it returns the appropriate Win32 or iSCSI error code.

## Remarks

When the iSCSI Initiator service starts, it does not complete initialization until the storage stack can access and enumerate all persistent iSCSI volumes and devices. If there is a service that is dependent on data stored on a persistent volume or device, it should be configured to have a dependency on the iSCSI service (MSiSCSI).

The correct procedure for a system administrator to configure a computer to use external persistent volumes is as follows:

* Login to all of the targets that contain the volumes
* Configure all volumes on top of the disks
* Use management software to call the **SetupPersistentIscsiDevices** routine, so that the iSCSI initiator service will add the volumes to its list of persistent volumes.