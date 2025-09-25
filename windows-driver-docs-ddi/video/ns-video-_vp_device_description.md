# _VP_DEVICE_DESCRIPTION structure

## Description

The VP_DEVICE_DESCRIPTION structure describes the attributes of the physical device for which a driver is requesting a DMA object.

## Members

### `ScatterGather`

If **TRUE**, indicates that the device supports scatter/gather DMA. If **FALSE**, the device does not support scatter/gather DMA.

### `Dma32BitAddresses`

If **TRUE**, specifies that 32-bit addresses are being used for DMA operations.

### `Dma64BitAddresses`

If **TRUE**, specifies that 64-bit addresses are being used for DMA operations.

### `MaximumLength`

Specifies the maximum number of bytes the device can handle in each DMA operation.

## Remarks

This structure is available in Windows XP and later.