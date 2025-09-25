# IVssWMComponent::GetComponentInfo

## Description

The
**GetComponentInfo** method obtains basic information about the specified writer metadata component.

## Parameters

### `ppInfo` [out]

Doubly indirect pointer to a
[VSS_COMPONENTINFO](https://learn.microsoft.com/windows/desktop/api/vsbackup/ns-vsbackup-vss_componentinfo) structure containing the returned component information.

## Return value

The following are the valid return codes for this method.

| Value | Meaning |
| --- | --- |
| **S_OK** | Successfully returned the component information. |
| **E_INVALIDARG** | One of the parameter values is not valid. |
| **E_OUTOFMEMORY** | The caller is out of memory or other system resources. |
| **VSS_E_INVALID_XML_DOCUMENT** | The XML document is not valid. Check the event log for details. For more information, see [Event and Error Handling Under VSS](https://learn.microsoft.com/windows/desktop/VSS/event-and-error-handling-under-vss). |
| **VSS_E_UNEXPECTED** | Unexpected error. The error code is logged in the error log file. For more information, see [Event and Error Handling Under VSS](https://learn.microsoft.com/windows/desktop/VSS/event-and-error-handling-under-vss).<br><br>**Windows Server 2008, Windows Vista, Windows Server 2003 and Windows XP:** This value is not supported until Windows Server 2008 R2 and Windows 7. E_UNEXPECTED is used instead. |

## Remarks

The caller is responsible for freeing the returned
[VSS_COMPONENTINFO](https://learn.microsoft.com/windows/desktop/api/vsbackup/ns-vsbackup-vss_componentinfo) structure by calling
[IVssWMComponent::FreeComponentInfo](https://learn.microsoft.com/windows/desktop/api/vsbackup/nf-vsbackup-ivsswmcomponent-freecomponentinfo).

## See also

[IVssWMComponent](https://learn.microsoft.com/windows/desktop/api/vsbackup/nl-vsbackup-ivsswmcomponent)

[VSS_COMPONENTINFO](https://learn.microsoft.com/windows/desktop/api/vsbackup/ns-vsbackup-vss_componentinfo)