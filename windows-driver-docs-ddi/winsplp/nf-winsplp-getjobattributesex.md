## Description

> [!WARNING]
> Starting with Windows 10, the APIs which support third-party print providers are deprecated. Microsoft does not recommend any investment into third-party print providers. Additionally, on Windows 8 and newer products where the v4 print driver model is available, third-party print providers may not create or manage queues which use v4 print drivers.

A print provider's **GetJobAttributesEx** function obtains information about a print job, including N-up and reverse printing options.

## Parameters

### `pPrinterName` [in]

Caller-supplied pointer to a NULL-terminated Unicode string that contains the printer name.

### `pDevmode` [in]

Caller-supplied pointer to a [**DEVMODEW**](https://learn.microsoft.com/windows/win32/api/wingdi/ns-wingdi-devmodew) structure that is passed to the print processor or printer driver.

### `dwLevel` [in]

Caller-supplied value that indicates the type of structure pointed to by *pAttributeInfo*, as indicated in the following table. For more information, see the **Remarks** section below.

| *dwLevel* value | Structure pointed to by *pAttributeInfo* |
|---|---|
| 1 | [ATTRIBUTE_INFO_1](https://learn.microsoft.com/windows-hardware/drivers/ddi/winddiui/ns-winddiui-_attribute_info_1) |
| 2 | [ATTRIBUTE_INFO_2](https://learn.microsoft.com/windows-hardware/drivers/ddi/winddiui/ns-winddiui-_attribute_info_2) |
| 3 | [ATTRIBUTE_INFO_3](https://learn.microsoft.com/windows-hardware/drivers/ddi/winddiui/ns-winddiui-_attribute_info_3) |
| 4 | [ATTRIBUTE_INFO_4](https://learn.microsoft.com/windows-hardware/drivers/ddi/winddiui/ns-winddiui-_attribute_info_4) |

### `pAttributeInfo` [out]

Caller-supplied pointer to an attribute information structure ([ATTRIBUTE_INFO_1](https://learn.microsoft.com/windows-hardware/drivers/ddi/winddiui/ns-winddiui-_attribute_info_1), [ATTRIBUTE_INFO_2](https://learn.microsoft.com/windows-hardware/drivers/ddi/winddiui/ns-winddiui-_attribute_info_2), [ATTRIBUTE_INFO_3](https://learn.microsoft.com/windows-hardware/drivers/ddi/winddiui/ns-winddiui-_attribute_info_3), or [ATTRIBUTE_INFO_4](https://learn.microsoft.com/windows-hardware/drivers/ddi/winddiui/ns-winddiui-_attribute_info_4)) that receives information about the print job.

### `nSize` [in]

Size of the buffer, in bytes, pointed to by *pAttributeInfo*.

### `dwFlags` [in]

If set by the caller to FILL_WITH_DEFAULTS, then the spooler will fill *pAttributeInfo* with default values from level 1 up to the level specified by *dwLevel*.

For example, if *dwLevel* is 4 and FILL_WITH_DEFAULTS is specified, *pAttributeInfo* will be filled with the following default member values of [ATTRIBUTE_INFO_4](https://learn.microsoft.com/windows-hardware/drivers/ddi/winddiui/ns-winddiui-_attribute_info_4):

**dwJobNumberOfPagesPerSide** = 1

**dwDrvNumberOfPagesPerSide** = 1

**dwNupBorderFlags** = 0

**dwJobPageOrderFlags** = 0

**dwDrvPageOrderFlags** = 0

**dwJobNumberOfCopies** = **dmCopies** member of [**DEVMODEW**](https://learn.microsoft.com/windows/win32/api/wingdi/ns-wingdi-devmodew)

**dwDrvNumberOfCopies** = **dmCopies** member of **DEVMODEW**

**dwColorOptimization** = 0

**dmPrintQuality** = **dmPrintQuality** member of **DEVMODEW**

**dmYResolution** = **dmYResolution** member of **DEVMODEW**

**dwNupDirection** = RIGHT_THEN_DOWN

**dwBookletFlags** = BOOKLET_EDGE_LEFT

**dwDuplexFlags** = 0

**dwScalingPercentX** = 100

**dwScalingPercentY** = 100

**dwJobHandlingFlags** = 0

## Return value

**GetJobAttributesEx** returns **TRUE** if it is successful in obtaining the print job attributes; otherwise, it returns **FALSE**.

## Remarks

This function first checks whether the driver supports the attribute level that is indicated by *dwLevel*. If the driver does not support that attribute level, then the function queries the driver for support for the next lower level, (*dwLevel* - 1), and continues to query for progressively lower levels of support until it obtains the level of support provided by the driver. If *dwFlags* is set to FILL_WITH_DEFAULTS, then the function fills in the default values for the unsupported levels.

## See also

[**ATTRIBUTE_INFO_3**](https://learn.microsoft.com/windows-hardware/drivers/ddi/winddiui/ns-winddiui-_attribute_info_3)

[**ATTRIBUTE_INFO_4**](https://learn.microsoft.com/windows-hardware/drivers/ddi/winddiui/ns-winddiui-_attribute_info_4)

[**DEVMODEW**](https://learn.microsoft.com/windows/win32/api/wingdi/ns-wingdi-devmodew)

[GetJobAttributes](https://learn.microsoft.com/windows-hardware/drivers/ddi/winsplp/nf-winsplp-getjobattributes)