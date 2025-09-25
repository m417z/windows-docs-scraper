# ScsiPortGetUncachedExtension function

## Description

The **ScsiPortGetUncachedExtension** routine allocates memory that can be used by both the CPU and a bus-master HBA for DMA or for shared data.

**Note** The SCSI port driver and SCSI miniport driver models may be altered or unavailable in the future. Instead, we recommend using the [Storport driver](https://learn.microsoft.com/windows-hardware/drivers/storage/storport-driver) and [Storport miniport](https://learn.microsoft.com/windows-hardware/drivers/storage/storport-miniport-drivers) driver models.

## Parameters

### `HwDeviceExtension` [in]

Pointer to the hardware device extension. This is a per-HBA storage area that the port driver allocates and initializes on behalf of the miniport driver. Miniport drivers usually store HBA-specific information in this extension, such as the state of the HBA and the HBA's mapped access ranges. This area is available to the miniport driver in the **DeviceExtension->HwDeviceExtension** member of the HBA's device object immediately after the miniport driver calls [ScsiPortInitialize](https://learn.microsoft.com/windows-hardware/drivers/ddi/srb/nf-srb-scsiportinitialize). The port driver frees this memory when it removes the device.

### `ConfigInfo` [in]

Specifies information about the HBA's DMA capabilities. The following members must be filled in: **DmaChannel** or **DmaPort**, **DmaWidth**, **DmaSpeed**, **MaximumTransferLength**, **ScatterGather**, **Master** set to **TRUE**, **NumberOfPhysicalBreaks**, **AdapterInterfaceType**, **Dma32BitAddresses**, **SystemIoBusNumber**, **AutoRequestSense**, and **SrbExtensionSize.**

Members that are not pertinent to the HBA, such as **DmaChannel** for an EISA bus-master adapter, must be left as is.

### `NumberOfBytes` [in]

Indicates the size in bytes of the uncached extension to be allocated. Drivers in Windows XP and earlier operating systems must not allocate more than 100 kilobytes of uncached extension, and if they participate in I/O operations on the hibernation file or the crash dump file, they must limit the amount of uncached extension that they allocate to under 32 kilobytes.

## Return value

**ScsiPortGetUncachedExtension** returns a virtual address pointer to the uncached extension. If it cannot allocate the requested memory, it returns **NULL**.

## Remarks

**ScsiPortGetUncachedExtension** can be called only from miniport driver's [HwScsiFindAdapter](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff557300(v=vs.85)) routine and only for a bus-master HBA. Calls from other miniport driver routines will result in system failure or incorrect operation for the caller.

Because high-end machines have caches and large memories, any memory to be shared between an HBA and the CPU must be specially allocated. Mailboxes or I/O request queues in system memory are examples of this type of shared memory.

A miniport driver must set **SrbExtensionSize.** before calling **ScsiPortGetUncachedExtension** to change the size of its per-request storage based on **NumberOfPhysicalBreaks**.

The [HwScsiFindAdapter](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff557300(v=vs.85)) routine can call **ScsiPortGetUncachedExtension** only once for each bus-master HBA the miniport driver supports.

To obtain the physical address for the uncached extension that the HBA can use, call [ScsiPortGetPhysicalAddress](https://learn.microsoft.com/windows-hardware/drivers/ddi/srb/nf-srb-scsiportgetphysicaladdress).

The ScsiPort driver will free the memory allocated by **ScsiPortGetUncachedExtension** when the adapter device is stopped.

## See also

[HwScsiFindAdapter](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff557300(v=vs.85))

[PORT_CONFIGURATION_INFORMATION (SCSI)](https://learn.microsoft.com/windows-hardware/drivers/ddi/srb/ns-srb-_port_configuration_information)

[ScsiPortGetPhysicalAddress](https://learn.microsoft.com/windows-hardware/drivers/ddi/srb/nf-srb-scsiportgetphysicaladdress)