# StorPortFreeDeviceBase function

## Description

**StorPortFreeDeviceBase** frees a range of device I/O memory that was mapped by [StorPortGetDeviceBase](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportgetdevicebase).

## Parameters

### `HwDeviceExtension` [in]

A pointer to the hardware device extension. This is a per HBA storage area that the port driver allocates and initializes on behalf of the miniport driver. Miniport drivers usually store HBA-specific information in this extension, such as the state of the HBA and the mapped access ranges for the HBA. This area is available to the miniport driver immediately after the miniport driver calls [StorPortInitialize](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportinitialize). The port driver frees this memory when it removes the device.

### `MappedAddress` [in]

Pointer to region of memory to be freed.

## Return value

None

## See also

[ScsiPortFreeDeviceBase](https://learn.microsoft.com/windows-hardware/drivers/ddi/srb/nf-srb-scsiportfreedevicebase)

[StorPortGetDeviceBase](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportgetdevicebase)