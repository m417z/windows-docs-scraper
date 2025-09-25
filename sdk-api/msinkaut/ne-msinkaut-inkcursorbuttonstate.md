# InkCursorButtonState enumeration

## Description

Defines values that specify the state of a cursor button.

## Constants

### `ICBS_Unavailable:0`

The cursor button is unavailable. A cursor button may become unavailable, for example, when a cursor leaves the range of Tablet PC.

### `ICBS_Up`

The cursor button is up. A button on a pen tip is up when the pen is not pressed against the digitizer. A button on a pen barrel is up when the button is not depressed.

### `ICBS_Down`

The cursor button is down. A button on a pen tip is down when the user lowers the pen to the digitizer and draws a stroke. For a button on a barrel, the button is down when the button is depressed.

## Remarks

The CursorButton state for the mouse is always **CursorUnavailable** when the mouse buttons are up.

## See also

[CursorInRange Event](https://learn.microsoft.com/windows/desktop/tablet/inkcollector-cursorinrange)

[State Property](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkcursorbutton-get_state)