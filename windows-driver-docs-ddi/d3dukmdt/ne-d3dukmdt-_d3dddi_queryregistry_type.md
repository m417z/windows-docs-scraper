# D3DDDI_QUERYREGISTRY_TYPE enumeration

## Description

**D3DDDI_QUERYREGISTRY_TYPE** enumeration values indicate which data to retrieve through [**pfnQueryAdapterInfoCb2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_queryadapterinfocb2) for [**D3DDDI_QUERYADAPTERTYPE_QUERYREGISTRY**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ne-d3dumddi-_d3dddi_queryadaptertype).

## Constants

### `D3DDDI_QUERYREGISTRY_SERVICEKEY`

Indicates to retrieve registry data from the service hive. The registry path is `\REGISTRY\MACHINE\SYSTEM\CurrentControlSet\Services\`.

See [Introduction to Registry Keys for Drivers](https://learn.microsoft.com/windows-hardware/drivers/wdf/introduction-to-registry-keys-for-drivers) for more details, where it is referred to as the driver's Parameters key.

### `D3DDDI_QUERYREGISTRY_ADAPTERKEY`

Indicates to retrieve registry data from the adapter hive. The registry path is `\REGISTRY\MACHINE\SYSTEM\CurrentControlSet\Control\Class\{4d36e968-e325-11ce-bfc1-08002be10318}\`.

See [Introduction to Registry Keys for Drivers](https://learn.microsoft.com/windows-hardware/drivers/wdf/introduction-to-registry-keys-for-drivers) for more details, where it is referred to as the driver's Software key.

### `D3DDDI_QUERYREGISTRY_DRIVERSTOREPATH`

Indicates to retrieve the driver store path for the adapter. The full driver store path is returned in [**D3DDDI_QUERYREGISTRY_INFO::OutputString**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ns-d3dukmdt-_d3dddi_queryregistry_info). The path is returned in the form of `:\system32\DriverStore\FileRepository\`.

### `D3DDDI_QUERYREGISTRY_DRIVERIMAGEPATH`

Indicates to retrieve the driver image path, which includes the driver name associated with [**DriverEntry**](https://learn.microsoft.com/windows-hardware/drivers/display/driverentry-of-display-miniport-driver).

### `D3DDDI_QUERYREGISTRY_MAX`

Max value for this enum; don't use.

## See also

[**D3DDDI_QUERYADAPTERTYPE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ne-d3dumddi-_d3dddi_queryadaptertype)

[**D3DDDI_QUERYREGISTRY_INFO**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ns-d3dukmdt-_d3dddi_queryregistry_info)

[**pfnQueryAdapterInfoCb2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_queryadapterinfocb2)