# IVssWMComponent::GetDependency

## Description

The
**GetDependency** method returns an instance of the
[IVssWMDependency](https://learn.microsoft.com/windows/desktop/api/vswriter/nl-vswriter-ivsswmdependency) interface containing accessors for obtaining information about explicit writer-component dependencies of one of the current components.

## Parameters

### `iDependency` [in]

Offset between 0 and *n*-1, where *n* is the number of dependencies associated with this component as specified by the **cDependencies** member of the
[VSS_COMPONENTINFO](https://learn.microsoft.com/windows/desktop/api/vsbackup/ns-vsbackup-vss_componentinfo) object returned by
[IVssWMComponent::GetComponentInfo](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-ivsswmcomponent-getcomponentinfo).

### `ppDependency` [out]

Doubly indirect pointer to an instance of the
[IVssWMDependency](https://learn.microsoft.com/windows/desktop/api/vswriter/nl-vswriter-ivsswmdependency) interface.

## Return value

This method can return one of these values.

| Value | Meaning |
| --- | --- |
| **S_OK** | The operation was successful. |
| **E_INVALIDARG** | One of the parameter values is not valid. |
| **E_OUTOFMEMORY** | The caller is out of memory or other system resources. |
| **VSS_E_INVALID_XML_DOCUMENT** | The XML document is not valid. Check the event log for details. For more information, see [Event and Error Handling Under VSS](https://learn.microsoft.com/windows/desktop/VSS/event-and-error-handling-under-vss). |
| **VSS_E_OBJECT_NOT_FOUND** | The component specified by the index *iDependency* does not exist. |
| **VSS_E_UNEXPECTED** | Unexpected error. The error code is logged in the error log file. For more information, see [Event and Error Handling Under VSS](https://learn.microsoft.com/windows/desktop/VSS/event-and-error-handling-under-vss).<br><br>**Windows Server 2008, Windows Vista, Windows Server 2003 and Windows XP:** This value is not supported until Windows Server 2008 R2 and Windows 7. E_UNEXPECTED is used instead. |

## Remarks

The caller is responsible for calling [IUnknown::Release](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-release) to release system resources held by the returned
[IVssWMFiledesc](https://learn.microsoft.com/windows/desktop/api/vswriter/nl-vswriter-ivsswmfiledesc) object.

## See also

[IVssWMComponent](https://learn.microsoft.com/windows/desktop/api/vsbackup/nl-vsbackup-ivsswmcomponent)

[IVssWMComponent::GetComponentInfo](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-ivsswmcomponent-getcomponentinfo)

[IVssWMDependency](https://learn.microsoft.com/windows/desktop/api/vswriter/nl-vswriter-ivsswmdependency)

[VSS_COMPONENTINFO](https://learn.microsoft.com/windows/desktop/api/vsbackup/ns-vsbackup-vss_componentinfo)