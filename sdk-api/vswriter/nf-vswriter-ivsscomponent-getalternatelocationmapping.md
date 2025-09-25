# IVssComponent::GetAlternateLocationMapping

## Description

The
**GetAlternateLocationMapping** is used to return a file set's alternate location for file restoration. This method can be called by either a writer or a requester.

## Parameters

### `iMapping` [in]

Index of a particular mapping. The value of this parameter is an integer from 0
to *n*–1 inclusive, where *n* is the total number of alternate location mappings associated with the current component. The value of *n* is returned by
[IVssComponent::GetAlternateLocationMappingCount](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-ivsscomponent-getalternatelocationmappingcount).

### `ppFiledesc` [out]

Doubly indirect pointer to a
[IVssWMFiledesc](https://learn.microsoft.com/windows/desktop/api/vswriter/nl-vswriter-ivsswmfiledesc) object containing the mapping information.

## Return value

The following are the valid return codes for this method.

| Value | Meaning |
| --- | --- |
| **S_OK** | Successfully returned the attribute value. |
| **E_INVALIDARG** | One of the parameter values is not valid. |
| **E_OUTOFMEMORY** | The caller is out of memory or other system resources. |
| **VSS_E_INVALID_XML_DOCUMENT** | The XML document is not valid. Check the event log for details. For more information, see [Event and Error Handling Under VSS](https://learn.microsoft.com/windows/desktop/VSS/event-and-error-handling-under-vss). |
| **VSS_E_OBJECT_NOT_FOUND** | The specified item was not found. |

## Remarks

Alternate location mappings returned by
**GetAlternateLocationMapping** can come not only from files in the current component, but also from files in any of its nonselectable subcomponents.

The value returned by **IVssComponent::GetAlternateLocationMapping** should also not be confused with that returned by
[IVssExamineWriterMetadata::GetAlternateLocationMapping](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-ivssexaminewritermetadata-getalternatelocationmapping):

* [IVssExamineWriterMetadata::GetAlternateLocationMapping](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-ivssexaminewritermetadata-getalternatelocationmapping) is the alternate location mapping to which a file may be restored if necessary.
* **IVssComponent::GetAlternateLocationMapping** is the alternate location to which a file was in fact restored.

A file should always be restored to its alternate location mapping if either of the following is true:

* The restore method (set at backup time) is VSS_RME_RESTORE_TO_ALTERNATE_LOCATION.
* Its restore target was set (at restore time) to VSS_RT_ALTERNATE.

In either case, having no alternate location mapping defined constitutes a writer error.

A file can be restored to an alternate location mapping if either of the following is true:

* The restore method is VSS_RME_RESTORE_IF_NOT_THERE and a version of the file is already present on disk.
* The restore method is VSS_RME_RESTORE_IF_CAN_REPLACE and a version of the file is present on disk and cannot be replaced.

An alternate location mapping is used only during a restore operation and should not be confused with an alternate path, which is used only during a backup operation.

The mapping returned by
**GetAlternateLocationMapping** refers to the alternate location mappings used in the course of restoring files.

Alternate location mappings are added to an
[IVssComponent](https://learn.microsoft.com/windows/desktop/api/vswriter/nl-vswriter-ivsscomponent) object by
[IVssBackupComponents::AddAlternativeLocationMapping](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-ivssbackupcomponents-addalternativelocationmapping).

The caller must call [IUnknown::Release](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-release) to release the system resources held by the *ppMapping* parameter when it is done with the
[IVssWMFiledesc](https://learn.microsoft.com/windows/desktop/api/vswriter/nl-vswriter-ivsswmfiledesc) object that it points to.

For more information on backup and restore file locations under VSS, see
[Non-Default Backup And Restore Locations](https://learn.microsoft.com/windows/desktop/VSS/non-default-backup-and-restore-locations).

## See also

[IVssBackupComponents::AddAlternativeLocationMapping](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-ivssbackupcomponents-addalternativelocationmapping)

[IVssComponent](https://learn.microsoft.com/windows/desktop/api/vswriter/nl-vswriter-ivsscomponent)

[IVssExamineWriterMetadata::GetAlternateLocationMapping](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-ivssexaminewritermetadata-getalternatelocationmapping)