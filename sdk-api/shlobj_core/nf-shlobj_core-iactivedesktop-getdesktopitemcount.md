# IActiveDesktop::GetDesktopItemCount

## Description

Gets a count of the desktop items.

## Parameters

### `pcItems` [out]

Type: **int***

A pointer to an **int** value that, when this method returns successfully, contains the count.

### `dwReserved`

Type: **DWORD**

Reserved. Must be set to zero.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The value pointed to by *pcItems* can be used to enumerate all desktop items. Desktop items have index values which start at zero and go to one less than the value pointed to by *pcItems*.

## See also

[IActiveDesktop](https://learn.microsoft.com/windows/desktop/api/shlobj_core/nn-shlobj_core-iactivedesktop)