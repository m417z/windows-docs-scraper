# _WIA_BARCODES structure

## Description

The **WIA_BARCODES** structure stores header information for the barcode metadata report of one scan job (one call to [IWiaMiniDrv::drvAcquireItemData](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiamindr_lh/nf-wiamindr_lh-iwiaminidrv-drvacquireitemdata)).

## Members

### `Tag`

Must be the literal 'WBAR', 4 single byte ASCII characters.

### `Version`

Must be the value 0x00010000 (Version 1.0).

### `Size`

The complete size of this **WIA_BARCODES** header structure, in bytes, including the complete size of the [WIA_BARCODE_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiadef/ns-wiadef-_wia_barcode_info) list.

### `Count`

Specifies the number of [WIA_BARCODE_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiadef/ns-wiadef-_wia_barcode_info) elements in the Barcodes sequence.

### `Barcodes`

Placeholder for a sequence of **Count** contiguous [WIA_BARCODE_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiadef/ns-wiadef-_wia_barcode_info) structures.

## Remarks

The header must be followed by a sequence of barcode information structures, one for each decoded barcode, in the order the barcodes were found and decoded.