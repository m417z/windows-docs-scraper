# PxeProviderEnumNext function

## Description

Enumerates registered providers.

## Parameters

### `hEnum` [in]

**HANDLE** returned by the
[PxeProviderEnumFirst](https://learn.microsoft.com/windows/desktop/api/wdspxe/nf-wdspxe-pxeproviderenumfirst) function.

### `ppProvider` [out]

Address of a [PXE_PROVIDER](https://learn.microsoft.com/windows/desktop/api/wdspxe/ns-wdspxe-pxe_provider) structure with the
**uSizeOfStruct** member filled in with the size of the structure. On return this
structure is filled in with provider information. This structure can be freed with the
[PxeProviderFreeInfo](https://learn.microsoft.com/windows/desktop/api/wdspxe/nf-wdspxe-pxeproviderfreeinfo) function.

## Return value

If the function succeeds, the return value is **ERROR_SUCCESS**.

## See also

[PXE_PROVIDER](https://learn.microsoft.com/windows/desktop/api/wdspxe/ns-wdspxe-pxe_provider)

[PxeProviderEnumClose](https://learn.microsoft.com/windows/desktop/api/wdspxe/nf-wdspxe-pxeproviderenumclose)

[PxeProviderEnumFirst](https://learn.microsoft.com/windows/desktop/api/wdspxe/nf-wdspxe-pxeproviderenumfirst)

[PxeProviderFreeInfo](https://learn.microsoft.com/windows/desktop/api/wdspxe/nf-wdspxe-pxeproviderfreeinfo)

[Windows Deployment Services Server Functions](https://learn.microsoft.com/windows/desktop/Wds/windows-deployment-services-server-functions)