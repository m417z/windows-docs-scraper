# IShellLinkA::SetHotkey

## Description

Sets a keyboard shortcut (hot key) for a Shell link object.

## Parameters

### `wHotkey`

Type: **WORD**

The new keyboard shortcut. The virtual key code is in the low-order byte, and the modifier flags are in the high-order byte. The modifier flags can be a combination of the values specified in the description of the [IShellLink::GetHotkey](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ishelllinka-gethotkey) method.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

Setting a keyboard shortcut allows the user to activate the object by pressing a particular combination of keys.