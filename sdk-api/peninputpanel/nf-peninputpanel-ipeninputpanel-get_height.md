# IPenInputPanel::get_Height

## Description

Deprecated. The [PenInputPanel](https://learn.microsoft.com/windows/desktop/tablet/peninputpanel-class) has been replaced by the [Text Input Panel (TIP)](https://learn.microsoft.com/windows/desktop/tablet/text-input-panel-reference).

Gets the height of the pen input panel in client coordinates.

This property is read-only.

## Parameters

## Remarks

The height of the pen input panel is dependent on the screen resolution for the particular Tablet PC. The panel height is the number of pixels equal to 1.25 inches. The default value at 96 dots per inch (dpi) is 157 pixels. The default value at 120 dpi is 196 pixels. The default value at 133 dpi is 218 pixels.

Starting with Microsoft Windows XP Tablet PC Edition 2005, the Tablet PC Input Panel allows the user to continue entering handwriting by automatically increasing the size of the Tablet PC Input Panel to accommodate new handwriting. The **Height** and [Width](https://learn.microsoft.com/windows/desktop/api/peninputpanel/nf-peninputpanel-ipeninputpanel-get_width) properties do not update to reflect the new size as the Tablet PC Input Panel grows. These properties return the original size of the Tablet PC Input Panel. They also do not report the dimensions of the Tablet PC Input Panel hover target.

## See also

[IPenInputPanel](https://learn.microsoft.com/windows/win32/api/peninputpanel/nn-peninputpanel-ipeninputpanel)

[PenInputPanel](https://learn.microsoft.com/windows/desktop/tablet/peninputpanel-class)

[Width Property [PenInputPanel Class]](https://learn.microsoft.com/windows/desktop/api/peninputpanel/nf-peninputpanel-ipeninputpanel-get_width)