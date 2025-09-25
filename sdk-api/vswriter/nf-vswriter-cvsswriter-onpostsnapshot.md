# CVssWriter::OnPostSnapshot

## Description

The **OnPostSnapshot** method is called by a
writer following a [PostSnapshot](https://learn.microsoft.com/windows/desktop/VSS/vssgloss-p)
event.

**OnPostSnapshot** is a virtual method. It is
implemented by the [CVssWriter](https://learn.microsoft.com/windows/desktop/api/vswriter/nl-vswriter-cvsswriter) base class but can be
overridden by derived classes.

## Parameters

### `pComponent` [in]

A pointer to an [IVssWriterComponents](https://learn.microsoft.com/windows/desktop/api/vswriter/nl-vswriter-ivsswritercomponents) object
passed in by VSS to provide the method with access to the writer's component information. The value of this
parameter may be NULL if the requester does not support components (if
[CVssWriter::AreComponentsSelected](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-cvsswriter-arecomponentsselected)
returns **false**).

## Return value

As implemented by the base class,
**OnPostSnapshot** always returns **true**.

Any other implementation of this method must return **true** except in the case of a fatal error.
If a fatal error occurs, the method must call the [CVssWriter::SetWriterFailure](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-cvsswriter-setwriterfailure) method to provide a description of the failure before returning **false**. If a nonfatal error occurs, the method should still call **SetWriterFailure** but return **true**. If the error is caused by a transient problem, the method should specify VSS_E_WRITERERROR_RETRYABLE in the call to **SetWriterFailure**.

 In all cases when a failure occurs, the method should write an event to the event log to report the exact reason for the failure.

## Remarks

The default implementation of this method by the
[CVssWriter](https://learn.microsoft.com/windows/desktop/api/vswriter/nl-vswriter-cvsswriter) base class returns **true** without
performing any other operation.

**CVssWriter::OnPostSnapshot** is typically
used to process any final updates by the writer to the backup components metadata and clean up (such as
removing temporary files).

If an incremental or differential backup is being performed, the writer may call [IVssComponent::GetPreviousBackupStamp](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-ivsscomponent-getpreviousbackupstamp) and [IVssComponent::SetBackupStamp](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-ivsscomponent-setbackupstamp). For more information, see [Writer Role in Backing Up Complex Stores](https://learn.microsoft.com/windows/desktop/VSS/writer-role-in-backing-up-complex-stores). Another method that can be called at this time is [IVssComponent::AddDifferencedFilesByLastModifyTime](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-ivsscomponent-adddifferencedfilesbylastmodifytime).

Most of the work needed to return the writer to normal operation (reversing the actions of
[CVssWriter::OnPrepareSnapshot](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-cvsswriter-onpreparesnapshot) and
[CVssWriter::OnFreeze](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-cvsswriter-onfreeze)) is typically performed in
[CVssWriter::OnThaw](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-cvsswriter-onthaw), not in
**OnPostSnapshot**.

Writers should never throw an exception from this method or any other **CVssWriter(Ex)::On*Xxx*** callback method.

 If the shadow copy has the **VSS_VOLSNAP_ATTR_AUTORECOVER** flag set in the context,
the writer should perform any recovery required (for example, rolling back any incomplete transactions) so that
the component will be usable on a read-only copy for data mining (without adding load to the live server) or
restore purposes (for example, to restore selected items from a database).

To retrieve the volume name of the shadow copy of a volume, perform the following steps:

1. Call the [CVssWriter::GetCurrentVolumeCount](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-cvsswriter-getcurrentvolumecount) method to query the number of volumes in the shadow copy set.
2. Call the [CVssWriter::GetCurrentVolumeArray](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-cvsswriter-getcurrentvolumearray) method to enumerate the original names of the volumes in the shadow copy set.
3. Call the [CVssWriter::GetSnapshotDeviceName](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-cvsswriter-getsnapshotdevicename) to retrieve the name of the shadow copy volume.

If this method calls the [CVssWriterEx2::GetSessionId](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-cvsswriterex2-getsessionid), [CVssWriter::SetWriterFailure](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-cvsswriter-setwriterfailure), or [CVssWriterEx2::SetWriterFailureEx](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-cvsswriterex2-setwriterfailureex) method, it must do so in the same thread that called this method. For more information, see
[Writer Event Handling](https://learn.microsoft.com/windows/desktop/VSS/writers).

## See also

[CVssWriter](https://learn.microsoft.com/windows/desktop/api/vswriter/nl-vswriter-cvsswriter)

[CVssWriter::GetSnapshotDeviceName](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-cvsswriter-getsnapshotdevicename)

[CVssWriter::OnPreRestore](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-cvsswriter-onprerestore)

[CVssWriter::OnPrepareBackup](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-cvsswriter-onpreparebackup)

[CVssWriter::SetWriterFailure](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-cvsswriter-setwriterfailure)

[CvssWriter::OnThaw](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-cvsswriter-onthaw)

[IVssWriterComponents](https://learn.microsoft.com/windows/desktop/api/vswriter/nl-vswriter-ivsswritercomponents)