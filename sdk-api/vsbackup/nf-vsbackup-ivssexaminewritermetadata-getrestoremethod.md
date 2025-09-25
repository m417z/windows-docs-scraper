# IVssExamineWriterMetadata::GetRestoreMethod

## Description

The
**GetRestoreMethod** method returns information about how a writer wants its data to be restored.

## Parameters

### `pMethod` [out]

Pointer to a
[VSS_RESTOREMETHOD_ENUM](https://learn.microsoft.com/windows/desktop/api/vswriter/ne-vswriter-vss_restoremethod_enum) value that specifies file overwriting, the use of alternate locations specifying the method that will be used in the restore operation.

### `pbstrService` [out]

If the value of *pMethod* is VSS_RME_STOP_RESTORE_START or VSS_RME_RESTORE_STOP_START, a pointer to a string containing the name of the service that is started and stopped. Otherwise, the value is **NULL**.

### `pbstrUserProcedure` [out]

Pointer to the URL of an HTML or XML document describing to the user how the restore is to be performed. The value may be **NULL**.

### `pwriterRestore` [out]

Pointer to a
[VSS_WRITERRESTORE_ENUM](https://learn.microsoft.com/windows/desktop/api/vswriter/ne-vswriter-vss_writerrestore_enum) value specifying whether the writer will be involved in restoring its data.

### `pbRebootRequired` [out]

Pointer to a Boolean value indicating whether a reboot will be required after the restore operation is complete. The value receives **true** if a reboot will be required, or **false** otherwise.

### `pcMappings` [out]

Pointer to the number of alternate mappings associated with the writer.

## Return value

The following are the valid return codes for this method.

| Value | Meaning |
| --- | --- |
| **S_OK** | Successfully returned the restore method information. |
| **S_FALSE** | A restore method does not exist. |
| **E_INVALIDARG** | One of the parameter values is not valid. |
| **E_OUTOFMEMORY** | The caller is out of memory or other system resources. |
| **VSS_E_INVALID_XML_DOCUMENT** | The XML document is not valid. Check the event log for details. For more information, see [Event and Error Handling Under VSS](https://learn.microsoft.com/windows/desktop/VSS/event-and-error-handling-under-vss). |
| **VSS_E_UNEXPECTED** | Unexpected error. The error code is logged in the error log file. For more information, see [Event and Error Handling Under VSS](https://learn.microsoft.com/windows/desktop/VSS/event-and-error-handling-under-vss).<br><br>**Windows Server 2008, Windows Vista, Windows Server 2003 and Windows XP:** This value is not supported until Windows Server 2008 R2 and Windows 7. E_UNEXPECTED is used instead. |

## Remarks

The caller must free the memory used by the *pbstrUserProcedure* and *pbstrService* parameters by calling [SysFreeString](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-sysfreestring).

A file should always be restored to its alternate location mapping if either of the following is true:

* The restore method (set at backup time) is VSS_RME_RESTORE_TO_ALTERNATE_LOCATION.
* Its restore target was set (at restore time) to VSS_RT_ALTERNATE.

In either case, if no valid alternate location mapping is defined, this constitutes a writer error.

A file can be restored to an alternate location mapping if :

* The restore method is VSS_RME_RESTORE_IF_NOT_THERE and a version of the file is already present on disk.
* The restore method is VSS_RME_RESTORE_IF_CAN_REPLACE and a version of the file is present on disk and cannot be replaced.

Again, if no valid alternate location mapping is defined, this constitutes a writer error.

An alternate location mapping is used only during a restore operation and should not be confused with an alternate path, which is used only during a backup operation.

For more information about restore methods, see [Setting VSS Restore Methods](https://learn.microsoft.com/windows/desktop/VSS/setting-vss-restore-methods).

If the restore method is VSS_RME_STOP_RESTORE_START or VSS_RME_RESTORE_STOP_START, a requester uses the name returned by *pbstrService* to determine which service must be stopped during and then restarted after restore. See
[Stopping Services For Restore by Requesters](https://learn.microsoft.com/windows/desktop/VSS/stopping-services-for-restore-by-requestors) for information on writer participation in stopping and restarting services during a restore operation.

## See also

[IVssCreateWriterMetadata::SetRestoreMethod](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-ivsscreatewritermetadata-setrestoremethod)

[IVssExamineWriterMetadata](https://learn.microsoft.com/windows/desktop/api/vsbackup/nl-vsbackup-ivssexaminewritermetadata)