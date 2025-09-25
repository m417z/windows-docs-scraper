# StorPortFreeRegistryBuffer function

## Description

The **StorPortFreeRegistryBuffer** routine frees the buffer that was allocated for storing registry data.

## Parameters

### `HwDeviceExtension` [in]

A pointer to the hardware device extension. This is a per HBA storage area that the port driver allocates and initializes on behalf of the miniport driver. Miniport drivers usually store HBA-specific information in this extension, such as the state of the HBA and the mapped access ranges for the HBA. This area is available to the miniport driver immediately after the miniport driver calls [StorPortInitialize](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportinitialize). The port driver frees this memory when it removes the device. The miniport driver must be running at IRQL PASSIVE_LEVEL when it calls this routine.

### `Buffer` [in]

Pointer to the buffer to be freed.

## Return value

None

## Remarks

The **StorPortFreeRegistryBuffer** routine frees the buffer that was allocated by [StorPortAllocateRegistryBuffer](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportallocateregistrybuffer). Miniport drivers can only have one registry buffer open at a time. After the miniport driver calls the **StorPortFreeRegistryBuffer** routine, subsequent calls by the miniport driver to **StorPortAllocateRegistryBuffer** will succeed.

## See also

[StorPortAllocateRegistryBuffer](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportallocateregistrybuffer)