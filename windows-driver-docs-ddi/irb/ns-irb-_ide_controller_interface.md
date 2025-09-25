# _IDE_CONTROLLER_INTERFACE structure

## Description

The IDE_CONTROLLER_INTERFACE structure is used to pass controller configuration information between the port driver and the miniport driver.

**Note** The ATA port driver and ATA miniport driver models may be altered or unavailable in the future. Instead, we recommend using the [Storport driver](https://learn.microsoft.com/windows-hardware/drivers/storage/storport-driver) and [Storport miniport](https://learn.microsoft.com/windows-hardware/drivers/storage/storport-miniport-drivers) driver models.

## Members

### `Version`

The port driver sets this field to indicate the version of the port driver. The port driver sets the version to sizeof(IDE_CONTROLLER_INTERFACE). The miniport driver should verify that the version is greater than or equal to the one it is using.

### `Reserved`

Reserved for future use. The miniport driver shall not use this field.

### `ControllerExtensionSize`

Specifies the size in bytes required by a miniport driver for its controller device extension.

### `ChannelExtensionSize`

Specifies the size in bytes required by a miniport driver for its per-channel device extension.

### `AlignmentMask`

Contains a mask indicating the alignment restrictions for buffers required by the HBA for transfer operations. Valid mask values are also restricted by characteristics of the memory managers on different versions of Windows. Under Windows 2000 and Windows XP, the valid mask values are 0 (byte-aligned), 1 (word-aligned), 3 (DWORD-aligned) and 7 (double DWORD-aligned). The miniport driver should set this mask if the HBA supports scatter/gather.

### `AtaChannelInitRoutine`

Pointer to the miniport's **AtaChannelInitRoutine** routine. The miniport needs to set this entry point only if it supports the Channel Interface.

### `AtaControllerChannelEnabled`

Pointer to the miniport's **AtaControllerChannelEnabled** routine. This is an optional entry point.

### `AtaControllerTransferModeSelect`

Pointer to the miniport's **AtaControllerTransferModeSelect** routine. This is an optional entry point.

### `AtaAdapterControl`

Pointer to the miniport's **AtaControllerAdapterControl** routine. This is a required entry point.