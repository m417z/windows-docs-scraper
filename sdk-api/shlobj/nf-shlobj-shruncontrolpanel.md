# SHRunControlPanel function

## Description

Opens a Control Panel item.

**Note** This function is not supported as of Windows Vista

## Parameters

### `lpcszCmdLine` [in]

Type: **PCWSTR**

Pointer to a string that contains the command line that opens the Control Panel item. This command line includes at least the name of the .cpl file. It can also contain any other necessary information such as the property sheet page within the item (either by ordinal or by name). For more information, see [Executing Control Panel Items](https://learn.microsoft.com/windows/desktop/shell/executing-control-panel-items).

### `hwndMsgParent` [in, optional]

Type: **HWND**

The handle of the parent window, used to display error messages about the opening of the item. This value can be **NULL**.

## Return value

Type: **BOOL**

**TRUE** if the Control Panel item was opened successfully; otherwise, **FALSE**.

As of Windows Vista, this function always returns **FALSE**.

## Remarks

If the specified Control Panel item is already running, **SHRunControlPanel** attempts to switch to that instance rather than opening a new instance.

#### Examples

Example calls to **SHRunControlPanel** are shown here.

``` syntax
SHRunControlPanel(TEXT("timedate.cpl"), hwnd);
SHRunControlPanel(L"appwiz.cpl", NULL);
SHRunControlPanel(L"appwiz.cpl,2", NULL);
SHRunControlPanel("desk.cpl,Settings", hwnd
```