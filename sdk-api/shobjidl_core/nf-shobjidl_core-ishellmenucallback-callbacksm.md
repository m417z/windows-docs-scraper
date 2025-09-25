# IShellMenuCallback::CallbackSM

## Description

Receives messages from a menu band object.

## Parameters

### `psmd` [in, out]

Type: **LPSMDATA**

A pointer to a [SMDATA](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/ns-shobjidl_core-smdata) structure that contains information about the menu.

### `uMsg`

Type: **UINT**

A message ID. This will be one of the SMC_XXX values. See [Shell Messages and Notifications](https://learn.microsoft.com/windows/desktop/shell/control-panel-applications) for a complete list.

### `wParam`

Type: **WPARAM**

A WPARAM value that contains additional information. See the specific SMC_XXX message reference for details.

### `lParam`

Type: **LPARAM**

An LPARAM value that contains additional information. See the specific SMC_XXX message reference for details.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.