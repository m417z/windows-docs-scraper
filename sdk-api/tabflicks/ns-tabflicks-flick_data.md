# FLICK_DATA structure

## Description

Contains information about a pen flick.

## Members

### `iFlickActionCommandCode`

The flick action assigned to the pen flick.

### `iFlickDirection`

The direction of the pen flick.

### `fControlModifier`

**TRUE** if the pen flick action activates the CTRL key; otherwise, **FALSE**.

### `fMenuModifier`

**TRUE** if the pen flick action activates the ALT key; otherwise, **FALSE**.

### `fAltGRModifier`

**TRUE** if the pen flick action activates the ALT GR key; otherwise, **FALSE**.

### `fWinModifier`

**TRUE** if the pen flick action activates the Windows Logo key; otherwise, **FALSE**.

### `fShiftModifier`

**TRUE** if the pen flick action activates the SHIFT key; otherwise, **FALSE**.

### `iReserved`

Do not use.

### `fOnInkingSurface`

**TRUE** if the pen flick is sent to an inking surface; otherwise, **FALSE**.

### `iActionArgument`

Contains additional information about **iFlickActionCommandCode**.

## Remarks

Windows Vista sends the **FLICK_DATA** structure to an application along with the [WM_TABLET_FLICK Message](https://learn.microsoft.com/windows/desktop/tablet/wm-tablet-flick-message) when a pen flick occurs.

The value of *iActionArgument* depends on the value of *iFlickActionCommandCode*. For example, if *iFlickCommandCode* is FLICKACTION_COMMANDCODE_SCROLL, the value of *iActionArgument* is one of the values in the [SCROLLDIRECTION Enumeration](https://learn.microsoft.com/windows/desktop/api/tabflicks/ne-tabflicks-scrolldirection).

If *iFlickCommandCode* is **FLICKACTION_COMMANDCODE_CUSTOMKEY**, the value of *iActionArgument* indicates the key stroke. The *fControlModifier*, *fMenuModifier*, *fAltGRModifier*, *fWinModifier*, and *fShiftModifier* fields indicate whether the pen action activates a modifier key. For example, if the user assigns a pen flick to the key stroke, CTRL+N, *fControlModifier* is **true** and *iActionArgument* is the virtual code key, VK_N.

## See also

[FLICKACTION_COMMANDCODE Enumeration](https://learn.microsoft.com/windows/desktop/api/tabflicks/ne-tabflicks-flickaction_commandcode)

[flickdirection enumeration](https://learn.microsoft.com/windows/desktop/api/tabflicks/ne-tabflicks-flickdirection)

[flicks gestures](https://learn.microsoft.com/windows/desktop/tablet/flicks-gestures)

[responding to pen flicks](https://learn.microsoft.com/previous-versions/windows/desktop/ms703447(v=vs.85))

[wm_tablet_flick message](https://learn.microsoft.com/windows/desktop/tablet/wm-tablet-flick-message)