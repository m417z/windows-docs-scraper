# IDE_HW_INITIALIZE callback function

## Description

The ***IdeHwInitialize*** miniport driver routine configures the indicated device.

**Note** The ATA port driver and ATA miniport driver models may be altered or unavailable in the future. Instead, we recommend using the [Storport driver](https://learn.microsoft.com/windows-hardware/drivers/storage/storport-driver) and [Storport miniport](https://learn.microsoft.com/windows-hardware/drivers/storage/storport-miniport-drivers) driver models.

## Parameters

### `ChannelExtension` [in]

A pointer to the miniport driver per channel device extension.

### `DeviceParameters` [in, out]

A pointer to a structure of type [IDE_DEVICE_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/irb/ns-irb-_ide_device_parameters) that identifies the device to configure and the device parameters with which to configure the device.

### `IdentifyData` [in]

A pointer to a structure of type [IDENTIFY_DEVICE_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/ata/ns-ata-_identify_device_data) that contains the identify data that is returned by the device.

## Return value

***IdeHwInitialize*** returns **TRUE** if the operation succeeds. It returns **FALSE** if the operation fails.

## Remarks

After the miniport driver enumerates the devices on a channel, it calls the ***IdeHwInitialize*** routine one time for each device it enumerates. The ***IdeHwInitialize*** routine must configure each device based on the information that is specified in the [IDE_DEVICE_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/irb/ns-irb-_ide_device_parameters) structure, pointed to by the *DeviceParameters* parameter. In exceptional cases, the miniport driver can configure the device by using a set of parameters that differ from those contained in **IDE_DEVICE_PARAMETERS**. In such cases, the miniport driver must update the information in **IDE_DEVICE_PARAMETERS** to contain the parameter value that it actually used to configure the device. After the ***IdeHwInitialize*** routine returns, the port driver updates its cached information with the parameter values that are provided by the miniport driver.

## See also

[IDENTIFY_DEVICE_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/ata/ns-ata-_identify_device_data)

[IDE_DEVICE_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/irb/ns-irb-_ide_device_parameters)