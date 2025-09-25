# IDE_HW_BUILDIO callback function

## Description

The ***IdeHwBuildIo*** miniport driver routine is called one time for every incoming I/O request.

**Note** The ATA port driver and ATA miniport driver models may be altered or unavailable in the future. Instead, we recommend using the [Storport driver](https://learn.microsoft.com/windows-hardware/drivers/storage/storport-driver) and [Storport miniport](https://learn.microsoft.com/windows-hardware/drivers/storage/storport-miniport-drivers) driver models.

## Parameters

### `ChannelExtension` [in]

A pointer to the miniport driver channel extension.

### `Irb` [in]

A pointer to a structure of type [IDE_REQUEST_BLOCK](https://learn.microsoft.com/windows-hardware/drivers/ddi/irb/ns-irb-_ide_request_block) that defines the Integrated Device Electronics (IDE) input/output request block (IRB) to process.

## Return value

***IdeHwBuildIo*** returns **TRUE** to acknowledge the receipt of the [IDE_REQUEST_BLOCK](https://learn.microsoft.com/windows-hardware/drivers/ddi/irb/ns-irb-_ide_request_block) structure. The port driver ignores a return value of **FALSE**.

## Remarks

Miniport drivers provide an ***AtaHwBuildlo*** routine that performs unsynchronized I/O processing with interrupts enabled. After ***IdeHwBuildIo*** completes all unsynchronized processing of a request, it returns to the port driver, and the port driver passes the request to the miniport driver's [IdeHwStartIo](https://learn.microsoft.com/windows-hardware/drivers/ddi/irb/nc-irb-ide_hw_startio) routine, which performs the tasks that require synchronization.

The miniport driver must observe certain restrictions while it executes the ***IdeHwBuildIo*** routine. The miniport driver calls ***IdeHwBuildIo*** without holding any locks. In particular, the miniport driver must not touch any shared data in its channel extension, nor can it call any of the routines exported by the ATA port driver.

If the miniport driver must complete a request while it executes the ***IdeHwBuildIo*** routine, it must assign the appropriate completion status value to the **IrbStatus** member of the [IDE_REQUEST_BLOCK](https://learn.microsoft.com/windows-hardware/drivers/ddi/irb/ns-irb-_ide_request_block) structure pointed to by the *Irb* parameter. The miniport driver must not set **IrbStatus** to a value of IRB_STATUS_PENDING.

The miniport driver can use the ***IdeHwBuildIo*** routine to indicate to the port driver how an IRB should be handled. For example, the miniport driver can request that the port driver map the buffer at *DataBuffer* by setting the **IrbFlags** member of the IRB to the appropriate value. The miniport driver should not request that the buffer that is associated with a request be mapped unless the request is some type of data transfer.

The ***IdeHwBuildIo*** routine resembles Storport's [HwStorBuildIo](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nc-storport-hw_buildio) routine in functionality. For more information about the ***HwStorBuildIo*** routine, see [Unsynchronized HwStorBuildIo Routine](https://learn.microsoft.com/windows-hardware/drivers/storage/unsynchronized-hwstorbuildio-routine).

***IdeHwBuildIo*** is an optional routine.

## See also

[IDE_REQUEST_BLOCK](https://learn.microsoft.com/windows-hardware/drivers/ddi/irb/ns-irb-_ide_request_block)

[IdeHwStartIo](https://learn.microsoft.com/windows-hardware/drivers/ddi/irb/nc-irb-ide_hw_startio)