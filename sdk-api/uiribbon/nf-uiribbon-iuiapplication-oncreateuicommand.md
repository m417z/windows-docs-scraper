# IUIApplication::OnCreateUICommand

## Description

Called for each Command specified in the Windows Ribbon framework markup to bind the Command to an [IUICommandHandler](https://learn.microsoft.com/windows/desktop/api/uiribbon/nn-uiribbon-iuicommandhandler).

## Parameters

### `commandId` [in]

Type: **UINT32**

The ID for the Command, which is specified in the markup resource file.

### `typeID` [in]

Type: **[UI_COMMANDTYPE](https://learn.microsoft.com/windows/desktop/api/uiribbon/ne-uiribbon-ui_commandtype)**

The [Command type](https://learn.microsoft.com/windows/desktop/api/uiribbon/ne-uiribbon-ui_commandtype) that is associated with a specific control.

### `commandHandler` [out]

Type: **[IUICommandHandler](https://learn.microsoft.com/windows/desktop/api/uiribbon/nn-uiribbon-iuicommandhandler)****

When this method returns, contains the address of a pointer to an
[IUICommandHandler](https://learn.microsoft.com/windows/desktop/api/uiribbon/nn-uiribbon-iuicommandhandler) object. This object is a host application
Command handler that is bound to one or more Commands.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

This callback notification is sent by the Ribbon framework to the host application for each Command declaration encountered
while processing the markup resource file.

For each Command specified in the Ribbon markup, the Ribbon framework requires a Command handler in the host application.
A new or existing handler must be assigned to each Command.

#### Examples

The following example demonstrates a basic implementation of the **IUIApplication::OnCreateUICommand** method.

```cpp
//
//  FUNCTION: OnCreateUICommand(UINT, UI_COMMANDTYPE, IUICommandHandler)
//
//  PURPOSE: Called by the Ribbon framework for each command specified in markup to allow
//           the host application to bind a command handler to that command.
//
//  PARAMETERS:
//                nCmdID - The Command identifier.
//                typeID - The Command type.
//                ppCommandHandler - Pointer to the address of the Command handler.
//
//  COMMENTS:
//
//    For this sample, return the same command handler for all commands
//    specified in the .xml file.
//
//
STDMETHODIMP CApplication::OnCreateUICommand(
    UINT nCmdID,
    UI_COMMANDTYPE typeID,
    IUICommandHandler** ppCommandHandler)
{
    HRESULT hr = E_NOTIMPL;

    switch(typeID)
    {
        case UI_COMMANDTYPE_DECIMAL:
            {
                _cwprintf(L"IUIApplication::OnCreateUICommand called for Spinner.\r\n");
                hr = _spSpinnerSite->QueryInterface(IID_PPV_ARGS(ppCommandHandler));
                break;
            }
        default:
            {
                _cwprintf(L"IUIApplication::OnCreateUICommand called with CmdID=%u, typeID=%u.\r\n", nCmdID, typeID);
                hr = _spCommandHandler->QueryInterface(IID_PPV_ARGS(ppCommandHandler));
            }
    }
    return hr;
}

```

## See also

[IUIApplication](https://learn.microsoft.com/windows/desktop/api/uiribbon/nn-uiribbon-iuiapplication)

[Windows Ribbon Framework Samples](https://learn.microsoft.com/windows/desktop/windowsribbon/windowsribbon-samples-entry)