# ITextInputPanel::get_DefaultInPlaceState

## Description

[[ITextInputPanel](https://learn.microsoft.com/windows/desktop/api/peninputpanel/nn-peninputpanel-itextinputpanel) is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions. Instead, use [IInputPanelConfiguration](https://learn.microsoft.com/windows/desktop/api/inputpanelconfiguration/nn-inputpanelconfiguration-iinputpanelconfiguration).

]

Gets or sets the default in-place state as specified by the [InPlaceState Enumeration](https://learn.microsoft.com/windows/win32/api/peninputpanel/ne-peninputpanel-inplacestate).

This property is read/write.

## Parameters

## Remarks

Set this property to [InPlaceState_Expanded](https://learn.microsoft.com/windows/win32/api/peninputpanel/ne-peninputpanel-inplacestate) to have the Input Panel open without requiring the user to tap the hover target. Setting the default state to **InPlaceState_HoverTarget** overrides the Input Panel's heuristics for remaining expanded. When switching between fields, setting the default forces Input Panel to the collapsed or hover state, after a focus change. The system default is **InPlaceState_Auto**.

#### Examples

This C++ example creates an [ITextInputPanel](https://learn.microsoft.com/windows/desktop/api/peninputpanel/nn-peninputpanel-itextinputpanel) object, `g_pTip`, and attaches it to the window handle of an [InkEdit](https://learn.microsoft.com/windows/desktop/tablet/inkedit-control-reference) control, `IDC_EDIT3`, by setting the [ITextInputPanel::AttachedEditWindow Property](https://learn.microsoft.com/windows/desktop/api/peninputpanel/nf-peninputpanel-itextinputpanel-get_attachededitwindow) property. It also sets, then gets the **ITextInputPanel::DefaultInPlaceState Property**.

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