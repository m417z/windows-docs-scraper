# IVssAdmin::RegisterProvider

## Description

The **RegisterProvider** method
registers a new shadow copy provider.

## Parameters

### `pProviderId` [in]

The **VSS_ID** that uniquely and persistently identifies the provider. After it is
defined, the *ProviderId* parameter should remain the same, even when the software
revision is updated. A *ProviderId* parameter should be changed only when the
functionality changes enough that both providers would be active on the same system. A requester may use the
*ProviderId* parameter to request that a specific provider be used in a shadow copy
creation.

### `ClassId` [in]

The CLSID of the provider.

### `pwszProviderName` [in]

The name of the provider.

### `eProviderType` [in]

A
[VSS_PROVIDER_TYPE](https://learn.microsoft.com/windows/desktop/api/vss/ne-vss-vss_provider_type) enumeration value that specifies the provider type. Note that **VSS_PROV_HARDWARE** is not a valid provider type on Windows client operating system versions. Hardware providers will run only on Windows server operating system versions.

### `pwszProviderVersion` [in]

The version of the provider.

### `ProviderVersionId` [in]

The **VSS_ID** that uniquely identifies this version of the provider. The
combination of the *pProviderId* and *ProviderVersionId*
parameters should be unique. The *ProviderVersionId* parameter can be the same as the
*ProviderVersionId* parameter of another provider.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| ****S_OK**** | The provider was registered successfully. |
| ****E_INVALIDARG**** | One or more of the parameter values is not valid. For example, **VSS_PROV_HARDWARE** is not a valid provider type on Windows client operating system versions. |
| ****E_OUTOFMEMORY**** | Out of memory or other system resources. |
| ****E_ACCESSDENIED**** | The caller is not an administrator. |
| ****VSS_E_PROVIDER_ALREADY_REGISTERED**** | The provider has already been registered on this computer. |
| **VSS_E_UNEXPECTED** | Unexpected error. The error code is logged in the error log file. For more information, see [Event and Error Handling Under VSS](https://learn.microsoft.com/windows/desktop/VSS/event-and-error-handling-under-vss).<br><br>**Windows Server 2008, Windows Vista, Windows Server 2003 and Windows XP:** This value is not supported until Windows Server 2008 R2 and Windows 7. E_UNEXPECTED is used instead. |

## Remarks

If the hardware provider is updated, the setup application should call the
[UnregisterProvider](https://learn.microsoft.com/windows/desktop/api/vsadmin/nf-vsadmin-ivssadmin-unregisterprovider) method to unregister the
outdated version, and then call the
**RegisterProvider** method to register the
updated provider.

**Note** Hardware providers can only be registered on Windows Server operating systems.

## See also

[IVssAdmin](https://learn.microsoft.com/windows/desktop/api/vsadmin/nn-vsadmin-ivssadmin)

[UnregisterProvider](https://learn.microsoft.com/windows/desktop/api/vsadmin/nf-vsadmin-ivssadmin-unregisterprovider)