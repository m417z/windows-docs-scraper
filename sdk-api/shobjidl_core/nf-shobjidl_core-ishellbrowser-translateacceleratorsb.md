# IShellBrowser::TranslateAcceleratorSB

## Description

Translates accelerator keystrokes intended for the browser's frame while the view is active.

## Parameters

### `pmsg`

Type: **LPMSG**

The address of an [MSG](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-msg) structure containing the keystroke message.

### `wID`

Type: **WORD**

The command identifier value corresponding to the keystroke in the container-provided accelerator table. Containers should use this value instead of translating again.

## Return value

Type: **HRESULT**

Returns **S_OK** if successful, or a COM-defined error value otherwise.

## Remarks

This method is similar to the [IOleInPlaceFrame::TranslateAccelerator](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-ioleinplaceframe-translateaccelerator) method.

## See also

[IShellBrowser](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellbrowser)