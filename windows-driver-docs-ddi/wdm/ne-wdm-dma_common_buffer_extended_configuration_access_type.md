## Description

Specifies permissions for hardware access for a common buffer being created when the **ConfigType** field of the [DMA_COMMON_BUFFER_EXTENDED_CONFIGURATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-dma_common_buffer_extended_configuration) structure is **CommonBufferConfigTypeHardwareAccessPermissions**.

## Constants

### `CommonBufferHardwareAccessReadOnly`

Hardware has read access to the common buffer.

### `CommonBufferHardwareAccessWriteOnly`

Hardware has write access to the common buffer.

### `CommonBufferHardwareAccessReadWrite`

Hardware has both read and write access to the common buffer.

### `CommonBufferHardwareAccessMax`

The number of common buffer hardware access values for this enumeration type that represent actual access types.

## See also

[DMA_COMMON_BUFFER_EXTENDED_CONFIGURATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-dma_common_buffer_extended_configuration)

[PCREATE_COMMON_BUFFER_FROM_MDL](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pcreate-common-buffer-from-mdl)