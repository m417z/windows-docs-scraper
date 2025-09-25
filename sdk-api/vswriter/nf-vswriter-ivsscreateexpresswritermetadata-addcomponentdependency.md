# IVssCreateExpressWriterMetadata::AddComponentDependency

## Description

Allows an express writer to indicate that a component it manages has an explicit writer-component dependency; that is, another component (possibly managed by another writer) must be backed up and restored with it.

## Parameters

### `wszForLogicalPath` [in]

A null-terminated wide character string containing the logical path of the component (managed by the express writer) that requires a dependency.

### `wszForComponentName` [in]

A null-terminated wide character string containing the component (managed by the express writer) that requires a dependency.

### `onWriterId` [in]

A
[VSS_ID](https://learn.microsoft.com/windows/desktop/VSS/volume-shadow-copy-api-data-types) (GUID) value that specifies the writer class of the express writer managing the component on which the current component depends.

### `wszOnLogicalPath` [in]

The logical path of the component (managed by the express writer identified by *onWriterId*) on which the current component depends.

### `wszOnComponentName` [in]

The name of the component (managed by the express writer identified by *onWriterId*) on which the current component depends.

## Return value

The following are the valid return codes for this method.

| Value | Meaning |
| --- | --- |
| **S_OK** | The operation was successful. |
| **E_INVALIDARG** | One of the parameter values is not valid. |
| **E_OUTOFMEMORY** | The caller is out of memory or other system resources. |
| **VSS_E_INVALID_XML_DOCUMENT** | The XML document is not valid. Check the event log for details. For more information, see [Event and Error Handling Under VSS](https://learn.microsoft.com/windows/desktop/VSS/event-and-error-handling-under-vss). |
| **VSS_E_OBJECT_NOT_FOUND** | The component specified by *wszForLogicalPath* and *wszForComponentName* does not exist. |
| **VSS_E_UNEXPECTED** | Unexpected error. The error code is logged in the error log file. For more information, see [Event and Error Handling Under VSS](https://learn.microsoft.com/windows/desktop/VSS/event-and-error-handling-under-vss).<br><br>**Windows Server 2008, Windows Vista, Windows Server 2003 and Windows XP:** This value is not supported until Windows Server 2008 R2 and Windows 7. E_UNEXPECTED is used instead. |

## See also

[IVssCreateExpressWriterMetadata](https://learn.microsoft.com/windows/desktop/api/vswriter/nl-vswriter-ivsscreateexpresswritermetadata)