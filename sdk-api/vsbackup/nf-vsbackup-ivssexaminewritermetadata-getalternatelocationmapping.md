# IVssExamineWriterMetadata::GetAlternateLocationMapping

## Description

The
**GetAlternateLocationMapping** method obtains a specific alternate location mapping of a file set.

## Parameters

### `iMapping` [in]

Index of a particular mapping. The value of this parameter is an integer from 0
to *n*–1 inclusive, where *n* is the total number of alternate location mappings associated with a given writer. The value of *n* is returned by
[IVssExamineWriterMetadata::GetRestoreMethod](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-ivssexaminewritermetadata-getrestoremethod).

### `ppFiledesc` [out]

Doubly indirect pointer to an
[IVssWMFiledesc](https://learn.microsoft.com/windows/desktop/api/vswriter/nl-vswriter-ivsswmfiledesc) object containing the alternate location mapping information.

## Return value

The following are the valid return codes for this method.

| Value | Meaning |
| --- | --- |
| **S_OK** | Successfully returned a pointer to an [IVssWMFiledesc](https://learn.microsoft.com/windows/desktop/api/vswriter/nl-vswriter-ivsswmfiledesc) interface. |
| **E_INVALIDARG** | One of the parameter values is not valid. |
| **E_OUTOFMEMORY** | The caller is out of memory or other system resources. |
| **VSS_E_INVALID_XML_DOCUMENT** | The XML document is not valid. Check the event log for details. For more information, see [Event and Error Handling Under VSS](https://learn.microsoft.com/windows/desktop/VSS/event-and-error-handling-under-vss). |
| **VSS_E_OBJECT_NOT_FOUND** | The specified alternate location mapping does not exist. |
| **VSS_E_UNEXPECTED** | Unexpected error. The error code is logged in the error log file. For more information, see [Event and Error Handling Under VSS](https://learn.microsoft.com/windows/desktop/VSS/event-and-error-handling-under-vss).<br><br>**Windows Server 2008, Windows Vista, Windows Server 2003 and Windows XP:** This value is not supported until Windows Server 2008 R2 and Windows 7. E_UNEXPECTED is used instead. |

## Remarks

The value returned by **IVssExamineWriterMetadata::GetAlternateLocationMapping** should not be confused with that returned by
[IVssComponent::GetAlternateLocationMapping](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-ivsscomponent-getalternatelocationmapping).

[IVssComponent::GetAlternateLocationMapping](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-ivsscomponent-getalternatelocationmapping) is the alternate location to which a file was restored.

**IVssExamineWriterMetadata::GetAlternateLocationMapping** is the alternate location mapping to which a file may be restored if necessary.

A file should always be restored to its alternate location mapping if either of the following is true:

* The restore method (set at backup time) is VSS_RME_RESTORE_TO_ALTERNATE_LOCATION.
* Its restore target was set (at restore time) to VSS_RT_ALTERNATE.

In either case, if no valid alternate location mapping is defined, this constitutes a writer error.

A file may be restored to an alternate location mapping if either of the following is true:

* The restore method is VSS_RME_RESTORE_IF_NOT_THERE and a version of the file is already present on disk.
* The restore method is VSS_RME_RESTORE_IF_CAN_REPLACE and a version of the file is present on disk and cannot be replaced.

Again, if no valid alternate location mapping is defined, this constitutes a writer error.

An alternate location mapping is used only during a restore operation and should not be confused with an alternate path, which is used only during a backup operation.

The caller is responsible for calling [IUnknown::Release](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-release) to release the resources of the returned
[IVssWMFiledesc](https://learn.microsoft.com/windows/desktop/api/vswriter/nl-vswriter-ivsswmfiledesc) object.

## See also

[IVssBackupComponents::AddAlternativeLocationMapping](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-ivssbackupcomponents-addalternativelocationmapping)

[IVssComponent::GetAlternateLocationMapping](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-ivsscomponent-getalternatelocationmapping)

[IVssExamineWriterMetadata](https://learn.microsoft.com/windows/desktop/api/vsbackup/nl-vsbackup-ivssexaminewritermetadata)

[IVssExamineWriterMetadata::GetRestoreMethod](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-ivssexaminewritermetadata-getrestoremethod)

[IVssWMFiledesc](https://learn.microsoft.com/windows/desktop/api/vswriter/nl-vswriter-ivsswmfiledesc)