# IPenInputPanel::get_DefaultPanel

## Description

Deprecated. The [PenInputPanel](https://learn.microsoft.com/windows/desktop/tablet/peninputpanel-class) has been replaced by the [Text Input Panel (TIP)](https://learn.microsoft.com/windows/desktop/tablet/text-input-panel-reference).

Gets or sets the default panel type used for input within the [PenInputPanel](https://learn.microsoft.com/windows/desktop/tablet/peninputpanel-class) object.

This property is read/write.

## Parameters

## Remarks

**Note** The **DefaultPanel** property cannot be set to [Inactive](https://learn.microsoft.com/windows/desktop/api/peninputpanel/ne-peninputpanel-paneltype).

The [Handwriting](https://learn.microsoft.com/windows/desktop/api/peninputpanel/ne-peninputpanel-paneltype) panel-also known as the writing pad-is the default input UI for a [PenInputPanel](https://learn.microsoft.com/windows/desktop/tablet/peninputpanel-class).

If the value of this property is [Default](https://learn.microsoft.com/windows/desktop/api/peninputpanel/ne-peninputpanel-paneltype), then the [PenInputPanel](https://learn.microsoft.com/windows/desktop/tablet/peninputpanel-class) object uses the last panel type used for any pen input panel in any application. If all previous references to the pen input panel have been destroyed in all active applications, a new **PenInputPanel** object uses the **Handwriting** panel type.

If the panel is changed by setting the [CurrentPanel](https://learn.microsoft.com/windows/desktop/api/peninputpanel/nf-peninputpanel-ipeninputpanel-get_currentpanel) property before the [PenInputPanel](https://learn.microsoft.com/windows/desktop/tablet/peninputpanel-class) object becomes active for the first time, a [PanelChanged](https://learn.microsoft.com/windows/desktop/tablet/peninputpanel-panelchanged) event occurs.

Setting the **DefaultPanel** property enables you to specify which type of panel shows by default in that instance of the [PenInputPanel](https://learn.microsoft.com/windows/desktop/tablet/peninputpanel-class) object. If the value of this property is [Handwriting](https://learn.microsoft.com/windows/desktop/api/peninputpanel/ne-peninputpanel-paneltype) or **Keyboard**, then each time the panel is made visible, it uses the handwriting or keyboard panel type, respectively.

If you re-attach the [PenInputPanel](https://learn.microsoft.com/windows/desktop/tablet/peninputpanel-class) to a different control and change the **DefaultPanel** property when the focus changes to the new control, be sure to set the **DefaultPanel** property before setting the [AttachedEditWindow](https://learn.microsoft.com/windows/desktop/api/peninputpanel/nf-peninputpanel-ipeninputpanel-get_attachededitwindow) property to ensure that the correct panel is displayed.

## See also

[CurrentPanel Property](https://learn.microsoft.com/windows/desktop/api/peninputpanel/nf-peninputpanel-ipeninputpanel-get_currentpanel)

[IPenInputPanel](https://learn.microsoft.com/windows/win32/api/peninputpanel/nn-peninputpanel-ipeninputpanel)

[PanelType Enumeration](https://learn.microsoft.com/windows/desktop/api/peninputpanel/ne-peninputpanel-paneltype)

[PenInputPanel](https://learn.microsoft.com/windows/desktop/tablet/peninputpanel-class)