# IPrintCoreUI2::DrvUpdateUISetting

## Description

The `IPrintCoreUI2::DrvUpdateUISetting` method is provided by the Windows XP Pscript5 driver so that Pscript5 user interface plug-ins can notify the driver of a modified user interface option.

## Parameters

### `pci`

Caller-supplied pointer to an [OEMUIOBJ](https://learn.microsoft.com/windows-hardware/drivers/ddi/printoem/ns-printoem-_oemuiobj) structure.

### `pOptItem`

Caller-supplied pointer to an [OPTITEM](https://learn.microsoft.com/windows-hardware/drivers/ddi/compstui/ns-compstui-_optitem) structure describing a user interface option item.

### `dwPreviousSelection`

Not used.

### `dwMode`

Caller-supplied integer constant indicating to which property sheet page the supplied option item belongs. The following constants are valid.

| Value | Definition |
| --- | --- |
| OEMCUIP_DOCPROP | The supplied option item belongs to the Advanced page of the document property sheet. |
| OEMCUIP_PRNPROP | The supplied option item belongs to the Device Settings page of the printer property sheet. |
| OEMCUIP_PRNPROP | The supplied option item belongs to the Device Settings page of the printer property sheet. |

## Return value

This method must return one of the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The operation succeeded. |
| **E_FAIL** | The operation failed. |
| **E_NOTIMPL** | The method is not implemented. |

## Remarks

This method is inherited from the [IPrintOemDriverUI COM Interface](https://learn.microsoft.com/windows-hardware/drivers/print/iprintoemdriverui-com-interface), and can be called only by Windows XP Pscript5 UI plug-ins that do not fully replace the core driver's standard UI pages, and is supported during the UI plug-in's [IPrintOemUI::DocumentPropertySheets](https://learn.microsoft.com/windows-hardware/drivers/ddi/prcomoem/nf-prcomoem-iprintoemui-documentpropertysheets) and [IPrintOemUI::DevicePropertySheets](https://learn.microsoft.com/windows-hardware/drivers/ddi/prcomoem/nf-prcomoem-iprintoemui-devicepropertysheets) functions, and their property sheet callback routines. When this method is supported, it has the same behavior as [IPrintOemDriverUI::DrvUpdateUISetting](https://learn.microsoft.com/windows-hardware/drivers/ddi/prcomoem/nf-prcomoem-iprintoemdriverui-drvupdateuisetting). When it is not supported, this method should return E_NOTIMPL.

## See also

[IPrintCoreUI2](https://learn.microsoft.com/windows-hardware/drivers/ddi/prcomoem/nn-prcomoem-iprintcoreui2)

[IPrintOemDriverUI::DrvUpdateUISetting](https://learn.microsoft.com/windows-hardware/drivers/ddi/prcomoem/nf-prcomoem-iprintoemdriverui-drvupdateuisetting)

[IPrintOemUI::DevicePropertySheets](https://learn.microsoft.com/windows-hardware/drivers/ddi/prcomoem/nf-prcomoem-iprintoemui-devicepropertysheets)

[IPrintOemUI::DocumentPropertySheets](https://learn.microsoft.com/windows-hardware/drivers/ddi/prcomoem/nf-prcomoem-iprintoemui-documentpropertysheets)