# IPrintOemUI::DocumentPropertySheets

## Description

The `IPrintOemUI::DocumentPropertySheets` method allows a user interface plug-in to append a new page to a printer device's document property sheet.

## Parameters

### `pPSUIInfo`

Caller-supplied pointer to a [PROPSHEETUI_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/compstui/ns-compstui-_propsheetui_info) structure.

### `lParam`

Caller-supplied value that depends on the reason value in *pPSUIInfo*-->**Reason**. The reason value can be one of the following constants, which are defined in compstui.h. For more information about these constants, see the Remarks section and *lParam* parameter description in the [PFNPROPSHEETUI](https://learn.microsoft.com/windows-hardware/drivers/ddi/compstui/nc-compstui-pfnpropsheetui) function type.

PROPSHEETUI_REASON_DESTROY

PROPSHEETUI_REASON_GET_ICON

PROPSHEETUI_REASON_GET_INFO_HEADER

PROPSHEETUI_REASON_INIT

PROPSHEETUI_REASON_SET_RESULT

## Return value

The return value depends on the contents of the PROPSHEETUI_INFO structure's **Reason** member. For more information, see the description of [DrvDocumentPropertySheets](https://learn.microsoft.com/windows-hardware/drivers/ddi/winddiui/nf-winddiui-drvdocumentpropertysheets).

## Remarks

A user interface plug-in's `IPrintOemUI::DocumentPropertySheets` method performs the same types of operations as the [DrvDocumentPropertySheets](https://learn.microsoft.com/windows-hardware/drivers/ddi/winddiui/nf-winddiui-drvdocumentpropertysheets) function that is exported by user-mode printer interface DLLs. Both functions have the same input parameters.

If you provide a user interface plug-in, the `IPrintOemUI::DocumentPropertySheets` method is called after the driver's **DrvDocumentPropertySheets** function is called.

When `IPrintOemUI::DocumentPropertySheets` is called, the **lParamInit** member of the [PROPSHEETUI_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/compstui/ns-compstui-_propsheetui_info) structure contains the address of an [OEMUIPSPARAM](https://learn.microsoft.com/windows-hardware/drivers/ddi/printoem/ns-printoem-_oemuipsparam) structure.

If you implement this method, you typically also supply a [_CPSUICALLBACK](https://learn.microsoft.com/windows-hardware/drivers/ddi/compstui/nc-compstui-_cpsuicallback)-typed callback function to handle user modifications. This callback function must call [IPrintOemDriverUI::DrvUpdateUISetting](https://learn.microsoft.com/windows-hardware/drivers/ddi/prcomoem/nf-prcomoem-iprintoemdriverui-drvupdateuisetting) to inform the driver when the value associated with a user interface setting has been modified, if the value is stored in the driver's [DEVMODEW](https://learn.microsoft.com/windows/win32/api/wingdi/ns-wingdi-devmodew) structure (instead of the plug-in's private DEVMODEW members ) or in registry keys.

If `IPrintOemUI::DocumentPropertySheets` methods are exported by multiple user interface plug-ins, the methods are called in the order that the plug-ins are specified for installation.

If one user interface plug-in supports several printer models, and if you only want the new page to be displayed for some of those models, the `IPrintOemUI::DocumentPropertySheets` method should just provide a success return value, without actually adding the page, for the models not requiring the page.

For more information about creating and installing user interface plug-ins, see [Customizing Microsoft's Printer Drivers](https://learn.microsoft.com/windows-hardware/drivers/print/customizing-microsoft-s-printer-drivers).

## See also

[DrvDocumentPropertySheets](https://learn.microsoft.com/windows-hardware/drivers/ddi/winddiui/nf-winddiui-drvdocumentpropertysheets)

[IPrintOemUI](https://learn.microsoft.com/windows-hardware/drivers/ddi/prcomoem/nn-prcomoem-iprintoemui)

[IPrintOemUI::DevicePropertySheets](https://learn.microsoft.com/windows-hardware/drivers/ddi/prcomoem/nf-prcomoem-iprintoemui-devicepropertysheets)

[PFNPROPSHEETUI](https://learn.microsoft.com/windows-hardware/drivers/ddi/compstui/nc-compstui-pfnpropsheetui)