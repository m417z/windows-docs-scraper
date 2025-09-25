# _NDIS_OPEN_NDK_ADAPTER_PARAMETERS structure

## Description

The **NDIS_OPEN_NDK_ADAPTER_PARAMETERS** structure specifies parameters to open an NDK adapter instance on the NDK-capable miniport adapter.

## Members

### `Version`

The version of the NDK provider interface ([NDK_VERSION](https://learn.microsoft.com/windows/win32/api/ndkinfo/ns-ndkinfo-ndk_version)) that is to be used.

For NDIS 6.30 (Windows Server 2012), the major version number is 1. The minor version number is 1.

For NDIS 6.40 (Windows Server 2012 R2), the major version number is 1. The minor version number is 2.

### `SwitchId`

### `VPortId`

## Remarks

To open an NDK adapter, NDIS calls the [OPEN_NDK_ADAPTER_HANDLER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndisndk/nc-ndisndk-open_ndk_adapter_handler) function and passes it a pointer to an **NDIS_OPEN_NDK_ADAPTER_PARAMETERS** structure that defines the NDK adapter open parameters.

## See also

[NDK_VERSION](https://learn.microsoft.com/windows/win32/api/ndkinfo/ns-ndkinfo-ndk_version)

[OPEN_NDK_ADAPTER_HANDLER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndisndk/nc-ndisndk-open_ndk_adapter_handler)