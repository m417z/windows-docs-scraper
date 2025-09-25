# IEnumShellItems::Skip

## Description

Skips a given number of [IShellItem](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellitem) interfaces in the enumeration. Used when retrieving interfaces.

## Parameters

### `celt` [in]

Type: **ULONG**

The number of [IShellItem](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellitem) interfaces to skip.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IEnumShellItems](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ienumshellitems)

[IShellItem](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellitem)