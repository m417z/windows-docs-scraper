# _IDE_TASK_FILE structure

## Description

The IDE_TASK_FILE structure contains the current and previous IDE task file.

**Note** The ATA port driver and ATA miniport driver models may be altered or unavailable in the future. Instead, we recommend using the [Storport driver](https://learn.microsoft.com/windows-hardware/drivers/storage/storport-driver) and [Storport miniport](https://learn.microsoft.com/windows-hardware/drivers/storage/storport-miniport-drivers) driver models.

## Members

### `Current`

Contains a structure of type [IDEREGISTERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/irb/ns-irb-_ideregisters) that holds the current contents of the ATA task file registers.

### `Previous`

Contains a structure of type [IDEREGISTERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/irb/ns-irb-_ideregisters) that holds the previous contents of the ATA task file registers in the case of a 48-bit LBA command.

## See also

[IDEREGISTERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/irb/ns-irb-_ideregisters)