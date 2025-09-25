# IDE_CHANNEL_INIT callback function

## Description

The **AtaChannelInitRoutine** miniport driver routine initializes the miniport driver's channel interface.

> [!NOTE]
> The ATA port driver and ATA miniport driver models may be altered or unavailable in the future. Instead, we recommend using the [Storport driver](https://learn.microsoft.com/windows-hardware/drivers/storage/storport-driver) and [Storport miniport](https://learn.microsoft.com/windows-hardware/drivers/storage/storport-miniport-drivers) driver models.

## Parameters

### `ChannelExtension`

[in] A pointer to the miniport driver channel extension.

### `ChannelInterface`

[in, out] Pointer to an [**IDE_CHANNEL_INTERFACE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/irb/ns-irb-_ide_channel_interface) structure containing interface information for the indicated channel.

### `InitContext`

[in, out] A pointer to the controller extension.

## Return value

**AtaChannelInitRoutine** returns TRUE if the initialization succeeded. It returns FALSE if the initialization failed.

## Remarks

A vendor-supplied miniport driver that supports the channel interface must implement an **AtaChannelInitRoutine** routine to initialize the controller's channels. In particular, the **AtaChannelInitRoutine** routine must complete the initialization of the [**IDE_CHANNEL_INTERFACE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/irb/ns-irb-_ide_channel_interface) structure. The following sequence describes how the miniport driver and the port driver interact to initialize a channel:

1. While in its [**DriverEntry**](https://learn.microsoft.com/windows-hardware/drivers/storage/driverentry-of-ide-controller-minidriver) routine, the miniport driver calls the port driver's [**AtaPortInitializeEx**](https://learn.microsoft.com/windows-hardware/drivers/ddi/irb/nf-irb-ataportinitializeex) library routine to launch the initialization of the controller and the miniport driver.

2. If the miniport driver supports the channel interface, the **DriverEntry** routine must initialize the **AtaChannelInitRoutine** member of [**IDE_CONTROLLER_INTERFACE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/irb/ns-irb-_ide_controller_interface) to point to the miniport driver's **AtaChannelInitRoutine** routine.

3. The port driver calls the **AtaAdapterControl** routine by using control action IdeStart. **AtaChannelInitRoutine** is called one time for every NumberOfChannels specified in the ControllerConfiguration structure that is returned by the **AtaAdapterControl** routine when **AtaAdapterControl** handles an **IdeStart** action.

## See also

[**AtaPortInitializeEx**](https://learn.microsoft.com/windows-hardware/drivers/ddi/irb/nf-irb-ataportinitializeex)

[**IDE_CHANNEL_INTERFACE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/irb/ns-irb-_ide_channel_interface)

[**IDE_CONTROLLER_INTERFACE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/irb/ns-irb-_ide_controller_interface)