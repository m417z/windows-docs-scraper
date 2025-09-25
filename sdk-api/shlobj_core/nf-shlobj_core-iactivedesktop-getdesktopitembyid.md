# IActiveDesktop::GetDesktopItemByID

## Description

Gets the desktop item that matches the given identification.

## Parameters

### `dwID`

Type: **ULONG_PTR**

An unsigned long integer value that contains the desktop item's identification.

### `pcomp` [in, out]

Type: **LPCOMPONENT**

The address of the [COMPONENT](https://learn.microsoft.com/windows/desktop/api/shlobj_core/ns-shlobj_core-component) structure of the retrieved desktop item.

### `dwReserved`

Type: **DWORD**

Reserved. Must be set to zero.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The desktop item's identification is returned in the **dwID** member of the [COMPONENT](https://learn.microsoft.com/windows/desktop/api/shlobj_core/ns-shlobj_core-component) structure that is returned from the [IActiveDesktop::GetDesktopItem](https://learn.microsoft.com/windows/desktop/api/shlobj_core/nf-shlobj_core-iactivedesktop-getdesktopitem) method. This identification is only valid until the [IActiveDesktop::ApplyChanges](https://learn.microsoft.com/windows/desktop/api/shlobj_core/nf-shlobj_core-iactivedesktop-applychanges) method is called. Applications that must retrieve the same desktop item consistently should enumerate the desktop items using the **IActiveDesktop::GetDesktopItem** and [IActiveDesktop::GetDesktopItemCount](https://learn.microsoft.com/windows/desktop/api/shlobj_core/nf-shlobj_core-iactivedesktop-getdesktopitemcount) methods.

## See also

[IActiveDesktop](https://learn.microsoft.com/windows/desktop/api/shlobj_core/nn-shlobj_core-iactivedesktop)