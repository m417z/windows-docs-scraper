# DrvQueryJobAttributes function

## Description

The **DrvQueryJobAttributes** function allows a printer interface DLL to specify support for such capabilities as printing multiple document pages on a physical page ("N-up" printing), printing multiple copies of each page, collating pages, and printing pages in reverse order.

## Parameters

### `hPrinter` [in]

Caller-supplied printer handle.

### `pDevMode` [in]

Caller-supplied pointer to a [DEVMODEW](https://learn.microsoft.com/windows/win32/api/wingdi/ns-wingdi-devmodew) structure.

### `dwLevel` [in]

Caller-supplied value indicating the type of structure pointed to by *lpAttributeInfo*, as indicated in the following table.

| *dwLevel* value | ColumStructure pointed to by *lpAttributeInfo* |
|--|--|
| 1 | [ATTRIBUTE_INFO_1](https://learn.microsoft.com/windows-hardware/drivers/ddi/winddiui/ns-winddiui-_attribute_info_1) |
| 2 | [ATTRIBUTE_INFO_2](https://learn.microsoft.com/windows-hardware/drivers/ddi/winddiui/ns-winddiui-_attribute_info_2) |
| 3 | [ATTRIBUTE_INFO_3](https://learn.microsoft.com/windows-hardware/drivers/ddi/winddiui/ns-winddiui-_attribute_info_3) |
| 4 | [ATTRIBUTE_INFO_4](https://learn.microsoft.com/windows-hardware/drivers/ddi/winddiui/ns-winddiui-_attribute_info_4) |

### `lpAttributeInfo` [out]

Caller-supplied pointer to a structure identified by *dwLevel*.

## Return value

If the operation succeeds, the function should return **TRUE**. Otherwise, it should return **FALSE**. Returning **FALSE** causes the current print job to be canceled.

## Remarks

A [printer interface DLL](https://learn.microsoft.com/windows-hardware/drivers/print/printer-interface-dll) can optionally provide a **DrvQueryJobAttributes** function. If the function is provided, it should fill in the supplied structure, described by *dwLevel* and *plAttributeInfo*, to indicate the current print job's user-requested attributes (such as N-up parameters and the number of copies) and the driver's ability to support those attributes. The function is typically called by the EMF print processor, so it can determine which job attributes can be handled by the driver (or printer), and which must be handled by the print processor.

## See also

[ATTRIBUTE_INFO_1](https://learn.microsoft.com/windows-hardware/drivers/ddi/winddiui/ns-winddiui-_attribute_info_1)

[ATTRIBUTE_INFO_2](https://learn.microsoft.com/windows-hardware/drivers/ddi/winddiui/ns-winddiui-_attribute_info_2)

[ATTRIBUTE_INFO_3](https://learn.microsoft.com/windows-hardware/drivers/ddi/winddiui/ns-winddiui-_attribute_info_3)

[ATTRIBUTE_INFO_4](https://learn.microsoft.com/windows-hardware/drivers/ddi/winddiui/ns-winddiui-_attribute_info_4)