# IOleWindow::ContextSensitiveHelp

## Description

Determines whether context-sensitive help mode should be entered during an in-place activation session.

## Parameters

### `fEnterMode` [in]

**TRUE** if help mode should be entered; **FALSE** if it should be exited.

## Return value

This method returns S_OK if the help mode was entered or exited successfully, depending on the value passed in *fEnterMode*. Other possible return values include the following.

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | The specified *fEnterMode* value is not valid. |
| **E_OUTOFMEMORY** | There is insufficient memory available for this operation. |
| **E_UNEXPECTED** | An unexpected error has occurred. |

## Remarks

Applications can invoke context-sensitive help when the user:

* presses SHIFT+F1, then clicks a topic
* presses F1 when a menu item is selected

When SHIFT+F1 is pressed, either the frame or active object can receive the keystrokes. If the container's frame receives the keystrokes, it calls its containing document's **IOleWindow::ContextSensitiveHelp** method with *fEnterMode* set to **TRUE**. This propagates the help state to all of its in-place objects so they can correctly handle the mouse click or WM_COMMAND.

If an active object receives the SHIFT+F1 keystrokes, it calls the container's **IOleWindow::ContextSensitiveHelp** method with *fEnterMode***TRUE**, which then recursively calls each of its in-place sites until there are no more to be notified. The container then calls its document's or frame's **IOleWindow::ContextSensitiveHelp** method with *fEnterMode***TRUE**.

When in context-sensitive help mode, an object that receives the mouse click can either:

* Ignore the click if it does not support context-sensitive help.
* Tell all the other objects to exit context-sensitive help mode with **ContextSensitiveHelp** set to **FALSE** and then provide help for that context.

An object in context-sensitive help mode that receives a WM_COMMAND should tell all the other in-place objects to exit context-sensitive help mode and then provide help for the command.

If a container application is to support context-sensitive help on menu items, it must either provide its own message filter so that it can intercept the F1 key or ask the OLE library to add a message filter by calling [OleSetMenuDescriptor](https://learn.microsoft.com/windows/desktop/api/ole2/nf-ole2-olesetmenudescriptor), passing valid, non-**NULL** values for the *lpFrame* and *lpActiveObj* parameters.

## See also

[IOleWindow](https://learn.microsoft.com/windows/desktop/api/oleidl/nn-oleidl-iolewindow)

[OleSetMenuDescriptor](https://learn.microsoft.com/windows/desktop/api/ole2/nf-ole2-olesetmenudescriptor)