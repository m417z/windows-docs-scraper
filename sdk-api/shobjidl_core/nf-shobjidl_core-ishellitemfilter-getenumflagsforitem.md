# IShellItemFilter::GetEnumFlagsForItem

## Description

Allows a client to specify which classes of objects in a [Shell item](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellitem) should be enumerated for inclusion in the view.

## Parameters

### `psi` [in]

Type: **[IShellItem](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellitem)***

A pointer to the [Shell item](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellitem) for which the [SHCONTF](https://learn.microsoft.com/windows/win32/api/shobjidl_core/ne-shobjidl_core-_shcontf) enum flags are to be retrieved.

### `pgrfFlags` [out]

Type: **[SHCONTF](https://learn.microsoft.com/windows/win32/api/shobjidl_core/ne-shobjidl_core-_shcontf)***

A pointer to the [SHCONTF](https://learn.microsoft.com/windows/win32/api/shobjidl_core/ne-shobjidl_core-_shcontf) enum flags for the given [Shell item](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellitem) that specifies which classes of objects to enumerate for inclusion in the view.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IShellItem](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellitem)

[IShellItemFilter](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellitemfilter)

[SHCONTF](https://learn.microsoft.com/windows/win32/api/shobjidl_core/ne-shobjidl_core-_shcontf)