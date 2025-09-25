# PxeProviderEnumFirst function

## Description

Starts an enumeration of registered providers.

## Parameters

### `phEnum` [out]

Address of a **HANDLE** that on successful return can be used with the
[PxeProviderEnumNext](https://learn.microsoft.com/windows/desktop/api/wdspxe/nf-wdspxe-pxeproviderenumnext) function to enumerate
providers. When the enumeration handle is no longer needed, use the
[PxeProviderEnumClose](https://learn.microsoft.com/windows/desktop/api/wdspxe/nf-wdspxe-pxeproviderenumclose) function to close the
enumeration.

## Return value

If the function succeeds, the return value is **ERROR_SUCCESS**.

## See also

[PxeProviderEnumClose](https://learn.microsoft.com/windows/desktop/api/wdspxe/nf-wdspxe-pxeproviderenumclose)

[PxeProviderEnumNext](https://learn.microsoft.com/windows/desktop/api/wdspxe/nf-wdspxe-pxeproviderenumnext)

[Windows Deployment Services Server Functions](https://learn.microsoft.com/windows/desktop/Wds/windows-deployment-services-server-functions)