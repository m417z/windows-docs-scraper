# InkCollectorEventInterest enumeration

## Description

Defines values that are used to specify whether an event occurred on an ink collector and, if so, which event fired. To get the status of a given event, call the [GetEventInterest](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkcollector-geteventinterest) method. To set the status of a given event, call the [SetEventInterest](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkcollector-seteventinterest) method.

## Constants

### `ICEI_DefaultEvents:-1`

The ink collector is interested in the [Stroke](https://learn.microsoft.com/windows/desktop/tablet/inkcollector-stroke), [CursorInRange](https://learn.microsoft.com/windows/desktop/tablet/inkcollector-cursorinrange), and [CursorOutOfRange](https://learn.microsoft.com/windows/desktop/tablet/inkcollector-cursoroutofrange) events.

### `ICEI_CursorDown`

The ink collector detects a cursor down.

### `ICEI_Stroke`

Specifies that a new stroke is drawn on a tablet.

### `ICEI_NewPackets`

The ink collector receives a *packet*.

### `ICEI_NewInAirPackets`

The ink collector detects an in-air packet.

### `ICEI_CursorButtonDown`

The ink collector detects a cursor button down.

### `ICEI_CursorButtonUp`

The ink collector detects a cursor button up.

### `ICEI_CursorInRange`

Specifies that a cursor is detected in range of a tablet.

### `ICEI_CursorOutOfRange`

Specifies that a cursor is detected leaving the range of a tablet.

### `ICEI_SystemGesture`

The ink collector recognizes a system gesture.

### `ICEI_TabletAdded`

Specifies that a tablet was added to the system.

### `ICEI_TabletRemoved`

Specifies that a tablet was removed from the system.

### `ICEI_MouseDown`

The mouse pointer is over the object and a mouse button is pressed.

### `ICEI_MouseMove`

The mouse pointer is moved over the object.

### `ICEI_MouseUp`

The mouse pointer is over the object and a mouse button is released.

### `ICEI_MouseWheel`

The mouse wheel moves while the object has focus.

### `ICEI_DblClick`

The object was double-clicked.

### `ICEI_AllEvents`

The ink collector recognizes all events.

## See also

[GetEventInterest Method](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkcollector-geteventinterest)

[InkCollector Class](https://learn.microsoft.com/windows/desktop/tablet/inkcollector-class)

[InkOverlay Class](https://learn.microsoft.com/windows/desktop/tablet/inkoverlay-class)

[InkPicture Control Reference](https://learn.microsoft.com/windows/desktop/tablet/inkpicture-control-reference)

[SetEventInterest Method](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkcollector-seteventinterest)