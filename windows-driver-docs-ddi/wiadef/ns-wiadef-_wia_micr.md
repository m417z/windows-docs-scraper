# _WIA_MICR structure

## Description

The **WIA_MICR** structure stores header information for the MICR metadata report of one scan job (one call to [IWiaMiniDrv::drvAcquireItemData](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiamindr_lh/nf-wiamindr_lh-iwiaminidrv-drvacquireitemdata)).

## Members

### `Tag`

Must be the literal 'WMIC', 4 single byte ASCII characters.

### `Version`

Must be the value 0x00010000 (Version 1.0).

### `Size`

The complete size of this **WIA_MICR** header structure, in bytes, including the complete size of the [WIA_MICR_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiadef/ns-wiadef-_wia_micr_info) list.

### `Placeholder`

Placeholder for unrecognized characters.

### `Reserved`

### `Count`

Specifies the number of [WIA_MICR_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiadef/ns-wiadef-_wia_micr_info) elements in the **Micr** sequence.

### `Micr`

Placeholder for a sequence of **Count** contiguous [WIA_MICR_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiadef/ns-wiadef-_wia_micr_info) structures.

## Remarks

The header must be followed by a sequence of MICR information structures, one for each decoded MICR code, in the order the MICR codes were found and decoded.