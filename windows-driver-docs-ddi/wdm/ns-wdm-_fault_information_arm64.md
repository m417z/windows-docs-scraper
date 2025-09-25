# _FAULT_INFORMATION_ARM64 structure

## Description

Describes fault information for an ARM64 system.

## Members

### `DomainHandle`

The handle to the DMA domain that the caller obtained from a previous call to [**PGET_DMA_DOMAIN**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pget_dma_domain).

### `FaultAddress`

### `PhysicalDeviceObject`

 A pointer the physical device object (PDO) in the device stack of the device.

### `InputMappingId`

The input mapping base for the device's desired stream.

### `Flags`

A bitwise of [**FAULT_INFORMATION_ARM64_FLAGS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_fault_information_arm64_flags) flags.

### `Type`

A bitwise of [**FAULT_INFORMATION_ARM64_TYPE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ne-wdm-_fault_information_arm64_type) flags.

### `IommuBaseAddress`

## Remarks

## See also