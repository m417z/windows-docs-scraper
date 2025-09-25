# IExplorerCommand::GetIcon

## Description

Gets an icon resource string of the icon associated with the specified Windows Explorer command item.

## Parameters

### `psiItemArray` [in]

Type: **[IShellItemArray](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellitemarray)***

A pointer to an [IShellItemArray](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellitemarray).

### `ppszIcon` [out]

Type: **LPWSTR***

Pointer to a buffer that, when this method returns successfully, receives the resource string that identifies the icon source.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The retrieved icon resource string is in the standard format, for instance "shell32.dll,-249".