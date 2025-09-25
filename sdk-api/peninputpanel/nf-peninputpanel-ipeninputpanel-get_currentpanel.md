# IPenInputPanel::get_CurrentPanel

## Description

Deprecated. The [PenInputPanel](https://learn.microsoft.com/windows/desktop/tablet/peninputpanel-class) has been replaced by the [Text Input Panel (TIP)](https://learn.microsoft.com/windows/desktop/tablet/text-input-panel-reference).

Gets or sets which panel type is currently being used for input within the [PenInputPanel](https://learn.microsoft.com/windows/desktop/tablet/peninputpanel-class) object.

This property is read/write.

## Parameters

## Remarks

**Note** The **CurrentPanel** property cannot be set to [Default](https://learn.microsoft.com/windows/desktop/api/peninputpanel/ne-peninputpanel-paneltype) or **Inactive**, only **Handwriting** or **Keyboard**.

When you create a [PenInputPanel](https://learn.microsoft.com/windows/desktop/tablet/peninputpanel-class) object, the [Handwriting](https://learn.microsoft.com/windows/desktop/api/peninputpanel/ne-peninputpanel-paneltype) panel - also known as the writing pad - is the default input UI.

If you change the panel by setting the **CurrentPanel** property before the [PenInputPanel](https://learn.microsoft.com/windows/desktop/tablet/peninputpanel-class) object becomes active for the first time, a [PanelChanged](https://learn.microsoft.com/windows/desktop/tablet/peninputpanel-panelchanged) event occurs.

**CurrentPanel** returns the [Inactive](https://learn.microsoft.com/windows/desktop/api/peninputpanel/ne-peninputpanel-paneltype) enumeration value if the panel window is associated with another instance of the [PenInputPanel](https://learn.microsoft.com/windows/desktop/tablet/peninputpanel-class) object. Setting the **CurrentPanel** property raises an exception if the panel is inactive or if the panel type is invalid.

## See also

[DefaultPanel Property](https://learn.microsoft.com/windows/desktop/api/peninputpanel/nf-peninputpanel-ipeninputpanel-get_defaultpanel)

[IPenInputPanel](https://learn.microsoft.com/windows/win32/api/peninputpanel/nn-peninputpanel-ipeninputpanel)

[PanelType Enumeration](https://learn.microsoft.com/windows/desktop/api/peninputpanel/ne-peninputpanel-paneltype)

[PenInputPanel](https://learn.microsoft.com/windows/desktop/tablet/peninputpanel-class)