# TapeClassLogicalBlockToPhysicalBlock function

## Description

The **TapeClassLogicalBlockToPhysicalBlock** routine translates a pseudological block address to a physical block address. This routine is for SCSI-1 devices.

## Parameters

### `DensityCode` [in]

Specifies the tape media density code. This routine supports tapes with the following density codes: QIC_24, QIC_120, QIC_150, QIC_525, QIC_1000, QIC_2GB, QIC_1350, and QIC_2100.

### `LogicalBlockAddress` [in]

Specifies a pseudological block address.

### `BlockLength` [in]

Specifies the logical block size, in bytes.

### `FromBOT` [in]

**TRUE** indicates that the physical block calculation should start at the beginning of the tape and account for the physical device header. **FALSE** indicates that the tape has two partitions, that the block address is on the directory partition, and therefore no physical device header needs to be factored into the calculation.

## Return value

**TapeClassLogicalBlockToPhysicalBlock** returns a structure containing the physical block address:

typedef struct _TAPE_PHYS_POSITION {

ULONG SeekBlockAddress;

ULONG SpaceBlockCount;

} TAPE_PHYS_POSITION, PTAPE_PHYS_POSITION;

## Remarks

A tape miniclass driver calls **TapeClassLogicalBlockToPhysicalBlock** to translate a logical block address from an application to a physical block address for a tape device. **TapeClassLogicalBlockToPhysicalBlock** is not necessary for SCSI-2 or later drivers because devices that comply with SCSI-2 or later standards support logical block addressing.

To position a tape to the physical block address returned by this routine, a tape miniclass driver issues two SCSI commands: a LOCATE command to position the tape to the **SeekBlockAddress**, and then a SPACE command to advance the tape **SpaceBlockCount**. The **SpaceBlockCount** value is necessary if the pseudological blocks on the tape are smaller than the physical blocks; in that case, the logical block boundary might not align with a physical block boundary.

If a tape miniclass driver calls this routine with an unsupported tape density code, **TapeClassLogicalBlockToPhysicalBlock** does not perform any translation. It returns the logical block address in **SeekBlockAddress** and returns zero in **SpaceBlockCount**.

## See also

[TapeClassPhysicalBlockToLogicalBlock](https://learn.microsoft.com/windows-hardware/drivers/ddi/minitape/nf-minitape-tapeclassphysicalblocktologicalblock)