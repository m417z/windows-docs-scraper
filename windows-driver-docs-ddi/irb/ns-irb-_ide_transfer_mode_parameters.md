# _IDE_TRANSFER_MODE_PARAMETERS structure

## Description

The IDE_TRANSFER_MODE_PARAMETERS structure is used in conjunction with the miniport driver's [AtaControllerTransferModeSelect](https://learn.microsoft.com/windows-hardware/drivers/ddi/irb/nc-irb-ide_transfer_mode_select) routine to set the transfer mode parameters on a channel.

**Note** The ATA port driver and ATA miniport driver models may be altered or unavailable in the future. Instead, we recommend using the [Storport driver](https://learn.microsoft.com/windows-hardware/drivers/storage/storport-driver) and [Storport miniport](https://learn.microsoft.com/windows-hardware/drivers/storage/storport-miniport-drivers) driver models.

## Members

### `ChannelNumber`

Indicates the channel number whose mode parameters are to be set.

### `DeviceType`

Contains an enumeration value of type [IDE_DEVICE_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/irb/ne-irb-ide_device_type) that indicates the type of device. The miniport driver should not select a transfer mode if the device type is **DeviceNotExist**.

### `IoReadySupported`

Indicates when **TRUE** that bit 11 of word 49 of the indicated device's identify data is set to 1. An IDE request with a function value of IRB_FUNCTION_ATA_IDENTIFY will retrieve a device's identify data. For more information about ATA identify data, see the sections on the Identify Device information packet in version 6.0 of the *ATA/ATAPI specification*.

### `DeviceTransferModeSupported`

Contains a bitmap that indicates the supported transfer modes for each of the devices on the channel. The port driver sets this member. The miniport driver must not select a transfer mode that the port driver does not support. For more information about this member, see the **Remarks** section.

### `DeviceTransferModeCurrent`

Contains a bitmap that indicates the current transfer mode settings for each of the device on the channel. The port driver retrieves the current transfer mode of the devices from their identify device data. For more information about this member, see the **Remarks** section.

### `DeviceTransferModeSelected`

Contains a bitmap that indicates the selected transfer mode settings for each of the device on the channel. The miniport driver should use this member to indicate to the port driver which transfer modes it selects. For more information about this member, see the **Remarks** section.

## Remarks

Member arrays **DeviceTransferModeSupported**, **DeviceTransferModeCurrent**, and **DeviceTransferModeSelected** are arrays of ULONG bitmaps indicating combinations of PIO and DMA transfer modes. The bitmaps are defined as follows:

// PIO Modes

```
#define PIO_MODE0           (1 << 0)
#define PIO_MODE1           (1 << 1)
#define PIO_MODE2           (1 << 2)
#define PIO_MODE3           (1 << 3)
#define PIO_MODE4           (1 << 4)

// Single-word DMA Modes

#define SWDMA_MODE0         (1 << 5)
#define SWDMA_MODE1         (1 << 6)
#define SWDMA_MODE2         (1 << 7)

// Multi-word DMA Modes

#define MWDMA_MODE0         (1 << 8)
#define MWDMA_MODE1         (1 << 9)
#define MWDMA_MODE2         (1 << 10)

// Ultra DMA Modes

#define UDMA_MODE0          (1 << 11)
#define UDMA_MODE1          (1 << 12)
#define UDMA_MODE2          (1 << 13)
#define UDMA_MODE3          (1 << 14)
#define UDMA_MODE4          (1 << 15)
#define UDMA_MODE5          (1 << 16)
```

## See also

[AtaControllerTransferModeSelect](https://learn.microsoft.com/windows-hardware/drivers/ddi/irb/nc-irb-ide_transfer_mode_select)

[IDE_DEVICE_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/irb/ne-irb-ide_device_type)