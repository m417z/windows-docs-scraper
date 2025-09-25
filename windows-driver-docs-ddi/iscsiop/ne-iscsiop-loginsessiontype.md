# LOGINSESSIONTYPE enumeration

## Description

The LOGINSESSIONTYPE enumeration indicates the type of logon session.

## Constants

### `ISCSI_LOGINTARGET_DISCOVERY`

The logon session is for discovery only. Initiators use this type of session to discover targets with the **SendTargets** command. The initiator must already have access to at least one target IP address and one target port (target portal information).

### `ISCSI_LOGINTARGET_INFORMATIONAL`

The logon session is for informational purposes only. Initiators use this type of session to send SCSI commands that query for information. Management software can use informational sessions to query for information by calling the **SendScsiReportLuns** and **SendScsiReadCapacity** user-mode library routines.

This type of session does not support transmission of user data, and the Plug and Play (PnP) manager does not enumerate target logical units (LUNs) for the storage stack of the initiator node.

### `ISCSI_LOGINTARGET_DATA`

The logon session is full-featured. It reports the target LUNs to the PnP manager on the (local) initiator node for enumeration. After enumerating these LUNs, the operating system can access them for data transfers, just as it would with local LUNs.

## See also

[LoginToTarget](https://learn.microsoft.com/windows-hardware/drivers/storage/logintotarget)