# StorPortAllocateRegistryBuffer function

## Description

The **StorPortAllocateRegistryBuffer** routine is called by the miniport driver to allocate a buffer that can be used to read and write registry data.

## Parameters

### `HwDeviceExtension` [in]

A pointer to the hardware device extension. This is a per HBA storage area that the port driver allocates and initializes on behalf of the miniport driver. Miniport drivers usually store HBA-specific information in this extension, such as the state of the HBA and the mapped access ranges for the HBA. This area is available to the miniport driver immediately after the miniport driver calls [StorPortInitialize](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportinitialize). The port driver frees this memory when it removes the device. The miniport driver must be running at IRQL PASSIVE_LEVEL when it calls this routine.

### `Length` [in]

Pointer to a long that indicates, on input, the length in bytes of the registry buffer that the caller requires. On output, *Length* is updated to reflect the actual size in bytes of the buffer that was allocated.

## Return value

**StorPortAllocateRegistryBuffer** returns a pointer to the registry buffer that the caller requested, or **NULL** if some error prevents the memory from being allocated.

## Remarks

Each instantiation of a miniport driver can only have one registry buffer allocated at a time. If a miniport driver attempts to allocate more than one registry buffer, the allocation will fail and **StorPortAllocateRegistryBuffer** will return **NULL**.

## See also

[StorPortFreeRegistryBuffer](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportfreeregistrybuffer)