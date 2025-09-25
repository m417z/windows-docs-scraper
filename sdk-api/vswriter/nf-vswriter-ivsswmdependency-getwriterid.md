# IVssWMDependency::GetWriterId

## Description

The **GetWriterId** method retrieves the class ID of a writer containing a component that the current component depends on in an explicit writer-component dependency.

## Parameters

### `pWriterId`

The class ID of a writer that manages a component on which the current component depends.

## Return value

This method can return one of these values.

| Value | Meaning |
| --- | --- |
| **S_OK** | Successfully returned the class ID of the writer managing the component that the current component depends on. |
| **S_FALSE** | No writer can be found that manages the component that the current component depends on. |
| **E_INVALIDARG** | The pointer *pWriterId* points to unallocated memory. |
| **E_OUTOFMEMORY** | The caller is out of memory or other system resources. |
| **VSS_E_INVALID_XML_DOCUMENT** | The XML document is not valid. Check the event log for details. For more information, see [Event and Error Handling Under VSS](https://learn.microsoft.com/windows/desktop/VSS/event-and-error-handling-under-vss). |
| **VSS_E_UNEXPECTED** | Unexpected error. The error code is logged in the error log file. For more information, see [Event and Error Handling Under VSS](https://learn.microsoft.com/windows/desktop/VSS/event-and-error-handling-under-vss).<br><br>**Windows Server 2008, Windows Vista, Windows Server 2003 and Windows XP:** This value is not supported until Windows Server 2008 R2 and Windows 7. E_UNEXPECTED is used instead. |

## Remarks

A dependency does not indicate an order of preference between the component with the documented dependencies and the components it depends on. A dependency merely indicates that the component and the components it depends on must always be backed up or restored together.

It is possible to have multiple instances of a given writer class; however, any component's logical path and name should be unique.

If there are multiple instances of a writer class, it will be necessary to use logical path and component name information to identify the instance managing the component that the current component depends on.

## See also

[IVssWMComponent::GetDependency](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-ivsswmcomponent-getdependency)

[IVssWMDependency](https://learn.microsoft.com/windows/desktop/api/vswriter/nl-vswriter-ivsswmdependency)

[IVssWMDependency::GetComponentName](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-ivsswmdependency-getcomponentname)

[IVssWMDependency::GetLogicalPath](https://learn.microsoft.com/windows/desktop/api/vswriter/nf-vswriter-ivsswmdependency-getlogicalpath)