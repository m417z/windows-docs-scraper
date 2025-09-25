# StorPortGetUncachedExtension function

## Description

The **StorPortGetUncachedExtension** routine allocates an uncached common buffer to be shared by the CPU and the device.

## Parameters

### `HwDeviceExtension`

A pointer to the hardware device extension. This is a per HBA storage area that the port driver allocates and initializes on behalf of the miniport driver. Miniport drivers usually store HBA-specific information in this extension, such as the state of the HBA and the mapped access ranges for the HBA. This area is available to the miniport driver immediately after the miniport driver calls [StorPortInitialize](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportinitialize). The port driver frees this memory when it removes the device.

### `ConfigInfo`

Specifies information about the HBA's DMA capabilities. The following members must be filled in: **DmaChannel** or **DmaPort**, **DmaWidth**, **DmaSpeed**, **MaximumTransferLength**, **ScatterGather**, **Master** set to **TRUE**, **NumberOfPhysicalBreaks**, **AdapterInterfaceType**, **Dma32BitAddresses**, **Dma64BitAddresses**, **SystemIoBusNumber**, **AutoRequestSense**, and **SrbExtensionSize**.

Members that are not pertinent to the HBA, such as **DmaChannel** for an EISA bus-master adapter, must be left as is.

### `NumberOfBytes`

The size required, in bytes, of the uncached extension to allocate.

## Return value

**StorPortGetUncachedExtension** returns a virtual address pointer to the uncached extension. If it cannot allocate the requested memory, it returns **NULL**. If the memory was previously allocated, the virtual address pointer to the current uncached extension is returned.

## Remarks

Bus-master devices use common buffer space for DMA transfers.

## See also

[ScsiPortGetUncachedExtension](https://learn.microsoft.com/windows-hardware/drivers/ddi/srb/nf-srb-scsiportgetuncachedextension)