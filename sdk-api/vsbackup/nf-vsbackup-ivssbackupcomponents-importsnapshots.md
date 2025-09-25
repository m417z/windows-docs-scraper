# IVssBackupComponents::ImportSnapshots

## Description

The **ImportSnapshots** method
imports shadow copies transported from a different machine.

**Note** This method is supported only on Windows Server operating systems and for Volume Shadow Copy Service hardware providers.

## Parameters

### `ppAsync` [out]

Doubly indirect pointer to an [IVssAsync](https://learn.microsoft.com/windows/desktop/api/vss/nn-vss-ivssasync) object
containing the imported shadow copy status data.

## Return value

The following are the valid return codes for this method.

| Value | Meaning |
| --- | --- |
| **S_OK** | Successfully returned a pointer to an instance of the [IVssAsync](https://learn.microsoft.com/windows/desktop/api/vss/nn-vss-ivssasync) interface. Refer to the reference page for [IVssAsync::QueryStatus](https://learn.microsoft.com/windows/desktop/api/vss/nf-vss-ivssasync-querystatus) for the error codes returned in the *pHrResult* parameter. |
| **E_ACCESSDENIED** | The caller does not have sufficient backup privileges or is not an administrator. |
| **E_INVALIDARG** | The *ppAsync* parameter does not point to a valid pointer; that is, it is **NULL**. |
| **E_OUTOFMEMORY** | The caller is out of memory or other system resources. |
| **VSS_E_BAD_STATE** | The backup components object is not initialized, this method has been called during a restore operation, or this method has not been called from within the correct sequence. |
| **VSS_E_UNEXPECTED** | Unexpected error. The error code is logged in the error log file. For more information, see [Event and Error Handling Under VSS](https://learn.microsoft.com/windows/desktop/VSS/event-and-error-handling-under-vss).<br><br>**Windows Server 2008, Windows Vista, Windows Server 2003 and Windows XP:** This value is not supported until Windows Server 2008 R2 and Windows 7. E_UNEXPECTED is used instead. |

## Remarks

Only one shadow copy can be imported at a time.

The requester is responsible for serializing the import shadow copy operation.

The caller is responsible for releasing the [IVssAsync](https://learn.microsoft.com/windows/desktop/api/vss/nn-vss-ivssasync)
interface.

For more information on importing shadow copies, see
[Importing Transportable Shadow
Copied Volumes](https://learn.microsoft.com/windows/desktop/VSS/importing-transportable-shadow-copied-volumes).

**Transportable shadow copies in a cluster:** For details about using transportable shadow copies in a cluster, see
[Fast Recovery Using
Transportable Shadow Copied Volumes](https://learn.microsoft.com/windows/desktop/VSS/fast-recovery-using-transportable-shadow-copied-volumes). The transportable shadow copy must be
imported from outside the cluster as long as the original volume is mounted within the cluster.

**Note** If the shadow copy import fails, the Volume Shadow Copy Service won't clean up LUNs on its own. The requester has to initiate the cleanup of LUNs.

## See also

[IVssAsync](https://learn.microsoft.com/windows/desktop/api/vss/nn-vss-ivssasync)

[IVssAsync::QueryStatus](https://learn.microsoft.com/windows/desktop/api/vss/nf-vss-ivssasync-querystatus)

[IVssBackupComponents](https://learn.microsoft.com/windows/desktop/api/vsbackup/nl-vsbackup-ivssbackupcomponents)

[IVssBackupComponents::ExposeSnapshot](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-ivssbackupcomponents-exposesnapshot)

[IVssBackupComponents::InitializeForBackup](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-ivssbackupcomponents-initializeforbackup)