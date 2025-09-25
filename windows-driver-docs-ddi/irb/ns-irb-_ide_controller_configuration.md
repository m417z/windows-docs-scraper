# _IDE_CONTROLLER_CONFIGURATION structure

## Description

The IDE_CONTROLLER_CONFIGURATION structure is used to pass controller configuration information between the port driver and the miniport driver.

**Note** The ATA port driver and ATA miniport driver models may be altered or unavailable in the future. Instead, we recommend using the [Storport driver](https://learn.microsoft.com/windows-hardware/drivers/storage/storport-driver) and [Storport miniport](https://learn.microsoft.com/windows-hardware/drivers/storage/storport-miniport-drivers) driver models.

## Members

### `Version`

The port driver sets this field to indicate the version of the port driver. The port driver sets the version to sizeof(IDE_CONTROLLER_CONFIGURATION). The miniport driver should verify that the version is greater than or equal to the one it is using.

### `NumberOfChannels`

Specifies the number of channels supported by the HBA. Note that this indicates the total number of channels including the ones that are disabled.

### `ControllerMode`

The port driver sets this field to inform the ATA miniport which mode it is running at. There are two possible modes:

| Mode | Description |
| --- | --- |
| IdeModeNormal | This is the standard full capabilities mode where the ATA miniport may operate normally. |
| IdeModeDump | This is the limited no memory mode that an ATA miniport operates in during hibernate or crashdump. Call Back Routines and Registry Access Routines cannot be used when in this mode. |

### `NumberOfPhysicalBreaks`

Specifies the maximum number of breaks between address ranges that a data buffer can have if the HBA supports scatter/gather. In other words, the number of scatter/gather lists minus one. By default, the value of this member is IDE_UNINITIALIZED_VALUE, which indicates the HBA can support an unlimited number of physical discontinuities. If the port driver sets a value for this member, the miniport driver can adjust the value lower but no higher. If this member is IDE_UNINITIALIZED_VALUE, the miniport driver must reset this member according to the HBA's scatter/gather capacity.

### `MaximumTransferLength`

Specifies the maximum number of bytes the HBA can transfer in a single transfer operation. By default, the value of this member is IDE_UNINITIALIZED_VALUE, which indicates an unlimited maximum transfer size.

### `Reserved`

Reserved for future use. The miniport driver must not use this field.

### `NativeModeEnabled`

The miniport driver could set this member to **TRUE** to indicate that the controller is to be operated in Native mode.

### `Dma64BitAddress`

The miniport driver could set this member to **TRUE** to indicate support for 64 bit DMA operation.

### `BusMaster`

The miniport driver could set this member to **TRUE** to indicate bus mastering support.

### `AtaBusType`

Indicates whether it is a SATA or a PATA controller.

### `ControllerResources`

Provides the hardware resources for the ATA controller.