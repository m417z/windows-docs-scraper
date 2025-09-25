# IShellLinkW::GetHotkey

## Description

Gets the keyboard shortcut (hot key) for a Shell link object.

## Parameters

### `pwHotkey`

Type: **WORD***

The address of the keyboard shortcut. The virtual key code is in the low-order byte, and the modifier flags are in the high-order byte. The modifier flags can be a combination of the following values.

#### HOTKEYF_ALT

ALT key

#### HOTKEYF_CONTROL

CTRL key

#### HOTKEYF_EXT

Extended key

#### HOTKEYF_SHIFT

SHIFT key

##### - pwHotkey.HOTKEYF_ALT

ALT key

##### - pwHotkey.HOTKEYF_CONTROL

CTRL key

##### - pwHotkey.HOTKEYF_EXT

Extended key

##### - pwHotkey.HOTKEYF_SHIFT

SHIFT key

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.