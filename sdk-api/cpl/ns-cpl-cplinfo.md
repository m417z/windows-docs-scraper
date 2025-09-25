## Description

Contains resource information and an application-defined value for a dialog box supported by a Control Panel application. The [CPlApplet](https://learn.microsoft.com/windows/desktop/api/cpl/nc-cpl-applet_proc) function of the Control Panel application returns this information to the Control Panel in response to a [CPL_INQUIRE](https://learn.microsoft.com/windows/desktop/shell/fa-perceivedtypes) message.

## Members

### `idIcon`

Type: **int**

The resource identifier of the icon that represents the dialog box.

### `idName`

Type: **int**

The resource identifier of the string containing the short name for the dialog box. This name is intended to be displayed below the icon.

### `idInfo`

Type: **int**

The resource identifier of the string containing the description for the dialog box that is intended to be displayed when the application icon is selected.

### `lData`

Type: **LONG_PTR**

A pointer to data defined by the application. When the Control Panel sends the [CPL_DBLCLK](https://learn.microsoft.com/windows/desktop/shell/fa-associationarray) and [CPL_STOP](https://learn.microsoft.com/windows/desktop/shell/library-functions-bumper) messages, it passes this value back to your application.

## Remarks

If the icon or display strings of the dialog box can change based on the state of the computer, you can specify the CPL_DYNAMIC_RES value for the **idIcon**, **idName**, or **idInfo** members rather than specifying a valid resource identifier. This causes the Control Panel to send the [CPL_NEWINQUIRE](https://learn.microsoft.com/windows/desktop/shell/glossary) message each time it needs the icon and display strings. Using this technique is significantly slower, however, because the Control Panel will need to load your application each time it sends the **CPL_NEWINQUIRE** message.