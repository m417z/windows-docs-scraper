# InkSystemGesture enumeration

## Description

Specifies the interest in a set of operating system-specific gestures.

## Constants

### `ISG_Tap:0x10`

A click of the left mouse button. This can be used to choose a command from the menu or toolbar, take action if a command is chosen, set an insertion point (IP), or show selection feedback.

### `ISG_DoubleTap:0x11`

A double-click of the left mouse button. This can be used to select a word or open a file or folder.

### `ISG_RightTap:0x12`

A click of the right mouse button. This can be used to show a shortcut menu.

### `ISG_Drag:0x13`

A drag of the mouse while pressing the left mouse button. This can be used to drag-select (such as in Microsoft Word when starting with an IP), select multiple words, drag (such as when dragging an object in Microsoft Windows), or scroll.

### `ISG_RightDrag:0x14`

A press and hold followed by a stroke, which maps to a right drag of a mouse. This can be used to drag (such as when dragging an object or selection followed by a shortcut menu).

### `ISG_HoldEnter:0x15`

A press and hold of the left mouse button that lasts for a long time, which has no mouse equivalent. This is a fallback for when a user continues a press-and-hold action for a long time and the event reverts to a Tap.

### `ISG_HoldLeave:0x16`

Not implemented.

### `ISG_HoverEnter:0x17`

A pause of the mouse on an object. This can be used to show a ToolTip, roll-over effects, or other mouse pausing behaviors.

### `ISG_HoverLeave:0x18`

A mouse leaving a pause. This can be used to end ToolTip roll-over effects or other mouse pausing behaviors.

### `ISG_Flick:0x1f`

A flick gesture.

## Remarks

The flick gesture is recognized in Windows Vista and later versions of Windows.

The Windows Vista and Tablet PC operating systems support these gestures by default. When any of these gestures are recognized, the [SystemGesture](https://learn.microsoft.com/windows/desktop/tablet/inkcollector-systemgesture) event fires automatically. Many of these gestures map to traditional mouse events. For instance, the Tap system gesture mimics a click of the left mouse button.

A system gesture is separate from an application gesture. Application gestures are defined in the [InkApplicationGesture](https://learn.microsoft.com/windows/desktop/api/msinkaut/ne-msinkaut-inkapplicationgesture) enumeration type.

For more information about system gestures, see [Using Gestures](https://learn.microsoft.com/windows/desktop/tablet/using-gestures).

## See also

[GetHotPoint Method](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkgesture-gethotpoint)

[InkCollector Class](https://learn.microsoft.com/windows/desktop/tablet/inkcollector-class)

[InkOverlay Class](https://learn.microsoft.com/windows/desktop/tablet/inkoverlay-class)

[InkPicture Control Reference](https://learn.microsoft.com/windows/desktop/tablet/inkpicture-control-reference)

[SystemGesture Event [InkPicture Control]](https://learn.microsoft.com/windows/desktop/tablet/inkpicture-systemgesture)

[Using Gestures](https://learn.microsoft.com/windows/desktop/tablet/using-gestures)