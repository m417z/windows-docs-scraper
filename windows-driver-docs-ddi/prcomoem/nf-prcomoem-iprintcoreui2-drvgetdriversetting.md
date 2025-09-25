# IPrintCoreUI2::DrvGetDriverSetting

## Description

The `IPrintCoreUI2::DrvGetDriverSetting` method is provided by the Windows XP Pscript5 driver so that Pscript5 user interface plug-ins can obtain the current status of printer features and other internal information.

## Parameters

### `pci`

Caller-supplied pointer to an [OEMUIOBJ](https://learn.microsoft.com/windows-hardware/drivers/ddi/printoem/ns-printoem-_oemuiobj) structure.

### `Feature`

Caller-supplied value identifying the printer feature for which option settings are returned. This can be either a string pointer or a constant, as described in the following Remarks section.

### `pOutput`

Caller-supplied pointer to a buffer to receive the specified information.

### `cbSize`

Caller-supplied size, in bytes, of the buffer pointed to by *pOutput*.

### `pcbNeeded`

Caller-supplied pointer to a location to receive the minimum buffer size required to contain the requested information.

### `pdwOptionsReturned`

Caller-supplied pointer to a location to receive the number of option strings placed in *pOutput*.

## Return value

This method must return one of the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The operation succeeded. |
| **E_FAIL** | The operation failed. |
| **E_NOTIMPL** | The method is not implemented. |

## Remarks

This method is inherited from the [IPrintOemDriverUI COM Interface](https://learn.microsoft.com/windows-hardware/drivers/print/iprintoemdriverui-com-interface), and can be called only by Windows XP and later Pscript5 UI plug-ins that do not fully replace the core driver's standard UI pages, and is supported during the UI plug-in's [IPrintOemUI::DocumentPropertySheets](https://learn.microsoft.com/windows-hardware/drivers/ddi/prcomoem/nf-prcomoem-iprintoemui-documentpropertysheets) and [IPrintOemUI::DevicePropertySheets](https://learn.microsoft.com/windows-hardware/drivers/ddi/prcomoem/nf-prcomoem-iprintoemui-devicepropertysheets) functions, and their property sheet callback routines. When this method is supported, it has the same behavior as [IPrintOemDriverUI::DrvGetDriverSetting](https://learn.microsoft.com/windows-hardware/drivers/ddi/prcomoem/nf-prcomoem-iprintoemdriverui-drvgetdriversetting). When it is not supported, this method should return E_NOTIMPL.

## See also

[IPrintCoreUI2](https://learn.microsoft.com/windows-hardware/drivers/ddi/prcomoem/nn-prcomoem-iprintcoreui2)

[IPrintOemDriverUI::DrvGetDriverSetting](https://learn.microsoft.com/windows-hardware/drivers/ddi/prcomoem/nf-prcomoem-iprintoemdriverui-drvgetdriversetting)

[IPrintOemUI::DevicePropertySheets](https://learn.microsoft.com/windows-hardware/drivers/ddi/prcomoem/nf-prcomoem-iprintoemui-devicepropertysheets)

[IPrintOemUI::DocumentPropertySheets](https://learn.microsoft.com/windows-hardware/drivers/ddi/prcomoem/nf-prcomoem-iprintoemui-documentpropertysheets)