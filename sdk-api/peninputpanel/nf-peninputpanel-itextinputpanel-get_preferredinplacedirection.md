# ITextInputPanel::get_PreferredInPlaceDirection

## Description

[[ITextInputPanel](https://learn.microsoft.com/windows/desktop/api/peninputpanel/nn-peninputpanel-itextinputpanel) is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions. Instead, use [IInputPanelConfiguration](https://learn.microsoft.com/windows/desktop/api/inputpanelconfiguration/nn-inputpanelconfiguration-iinputpanelconfiguration).

]

Gets or sets the preferred direction of the in-place Input Panel relative to the text entry field.

This property is read/write.

## Parameters

## Remarks

An application can specify whether the in-place Input Panel defaults to appearing above or below a text entry field. To do this the application can set the **ITextInputPanel::PreferredInPlaceDirection Property** to [InPlaceDirection_Bottom](https://learn.microsoft.com/windows/win32/api/peninputpanel/ne-peninputpanel-inplacedirection) or **InPlaceDirection_Top**. **ITextInputPanel::PreferredInPlaceDirection Property** is a preference because the in-place Input Panel overrides the preference set by the application when necessary to keep Input Panel on the screen. The system default is to position the in-place Input Panel below a text field when possible and otherwise to position it above. Setting the **PreferredInPlaceDirection** to **InPlaceDirection_Auto** restores the system default.

#### Examples

This C++ example creates an [ITextInputPanel](https://learn.microsoft.com/windows/desktop/api/peninputpanel/nn-peninputpanel-itextinputpanel) object, `g_pTip`, and attaches it to the window handle of an [InkEdit](https://learn.microsoft.com/windows/desktop/tablet/inkedit-control-reference) control, `IDC_EDIT3`, by setting the [ITextInputPanel::AttachedEditWindow Property](https://learn.microsoft.com/windows/desktop/api/peninputpanel/nf-peninputpanel-itextinputpanel-get_attachededitwindow) property. It also sets, then gets the **ITextInputPanel::PreferredInPlaceDirection Property**.

```cpp
if (SUCCEEDED(CoInitialize(NULL)))
{
    if (SUCCEEDED(CoCreateInstance(CLSID_TextInputPanel, NULL, CLSCTX_INPROC, IID_ITextInputPanel, (VOID**)&g_pTip)))
    {
        if (SUCCEEDED(g_pTip->put_AttachedEditWindow(GetDlgItem(IDC_EDIT3)->m_hWnd)))
        {
            g_pTip->put_DefaultInPlaceState(InPlaceState_Expanded);
            InPlaceState ips;
            g_pTip->get_DefaultInPlaceState(&ips);
            TRACE("DefaultInplaceState: %d\n", ips);

            g_pTip->put_DefaultInputArea(PanelInputArea_CharacterPad);
            PanelInputArea pia;
            g_pTip->get_DefaultInputArea(&pia);
            TRACE("DefaultInputArea: %d\n", pia);

            g_pTip->put_ExpandPostInsertionCorrection(FALSE);
            BOOL epic;
            g_pTip->get_ExpandPostInsertionCorrection(&epic);
            TRACE("ExpandPostInsertionCorrection: %d\n", epic);

            g_pTip->put_InPlaceVisibleOnFocus(TRUE);
            BOOL ipvof;
            g_pTip->get_InPlaceVisibleOnFocus(&ipvof);
            TRACE("InPlaceVisibleOnFocus: %d\n", ipvof);

            g_pTip->put_PreferredInPlaceDirection(InPlaceDirection_Top);
            InPlaceDirection direction;
            g_pTip->get_PreferredInPlaceDirection(&direction);
            TRACE("PreferredInPlaceDirection: %d\n", direction);
        }
    }
    else
    {
        TRACE("Failed to create ITextInputPanel object.\n");
    }
}

```

## See also

[ITextInputPanel Interface](https://learn.microsoft.com/windows/desktop/api/peninputpanel/nn-peninputpanel-itextinputpanel)