# IUIFramework::SetUICommandProperty

## Description

Sets a command property, value, or state.

## Parameters

### `commandId` [in]

Type: **UINT32**

The ID for the Command, which is specified in the Markup resource file.

### `key` [in]

Type: **REFPROPERTYKEY**

The property key of the command property, value, or state.

### `value` [in]

Type: **PROPVARIANT**

The property, value, or state.

## Return value

Type: **HRESULT**

Returns S_OK if successful, otherwise an error value from the following list.

| Value | Description |
| --- | --- |
| HRESULT_FROM_WIN32(ERROR_NOT_SUPPORTED) | The property, value, or state does not support **IUIFramework::SetUICommandProperty**. They may support being set through invalidation only. |
| E_FAIL | The operation failed. |

## Remarks

A limited number of property keys can be set using **IUIFramework::SetUICommandProperty**. For those properties where **IUIFramework::SetUICommandProperty** returns **HRESULT_FROM_WIN32(ERROR_NOT_SUPPORTED)**, [IUIFramework::InvalidateUICommand](https://learn.microsoft.com/windows/desktop/api/uiribbon/nf-uiribbon-iuiframework-invalidateuicommand) should be used instead.

For more information on how to set a property key for a specific control, see the [Windows Ribbon Framework Control Library](https://learn.microsoft.com/windows/desktop/windowsribbon/windowsribbon-controls-entry) page for that control.

## See also

[IUIFramework](https://learn.microsoft.com/windows/desktop/api/uiribbon/nn-uiribbon-iuiframework)

[Windows Ribbon Framework Samples](https://learn.microsoft.com/windows/desktop/windowsribbon/windowsribbon-samples-entry)