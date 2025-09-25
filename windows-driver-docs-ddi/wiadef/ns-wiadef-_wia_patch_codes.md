# _WIA_PATCH_CODES structure

## Description

The **WIA_PATCH_CODES** structure stores header information for the patch code metadata report of one scan job (one call to [IWiaMiniDrv::drvAcquireItemData](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiamindr_lh/nf-wiamindr_lh-iwiaminidrv-drvacquireitemdata)).

## Members

### `Tag`

Must be the literal 'WBAT', 4 single byte ASCII characters.

### `Version`

Must be the value 0x00010000 (Version 1.0).

### `Size`

The complete size of this **WIA_PATCH_CODES** header structure, in bytes, including the complete size of the [WIA_PATCH_CODES_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiadef/ns-wiadef-_wia_patch_code_info) list.

### `Count`

Specifies the number of [WIA_PATCH_CODES_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiadef/ns-wiadef-_wia_patch_code_info) elements in the PatchCodes sequence.

### `PatchCodes`

Placeholder for a sequence of **Count** contiguous [WIA_PATCH_CODES_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiadef/ns-wiadef-_wia_patch_code_info) structures.

## Remarks

The header must be followed by a sequence of patch code information structures, one for each detected patch code, in the order the patch codes were found and decoded.