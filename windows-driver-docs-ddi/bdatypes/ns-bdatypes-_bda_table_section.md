# _BDA_TABLE_SECTION structure

## Description

The BDA_TABLE_SECTION structure describes a table section.

## Members

### `ulPrimarySectionId`

Identifier of the primary table section.

### `ulSecondarySectionId`

Identifier of the secondary table section.

### `ulcbSectionLength`

Size, in bytes, of the **argbSectionData** array.

### `argbSectionData`

Array of table section data.

## See also

[KSPROPSETID_BdaTableSection](https://learn.microsoft.com/windows-hardware/drivers/stream/kspropsetid-bdatablesection)