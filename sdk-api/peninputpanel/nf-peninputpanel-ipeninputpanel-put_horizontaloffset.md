# IPenInputPanel::put_HorizontalOffset

## Description

Deprecated. The [PenInputPanel](https://learn.microsoft.com/windows/desktop/tablet/peninputpanel-class) has been replaced by the [Text Input Panel (TIP)](https://learn.microsoft.com/windows/desktop/tablet/text-input-panel-reference).

Gets or sets the offset between the left edge of the pen input panel and the left edge of the control to which it is attached.

This property is read/write.

## Parameters

## Remarks

The default value is the equivalent of 0.25 inches in pixels, dependent on screen resolution settings. A negative value indicates a shift to the left of the control. A positive value indicates a shift to the right. A zero value indicates that the left edge of the pen input panel is positioned exactly at the left edge of the control.

If the new position causes the panel to appear outside the boundary of the screen working area, the panel is shifted toward the center of the working area so that the edges of the panel are adjacent to the nearest edges of the screen.

## See also

[IPenInputPanel](https://learn.microsoft.com/windows/win32/api/peninputpanel/nn-peninputpanel-ipeninputpanel)

[PenInputPanel](https://learn.microsoft.com/windows/desktop/tablet/peninputpanel-class)

[VerticalOffset Property](https://learn.microsoft.com/windows/desktop/api/peninputpanel/nf-peninputpanel-ipeninputpanel-get_verticaloffset)