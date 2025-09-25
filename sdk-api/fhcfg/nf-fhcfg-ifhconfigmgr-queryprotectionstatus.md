# IFhConfigMgr::QueryProtectionStatus

## Description

Retrieves the current File History protection state.

> [!NOTE]
> **IFhConfigMgr** is deprecated and may be altered or unavailable in future releases.

## Parameters

### `ProtectionState` [out]

On return, this parameter receives the current File History protection state. The following protection states are defined in the FhStatus.h header file.

| Value | Meaning |
| --- | --- |
| **FH_STATE_NOT_TRACKED**<br><br>0x00 | The File History protection state is unknown, because the File History service is not started or the current user is not tracked in it. This value cannot be ORed with **FH_STATE_RUNNING** (0x100). |
| **FH_STATE_OFF**<br><br>0x01 | File History protection is not enabled for the current user. No files will be backed up. This value cannot be ORed with **FH_STATE_RUNNING** (0x100). |
| **FH_STATE_DISABLED_BY_GP**<br><br>0x02 | File History protection is disabled by Group Policy. No files will be backed up. This value cannot be ORed with **FH_STATE_RUNNING** (0x100). |
| **FH_STATE_FATAL_CONFIG_ERROR**<br><br>0x03 | There is a fatal error in one of the files that store internal File History information for the current user. No files will be backed up. This value cannot be ORed with **FH_STATE_RUNNING** (0x100). |
| **FH_STATE_TARGET_ACCESS_DENIED**<br><br>0x0E | The current user does not have write permission for the currently assigned target. Backup copies of file versions will not be created. This value can be ORed with **FH_STATE_RUNNING** (0x100) to indicate that a backup cycle is being performed for the current user right now. |
| **FH_STATE_TARGET_VOLUME_DIRTY**<br><br>0x0F | The currently assigned target has been marked as dirty. Backup copies of file versions will not be created until after the [Chkdsk](https://learn.microsoft.com/previous-versions/windows/it-pro/windows-server-2012-R2-and-2012/cc730714(v=ws.11)) utility is run. This value can be ORed with **FH_STATE_RUNNING** (0x100) to indicate that a backup cycle is being performed for the current user right now. |
| **FH_STATE_TARGET_FULL_RETENTION_MAX**<br><br>0x10 | The currently assigned target does not have sufficient space for storing backup copies of files from the File History protection scope, and retention is already set to the most aggressive policy. File History will provide a degraded level of protection. This value can be ORed with **FH_STATE_RUNNING** (0x100) to indicate that a backup cycle is being performed for the current user right now. |
| **FH_STATE_TARGET_FULL**<br><br>0x11 | The currently assigned target does not have sufficient space for storing backup copies of files from the File History protection scope. File History will provide a degraded level of protection. This value can be ORed with **FH_STATE_RUNNING** (0x100) to indicate that a backup cycle is being performed for the current user right now. |
| **FH_STATE_STAGING_FULL**<br><br>0x12 | The File History cache on one of the local disks does not have sufficient space for storing backup copies of files from the File History protection scope temporarily. File History will provide a degraded level of protection. This value can be ORed with **FH_STATE_RUNNING** (0x100) to indicate that a backup cycle is being performed for the current user right now. |
| **FH_STATE_TARGET_LOW_SPACE_RETENTION_MAX**<br><br>0x13 | The currently assigned target is running low on free space, and retention is already set to the most aggressive policy. The level of File History protection is likely to degrade soon. This value can be ORed with **FH_STATE_RUNNING** (0x100) to indicate that a backup cycle is being performed for the current user right now. |
| **FH_STATE_TARGET_LOW_SPACE**<br><br>0x14 | The currently assigned target is running low on free space. The level of File History protection is likely to degrade soon. This value can be ORed with **FH_STATE_RUNNING** (0x100) to indicate that a backup cycle is being performed for the current user right now. |
| **FH_STATE_TARGET_ABSENT**<br><br>0x15 | The currently assigned target has not been available for backups for a substantial period of time, causing File History level of protection to start degrading. This value can be ORed with **FH_STATE_RUNNING** (0x100) to indicate that a backup cycle is being performed for the current user right now. |
| **FH_STATE_TOO_MUCH_BEHIND**<br><br>0x16 | Too many changes have been made in the protected files or the protection scope. File History level of protection is likely to degrade, unless the user explicitly initiates an immediate backup instead of relying on regular backup cycles to be performed in the background. This value can be ORed with **FH_STATE_RUNNING** (0x100) to indicate that a backup cycle is being performed for the current user right now. |
| **FH_STATE_NO_ERROR**<br><br>0xFF | File History backups are performed regularly, no error conditions are detected, an optimal level of File History protection is provided. This value can be ORed with **FH_STATE_RUNNING** (0x100) to indicate that a backup cycle is being performed for the current user right now. |

### `ProtectedUntilTime` [out]

Receives a pointer to a string allocated with [SysAllocString](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-sysallocstring) containing the date and time until which all files within the File History protection scope are protected. The date and time are formatted per the system locale. If the date and time are unknown, an empty string is returned.

A file is considered protected until a certain point in time if one of the following conditions is true:

* There is a version of that file that was captured at or after that point in time and was fully copied to the currently assigned backup target before now.
* The file was created or included in the File History protection scope at or after that point in time.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code such as one of the values defined in the FhErrors.h header file.

## Remarks

The caller is responsible for releasing the memory allocated for *ProtectedUntilTime* by calling [SysFreeString](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-sysfreestring) on it.

The protection state indicates the File History operational state and the date and time until which all files within the protection scope are protected.

If the target is full or disconnected, the File History feature will provide a degraded level of protection as follows:

* Files will be backed up to the File History cache on one of the local disks.
* If the cache fills up during this time, older copies will be deleted from the cache to back up newer copies.
* If the target is low on free space, the degraded level of protection will start once the target becomes full.

## See also

[FhConfigMgr](https://learn.microsoft.com/windows/desktop/DevNotes/fhconfigmgr)

[IFhConfigMgr](https://learn.microsoft.com/windows/desktop/api/fhcfg/nn-fhcfg-ifhconfigmgr)