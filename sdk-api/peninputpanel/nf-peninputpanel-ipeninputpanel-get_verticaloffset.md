# IPenInputPanel::get_VerticalOffset

## Description

Deprecated. The [PenInputPanel](https://learn.microsoft.com/windows/desktop/tablet/peninputpanel-class) has been replaced by the [Text Input Panel (TIP)](https://learn.microsoft.com/windows/desktop/tablet/text-input-panel-reference).

Gets or sets the offset between the closest horizontal edge of the pen input panel and the closest horizontal edge of the control to which it is attached.

This property is read/write.

## Parameters

## Remarks

The default value is the equivalent of 1/16 inches in pixels, dependent on screen resolution settings. A value of 0 (zero) attaches the [PenInputPanel](https://learn.microsoft.com/windows/desktop/tablet/peninputpanel-class) object directly to the bottom of the control. A value of -1 places it 1 pixel above the control.

If the new position of the [PenInputPanel](https://learn.microsoft.com/windows/desktop/tablet/peninputpanel-class) causes the panel to appear outside the boundary of the screen working area, the panel is shifted toward the center of the working area so that the edges of the panel are adjacent to the nearest edges of the screen.

## See also

[HorizontalOffset Property](https://learn.microsoft.com/windows/desktop/api/peninputpanel/nf-peninputpanel-ipeninputpanel-get_horizontaloffset)

[IPenInputPanel](https://learn.microsoft.com/windows/win32/api/peninputpanel/nn-peninputpanel-ipeninputpanel)

[PenInputPanel](https://learn.microsoft.com/windows/desktop/tablet/peninputpanel-class)