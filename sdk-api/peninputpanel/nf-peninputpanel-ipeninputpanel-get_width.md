# IPenInputPanel::get_Width

## Description

Deprecated. The [PenInputPanel](https://learn.microsoft.com/windows/desktop/tablet/peninputpanel-class) has been replaced by the [Text Input Panel (TIP)](https://learn.microsoft.com/windows/desktop/tablet/text-input-panel-reference).

Gets the width of the pen input panel in client coordinates.

This property is read-only.

## Parameters

## Remarks

The width of the [PenInputPanel](https://learn.microsoft.com/windows/desktop/tablet/peninputpanel-class) object is dependent on the screen resolution for the particular Tablet PC. The default value at 96 dots per inch (dpi) is 570 pixels. The default value at 120 dpi is 712 pixels. The default value at 133 dpi is 790 pixels.

Starting with Microsoft Windows XP Tablet PC Edition 2005, the Tablet PC Input Panel allows the user to continue entering handwriting by automatically increasing the size of the Tablet PC Input Panel to accommodate new handwriting. The [Height](https://learn.microsoft.com/windows/desktop/api/peninputpanel/nf-peninputpanel-ipeninputpanel-get_height) and **Width** properties do not update to reflect the new size as the Tablet PC Input Panel grows. These properties return the original size of the Tablet PC Input Panel. They also do not report the dimensions of the Tablet PC Input Panel hover target.

## See also

[Height Property [PenInputPanel Class]](https://learn.microsoft.com/windows/desktop/api/peninputpanel/nf-peninputpanel-ipeninputpanel-get_height)

[IPenInputPanel](https://learn.microsoft.com/windows/win32/api/peninputpanel/nn-peninputpanel-ipeninputpanel)

[PenInputPanel](https://learn.microsoft.com/windows/desktop/tablet/peninputpanel-class)