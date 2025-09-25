# AtaPortInitializeEx function

## Description

The **AtaPortInitializeEx** ATA port driver library routine initializes the port and miniport drivers.

**Note** The ATA port driver and ATA miniport driver models may be altered or unavailable in the future. Instead, we recommend using the [Storport driver](https://learn.microsoft.com/windows-hardware/drivers/storage/storport-driver) and [Storport miniport](https://learn.microsoft.com/windows-hardware/drivers/storage/storport-miniport-drivers) driver models.

## Parameters

### `DriverObject` [in]

A pointer to the miniport driver object.

### `RegistryPath` [in]

Contains a Unicode string that indicates the location in the registry where the miniport driver configuration information is stored.

### `ControllerInterface` [in]

Contains the entry points for the ***AtaAdapterControl***, ***AtaChannelInitRoutine***, ***AtaControllerChannelEnabled***, and ***AtaControllerTransferModeSelect*** routines.

## Return value

**AtaPortInitializeEx** returns STATUS_SUCCESS if the operation succeeds. Otherwise, it returns an error code.

## Remarks

The **AtaPortInitializeEx** routine initializes key data structures that are used by the port and miniport drivers. It also starts the initialization of the controller's channels. The following sequence describes the principal actions taken by this routine:

1. While in its [DriverEntry](https://learn.microsoft.com/windows-hardware/drivers/storage/driverentry-of-ide-controller-minidriver) routine, the miniport driver calls the port driver's **AtaPortInitializeEx** library routine and passes it the following key parameters:
   * *ControllerInterface*: Contains the entry points for the ***AtaAdapterControl***, ***AtaChannelInitRoutine***, ***AtaControllerChannelEnabled***, and ***AtaControllerTransferModeSelect*** routines.
2. The **AtaPortInitializeEx** routine initializes key data structures that are used by the port and miniport drivers and performs the following actions:
   1. Initializes the miniport driver's dispatch tables.
   2. Allocates an extension for the driver object.
   3. Copies ControllerInterface into the driver extension.
   4. After ***AtaPortInitializeEx*** completes the initialization of the port driver, it returns to the miniport driver's ***DriverEntry*** routine.
3. While starting the adapter device, the miniport driver routine ***AtaAdapterControl*** will be called by the port driver with control action **IdeStart**.
4. When the ATA port driver is processing a channel device start request, the miniport driver routine [AtaControllerChannelEnabled](https://learn.microsoft.com/windows-hardware/drivers/ddi/irb/nc-irb-ide_channel_enabled) is called for each channel on the controller to determine whether it is enabled.
5. After the [AtaControllerChannelEnabled](https://learn.microsoft.com/windows-hardware/drivers/ddi/irb/nc-irb-ide_channel_enabled) routine determines which channels are enabled, the ATA port driver calls [AtaChannelInitRoutine](https://learn.microsoft.com/windows-hardware/drivers/ddi/irb/nc-irb-ide_channel_init) for this channel.

## See also

[AtaChannelInitRoutine](https://learn.microsoft.com/windows-hardware/drivers/ddi/irb/nc-irb-ide_channel_init)

[AtaControllerChannelEnabled](https://learn.microsoft.com/windows-hardware/drivers/ddi/irb/nc-irb-ide_channel_enabled)

[DriverEntry](https://learn.microsoft.com/windows-hardware/drivers/storage/driverentry-of-ide-controller-minidriver)

[IDE_CONTROLLER_CONFIGURATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/irb/ns-irb-_ide_controller_configuration)