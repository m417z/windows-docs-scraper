# IUICommandHandler::Execute

## Description

Responds to execute events on Commands bound to the Command handler.

## Parameters

### `commandId` [in]

Type: **UINT32**

The ID for the Command, which is specified in the Markup resource file.

### `verb` [in]

Type: **[UI_EXECUTIONVERB](https://learn.microsoft.com/windows/desktop/api/uiribbon/ne-uiribbon-ui_executionverb)**

The [UI_EXECUTIONVERB](https://learn.microsoft.com/windows/desktop/api/uiribbon/ne-uiribbon-ui_executionverb) or action that is initiated by the user.

### `key` [in, optional]

Type: **const PROPERTYKEY***

A pointer to a [Property Key](https://learn.microsoft.com/windows/desktop/windowsribbon/windowsribbon-reference-properties) that has changed value. This parameter can be **NULL**.

### `currentValue` [in, optional]

Type: **const PROPVARIANT***

A pointer to the current value for *key*. This parameter can be **NULL**.

### `commandExecutionProperties` [in, optional]

Type: **[IUISimplePropertySet](https://learn.microsoft.com/windows/desktop/api/uiribbon/nn-uiribbon-iuisimplepropertyset)***

A pointer to an [IUISimplePropertySet](https://learn.microsoft.com/windows/desktop/api/uiribbon/nn-uiribbon-iuisimplepropertyset) object that contains
Command state properties and property values, such as screen coordinates and list item indices. This parameter can be **NULL**.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

Each Command in a View must be bound to a new or existing Command handler in the host application.

## See also

[IUICommandHandler](https://learn.microsoft.com/windows/desktop/api/uiribbon/nn-uiribbon-iuicommandhandler)

[Windows Ribbon Framework Samples](https://learn.microsoft.com/windows/desktop/windowsribbon/windowsribbon-samples-entry)