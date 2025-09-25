# AtaPortRegistryAllocateBuffer function

## Description

The **AtaPortRegistryAllocateBuffer** routine allocates a buffer for registry operations.

**Note** The ATA port driver and ATA miniport driver models may be altered or unavailable in the future. Instead, we recommend using the [Storport driver](https://learn.microsoft.com/windows-hardware/drivers/storage/storport-driver) and [Storport miniport](https://learn.microsoft.com/windows-hardware/drivers/storage/storport-miniport-drivers) driver models.

## Parameters

### `ChannelExtension` [in]

A pointer to the channel extension.

### `BufferSize`

Specifies the length of the buffer, in bytes.

## Return value

**AtaPortRegistryAllocateBuffer** returns a pointer to the allocated buffer on success. Otherwise, it returns **NULL**.

## Remarks

The port driver enables the miniport driver to allocate one buffer for all its registry operations. After the miniport driver has allocated a buffer with **AtaPortRegistryAllocateBuffer**, later calls to **AtaPortRegistryAllocateBuffer** will fail and return **NULL**. After the miniport driver frees the allocated buffer with a call to the [AtaPortRegistryFreeBuffer](https://learn.microsoft.com/windows-hardware/drivers/ddi/irb/nf-irb-ataportregistryfreebuffer) routine, it can again allocate buffers by calling **AtaPortRegistryAllocateBuffer**.

The miniport driver must call **AtaPortRegistryAllocateBuffer** either in its [AtaChannelInitRoutine](https://learn.microsoft.com/windows-hardware/drivers/ddi/irb/nc-irb-ide_channel_init) routine or in its [IdeHwControl](https://learn.microsoft.com/windows-hardware/drivers/ddi/irb/nc-irb-ide_hw_control) routine. It cannot call **AtaPortRegistryAllocateBuffer** from any other routine. Additionally, the miniport driver can only call **AtaPortRegistryAllocateBuffer** from its **IdeHwControl** routine if its **IdeHwControl** routine was called and had a value of either **StartChannel** or **StopChannel** in its *ControlAction* parameter.

## See also

[AtaChannelInitRoutine](https://learn.microsoft.com/windows-hardware/drivers/ddi/irb/nc-irb-ide_channel_init)

[AtaPortRegistryFreeBuffer](https://learn.microsoft.com/windows-hardware/drivers/ddi/irb/nf-irb-ataportregistryfreebuffer)

[IdeHwControl](https://learn.microsoft.com/windows-hardware/drivers/ddi/irb/nc-irb-ide_hw_control)