# ITextInputPanel::SetInPlacePosition

## Description

[[ITextInputPanel](https://learn.microsoft.com/windows/desktop/api/peninputpanel/nn-peninputpanel-itextinputpanel) is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions. Instead, use [IInputPanelConfiguration](https://learn.microsoft.com/windows/desktop/api/inputpanelconfiguration/nn-inputpanelconfiguration-iinputpanelconfiguration).

]

Explicitly positions the Tablet PC Input Panel in screen coordinates.

## Parameters

### `xPosition`

The horizontal x-coordinate for the top left corner of the Input Panel, with no correction comb visible.

### `yPosition`

The vertical y-coordinate for the top left corner of the Input Panel, with no correction comb visible.

### `position`

The direction the post insertion correction comb should pop up in, as defined by the [CorrectionPosition](https://learn.microsoft.com/windows/win32/api/peninputpanel/ne-peninputpanel-correctionposition) enumeration.

## Return value

Returns **false** when the Input Panel is open (docked or floating) and cannot be moved; otherwise it returns **true**.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **E_FAIL** | An unspecified error occurred. |

## Remarks

**Note** In Windows 7, calling **SetInPlacePosition** will no longer use the *CorrectionPosition* parameter.

Take the height of the correction comb in mind when deciding where to position the Input Panel in order to keep the Input Panel and correction comb on screen. The direction specified in the *position* parameter overrides the direction set using the [ITextInputPanel::PreferredInPlaceDirection Property](https://learn.microsoft.com/windows/desktop/api/peninputpanel/nf-peninputpanel-itextinputpanel-get_preferredinplacedirection).

There are no restrictions on where the Input Panel can be positioned. It is the responsibility of the application developer to make sure the Input Panel does not go off the screen. The [ITextInputPanel::InPlaceBoundingRectangle Property](https://learn.microsoft.com/windows/desktop/api/peninputpanel/nf-peninputpanel-itextinputpanel-get_inplaceboundingrectangle), [ITextInputPanel::PopUpCorrectionHeight Property](https://learn.microsoft.com/windows/desktop/api/peninputpanel/nf-peninputpanel-itextinputpanel-get_popupcorrectionheight), and [ITextInputPanel::PopDownCorrectionHeight Property](https://learn.microsoft.com/windows/desktop/api/peninputpanel/nf-peninputpanel-itextinputpanel-get_popdowncorrectionheight), along with the [ITextInputPanelEventSink::InPlaceSizeChanging Method](https://learn.microsoft.com/windows/desktop/api/peninputpanel/nf-peninputpanel-itextinputpaneleventsink-inplacesizechanging), can be used for this purpose.

This method is synchronous. Positioning occurs before the method returns.

#### Examples

This C++ example implements an `EN_SETFOCUS` event handler for an Edit control, `IDC_EDIT3`. It first checks to if an [ITextInputPanel](https://learn.microsoft.com/windows/desktop/api/peninputpanel/nn-peninputpanel-itextinputpanel) object, `g_pTip`, has been created. If it exists, it reports the values of several **ITextInputPanel Interface** properties to debug output using the **TRACE** macro. It also sets the position of the Input Panel by calling the **ITextInputPanel::SetInPlacePosition Method**.

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

[ITextInputPanel::SetInPlaceHoverTargetPosition Method](https://learn.microsoft.com/windows/desktop/api/peninputpanel/nf-peninputpanel-itextinputpanel-setinplacehovertargetposition)

[ITextInputPanel::SetInPlaceVisibility Method](https://learn.microsoft.com/windows/desktop/api/peninputpanel/nf-peninputpanel-itextinputpanel-setinplacevisibility)