# ITransferAdviseSink::ConfirmOverwrite

## Description

Displays a message to the user confirming that overwriting existing items is acceptable.

## Parameters

### `psiSource`

Type: **[IShellItem](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellitem)***

A pointer to the source [IShellItem](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellitem) .

### `psiDestParent`

Type: **[IShellItem](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellitem)***

A pointer to the destination parent folder [IShellItem](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellitem).

### `pszName`

Type: **LPCWSTR**

A pointer to a wide-string containing the desired name of the item at the destination. If **NULL**, the name is the same as the Shell item pointed to by *psiSource*.

## Return value

Type: **HRESULT**

The return values listed below are emitted specifically by this method to inform the calling process of how the operation ended. If other results or errors are emitted during the operation of this method, they should be returned to the calling process.

| Return code | Description |
| --- | --- |
| **COPYENGINE_S_USER_IGNORED** | The user clicked **Ignore**. Allows the calling process to continue processing other files as appropriate. |
| **COPYENGINE_E_USER_CANCELLED** | The user clicked **Cancel**. Stops processing of the current document and ends the current process. |