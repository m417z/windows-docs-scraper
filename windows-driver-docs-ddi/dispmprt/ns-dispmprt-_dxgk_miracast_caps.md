# _DXGK_MIRACAST_CAPS structure

## Description

Used by a display miniport driver to identify capabilities of a Miracast device.

## Members

### `MaxChunkPrivateDriverDataSize`

The maximum size, in bytes, of the private data that the display miniport driver will pass when it reports a [DXGK_INTERRUPT_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ne-d3dkmddi-_dxgk_interrupt_type) interrupt type of **DXGK_INTERRUPT_MICACAST_CHUNK_PROCESSING_COMPLETE**.

### `Flags`

### `Flags.HdcpSupport`

Indicates whether the display adapter supports the Miracast High-bandwidth Digital Content Protection (HDCP) feature.

### `Flags.Reserved`

Reserved for system use. The display miniport driver must set this value to zero.

### `Flags.Value`

Holds a 32-bit value that identifies the capabilities of the Miracast device.

## See also

[DXGK_INTERRUPT_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ne-d3dkmddi-_dxgk_interrupt_type)