## Description

Defines a configuration that further describes constraints and features when creating a common buffer. The driver can provide an array of **DMA_COMMON_BUFFER_EXTENDED_CONFIGURATION** structures in the [*CreateCommonBufferFromMdl*](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pcreate-common-buffer-from-mdl) callback routine.

## Members

### `ConfigType`

A [**DMA_COMMON_BUFFER_EXTENDED_CONFIGURATION_TYPE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ne-wdm-_dma_common_buffer_extended_configuration_type)-typed value that indicates the type of common buffer extended configuration this instance represents.

### `LogicalAddressLimits`

When *ConfigType* is **CommonBufferConfigTypeLogicalAddressLimits**, describes the logical address limits for the common buffer being created.

### `LogicalAddressLimits.MinimumAddress`

Provides the (inclusive) minimum starting logical address of the common buffer being created.

### `LogicalAddressLimits.MaximumAddress`

Provides the (inclusive) maximum final logical address of the common buffer being created.

### `SubSection`

When *ConfigType* is **CommonBufferConfigTypeSubSection**, describes the subsection within a backing MDL that should be used to back the common buffer being created.

A subsection must only be contained within a single MDL in an MDL chain.

### `SubSection.Offset`

Provides the offset into the MDL to indicate the starting address of the common buffer. **Must be page-aligned.**

### `SubSection.Length`

Provides the length of the common buffer subsection. **Must be page-aligned.**

### `HardwareAccessType`

When *ConfigType* is **CommonBufferConfigTypeHardwareAccessPermissions**, this is a [**DMA_COMMON_BUFFER_EXTENDED_CONFIGURATION_ACCESS_TYPE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ne-wdm-dma_common_buffer_extended_configuration_access_type)-typed value that describes the hardware access permissions for the common buffer being created.

Common buffer creation fails if the access type is not possible on the system. **ReadOnly** and **WriteOnly** are only permissible if the DMA Adapter is using DMA Remapping.

### `Reserved`

This field is unused.

## Remarks

The extended configurations are an optional parameter for the [*CreateCommonBufferFromMdl*](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pcreate-common-buffer-from-mdl) callback routine.

If no extended configurations are provided, common buffer creation uses the entire MDL as backing memory, with a minimum logical address of zero and a maximum logical address defined by the [**DMA_ADAPTER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_dma_adapter) being used.

## See also

[**DMA_COMMON_BUFFER_EXTENDED_CONFIGURATION_TYPE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ne-wdm-_dma_common_buffer_extended_configuration_type) enumeration

[**DMA_COMMON_BUFFER_EXTENDED_CONFIGURATION_ACCESS_TYPE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ne-wdm-dma_common_buffer_extended_configuration_access_type) enumeration

[*PCREATE_COMMON_BUFFER_FROM_MDL*](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pcreate-common-buffer-from-mdl) callback routine