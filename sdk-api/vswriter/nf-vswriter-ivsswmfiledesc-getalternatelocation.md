# IVssWMFiledesc::GetAlternateLocation

## Description

The
**GetAlternateLocation** method obtains an alternate location for a file set.

## Parameters

### `pbstrAlternateLocation` [out]

The address of a caller-allocated variable that receives a string specifying the alternate backup location. The path of this location can be a local path or the UNC path of a remote file share. If there is no alternate location, the pointer is **NULL**.

## Return value

The following are the valid return codes for this method.

| Value | Meaning |
| --- | --- |
| **S_OK** | Successfully returned the alternate location information. |
| **S_FALSE** | The requested information could not be found. |
| **E_INVALIDARG** | One of the parameter values is not valid. |
| **E_OUTOFMEMORY** | The caller is out of memory or other system resources. |
| **VSS_E_INVALID_XML_DOCUMENT** | The XML document is not valid. Check the event log for details. For more information, see [Event and Error Handling Under VSS](https://learn.microsoft.com/windows/desktop/VSS/event-and-error-handling-under-vss). |
| **VSS_E_UNEXPECTED** | Unexpected error. The error code is logged in the error log file. For more information, see [Event and Error Handling Under VSS](https://learn.microsoft.com/windows/desktop/VSS/event-and-error-handling-under-vss).<br><br>**Windows Server 2008, Windows Vista, Windows Server 2003 and Windows XP:** This value is not supported until Windows Server 2008 R2 and Windows 7. E_UNEXPECTED is used instead. |

## Remarks

**Windows 7, Windows Server 2008 R2, Windows Vista, Windows Server 2008, Windows XP and Windows Server 2003:** Remote file shares are not supported until Windows 8 and Windows Server 2012.

The caller must call [SysFreeString](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-sysfreestring) to free the memory held by the *pbstrAlternateLocation* parameter.

The interpretation of the alternate location returned by
**GetAlternateLocation** differs depending on the method used to retrieve the
[IVssWMFiledesc](https://learn.microsoft.com/windows/desktop/api/vswriter/nl-vswriter-ivsswmfiledesc) object.

* [IVssExamineWriterMetadata::GetExcludeFile](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-ivssexaminewritermetadata-getexcludefile)
* [IVssWMComponent::GetDatabaseFile](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-ivsswmcomponent-getdatabasefile)
* [IVssWMComponent::GetDatabaseLogFile](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-ivsswmcomponent-getdatabaselogfile)
* [IVssWMComponent::GetFile](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-ivsswmcomponent-getfile)

The value returned by
**GetAlternateLocation** refers to an alternate location mapping when returned by the
[IVssExamineWriterMetadata::GetAlternateLocationMapping](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-ivssexaminewritermetadata-getalternatelocationmapping) method.

During backup operations, this is the alternate location from which to back up a file. During a restore, it is the alternate location to which to restore a file.

For more information, see
[Non-Default Backup And Restore Locations](https://learn.microsoft.com/windows/desktop/VSS/non-default-backup-and-restore-locations).

## See also

[IVssWMFiledesc](https://learn.microsoft.com/windows/desktop/api/vswriter/nl-vswriter-ivsswmfiledesc)