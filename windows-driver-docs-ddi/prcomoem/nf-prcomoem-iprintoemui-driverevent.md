# IPrintOemUI::DriverEvent

## Description

The printer driver's [DrvDriverEvent](https://learn.microsoft.com/windows-hardware/drivers/ddi/winddiui/nf-winddiui-drvdriverevent) function calls a user interface plug-in's `IPrintOemUI::DriverEvent` method for additional processing of printer driver events.

## Parameters

### `dwDriverEvent`

Caller-supplied bit flag indicating the event that has occurred. Valid flags are listed in the following table.

| Flag | Definition |
| --- | --- |
| DRIVER_EVENT_DELETE | The driver is being removed. |
| DRIVER_EVENT_INITIALIZE | The driver has just been installed. |

### `dwLevel`

Caller-supplied value indicating the type of structure pointed to by the *pDriverInfo* parameter, as indicated in the following table.

| *dwLevel* Value | Structure pointed to by *pDriverInfo* |
| --- | --- |
| 1 | DRIVER_INFO_1 |
| 2 | DRIVER_INFO_2 |
| 3 | DRIVER_INFO_3 |

The DRIVER_INFO_*N* structures are described in the Microsoft Windows SDK documentation.

### `pDriverInfo`

Caller-supplied pointer to a structure whose type is identified by the *dwLevel* parameter.

### `lParam`

Caller-supplied flags. See the following Remarks section.

## Return value

The method must return one of the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The operation succeeded. |
| **E_FAIL** | The operation failed. |
| **E_NOTIMPL** | The method is not implemented. |

## Remarks

A user interface plug-in's `IPrintOemUI::DriverEvent` method performs the same types of operations as the **DrvDriverEvent** function that is exported by user-mode printer interface DLLs. For information about driver events and how they should be processed, see the description of the [DrvDriverEvent](https://learn.microsoft.com/windows-hardware/drivers/ddi/winddiui/nf-winddiui-drvdriverevent) function.

If you provide a user interface plug-in, the printer driver's **DrvDriverEvent** function calls the `IPrintOemUI::DriverEvent` method. The **DrvDriverEvent** function performs its own processing for the specified event, and then calls the `IPrintOemUI::DriverEvent` method to handle additional processing of the event.

If `IPrintOemUI::DriverEvent` methods are exported by multiple user interface plug-ins, the methods are called in the order that the plug-ins are specified for installation.

For more information about creating and installing user interface plug-ins, see [Customizing Microsoft's Printer Drivers](https://learn.microsoft.com/windows-hardware/drivers/print/customizing-microsoft-s-printer-drivers).

## See also

[DrvDriverEvent](https://learn.microsoft.com/windows-hardware/drivers/ddi/winddiui/nf-winddiui-drvdriverevent)

[IPrintOemUI](https://learn.microsoft.com/windows-hardware/drivers/ddi/prcomoem/nn-prcomoem-iprintoemui)