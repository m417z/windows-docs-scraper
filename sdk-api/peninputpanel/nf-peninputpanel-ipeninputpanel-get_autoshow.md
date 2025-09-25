# IPenInputPanel::get_AutoShow

## Description

Deprecated. The [PenInputPanel](https://learn.microsoft.com/windows/desktop/tablet/peninputpanel-class) has been replaced by the [Text Input Panel (TIP)](https://learn.microsoft.com/windows/desktop/tablet/text-input-panel-reference).

Gets or sets a value that indicates whether the pen input panel appears when focus is set on the attached control by using the pen.

This property is read/write.

## Parameters

## Remarks

When the **AutoShow** property is set to **VARIANT_FALSE**, Tablet PC Input Panel does not show until the [Visible](https://learn.microsoft.com/windows/desktop/api/peninputpanel/nf-peninputpanel-ipeninputpanel-get_visible) property is set to **VARIANT_TRUE**. At this point, Tablet PC Input Panel is displayed but no hover target is shown.

## See also

[IPenInputPanel](https://learn.microsoft.com/windows/win32/api/peninputpanel/nn-peninputpanel-ipeninputpanel)

[PenInputPanel](https://learn.microsoft.com/windows/desktop/tablet/peninputpanel-class)