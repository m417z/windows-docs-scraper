# IExecuteCommand::SetPosition

## Description

Sets the coordinates of a point used for display.

## Parameters

### `pt` [in]

Type: **[POINT](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-point)**

The screen coordinates at which the user right-clicked to invoke the shortcut menu from which a command was chosen. Applications can use this information to present any UI. This is particularly useful in a multi-monitor situation. The default position is the center of the default monitor.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.