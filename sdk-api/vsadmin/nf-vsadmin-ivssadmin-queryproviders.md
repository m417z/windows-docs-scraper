# IVssAdmin::QueryProviders

## Description

The **QueryProviders**
method queries all registered providers.

## Parameters

### `ppEnum` [out]

The address of an [IVssEnumObject](https://learn.microsoft.com/windows/desktop/api/vss/nn-vss-ivssenumobject) interface pointer,
which is initialized on return. Callers must release the interface.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| ****S_OK**** | The query was returned successfully. |
| ****E_INVALIDARG**** | One or more of the parameter values is not valid. |
| ****E_OUTOFMEMORY**** | Out of memory or other system resources. |
| ****E_ACCESSDENIED**** | The caller is not an administrator. |
| ****E_UNEXPECTED**** | An unexpected error occurred. |
| ****VSS_E_OBJECT_NOT_FOUND**** | An unexpected provider error occurred. |
| **VSS_E_PROVIDER_VETO** | Expected provider error. The provider logged the error in the event log. For more information, see [Event and Error Handling Under VSS](https://learn.microsoft.com/windows/desktop/VSS/event-and-error-handling-under-vss). |
| **VSS_E_UNEXPECTED** | Unexpected error. The error code is logged in the error log file. For more information, see [Event and Error Handling Under VSS](https://learn.microsoft.com/windows/desktop/VSS/event-and-error-handling-under-vss).<br><br>**Windows Server 2008, Windows Vista, Windows Server 2003 and Windows XP:** This value is not supported until Windows Server 2008 R2 and Windows 7. E_UNEXPECTED is used instead. |
| **VSS_E_UNEXPECTED_PROVIDER_ERROR** | Unexpected provider error. The error code is logged in the error log. For more information, see [Event and Error Handling Under VSS](https://learn.microsoft.com/windows/desktop/VSS/event-and-error-handling-under-vss). |

## Remarks

Calling the [IVssEnumObject::Next](https://learn.microsoft.com/windows/desktop/api/vss/nf-vss-ivssenumobject-next) method on the
[IVssEnumObject](https://learn.microsoft.com/windows/desktop/api/vss/nn-vss-ivssenumobject) interface returned though the
*ppEnum* parameter will return
[VSS_OBJECT_PROP](https://learn.microsoft.com/windows/desktop/api/vss/ns-vss-vss_object_prop) structures containing a
[VSS_PROVIDER_PROP](https://learn.microsoft.com/windows/desktop/api/vss/ns-vss-vss_provider_prop) structure for each registered
provider.

## See also

[IVssAdmin](https://learn.microsoft.com/windows/desktop/api/vsadmin/nn-vsadmin-ivssadmin)