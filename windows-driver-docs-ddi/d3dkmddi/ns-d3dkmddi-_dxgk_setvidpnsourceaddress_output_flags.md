# DXGK_SETVIDPNSOURCEADDRESS_OUTPUT_FLAGS structure

## Description

The **DXGK_SETVIDPNSOURCEADDRESS_OUTPUT_FLAGS** structure contains the flags used to set the VidPN source address.

## Members

### `PrePresentNeeded`

Indicates that the driver must be called again at the PASSIVE_LEVEL to perform the requested operation.

### `HwFlipQueueDrainNeeded`

Indicates that the OS should attempt to submit the flip request again after all pending flips on planes affected by this flip are finished and once the target time is reached. See [Hardware flip queue](https://learn.microsoft.com/windows-hardware/drivers/display/hardware-flip-queue) for more information.

### `HwFlipQueueDrainAllPlanes`

Indicates that the display hardware may require completion of pending flips on all planes, not just the ones referenced by the incoming flip request. In this case, the driver should set both the **HwFlipQueueDrainNeeded** and **HwFlipQueueDrainAllPlanes**. See [Hardware flip queue](https://learn.microsoft.com/windows-hardware/drivers/display/hardware-flip-queue) for more information.

### `HwFlipQueueDrainAllSources`

Indicates that the display hardware may require completion of pending flips on all VidPn sources in order to reallocate internal resources. In this case, the driver should set both the **HwFlipQueueDrainNeeded** and **HwFlipQueueDrainAllSources** flags. See [Hardware flip queue](https://learn.microsoft.com/windows-hardware/drivers/display/hardware-flip-queue) for more information.

### `Reserved`

This member is reserved and should be set to zero.

### `Value`

An alternative way to access the bits.

## See also

[**DXGKARG_SETVIDPNSOURCEADDRESSWITHMULTIPLANEOVERLAY3**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkarg_setvidpnsourceaddresswithmultiplaneoverlay3)

[**DXGKDDI_SETVIDPNSOURCEADDRESSWITHMULTIPLANEOVERLAY3**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_setvidpnsourceaddresswithmultiplaneoverlay3)