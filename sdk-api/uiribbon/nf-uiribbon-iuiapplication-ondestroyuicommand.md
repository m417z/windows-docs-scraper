# IUIApplication::OnDestroyUICommand

## Description

Called for each Command specified in the Windows Ribbon framework markup when the application window is destroyed.

## Parameters

### `commandId` [in]

Type: **UINT32**

The ID for the Command, which is specified in the markup resource file.

### `typeID` [in]

Type: **[UI_COMMANDTYPE](https://learn.microsoft.com/windows/desktop/api/uiribbon/ne-uiribbon-ui_commandtype)**

The [Command type](https://learn.microsoft.com/windows/desktop/api/uiribbon/ne-uiribbon-ui_commandtype) that is associated with a specific control.

### `commandHandler` [in, optional]

Type: **[IUICommandHandler](https://learn.microsoft.com/windows/desktop/api/uiribbon/nn-uiribbon-iuicommandhandler)***

A pointer to an [IUICommandHandler](https://learn.microsoft.com/windows/desktop/api/uiribbon/nn-uiribbon-iuicommandhandler) object. This value can be **NULL**.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

This callback notification is sent by the Ribbon framework to the host application for each Command declaration in the markup resource file.

All resources in the host application associated with each Command are released.

#### Examples

The following example demonstrates a basic implementation of the **IUIApplication::OnDestroyUICommand** method.

```cpp
//
//  FUNCTION:    OnDestroyUICommand(UINT, UI_COMMANDTYPE, IUICommandHandler*)
//
//  PURPOSE:    Called for each Command specified in the Ribbon markup
//                when the Ribbon host application window is destroyed.
//
//  PARAMETERS:
//                nCmdID - The Command identifier.
//                typeID - The Command type.
//                commandHandler - The Command handler.
//
//  COMMENTS:
//
//
STDMETHODIMP CApplication::OnDestroyUICommand(
    UINT32 nCmdID,
    UI_COMMANDTYPE typeID,
    IUICommandHandler* commandHandler)
{
    return E_NOTIMPL;
}

```

## See also

[IUIApplication](https://learn.microsoft.com/windows/desktop/api/uiribbon/nn-uiribbon-iuiapplication)

[Windows Ribbon Framework Samples](https://learn.microsoft.com/windows/desktop/windowsribbon/windowsribbon-samples-entry)