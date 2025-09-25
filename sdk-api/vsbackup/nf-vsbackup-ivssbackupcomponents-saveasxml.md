# IVssBackupComponents::SaveAsXML

## Description

The
**SaveAsXML** method saves the Backup Components Document containing a requester's state information to a specified string. This XML document, which contains the Backup Components Document, should always be securely saved as part of a backup operation.

## Parameters

### `pbstrXML` [in]

Pointer to a string to be used to store the Backup Components Document containing a requester's state information.

## Return value

The following are the valid return codes for this method.

| Value | Meaning |
| --- | --- |
| **S_OK** | Successfully saved the XML document as the *pbstrXML* parameter value. |
| **E_INVALIDARG** | One of the parameter values is not valid. |
| **E_OUTOFMEMORY** | The caller is out of memory or other system resources. |
| **VSS_E_BAD_STATE** | The backup components object is not initialized, this method has been called during a restore operation, or this method has not been called within the correct sequence. |
| **VSS_E_UNEXPECTED** | Unexpected error. The error code is logged in the error log file. For more information, see [Event and Error Handling Under VSS](https://learn.microsoft.com/windows/desktop/VSS/event-and-error-handling-under-vss).<br><br>**Windows Server 2008, Windows Vista, Windows Server 2003 and Windows XP:** This value is not supported until Windows Server 2008 R2 and Windows 7. E_UNEXPECTED is used instead. |

## Remarks

For a typical backup operation,
**SaveAsXML** should not be called until after both writers and the requester are finished modifying the Backup Components Document.

Writers can continue to modify the Backup Components Document until their successful return from handling the PostSnapshot event ([CVssWriter::OnPostSnapshot](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-cvsswriter-onpostsnapshot)), or equivalently upon the completion of
[IVssBackupComponents::DoSnapshotSet](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-ivssbackupcomponents-dosnapshotset).

Requesters will need to continue to modify the Backup Components Document as the backup progresses. In particular, a requester will store a component-by-component record of the success or failure of the backup through calls to the
[IVssBackupComponents::SetBackupSucceeded](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-ivssbackupcomponents-setbackupsucceeded) method.

Once the requester has finished modifying the Backup Components Document, the requester should use
**SaveAsXML** to save a copy of the document to the backup media.

A Backup Components Document can be saved at earlier points in the life cycle of a backup operation—for instance, to support the generation of transportable shadow copies to be handled on remote machines. (See
[Importing Transportable Shadow Copied Volumes](https://learn.microsoft.com/windows/desktop/VSS/importing-transportable-shadow-copied-volumes) for more information.)

However,
**SaveAsXML** should never be called prior to
[IVssBackupComponents::PrepareForBackup](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-ivssbackupcomponents-prepareforbackup), because the Backup Components Document will not have been filled by the requester and the writers.

## See also

[IVssBackupComponents](https://learn.microsoft.com/windows/desktop/api/vsbackup/nl-vsbackup-ivssbackupcomponents)

[IVssBackupComponents::GatherWriterMetadata](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-ivssbackupcomponents-gatherwritermetadata)

[IVssBackupComponents::InitializeForBackup](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-ivssbackupcomponents-initializeforbackup)

[IVssBackupComponents::InitializeForRestore](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-ivssbackupcomponents-initializeforrestore)

[IVssBackupComponents::PrepareForBackup](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-ivssbackupcomponents-prepareforbackup)