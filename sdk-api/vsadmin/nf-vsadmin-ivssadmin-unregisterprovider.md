# IVssAdmin::UnregisterProvider

## Description

The **UnregisterProvider**
method unregisters an existing provider.

## Parameters

### `ProviderId` [in]

The **VSS_ID** of the provider.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | The provider was unregistered successfully. |
| **VSS_E_PROVIDER_IN_USE** | The provider is in use. |
| **VSS_E_PROVIDER_NOT_REGISTERED** | The provider is not registered. |
| **E_OUTOFMEMORY** | Out of memory or other system resources. |
| **VSS_E_UNEXPECTED** | Unexpected error. The error code is logged in the error log file. For more information, see [Event and Error Handling Under VSS](https://learn.microsoft.com/windows/desktop/VSS/event-and-error-handling-under-vss).<br><br>**Windows Server 2008, Windows Vista, Windows Server 2003 and Windows XP:** This value is not supported until Windows Server 2008 R2 and Windows 7. E_UNEXPECTED is used instead. |

## See also

[IVssAdmin](https://learn.microsoft.com/windows/desktop/api/vsadmin/nn-vsadmin-ivssadmin)

[RegisterProvider](https://learn.microsoft.com/windows/desktop/api/vsadmin/nf-vsadmin-ivssadmin-registerprovider)