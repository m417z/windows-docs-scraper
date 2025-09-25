# IPrintOemUI2::HideStandardUI

## Description

The `IPrintOemUI2::HideStandardUI` method allows a user interface plug-in to specify whether the standard property sheets should be displayed or hidden. Beginning with Microsoft Windows XP, this method can be implemented by a Pscript5 user interface plug-in. Beginning with Windows Vista, this method can be implemented by a Unidrv user interface plug-in.

## Parameters

### `dwMode`

Specifies which type of property sheet UI -- document property sheet or device property sheet -- to hide. This parameter should be set to one of the following constants, which are defined in printoem.h:

| Value | Meaning |
| --- | --- |
| OEMCUIP_DOCPROP | Hide standard document property sheet UI. |
| OEMCUIP_PRNPROP | Hide standard device property sheet UI. |

## Return value

On success, this method should return S_OK. Otherwise, it should return E_NOTIMPL. See Remarks for additional information.

## Remarks

This method is supported in Windows Vista for Pscript 5 and Unidrv plug-ins, and in Windows XP only for Pscript5 plug-ins.

Within the [DrvDocumentPropertySheets](https://learn.microsoft.com/windows-hardware/drivers/ddi/winddiui/nf-winddiui-drvdocumentpropertysheets) or [DrvDevicePropertySheets](https://learn.microsoft.com/windows-hardware/drivers/ddi/winddiui/nf-winddiui-drvdevicepropertysheets) DDIs when pPSUIInfo-->Reason is set to PROPSHEETUI_REASON_INIT, the driver calls the `IPrintOemUI2::HideStandardUI` method to ask the UI plug-in about user interface requests. This method can respond in any of four ways:

1. Hide standard document property sheet UI.
2. Hide standard device property sheet UI.
3. Hide all standard property sheet UI.
4. Do not hide any standard property sheet UI.

The following table summarizes how the `IPrintOemUI2::HideStandardUI` method would respond in each of these situations.

| To indicate this response... | IPrintOemUI2::HideStandardUI returns... |
| --- | --- |
| Hide standard document property sheet UI. The plug-in implements its own document property sheet UI. | If *dwMode* == OEMCUIP_DOCPROP, return S_OK; otherwise return E_NOTIMPL. |
| Hide standard device property sheet UI. The plug-in implements its own device property sheet UI. | If *dwMode* == OEMCUIP_PRNPROP, return S_OK; otherwise return E_NOTIMPL. |
| Hide all standard property sheet UI. The plug-in implements its own document property sheet and device property sheet UI. | Return S_OK, regardless of the value of *dwMode*. |
| Display all standard property sheet UI. | Return E_NOTIMPL, regardless of the value of *dwMode*. |

If the `IPrintOemUI2::HideStandardUI` method indicates to the driver that all standard property sheets should be hidden, the driver omits calls to compstui.dll (see [Pscript Components](https://learn.microsoft.com/windows-hardware/drivers/print/pscript-components)) to add the standard property sheets. A UI plug-in must implement at least one custom property sheet UI if `IPrintOemUI2::HideStandardUI` returns S_OK.

When the printer has multiple UI plug-ins installed, the driver calls UI plug-ins in the order they were installed, until one of them returns S_OK, or until all of the UI plug-ins have been called and none of them returned S_OK. The former case indicates to the driver that the standard property sheet UI should be hidden. The latter case indicates to the driver that the standard property sheet UI should be displayed.

## See also

[DrvDevicePropertySheets](https://learn.microsoft.com/windows-hardware/drivers/ddi/winddiui/nf-winddiui-drvdevicepropertysheets)

[DrvDocumentPropertySheets](https://learn.microsoft.com/windows-hardware/drivers/ddi/winddiui/nf-winddiui-drvdocumentpropertysheets)

[IPrintOemUI2](https://learn.microsoft.com/windows-hardware/drivers/ddi/prcomoem/nn-prcomoem-iprintoemui2)