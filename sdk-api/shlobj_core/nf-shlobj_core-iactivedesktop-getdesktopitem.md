# IActiveDesktop::GetDesktopItem

## Description

Gets the specified desktop item.

## Parameters

### `nComponent`

Type: **int**

An unsigned long integer value that contains the desktop item's index. The index values start at zero. Use [IActiveDesktop::GetDesktopItemCount](https://learn.microsoft.com/windows/desktop/api/shlobj_core/nf-shlobj_core-iactivedesktop-getdesktopitemcount) to retrieve a count on the total number of desktop items.

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

The index values will change as desktop items are added and removed from the Active Desktop. Applications cannot assume that an index value will always be associated with a particular desktop item.

## See also

[IActiveDesktop](https://learn.microsoft.com/windows/desktop/api/shlobj_core/nn-shlobj_core-iactivedesktop)