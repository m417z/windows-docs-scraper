# _IDEREGISTERS structure

## Description

The IDEREGISTERS structure is used to report the contents of the IDE controller registers.

**Note** The ATA port driver and ATA miniport driver models may be altered or unavailable in the future. Instead, we recommend using the [Storport driver](https://learn.microsoft.com/windows-hardware/drivers/storage/storport-driver) and [Storport miniport](https://learn.microsoft.com/windows-hardware/drivers/storage/storport-miniport-drivers) driver models.

## Members

### `bFeaturesReg`

Specifies the contents of the ATA features register.

### `bSectorCountReg`

Specifies the contents of the ATA Sector Count register.

### `bSectorNumberReg`

Specifies the contents of the ATA Sector Number register.

### `bCylLowReg`

Specifies the contents of the ATA Cylinder Low register.

### `bCylHighReg`

Specifies the contents of the ATA Cylinder High register.

### `bDriveHeadReg`

Specifies the contents of the ATA Device/Head register.

### `bCommandReg`

Specifies the contents of the ATA Command register.

### `bReserved`

Reserved for future use. The miniport driver shall not use this field.

## Remarks

The information reported in the IDEREGISTERS structure is intended to be a superset of the information contained in [IDEREGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntdddisk/ns-ntdddisk-_ideregs). Microsoft might expand the contents of the IDEREGISTERS structure in the future. If you need a structure whose size is stable across different versions of the operating system, you should use **IDEREGS**.

## See also

[IDEREGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntdddisk/ns-ntdddisk-_ideregs)