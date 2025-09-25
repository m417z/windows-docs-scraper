# IEnumShellItems::Next

## Description

Gets an array of one or more [IShellItem](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellitem) interfaces from the enumeration.

## Parameters

### `celt` [in]

Type: **ULONG**

The number of elements in the array referenced by the *rgelt* parameter.

### `rgelt` [out]

Type: **[IShellItem](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellitem)****

The address of an array of pointers to [IShellItem](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellitem) interfaces that receive the enumerated item or items. The calling application is responsible for freeing the **IShellItem** interfaces by calling the [IUnknown::Release](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-release) method.

### `pceltFetched` [out]

Type: **ULONG***

A pointer to a value that receives the number of [IShellItem](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellitem) interfaces successfully retrieved. The count can be smaller than the value specified in the *celt* parameter. This parameter can be **NULL** on entry only if *celt* is one, because in that case the method can only retrieve one item and return **S_OK**, or zero items and return **S_FALSE**.

## Return value

Type: **HRESULT**

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | if at least [IShellItem](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellitem) interface was retrieved. |
| **S_FALSE** | if there are no more [IShellItem](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellitem) interfaces in the enumeration. |
|  | Returns an error value if the function fails for any other reason. |

## See also

[IEnumShellItems](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ienumshellitems)

[IShellItem](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellitem)