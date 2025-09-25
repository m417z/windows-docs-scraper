# _IDE_DEVICE_PARAMETERS structure

## Description

The IDE_DEVICE_PARAMETERS structure contains configuration information that the port driver provides to the miniport driver to configure a device.

**Note** The ATA port driver and ATA miniport driver models may be altered or unavailable in the future. Instead, we recommend using the [Storport driver](https://learn.microsoft.com/windows-hardware/drivers/storage/storport-driver) and [Storport miniport](https://learn.microsoft.com/windows-hardware/drivers/storage/storport-miniport-drivers) driver models.

## Members

### `Version`

Indicates the size of the *Device* parameters structure. The miniport driver should verify that sizeof(IDE_DEVICE_PARAMETERS) is less than or equal to the **Version** field.

### `IdeDeviceType`

Indicates the type of the device. The allowed device types are *DeviceIsAta* for ATA devices, *DeviceIsAtapi* for ATAPI devices, and *DeviceNotExist* if no device was found at that address. The other fields in this structure are not valid if the **IdeDeviceType** is set to *DeviceNotExist*.

### `TargetId`

Specifies the target ID of the device.

### `MaximumLun`

The miniport driver must update this field to indicate the maximum logical unit number supported by this device. By default, the member is set to 0 indicating the existence of just one LUN.

### `NumberOfOverlappedRequests`

The miniport driver must update this field to specify the number of overlapped requests it can handle for this device. By default, the member is set to 1.

### `MaxBlockXfer`

Specifies the number of sectors in a block of data to be transferred. This value applies to the data blocks used in ATA block transfer commands such as Read Multiple (0xC4), Write Multiple (0xC5). For more information about the ReadMultiple and WriteMultiple commands, see the *ATA Specification*.

### `DeviceCharacteristics`

Specifies the device characteristics. The table below lists the characteristics that could be set in this member. The high byte of this member is opaque and shall not be changed by the ATA miniport.

| Device Characteristic | Description |
| --- | --- |
| DFLAGS_REMOVABLE_MEDIA | Indicates that the drive has removable media |
| DFLAGS_ REMOVABLE_DEVICE | Indicates that the device can be safely unplugged |
| DFLAGS_FUA_SUPPORT | Indicates that the device supports FUA (Force Unit Access) |
| DFLAGS_INT_DRQ | Indicates that the device interrupts as DRQ is set after receiving ATAPI Packet command |
| DFLAGS_MSN_SUPPORT | Indicates that the device supports Media Status Notification. |

### `AddressTranslation`

Contains an enumeration value of type [ATA_ADDRESS_TRANSLATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/irb/ne-irb-ata_address_translation) that specifies the sort of address translation used during data transfers.

### `MaxLba`

Specifies the maximum user-addressable logical block address (LBA). This member is defined when **AddressTranslation** is equal to either **LbaMode** or **Lba48BitMode**.

### `Chs`

Specifies the drive geometry with the values for the number of cylinders, heads per cylinder, and the sectors per track. This member is defined when **AddressTranslation** is equal to **ChsMode**.

### `Chs.NumCylinders`

### `Chs.NumHeads`

### `Chs.NumSectorsPerTrack`

### `Chs.Reserved`

### `BytesPerLogicalSector`

This member specifies the number of bytes per logical sector (LBA) for the given device.

### `BytesPerPhysicalSector`

This member specifies the number of bytes per physical sector (that is, the smallest amount of data that the device can physically write internally) for the given device.

### `BytesOffsetForSectorAlignment`

This member specifies the location of sector 0 within the first physical sector as defined in the ATA specification represented in bytes.

### `TransferModeSupported`

Contains a bitmap that indicates the supported transfer modes.

### `TransferModeSelected`

Indicates the selected transfer modes on the device. The miniport driver must set this member.

## Remarks

The port driver passes a IDE_DEVICE_PARAMETERS structure to the miniport driver when it calls [IdeHwInitialize](https://learn.microsoft.com/windows-hardware/drivers/ddi/irb/nc-irb-ide_hw_initialize).

## See also

[ATA_ADDRESS_TRANSLATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/irb/ne-irb-ata_address_translation)

[IDE_DEVICE_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/irb/ne-irb-ide_device_type)

[IdeHwInitialize](https://learn.microsoft.com/windows-hardware/drivers/ddi/irb/nc-irb-ide_hw_initialize)