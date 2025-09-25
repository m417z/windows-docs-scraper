# IDE_CHANNEL_INTERFACE structure

## Description

The IDE_CHANNEL_INTERFACE structure contains interface information for the indicated channel.

> [!NOTE]
> The ATA port driver and ATA miniport driver models may be altered or unavailable in the future. Instead, we recommend using the [Storport driver](https://learn.microsoft.com/windows-hardware/drivers/storage/storport-driver) and [Storport miniport](https://learn.microsoft.com/windows-hardware/drivers/storage/storport-miniport-drivers) driver models.

## Members

### `Version`

The port driver sets this member to sizeof(IDE_CHANNEL_INTERFACE). The miniport driver should verify that the version is greater than or equal to the one it is using.

### `ChannelNumber`

The port driver sets this field to the number assigned for this channel. For non-native mode controllers, the primary channel will always be assigned 0 and the secondary channel will always be assigned 1.

### `Reserved`

Reserved. The miniport driver must not use this field.

### `ReservedUlong`

Reserved. The miniport driver must not use this field.

### `IdeHwInitialize`

The miniport's [**IdeHwInitialize**](https://learn.microsoft.com/windows-hardware/drivers/ddi/irb/nc-irb-ide_hw_initialize) routine.

### `IdeHwBuildIo`

The miniport's [**IdeHwBuildIo**](https://learn.microsoft.com/windows-hardware/drivers/ddi/irb/nc-irb-ide_hw_buildio) routine.

### `IdeHwStartIo`

The miniport's [**IdeHwStartIo**](https://learn.microsoft.com/windows-hardware/drivers/ddi/irb/nc-irb-ide_hw_startio) routine.

### `IdeHwInterrupt`

The miniport's [**IdeHwInterrupt**](https://learn.microsoft.com/windows-hardware/drivers/ddi/irb/nc-irb-ide_hw_interrupt) routine.

### `IdeHwReset`

The miniport's [**IdeHwReset**](https://learn.microsoft.com/windows-hardware/drivers/ddi/irb/nc-irb-ide_hw_reset) routine.

### `IdeHwControl`

The miniport's [**IdeHwControl**](https://learn.microsoft.com/windows-hardware/drivers/ddi/irb/nc-irb-ide_hw_control) routine.

## See also

[**IdeHwBuildIo**](https://learn.microsoft.com/windows-hardware/drivers/ddi/irb/nc-irb-ide_hw_buildio)

[**IdeHwControl**](https://learn.microsoft.com/windows-hardware/drivers/ddi/irb/nc-irb-ide_hw_control)

[**IdeHwInitialize**](https://learn.microsoft.com/windows-hardware/drivers/ddi/irb/nc-irb-ide_hw_initialize)

[**IdeHwInterrupt**](https://learn.microsoft.com/windows-hardware/drivers/ddi/irb/nc-irb-ide_hw_interrupt)

[**IdeHwReset**](https://learn.microsoft.com/windows-hardware/drivers/ddi/irb/nc-irb-ide_hw_reset)

[**IdeHwStartIo**](https://learn.microsoft.com/windows-hardware/drivers/ddi/irb/nc-irb-ide_hw_startio)