# IUIFramework::GetUICommandProperty

## Description

Retrieves a command property, value, or state.

## Parameters

### `commandId` [in]

Type: **UINT32**

The ID for the Command, which is specified in the Markup resource file.

### `key` [in]

Type: **REFPROPERTYKEY**

The property key of the command property, value, or state.

### `value` [out]

Type: **PROPVARIANT***

When this method returns, contains the property, value, or state.

## Return value

Type: **HRESULT**

Returns S_OK if successful; otherwise, an error value from the following list.

| Value | Description |
| --- | --- |
| HRESULT_FROM_WIN32(ERROR_NOT_SUPPORTED) | The property, value, or state does not support **IUIFramework::GetUICommandProperty**. |
| E_FAIL | The operation failed. |

## See also

[IUIFramework](https://learn.microsoft.com/windows/desktop/api/uiribbon/nn-uiribbon-iuiframework)

[Windows Ribbon Framework Samples](https://learn.microsoft.com/windows/desktop/windowsribbon/windowsribbon-samples-entry)