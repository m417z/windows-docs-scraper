# HotkeyPrefix enumeration

## Description

The **HotkeyPrefix** enumeration specifies how to display hot keys. There are three options: do nothing, display hot keys underlined, and hide the hot key underlines.

## Constants

### `HotkeyPrefixNone:0`

Specifies that no hot key processing occurs.

### `HotkeyPrefixShow:1`

Specifies that Unicode text is scanned for ampersands (&), which are interpreted as hot key markers in the same way as menu and dialog resources are processed in the Windows user interface. All pairs of ampersands are replaced by a single ampersand. All single ampersands are removed and the first character that follows the first single ampersand is displayed underlined.

### `HotkeyPrefixHide:2`

Specifies that Unicode text is scanned for ampersands (&), which are substituted and removed as in HotkeyPrefixShow but no underline is shown. This option can be used when accessibility hot key underlines are not required.

## Remarks

Hot keys are keys that are programmed to provide keyboard shortcuts to functionality and are activated by pressing the ALT key. The keys are application dependent and are identified by an underscored letter, typically in a menu. An example would be the
**File** menu with the letter F underscored. This makes the F key a hot key to launch the
**File** menu.