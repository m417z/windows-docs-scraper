## Description

> [!WARNING]
> Starting with Windows 10, the APIs which support third-party print providers are deprecated. Microsoft does not recommend any investment into third-party print providers. Additionally, on Windows 8 and newer products where the v4 print driver model is available, third-party print providers may not create or manage queues which use v4 print drivers.

A print provider's **GetJobAttributes** function gets information about a print job.

## Parameters

### `pPrinterName` [in]

Caller-supplied pointer to a NULL-terminated Unicode string containing the printer name.

### `pDevmode` [in]

Caller-supplied pointer to a [DEVMODEW](https://learn.microsoft.com/windows/win32/api/wingdi/ns-wingdi-devmodew) structure that is passed to the print processor or printer driver.

### `pAttributeInfo` [out]

Caller-supplied pointer to an [ATTRIBUTE_INFO_3](https://learn.microsoft.com/windows-hardware/drivers/ddi/winddiui/ns-winddiui-_attribute_info_3) structure that receives information about the print job.

## Return value

**GetJobAttributes** returns **TRUE** if it is successful in obtaining the print job attributes; otherwise it returns **FALSE**.

## See also

[**ATTRIBUTE_INFO_3**](https://learn.microsoft.com/windows-hardware/drivers/ddi/winddiui/ns-winddiui-_attribute_info_3)

[**DEVMODEW**](https://learn.microsoft.com/windows/win32/api/wingdi/ns-wingdi-devmodew)

[GetJobAttributesEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/winsplp/nf-winsplp-getjobattributesex)