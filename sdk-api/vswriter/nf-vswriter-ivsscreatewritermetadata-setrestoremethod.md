# IVssCreateWriterMetadata::SetRestoreMethod

## Description

The
**SetRestoreMethod** method indicates how the writer's data is to be restored.

## Parameters

### `method` [in]

[VSS_RESTOREMETHOD_ENUM](https://learn.microsoft.com/windows/desktop/api/vswriter/ne-vswriter-vss_restoremethod_enum) value specifying the method that will be used in the restore operation.

### `wszService` [in]

A pointer to a wide character string containing the name of a service that must be stopped prior to a restore operation and then started after the restore operation takes place, if the value of *method* is VSS_RME_STOP_RESTORE_START or VSS_RME_RESTORE_STOP_START.

If the value of *method* is not VSS_RME_STOP_RESTORE_START or VSS_RME_RESTORE_STOP_START, this argument is not used and should be set to **NULL**.

### `wszUserProcedure` [in]

Reserved for future use. The value of this parameter should always be set to **NULL**.

### `writerRestore` [in]

[VSS_WRITERRESTORE_ENUM](https://learn.microsoft.com/windows/desktop/api/vswriter/ne-vswriter-vss_writerrestore_enum) value specifying whether the writer will be involved in restoring its data.

Express writers must set this parameter to *VSS_WRE_NEVER*.

### `bRebootRequired` [in]

Boolean indicating whether a reboot will be required after the restore operation is complete.

## Return value

The following are the valid return codes for this method.

| Value | Meaning |
| --- | --- |
| **S_OK**<br><br>0x00000000L | The operation was successful. |
| **E_INVALIDARG**<br><br>0x80070057L | One of the parameter values is not valid. |
| **E_OUTOFMEMORY**<br><br>0x8007000EL | The caller is out of memory or other system resources. |
| **VSS_E_INVALID_XML_DOCUMENT**<br><br>0x80042311L | The XML document is not valid. Check the event log for details. For more information, see [Event and Error Handling Under VSS](https://learn.microsoft.com/windows/desktop/VSS/event-and-error-handling-under-vss). |
| **VSS_E_NOT_SUPPORTED**<br><br>0x8004232FL | The caller specified a [VSS_WRITERRESTORE_ENUM](https://learn.microsoft.com/windows/desktop/api/vswriter/ne-vswriter-vss_writerrestore_enum) value that is not supported for express writers. |
| **VSS_E_UNEXPECTED** | Unexpected error. The error code is logged in the error log file. For more information, see [Event and Error Handling Under VSS](https://learn.microsoft.com/windows/desktop/VSS/event-and-error-handling-under-vss).<br><br>**Windows Server 2008, Windows Vista, Windows Server 2003 and Windows XP:** This value is not supported until Windows Server 2008 R2 and Windows 7. E_UNEXPECTED is used instead. |

## Remarks

There is a single restore method defined for a writer. If the restore method is not overridden, all of the writer's components will be restored using the same method.

Writers override the restore method on a component-by-component basis by setting a restore target, typically while handling a
[PreRestore](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-ivssbackupcomponents-prerestore) event ([CVssWriter::OnPreRestore](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-cvsswriter-onprerestore)).

It is important to note that despite the fact that restore methods are applied writer-wide, methods are implemented on a per-component basis. For example, if the method specified by the *method* parameter is VSS_RME_RESTORE_IF_CAN_REPLACE, then all of the files in the component are restored to their original location if they can all be replaced without an error occurring. Otherwise, they are restored to their alternate location if one is specified.

A file should always be restored to its alternate location mapping if either of the following is true:

* The restore method (set at backup time) is VSS_RME_RESTORE_TO_ALTERNATE_LOCATION.
* Its restore target was set (at restore time) to VSS_RT_ALTERNATE.

In either case, if no valid alternate location mapping is defined, this constitutes a writer error.

A file can be restored to an alternate location mapping if either of the following is true:

* The restore method is VSS_RME_RESTORE_IF_NOT_THERE and a version of the file is already present on disk.
* The restore method is VSS_RME_RESTORE_IF_CAN_REPLACE and a version of the file is present on disk and cannot be replaced.

Again, if no valid alternate location mapping is defined, this constitutes a writer error.

An alternate location mapping is used only during a restore operation and should not be confused with an alternate path, which is used only during a backup operation.

For more information about restore methods, see [Setting VSS Restore Methods](https://learn.microsoft.com/windows/desktop/VSS/setting-vss-restore-methods).

If the restore method is VSS_RME_STOP_RESTORE_START or VSS_RME_RESTORE_STOP_START, then the correct name of the service must be provided as the *wszService* argument. For information on writer participation in stopping and restarting services during a restore operation, see [Stopping Services for Restore by Requesters](https://learn.microsoft.com/windows/desktop/VSS/stopping-services-for-restore-by-requestors).

## See also

[CVssWriter::OnPostRestore](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-cvsswriter-onpostrestore)

[CVssWriter::OnPreRestore](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-cvsswriter-onprerestore)

[IVssCreateWriterMetadata](https://learn.microsoft.com/windows/desktop/api/vswriter/nl-vswriter-ivsscreatewritermetadata)

[IVssExamineWriterMetadata::GetRestoreMethod](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-ivssexaminewritermetadata-getrestoremethod)