# IVssWMFiledesc::GetRecursive

## Description

The **GetRecursive** method
indicates whether the list of files described in a
[IVssWMFiledesc](https://learn.microsoft.com/windows/desktop/api/vswriter/nl-vswriter-ivsswmfiledesc) object with a root directory returned by
[IVssWMFiledesc::GetPath](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-ivsswmfiledesc-getpath) contains only files in
that directory or whether the file list contains files from the directory hierarchy as well.

## Parameters

### `pbRecursive` [out]

A pointer to a Boolean value specifying whether the value returned by
[IVssWMFiledesc::GetPath](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-ivsswmfiledesc-getpath) identifies
only a single directory or if it indicates a hierarchy of directories to be traversed recursively. The Boolean value receives
**true** if the path is treated as a hierarchy of directories to be traversed recursively, or **false** if not.

For information on traversing over mounted folders, see
[Working with Mounted Folders and Reparse Points](https://learn.microsoft.com/windows/desktop/VSS/working-with-reparse-and-mount-points).

## Return value

The following are the valid return codes for this method.

| Value | Meaning |
| --- | --- |
| **S_OK** | Successfully returned the recursive information. |
| **E_INVALIDARG** | One of the parameter values is not valid. |
| **E_OUTOFMEMORY** | The caller is out of memory or other system resources. |
| **VSS_E_UNEXPECTED** | Unexpected error. The error code is logged in the error log file. For more information, see [Event and Error Handling Under VSS](https://learn.microsoft.com/windows/desktop/VSS/event-and-error-handling-under-vss).<br><br>**Windows Server 2008, Windows Vista, Windows Server 2003 and Windows XP:** This value is not supported until Windows Server 2008 R2 and Windows 7. E_UNEXPECTED is used instead. |
| **VSS_E_INVALID_XML_DOCUMENT** | The XML document is not valid. Check the event log for details. For more information, see [Event and Error Handling Under VSS](https://learn.microsoft.com/windows/desktop/VSS/event-and-error-handling-under-vss). |

## See also

[IVssWMFiledesc](https://learn.microsoft.com/windows/desktop/api/vswriter/nl-vswriter-ivsswmfiledesc)