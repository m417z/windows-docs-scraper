# DriverEntry function

## Description

The ***DriverEntry*** miniport driver routine is called when the miniport driver is loaded.

**Note** The ATA port driver and ATA miniport driver models may be altered or unavailable in the future. Instead, we recommend using the [Storport driver](https://learn.microsoft.com/windows-hardware/drivers/storage/storport-driver) and [Storport miniport](https://learn.microsoft.com/windows-hardware/drivers/storage/storport-miniport-drivers) driver models.

## Parameters

### `DriverObject` [in]

A pointer to an opaque structure to be used as the first parameter when this routine calls the [AtaPortInitializeEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/irb/nf-irb-ataportinitializeex) routine.

### `RegistryPath` [in]

A pointer to an opaque structure to be used as the second parameter when this routine calls the [AtaPortInitializeEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/irb/nf-irb-ataportinitializeex) routine.

## Return value

The return values for this routine are recommended to mirror the return values of [AtaPortInitializeEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/irb/nf-irb-ataportinitializeex).

## Remarks

**DriverEntry** is the first function that is called in an ATA miniport driver. The ATA miniport driver must allocate an [IDE_CONTROLLER_INTERFACE](https://learn.microsoft.com/windows-hardware/drivers/ddi/irb/ns-irb-_ide_controller_interface) structure, initialize it, and send it to [AtaPortInitializeEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/irb/nf-irb-ataportinitializeex). The ATA miniport driver indicates its support for the channel interface by setting the ChannelExtensionSize and the ***AtaChannelInitRoutine*** entry point in the **IDE_CONTROLLER_INTERFACE** structure. This causes the ATA port driver to call the function that is specified in the ***AtaChannelInitRoutine*** field that has a ChannelExtension of size ChannelExtensionSize. The function is called one time for every NumberOfChannels specified in the ControllerConfiguration structure that are returned by [AtaAdapterControl](https://learn.microsoft.com/windows-hardware/drivers/ddi/irb/nc-irb-ide_adapter_control) when **AtaAdapterControl** handles an IdeStart action.

## See also

[AtaAdapterControl](https://learn.microsoft.com/windows-hardware/drivers/ddi/irb/nc-irb-ide_adapter_control)

[AtaPortInitializeEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/irb/nf-irb-ataportinitializeex)