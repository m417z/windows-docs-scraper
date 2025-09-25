# TapeClassPhysicalBlockToLogicalBlock function

## Description

The **TapeClassPhysicalBlockToLogicalBlock** routine translates a physical block address to a pseudological block address. This routine is for SCSI-1 devices.

## Parameters

### `DensityCode` [in]

Specifies the tape media density code. This routine supports tapes with the following density codes: QIC_24, QIC_120, QIC_150, QIC_525, QIC_1000, QIC_2GB, QIC_1350, and QIC_2100.

### `PhysicalBlockAddress` [in]

Specifies the physical block address obtained by a SCSI READ POSITION command.

### `BlockLength` [in]

Specifies the logical block size, in bytes.

### `FromBOT` [in]

**TRUE** indicates that the logical block calculation should start at the beginning of the tape and account for the physical device header. **FALSE** indicates that the tape has two partitions, that the block address is on the directory partition, and therefore no physical device header needs to be factored into the calculation.

## Return value

**TapeClassPhysicalBlockToLogicalBlock** returns the logical block address.

## Remarks

A tape miniclass driver calls **TapeClassPhysicalBlockToLogicalBlock** to translate a physical block address from a tape device to a logical block address for an application. **TapeClassPhysicalBlockToLogicalBlock** is not necessary for SCSI-2 or later drivers because devices that comply with SCSI-2 or later standards support logical block addressing.

If a tape miniclass driver calls this routine with an unsupported tape density code, **TapeClassPhysicalBlockToLogicalBlock** returns the physical block address in the return value, without performing any translation.

## See also

[TapeClassLogicalBlockToPhysicalBlock](https://learn.microsoft.com/windows-hardware/drivers/ddi/minitape/nf-minitape-tapeclasslogicalblocktophysicalblock)