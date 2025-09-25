# PXE_PROVIDER structure

## Description

Describes a provider.

## Members

### `uSizeOfStruct`

Size of the **PXE_PROVIDER** structure.

### `pwszName`

Address of a null-terminated string that specifies the display name of the provider. This name is displayed
to the user and must be unique among registered providers.

### `pwszFilePath`

Address of a null-terminated string that specifies the full path to the provider DLL.

### `bIsCritical`

Indicates whether the provider is critical. If a critical provider fails, the WDS server will also
fail.

### `uIndex`

Index of a provider in the list of registered providers.

## See also

[PxeProviderEnumNext](https://learn.microsoft.com/windows/desktop/api/wdspxe/nf-wdspxe-pxeproviderenumnext)

[PxeProviderFreeInfo](https://learn.microsoft.com/windows/desktop/api/wdspxe/nf-wdspxe-pxeproviderfreeinfo)

[Windows Deployment Services Structures](https://learn.microsoft.com/windows/desktop/Wds/windows-deployment-services-structures)