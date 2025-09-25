# ITextInputPanel::put_InPlaceVisibleOnFocus

## Description

[[ITextInputPanel](https://learn.microsoft.com/windows/desktop/api/peninputpanel/nn-peninputpanel-itextinputpanel) is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions. Instead, use [IInputPanelConfiguration](https://learn.microsoft.com/windows/desktop/api/inputpanelconfiguration/nn-inputpanelconfiguration-iinputpanelconfiguration).

]

Gets or sets a value that indicates whether the Tablet PC Input Panel is displayed automatically when the window to which it is attached gets focus.

This property is read/write.

## Parameters

## Remarks

If **ITextInputPanel::InPlaceVisibleOnFocus Property** is set to **TRUE** for a control, then when the control gains focus, the Tablet PC Input Panel automatically shows in the default [InPlaceState Enumeration](https://learn.microsoft.com/windows/win32/api/peninputpanel/ne-peninputpanel-inplacestate) provided it is a legal operation.

It is possible to prevent the in-place Input Panel and the Input Panel Icon from ever appearing by setting the **ITextInputPanel::InPlaceVisibleOnFocus Property** to **FALSE**. Setting it to **TRUE** reverts it to the system default of appearing when possible, provided it has not been disabled by the user or Group Policy. This option is useful for applications that include custom text entry solutions as an alternative to the Input Panel.

The default value is **TRUE**.

#### Examples

This C++ example creates an [ITextInputPanel](https://learn.microsoft.com/windows/desktop/api/peninputpanel/nn-peninputpanel-itextinputpanel) object, `g_pTip`, and attaches it to the window handle of an [InkEdit](https://learn.microsoft.com/windows/desktop/tablet/inkedit-control-reference) control, `IDC_EDIT3`, by setting the [ITextInputPanel::AttachedEditWindow Property](https://learn.microsoft.com/windows/desktop/api/peninputpanel/nf-peninputpanel-itextinputpanel-get_attachededitwindow) property. It also sets, then gets the **ITextInputPanel::InPlaceVisibleOnFocus Property**.

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