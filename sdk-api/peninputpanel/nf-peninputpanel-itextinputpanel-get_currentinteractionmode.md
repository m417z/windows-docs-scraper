# ITextInputPanel::get_CurrentInteractionMode

## Description

[[ITextInputPanel](https://learn.microsoft.com/windows/desktop/api/peninputpanel/nn-peninputpanel-itextinputpanel) is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions. Instead, use [IInputPanelConfiguration](https://learn.microsoft.com/windows/desktop/api/inputpanelconfiguration/nn-inputpanelconfiguration-iinputpanelconfiguration).

]

Gets the positioning of the Tablet PC Input Panel as specified by the [InteractionMode Enumeration](https://learn.microsoft.com/windows/win32/api/peninputpanel/ne-peninputpanel-interactionmode).

This property is read-only.

## Parameters

## Remarks

The current interaction mode is dictated by the user. However, the [InteractionMode_InPlace](https://learn.microsoft.com/windows/win32/api/peninputpanel/ne-peninputpanel-interactionmode) mode can be disabled by the application on a per field basis.

#### Examples

This C++ example implements an `EN_SETFOCUS` event handler for an Edit control, `IDC_EDIT3`. It first checks if an [ITextInputPanel](https://learn.microsoft.com/windows/desktop/api/peninputpanel/nn-peninputpanel-itextinputpanel) object, `g_pTip`, has been created. If it exists, it reports the values of several **ITextInputPanel Interface** properties to debug output using the **TRACE** macro.

```cpp
void CCOMTIPDlg::OnEnSetFocusEdit3()
{
    if (NULL != g_pTip)
    {
		CorrectionMode mode;

		if (SUCCEEDED(g_pTip->get_CurrentCorrectionMode(&mode)))
        {
			TRACE("CurrentCorrectionMode: %d\n", mode);
		}

		InPlaceState state;

		if (SUCCEEDED(g_pTip->get_CurrentInPlaceState(&state)))
        {
			TRACE("CurrentInPlaceState: %d\n", state);
		}

		PanelInputArea area;

		if (SUCCEEDED(g_pTip->get_CurrentInputArea(&area)))
        {
			TRACE("CurrentInputArea: %d\n", area);
		}

		InteractionMode iMode;

		if (SUCCEEDED(g_pTip->get_CurrentInteractionMode(&iMode)))
        {
			TRACE("CurrentInteractionMode: %d\n", iMode);
		}

        RECT rect;

		if (SUCCEEDED(g_pTip->get_InPlaceBoundingRectangle(&rect)))
        {
	        TRACE("InPlaceBoundingRectangle.top: %d\n", rect.top);
	        TRACE("InPlaceBoundingRectangle.left: %d\n", rect.left);
	        TRACE("InPlaceBoundingRectangle.bottom: %d\n", rect.bottom);
	        TRACE("InPlaceBoundingRectangle.right: %d\n", rect.right);
        }

	    int nHeight;

		if (SUCCEEDED(g_pTip->get_PopDownCorrectionHeight(&nHeight)))
        {
	        TRACE("PopDownCorrectionHeight: %d\n", nHeight);
        }

	    if (SUCCEEDED(g_pTip->get_PopUpCorrectionHeight(&nHeight)))
        {
	        TRACE("PopUpCorrectionHeight: %d\n", nHeight);
        }

		if (SUCCEEDED(g_pTip->SetInPlacePosition(300, 300, CorrectionPosition_Bottom)))
		{
			TRACE("Call to SetInPlacePosition() succeeded.\n");
		}
		else
		{
			TRACE("Call to SetInPlacePosition() failed.\n");
		}
    }
    else
    {
        TRACE("ITextInputPanel object is NULL.\n");
    }
}

```

## See also

[ITextInputPanel Interface](https://learn.microsoft.com/windows/desktop/api/peninputpanel/nn-peninputpanel-itextinputpanel)