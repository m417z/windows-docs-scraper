# PxeProviderFreeInfo function

## Description

Frees memory allocated by the
[PxeProviderEnumNext](https://learn.microsoft.com/windows/desktop/api/wdspxe/nf-wdspxe-pxeproviderenumnext) function.

## Parameters

### `pProvider` [in]

Address of a [PXE_PROVIDER](https://learn.microsoft.com/windows/desktop/api/wdspxe/ns-wdspxe-pxe_provider) structure returned from the
[PxeProviderEnumNext](https://learn.microsoft.com/windows/desktop/api/wdspxe/nf-wdspxe-pxeproviderenumnext) function.

## Return value

If the function succeeds, the return value is **ERROR_SUCCESS**.

## See also

[PXE_PROVIDER](https://learn.microsoft.com/windows/desktop/api/wdspxe/ns-wdspxe-pxe_provider)

[PxeProviderEnumNext](https://learn.microsoft.com/windows/desktop/api/wdspxe/nf-wdspxe-pxeproviderenumnext)

[Windows Deployment Services Server Functions](https://learn.microsoft.com/windows/desktop/Wds/windows-deployment-services-server-functions)