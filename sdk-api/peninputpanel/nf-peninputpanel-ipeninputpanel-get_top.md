# IPenInputPanel::get_Top

## Description

Deprecated. The [PenInputPanel](https://learn.microsoft.com/windows/desktop/tablet/peninputpanel-class) has been replaced by the [Text Input Panel (TIP)](https://learn.microsoft.com/windows/desktop/tablet/text-input-panel-reference).

Gets the vertical, or y-axis, location of the top edge of the [PenInputPanel](https://learn.microsoft.com/windows/desktop/tablet/peninputpanel-class) object, in screen coordinates.

This property is read-only.

## Parameters

## Remarks

To explicitly override the automatic positioning behavior of the [PenInputPanel](https://learn.microsoft.com/windows/desktop/tablet/peninputpanel-class) object, use the [Left](https://learn.microsoft.com/windows/desktop/api/peninputpanel/nf-peninputpanel-ipeninputpanel-get_left) and **Top** properties of the object to determine the current position of the pen input panel. If the pen input panel is located on a section of the screen that should be visible, use the [MoveTo](https://learn.microsoft.com/windows/desktop/api/peninputpanel/nf-peninputpanel-ipeninputpanel-moveto) method to relocate the pen input panel.

You can also override the automatic positioning behavior of the [PenInputPanel](https://learn.microsoft.com/windows/desktop/tablet/peninputpanel-class) object by listening for the *Left* and *Top* parameters during a [PanelMoving](https://learn.microsoft.com/windows/desktop/tablet/peninputpanel-panelmoving) event. If the pen input panel is located on a section of the screen that should be visible, use the [MoveTo](https://learn.microsoft.com/windows/desktop/api/peninputpanel/nf-peninputpanel-ipeninputpanel-moveto) method to relocate the pen input panel.

## See also

[IPenInputPanel](https://learn.microsoft.com/windows/win32/api/peninputpanel/nn-peninputpanel-ipeninputpanel)

[Left Property [PenInputPanel Class]](https://learn.microsoft.com/windows/desktop/api/peninputpanel/nf-peninputpanel-ipeninputpanel-get_left)

[PenInputPanel](https://learn.microsoft.com/windows/desktop/tablet/peninputpanel-class)