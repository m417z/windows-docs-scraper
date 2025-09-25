# AtaPortRegistryFreeBuffer function

## Description

The **AtaPortRegistryFreeBuffer** routine frees the registry buffer that was allocated by using [AtaPortRegistryAllocateBuffer](https://learn.microsoft.com/windows-hardware/drivers/ddi/irb/nf-irb-ataportregistryallocatebuffer).

**Note** The ATA port driver and ATA miniport driver models may be altered or unavailable in the future. Instead, we recommend using the [Storport driver](https://learn.microsoft.com/windows-hardware/drivers/storage/storport-driver) and [Storport miniport](https://learn.microsoft.com/windows-hardware/drivers/storage/storport-miniport-drivers) driver models.

## Parameters

### `ChannelExtension` [in]

A pointer to the channel extension.

### `Buffer` [in]

A pointer to the buffer to free.

## Remarks

**AtaPortRegistryFreeBuffer** flushes deferred write operations to the registry.

The miniport driver must call **AtaPortRegistryFreeBuffer** either in its [AtaChannelInitRoutine](https://learn.microsoft.com/windows-hardware/drivers/ddi/irb/nc-irb-ide_channel_init) routine or in its [IdeHwControl](https://learn.microsoft.com/windows-hardware/drivers/ddi/irb/nc-irb-ide_hw_control) routine. It cannot call **AtaPortRegistryFreeBuffer** from any other routine. Additionally, the miniport driver can only call **AtaPortRegistryFreeBuffer** from its **IdeHwControl** routine if its **IdeHwControl** routine was called and had a value of either **StartChannel** or **StopChannel** in its *ControlAction* parameter.

## See also

[AtaChannelInitRoutine](https://learn.microsoft.com/windows-hardware/drivers/ddi/irb/nc-irb-ide_channel_init)

[AtaPortRegistryAllocateBuffer](https://learn.microsoft.com/windows-hardware/drivers/ddi/irb/nf-irb-ataportregistryallocatebuffer)

[IdeHwControl](https://learn.microsoft.com/windows-hardware/drivers/ddi/irb/nc-irb-ide_hw_control)