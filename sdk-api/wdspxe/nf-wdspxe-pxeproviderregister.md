# PxeProviderRegister function

## Description

Registers a provider with the system. Providers use this function during installation to
register with the system. On successful registration, a registry key handle is returned that should be used to
store configuration information.

## Parameters

### `pszProviderName` [in]

Address of a null terminated string that specifies the display name of the provider. This name is
displayed to the user and must be unique among registered providers.

### `pszModulePath` [in]

Address of a null-terminated string that specifies the full path to the provider DLL.

### `Index` [in]

Index into the list of providers. Any existing providers are shifted down if necessary. The administrator
can rearrange the providers as needed, so no assumptions should be made about the order of providers.

| Value | Meaning |
| --- | --- |
| **PXE_REG_INDEX_TOP**<br><br>0 | Add the provider to the top of the list to be the first to receive client requests. |
| **PXE_REG_INDEX_BOTTOM**<br><br>0xFFFFFFFF | Add the provider to the bottom of the list. |

### `bIsCritical` [in]

Indicates whether the provider is critical. If a critical provider fails, the WDS server will also
fail.

### `phProviderKey` [out]

Address of a **HKEY** where the configuration should be stored. The provider will
receive a handle to this same key as the *hProviderKey* parameter to its
[PxeProviderInitialize](https://learn.microsoft.com/windows/desktop/Wds/pxeproviderinitialize) callback.

## Return value

If the function succeeds, the return value is **ERROR_SUCCESS**.

## See also

[PxeProviderInitialize](https://learn.microsoft.com/windows/desktop/Wds/pxeproviderinitialize)

[PxeProviderUnRegister](https://learn.microsoft.com/windows/desktop/api/wdspxe/nf-wdspxe-pxeproviderunregister)

[Windows Deployment Services Server Functions](https://learn.microsoft.com/windows/desktop/Wds/windows-deployment-services-server-functions)