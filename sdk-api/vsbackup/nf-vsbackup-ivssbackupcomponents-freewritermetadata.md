# IVssBackupComponents::FreeWriterMetadata

## Description

The
**FreeWriterMetadata** method frees system resources allocated when [IVssBackupComponents::GatherWriterMetadata](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-ivssbackupcomponents-gatherwritermetadata) was called.

## Return value

The following are the valid return codes for this method.

| Value | Meaning |
| --- | --- |
| **S_OK** | The writer metadata was successfully freed. |
| **VSS_E_BAD_STATE** | The backup components object is not initialized, this method has been called during a restore operation, or this method has not been called within the correct sequence. |

## Remarks

This method should never be called prior to the completion of
[IVssBackupComponents::GatherWriterMetadata](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-ivssbackupcomponents-gatherwritermetadata). The result of calling the method prior to completion of the metadata gather is undefined.

Once writer metadata has been freed, it cannot be recovered by the current instance of the
[IVssBackupComponents](https://learn.microsoft.com/windows/desktop/api/vsbackup/nl-vsbackup-ivssbackupcomponents) interface. It will be necessary to create a new instance of
**IVssBackupComponents**, and call the [IVssBackupComponents::GatherWriterMetadata](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-ivssbackupcomponents-gatherwritermetadata) method again.

## See also

[IVssBackupComponents](https://learn.microsoft.com/windows/desktop/api/vsbackup/nl-vsbackup-ivssbackupcomponents)

[IVssBackupComponents::GatherWriterMetadata](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-ivssbackupcomponents-gatherwritermetadata)