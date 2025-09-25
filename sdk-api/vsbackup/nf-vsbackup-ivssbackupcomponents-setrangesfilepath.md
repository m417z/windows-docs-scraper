# IVssBackupComponents::SetRangesFilePath

## Description

The
**SetRangesFilePath** method is used when a partial file operation requires a ranges file, and that file has been restored to a location other than its original one.

## Parameters

### `writerId` [in]

Globally unique identifier (GUID) of the writer class containing the files involved in the partial file operation.

### `ct` [in]

Identifies the type of the component. Refer to
[VSS_COMPONENT_TYPE](https://learn.microsoft.com/windows/desktop/api/vswriter/ne-vswriter-vss_component_type) for possible return values.

### `wszLogicalPath` [in]

**Null**-terminated wide character string containing the logical path of the component containing the files that are participating in the partial file operation.

For more information, see [Logical Pathing of Components](https://learn.microsoft.com/windows/desktop/VSS/logical-pathing-of-components).

The value of the string containing the logical path used here should be the same as was used when the component was added to the backup set using
[IVssBackupComponents::AddComponent](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-ivssbackupcomponents-addcomponent).

The logical path can be **NULL**.

There are no restrictions on the characters that can appear in a non-**NULL** logical path.

### `wszComponentName` [in]

**Null**-terminated wide character string containing the name of the component containing the files that are participating in the partial file operation.

The string cannot be **NULL** and should contain the same component name as was used when the component was added to the backup set using
[IVssBackupComponents::AddComponent](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-ivssbackupcomponents-addcomponent).

### `iPartialFile` [in]

Index number of the partial file. The value of this parameter is an integer from 0
to *n*–1 inclusive, where *n* is the total number of partial files associated with a given component. The value of *n* is returned by
[IVssComponent::GetPartialFileCount](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-ivsscomponent-getpartialfilecount).

### `wszRangesFile` [in]

**Null**-terminated wide character string containing the fully qualified path of a ranges file.

## Return value

The following are the valid return codes for this method.

| Value | Meaning |
| --- | --- |
| **S_OK** | Successfully added the new restore target. |
| **E_INVALIDARG** | One of the parameter values is not valid. |
| **E_OUTOFMEMORY** | The caller is out of memory or other system resources. |
| **VSS_E_BAD_STATE** | The backup components object is not initialized, or this method has been called other than during a restore operation. |
| **VSS_E_OBJECT_NOT_FOUND** | The component does not exist or the path and file specification do not match a component and file specification in the component. |
| **VSS_E_INVALID_XML_DOCUMENT** | The XML document is not valid. Check the event log for details. For more information, see [Event and Error Handling Under VSS](https://learn.microsoft.com/windows/desktop/VSS/event-and-error-handling-under-vss). |
| **VSS_E_UNEXPECTED** | Unexpected error. The error code is logged in the error log file. For more information, see [Event and Error Handling Under VSS](https://learn.microsoft.com/windows/desktop/VSS/event-and-error-handling-under-vss).<br><br>**Windows Server 2008, Windows Vista, Windows Server 2003 and Windows XP:** This value is not supported until Windows Server 2008 R2 and Windows 7. E_UNEXPECTED is used instead. |

## Remarks

Calling
**SetRangesFilePath** is not necessary if ranges files are restored in place.

## See also

[IVssBackupComponents](https://learn.microsoft.com/windows/desktop/api/vsbackup/nl-vsbackup-ivssbackupcomponents)

[IVssComponent::AddPartialFile](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-ivsscomponent-addpartialfile)

[IVssComponent::GetPartialFile](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-ivsscomponent-getpartialfile)

[IVssComponent::GetPartialFileCount](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-ivsscomponent-getpartialfilecount)