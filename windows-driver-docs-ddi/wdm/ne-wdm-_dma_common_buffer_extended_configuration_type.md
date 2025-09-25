## Description

Provides the types of optional configurations that can be provided when creating a common buffer from an MDL. The configuration values corresponding to the types are held in the [DMA_COMMON_BUFFER_EXTENDED_CONFIGURATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-dma_common_buffer_extended_configuration) structure.

## Constants

### `CommonBufferConfigTypeLogicalAddressLimits`

The associated configuration will contain information about the limits of logical address that can be used to fulfill common buffer creation.

### `CommonBufferConfigTypeSubSection`

The associated configuration will contain information about the subsection within the MDL to use to create the common buffer.

### `CommonBufferConfigTypeHardwareAccessPermissions`

The associated configuration will contain information about the access permissions for the hardware.

### `CommonBufferConfigTypeMax`

The number of common buffer extended configuration values for this enumeration type that represent actual common buffer configuration types.

## See also

[DMA_COMMON_BUFFER_EXTENDED_CONFIGURATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-dma_common_buffer_extended_configuration)

[PCREATE_COMMON_BUFFER_FROM_MDL](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pcreate-common-buffer-from-mdl)