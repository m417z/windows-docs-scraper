# IPrintOemDriverUI::DrvUpdateUISetting

## Description

The `IPrintOemDriverUI::DrvUpdateUISetting` method is provided by the Unidrv and Pscript5 minidrivers so that user interface plug-ins can notify the driver of a modified user interface option.

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

For more information, see the following Remarks section.

## Return value

The method must return one of the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The operation succeeded. |
| **E_FAIL** | The operation failed. |
| **E_NOTIMPL** | The method is not implemented. |

## Remarks

If you are providing a user interface plug-in that implements the [IPrintOemUI::DocumentPropertySheets](https://learn.microsoft.com/windows-hardware/drivers/ddi/prcomoem/nf-prcomoem-iprintoemui-documentpropertysheets) method or the [IPrintOemUI::DevicePropertySheets](https://learn.microsoft.com/windows-hardware/drivers/ddi/prcomoem/nf-prcomoem-iprintoemui-devicepropertysheets) method, you typically also supply a [_CPSUICALLBACK](https://learn.microsoft.com/windows-hardware/drivers/ddi/compstui/nc-compstui-_cpsuicallback)-typed callback function to handle user modifications. This callback function must call `IPrintOemDriverUI::DrvUpdateUISetting` to inform the driver when the value associated with a user interface setting has been modified, if the value is stored in the driver's [DEVMODEW](https://learn.microsoft.com/windows/win32/api/wingdi/ns-wingdi-devmodew) structure (instead of the plug-in's private DEVMODEW members ) or in registry keys.

The value specified for *dwMode* should be based on which method specified the callback function.