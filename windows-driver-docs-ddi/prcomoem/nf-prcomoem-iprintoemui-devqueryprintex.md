# IPrintOemUI::DevQueryPrintEx

## Description

The `IPrintOemUI::DevQueryPrintEx` method allows a user interface plug-in to help determine if a print job is printable.

## Parameters

### `poemuiobj`

Caller-supplied pointer to an [OEMUIOBJ](https://learn.microsoft.com/windows-hardware/drivers/ddi/printoem/ns-printoem-_oemuiobj) structure.

### `pDQPInfo`

Caller-supplied pointer to a [DEVQUERYPRINT_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/winddiui/ns-winddiui-_devqueryprint_info) structure.

### `pPublicDM`

Caller-supplied pointer to a validated [DEVMODEW](https://learn.microsoft.com/windows/win32/api/wingdi/ns-wingdi-devmodew) structure.

### `pOEMDM`

Caller-supplied pointer to the user interface plug-in's private DEVMODEW structure members.

## Return value

The method must return one of the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The operation succeeded. |
| **E_FAIL** | The operation failed. |
| **E_NOTIMPL** | The method is not implemented. |

## Remarks

A user interface plug-in's `IPrintOemUI::DevQueryPrintEx` method performs the same types of operations as the [DevQueryPrintEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/winddiui/nf-winddiui-devqueryprintex) function that is exported by user-mode printer interface DLLs. You can use this method to enhance the functionality provided by the **DevQueryPrintEx** function. Like the **DevQueryPrintEx** function, the `IPrintOemUI::DevQueryPrintEx` method's responsibility is to determine if the print job described by the supplied DEVMODEW structure can be printed.

When the driver's **DevQueryPrintEx** function is called, it checks the DEVMODEW structure, along with the currently selected printer options, to determine if the job is printable. If it is not, the function returns **FALSE**. If the job appears to be printable, the function calls the `IPrintOemUI::DevQueryPrintEx` method in each user interface plug-in associated with the driver. If all `IPrintOemUI::DevQueryPrintEx` methods return S_OK, then **DevQueryPrintEx** returns **TRUE**. Thus, a job is not printable unless the **DevQueryPrintEx** function and all `IPrintOemUI::DevQueryPrintEx` methods declare it to be printable.

If `IPrintOemUI::DevQueryPrintEx` methods are exported by multiple user interface plug-ins, the methods are called in the order that the plug-ins are specified for installation.

For more information about creating and installing user interface plug-ins, see [Customizing Microsoft's Printer Drivers](https://learn.microsoft.com/windows-hardware/drivers/print/customizing-microsoft-s-printer-drivers).

## See also

[DevQueryPrintEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/winddiui/nf-winddiui-devqueryprintex)