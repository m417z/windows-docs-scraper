# AtaPortGetUnCachedExtension function

## Description

The **AtaPortGetUncachedExtension** routine allocates an uncached common buffer that is shared by the CPU and the device.

**Note** The ATA port driver and ATA miniport driver models may be altered or unavailable in the future. Instead, we recommend using the [Storport driver](https://learn.microsoft.com/windows-hardware/drivers/storage/storport-driver) and [Storport miniport](https://learn.microsoft.com/windows-hardware/drivers/storage/storport-miniport-drivers) driver models.

## Parameters

### `ChannelExtension` [in]

A pointer to the channel extension.

### `UncachedExtensionSize` [in]

Specifies the length, in bytes, of the uncached common buffer. Set this parameter to 0 if the miniport driver does not require an uncached extension.

### `IrbExtensionSize` [in]

Specifies the size, in bytes, that is required by the miniport driver for its per request storage, if any.

Set this parameter set to 0 if the miniport driver does not maintain per IRB information for which it requires storage.

## Return value

**AtaPortGetUncachedExtension** returns a virtual address pointer to the uncached extension. If it cannot allocate the requested memory, or if the memory was previously allocated, it returns **NULL**.

## Remarks

The miniport driver can use IRB extensions as storage for driver-determined, request-specific information, such as data that is necessary to process a particular request.

The port driver does not initialize IRB extensions, but sets a pointer to an extension in each IRB that it sends to the miniport driver.

HBA hardware can safely access an IRB extension.

The miniport driver must not call **AtaPortGetUncachedExtension** from any routine other than its [IdeHwControl](https://learn.microsoft.com/windows-hardware/drivers/ddi/irb/nc-irb-ide_hw_control) routine, and only when it is processing a control action of **StartChannel**. Calls of **AtaPortGetUncachedExtension** from other miniport driver routines result in incorrect operation or even system failure. The port driver automatically frees the uncached extension after it invokes **IdeHwControl** with the **StopChannel** control action.

## See also

[IdeHwControl](https://learn.microsoft.com/windows-hardware/drivers/ddi/irb/nc-irb-ide_hw_control)