# IVssBackupComponents::GetWriterComponents

## Description

The
**GetWriterComponents** method is used to return information about those components of a given writer that have been stored in a requester's Backup Components Document.

## Parameters

### `iWriter` [in]

The index of the writer being queried. It is a number between 0 and *n*-1, where *n* is the value returned by
[IVssBackupComponents::GetWriterComponentsCount](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-ivssbackupcomponents-getwritercomponentscount).

### `ppWriter` [out]

Doubly indirect pointer to an
[IVssWriterComponentsExt](https://learn.microsoft.com/windows/desktop/api/vsbackup/nl-vsbackup-ivsswritercomponentsext) interface object that will receive the returned component information.

## Return value

The following are the valid return codes for this method.

| Value | Meaning |
| --- | --- |
| **S_OK** | Successfully returned a pointer to an [IVssWriterComponentsExt](https://learn.microsoft.com/windows/desktop/api/vsbackup/nl-vsbackup-ivsswritercomponentsext) interface object. |
| **E_INVALIDARG** | One of the parameter values is not valid. |
| **E_OUTOFMEMORY** | The caller is out of memory or other system resources. |
| **VSS_E_BAD_STATE** | The backup components object is not initialized, this method has been called during a restore operation, or this method has not been called within the correct sequence. |
| **VSS_E_OBJECT_NOT_FOUND** | The specified shadow copy does not exist. |
| **VSS_E_UNEXPECTED** | Unexpected error. The error code is logged in the error log file. For more information, see [Event and Error Handling Under VSS](https://learn.microsoft.com/windows/desktop/VSS/event-and-error-handling-under-vss).<br><br>**Windows Server 2008, Windows Vista, Windows Server 2003 and Windows XP:** This value is not supported until Windows Server 2008 R2 and Windows 7. E_UNEXPECTED is used instead. |

## Remarks

The caller of this method must call [IUnknown::Release](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-release) when it finishes accessing the component information.

**GetWriterComponents** retrieves component information for a component stored in the Backup Components Document by earlier calls to
[IVssBackupComponents::AddComponent](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-ivssbackupcomponents-addcomponent).

The information in the components stored in the Backup Components Document is not static. If a writer updates a component during a restore, that change will be reflected in the component retrieved by
**GetWriterComponents**. This is in contrast with component information found in the
[IVssWMComponent](https://learn.microsoft.com/windows/desktop/api/vsbackup/nl-vsbackup-ivsswmcomponent) object returned by
[IVssExamineWriterMetadata::GetComponent](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-ivssexaminewritermetadata-getcomponent). That information is read-only and comes from the Writer Metadata Document of a writer process.

The [IVssWriterComponentsExt](https://learn.microsoft.com/windows/desktop/api/vsbackup/nl-vsbackup-ivsswritercomponentsext) interface pointer that is returned in the *pWriterComponents* parameter should not be cached, because the following [IVssBackupComponents](https://learn.microsoft.com/windows/desktop/api/vsbackup/nl-vsbackup-ivssbackupcomponents) methods cause the interface pointer that is returned by **GetWriterComponents** to be no longer valid:

[IVssBackupComponents::PrepareForBackup](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-ivssbackupcomponents-prepareforbackup)
[IVssBackupComponents::DoSnapshotSet](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-ivssbackupcomponents-dosnapshotset)
[IVssBackupComponents::BackupComplete](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-ivssbackupcomponents-backupcomplete)
[IVssBackupComponents::PreRestore](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-ivssbackupcomponents-prerestore)
[IVssBackupComponents::PostRestore](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-ivssbackupcomponents-postrestore)
If you call one of these methods after you have retrieved an [IVssWriterComponentsExt](https://learn.microsoft.com/windows/desktop/api/vsbackup/nl-vsbackup-ivsswritercomponentsext) interface pointer by calling **GetWriterComponents**, you cannot reuse that pointer, because it is no longer valid. Instead, you must call **GetWriterComponents** again to retrieve a new **IVssWriterComponentsExt** interface pointer.

## See also

[IVssBackupComponents](https://learn.microsoft.com/windows/desktop/api/vsbackup/nl-vsbackup-ivssbackupcomponents)

[IVssBackupComponents::AddComponent](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-ivssbackupcomponents-addcomponent)

[IVssBackupComponents::GatherWriterMetadata](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-ivssbackupcomponents-gatherwritermetadata)

[IVssBackupComponents::GetWriterComponentsCount](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-ivssbackupcomponents-getwritercomponentscount)

[IVssBackupComponents::GetWriterMetadata](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-ivssbackupcomponents-getwritermetadata)

[IVssBackupComponents::PreRestore](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-ivssbackupcomponents-prerestore)

[IVssExamineWriterMetadata](https://learn.microsoft.com/windows/desktop/api/vsbackup/nl-vsbackup-ivssexaminewritermetadata)

[IVssExamineWriterMetadata::GetComponent](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-ivssexaminewritermetadata-getcomponent)

[IVssWriterComponents](https://learn.microsoft.com/windows/desktop/api/vswriter/nl-vswriter-ivsswritercomponents)

[IVssWriterComponentsExt](https://learn.microsoft.com/windows/desktop/api/vsbackup/nl-vsbackup-ivsswritercomponentsext)