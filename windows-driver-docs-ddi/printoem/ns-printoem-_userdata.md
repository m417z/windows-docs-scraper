## Description

The **USERDATA** structure is used by [Unidrv](https://learn.microsoft.com/windows-hardware/drivers/) and [Pscript](https://learn.microsoft.com/windows-hardware/drivers/) to specify additional information about printer features. A **USERDATA** structure pointer is supplied as the **UserData** member for each [**OPTITEM**](https://learn.microsoft.com/windows-hardware/drivers/ddi/compstui/ns-compstui-_optitem) structure.

## Members

### `dwSize`

Size, in bytes, of the **USERDATA** structure.

### `dwItemID`

Printer feature identifier.

### `pKeyWordName`

Pointer to a non-localized text string identifying a printer feature.

### `dwReserved`

Reserved.