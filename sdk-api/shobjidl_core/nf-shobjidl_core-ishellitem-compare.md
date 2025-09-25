# IShellItem::Compare

## Description

Compares two [IShellItem](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellitem) objects.

## Parameters

### `psi`

Type: **[IShellItem](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellitem)***

A pointer to an [IShellItem](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellitem) object to compare with the existing **IShellItem** object.

### `hint`

Type: **[SICHINTF](https://learn.microsoft.com/windows/win32/api/shobjidl_core/ne-shobjidl_core-_sichintf)**

One of the [SICHINTF](https://learn.microsoft.com/windows/win32/api/shobjidl_core/ne-shobjidl_core-_sichintf) values that determines how to perform the comparison. See **SICHINTF** for the list of possible values for this parameter.

### `piOrder`

Type: **int***

This parameter receives the result of the comparison. If the two items are the same this parameter equals zero; if they are different the parameter is nonzero.

## Return value

Type: **HRESULT**

Returns S_OK if the items are the same, S_FALSE if they are different, or an error value otherwise.

## Remarks

The data type used in the second parameter, SICHINTF, is defined as:

```
typedef DWORD SICHINTF;
```

## See also

[IShellFolder](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellfolder)

[IShellItem](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellitem)