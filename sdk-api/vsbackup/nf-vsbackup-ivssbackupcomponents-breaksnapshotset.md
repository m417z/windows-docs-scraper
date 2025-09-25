# IVssBackupComponents::BreakSnapshotSet

## Description

The
**BreakSnapshotSet** method causes the existence of a shadow copy set to be "forgotten" by VSS.

## Parameters

### `SnapshotSetId` [in]

Shadow copy set identifier.

## Return value

The following are the valid return codes for this method.

| Value | Meaning |
| --- | --- |
| **S_OK** | The shadow copy set was successfully broken. |
| **E_ACCESSDENIED** | The caller does not have sufficient backup privileges or is not an administrator. |
| **E_INVALIDARG** | One of the parameter values is not valid. |
| **E_OUTOFMEMORY** | The caller is out of memory or other system resources. |
| **VSS_E_OBJECT_NOT_FOUND** | The specified shadow copy does not exist. |
| **VSS_E_PROVIDER_VETO** | The shadow copy was created by a software provider and cannot be broken. |
| **VSS_E_UNEXPECTED** | Unexpected error. The error code is logged in the error log file. For more information, see [Event and Error Handling Under VSS](https://learn.microsoft.com/windows/desktop/VSS/event-and-error-handling-under-vss).<br><br>**Windows Server 2008, Windows Vista, Windows Server 2003 and Windows XP:** This value is not supported until Windows Server 2008 R2 and Windows 7. E_UNEXPECTED is used instead. |

## Remarks

**BreakSnapshotSet** can be used only for shadow copies created by a hardware shadow copy provider. This method makes these shadow copies regular volumes.

Shadow copies of volumes "broken" with
**BreakSnapshotSet** must be managed independently of VSS as stand-alone volumes. See
[Breaking Shadow Copies](https://learn.microsoft.com/windows/desktop/VSS/breaking-shadow-copies) for more information.

[IVssBackupComponentsEx2::BreakSnapshotSetEx](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-ivssbackupcomponentsex2-breaksnapshotsetex) is similar to the **BreakSnapshotSet** method, except that it has extra parameters to query status and specify how the shadow copy set is broken.

## See also

[IVssBackupComponents](https://learn.microsoft.com/windows/desktop/api/vsbackup/nl-vsbackup-ivssbackupcomponents)

[IVssBackupComponents::DeleteSnapshots](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-ivssbackupcomponents-deletesnapshots)