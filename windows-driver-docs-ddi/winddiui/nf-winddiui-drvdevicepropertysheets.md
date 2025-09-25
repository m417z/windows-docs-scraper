## Description

A printer interface DLL's **DrvDevicePropertySheets** function is responsible for creating property sheet pages that describe a printer's properties.

## Parameters

### `pPSUIInfo` [in, optional]

Caller-supplied pointer to a [**PROPSHEETUI_INFO**](https://learn.microsoft.com/windows-hardware/drivers/ddi/compstui/ns-compstui-_propsheetui_info) structure.

### `lParam`

Caller-supplied integer value that is dependent on the contents of the **Reason** member of the PROPSHEETUI_INFO structure, as listed in the following table.

| Reason value | Definition of *lParam* |
|---|---|
| PROPSHEETUI_REASON_INIT | Pointer to a [**DEVICEPROPERTYHEADER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/winddiui/ns-winddiui-_devicepropertyheader) structure. |
| All other reason values | See the description of the *lParam* parameter for the [PFNPROPSHEETUI](https://learn.microsoft.com/windows-hardware/drivers/ddi/compstui/nc-compstui-pfnpropsheetui) function type. (The [**DEVICEPROPERTYHEADER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/winddiui/ns-winddiui-_devicepropertyheader) structure's address is contained in the **lParamInit** member of the [**PROPSHEETUI_INFO**](https://learn.microsoft.com/windows-hardware/drivers/ddi/compstui/ns-compstui-_propsheetui_info) structure.) |

## Return value

See the ReturnValue section in the description of the [PFNPROPSHEETUI](https://learn.microsoft.com/windows-hardware/drivers/ddi/compstui/nc-compstui-pfnpropsheetui) function type.

## Remarks

All [printer interface DLLs](https://learn.microsoft.com/windows-hardware/drivers/print/printer-interface-dll) must provide a **DrvDevicePropertySheets** function, which is defined using the [PFNPROPSHEETUI](https://learn.microsoft.com/windows-hardware/drivers/ddi/compstui/nc-compstui-pfnpropsheetui) function type. The function's purpose is to call the [ComPropSheet](https://learn.microsoft.com/windows-hardware/drivers/ddi/compstui/nc-compstui-pfncompropsheet) function, provided by [CPSUI](https://learn.microsoft.com/windows-hardware/drivers/print/common-property-sheet-user-interface), to specify a property sheet page containing user-modifiable properties for the printer.

The function should perform operations as described for the [PFNPROPSHEETUI](https://learn.microsoft.com/windows-hardware/drivers/ddi/compstui/nc-compstui-pfnpropsheetui) function type. The function should create the printer's DeviceSettings property sheet page (see the **pDlgPage** member of the [**COMPROPSHEETUI**](https://learn.microsoft.com/windows-hardware/drivers/ddi/compstui/ns-compstui-_compropsheetui) structure).

Printer device settings should be stored in the registry. If a user with administrator privilege modifies options on the DeviceSettings page, the **DrvDevicePropertySheets** function should write the updated values to the registry by calling SetPrinterData (described in the Microsoft Windows SDK documentation).

## See also

[DrvDocumentPropertySheets](https://learn.microsoft.com/windows-hardware/drivers/ddi/winddiui/nf-winddiui-drvdocumentpropertysheets)

[IPrintOemUI::DevicePropertySheets](https://learn.microsoft.com/windows-hardware/drivers/ddi/prcomoem/nf-prcomoem-iprintoemui-devicepropertysheets)