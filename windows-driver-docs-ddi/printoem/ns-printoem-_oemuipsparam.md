## Description

The **OEMUIPSPARAM** structure is passed to a user interface plug-in's [IPrintOemUI::DevicePropertySheets](https://learn.microsoft.com/windows-hardware/drivers/ddi/prcomoem/nf-prcomoem-iprintoemui-devicepropertysheets) and [IPrintOemUI::DocumentPropertySheets](https://learn.microsoft.com/windows-hardware/drivers/ddi/prcomoem/nf-prcomoem-iprintoemui-documentpropertysheets) methods.

## Members

### `cbSize`

Size of the **OEMUIPSPARAM** structure. Supplied by the Unidrv or Pscript5 driver.

### `poemuiobj`

Not used.

### `hPrinter`

Handle to the printer. Supplied by the Unidrv or Pscript5 driver.

### `pPrinterName`

String containing the printer name. Supplied by the Unidrv or Pscript5 driver.

### `hModule`

Handle to the user interface plug-in. Supplied by the Unidrv or Pscript5 driver.

### `hOEMHeap`

Handle to a heap from which space can be allocated by calling the **HeapAlloc** function. Supplied by the Unidrv or Pscript5 driver.

### `pPublicDM`

#### For calls to IPrintOemUI::DocumentPropertySheets

Caller-supplied pointer to the printer's public **DEVMODEW** structure.

#### For calls to IPrintOemUI::DevicePropertySheets

Not used.

### `pOEMDM`

**For calls to IPrintOemUI::DocumentPropertySheets**
Caller-supplied pointer to the user interface plug-in's private **DEVMODEW** members.

**For calls to IPrintOemUI::DevicePropertySheets**
Not used.

### `pOEMUserData`

Pointer, supplied by user interface plug-in, to a location containing private information. This pointer is returned to the plug-in's [_CPSUICALLBACK](https://learn.microsoft.com/windows-hardware/drivers/ddi/compstui/nc-compstui-_cpsuicallback)-typed callback function when a property sheet item has changed.

### `dwFlags`

**For calls to IPrintOemUI::DocumentPropertySheets**
Contains the contents of the **fMode** member of the **DOCUMENTPROPERTYHEADER** structure received by the printer driver's [DrvDocumentPropertySheets](https://learn.microsoft.com/windows-hardware/drivers/ddi/winddiui/nf-winddiui-drvdocumentpropertysheets) function.

**For calls to IPrintOemUI::DevicePropertySheets**
Contains the contents of the **Flags** member of the **DEVICEPROPERTYHEADER** structure received by the printer driver's [DrvDevicePropertySheets](https://learn.microsoft.com/windows-hardware/drivers/ddi/winddiui/nf-winddiui-drvdevicepropertysheets) function.

### `pOemEntry`

Reserved for system use.

## See also

[DrvDevicePropertySheets](https://learn.microsoft.com/windows-hardware/drivers/ddi/winddiui/nf-winddiui-drvdevicepropertysheets)

[DrvDocumentPropertySheets](https://learn.microsoft.com/windows-hardware/drivers/ddi/winddiui/nf-winddiui-drvdocumentpropertysheets)

[IPrintOemUI::DevicePropertySheets](https://learn.microsoft.com/windows-hardware/drivers/ddi/prcomoem/nf-prcomoem-iprintoemui-devicepropertysheets)

[IPrintOemUI::DocumentPropertySheets](https://learn.microsoft.com/windows-hardware/drivers/ddi/prcomoem/nf-prcomoem-iprintoemui-documentpropertysheets)

[_CPSUICALLBACK](https://learn.microsoft.com/windows-hardware/drivers/ddi/compstui/nc-compstui-_cpsuicallback)