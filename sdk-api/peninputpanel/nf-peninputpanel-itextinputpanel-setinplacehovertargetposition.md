# ITextInputPanel::SetInPlaceHoverTargetPosition

## Description

[[ITextInputPanel](https://learn.microsoft.com/windows/desktop/api/peninputpanel/nn-peninputpanel-itextinputpanel) is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions. Instead, use [IInputPanelConfiguration](https://learn.microsoft.com/windows/desktop/api/inputpanelconfiguration/nn-inputpanelconfiguration-iinputpanelconfiguration).

]

Explicitly positions the Tablet PC Input Panel hover target in screen coordinates.

## Parameters

### `xPosition`

The horizontal x-coordinate for the top left corner of the hover target, with no correction comb visible.

### `yPosition`

The vertical y-coordinate for the top left corner of the hover target, with no correction comb visible.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **E_FAIL** | An unspecified error occurred. |

## Remarks

There are no restrictions on where the hover target can be placed. The application is responsible for making sure the hover target stays on screen.

The **SetInPlaceHoverTargetPosition** method is synchronous. Positioning occurs before the method returns.

#### Examples

This C++ example implements an `EN_SETFOCUS` event handler for an Edit control, `IDC_EDIT2`. It first checks if an [ITextInputPanel](https://learn.microsoft.com/windows/desktop/api/peninputpanel/nn-peninputpanel-itextinputpanel) object, `g_pTip`, has been created. If it exists, it sets the position of the Input Panel hover target by calling the **ITextInputPanel::SetInPlaceHoverTargetPosition Method**. It then reports whether the call was successful to debug output using the **TRACE** macro.

```cpp
void CCOMTIPDlg::OnEnSetfocusEdit2()
{
	if (NULL != g_pTip)
	{
		if (SUCCEEDED(g_pTip->SetInPlaceHoverTargetPosition(300, 300)))
		{
			TRACE("Call to SetInPlaceHoverTargetPosition() succeeded.\n");
		}
		else
		{
			TRACE("Call to SetInPlaceHoverTargetPosition() failed.\n");
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

[ITextInputPanel::SetInPlacePosition Method](https://learn.microsoft.com/windows/desktop/api/peninputpanel/nf-peninputpanel-itextinputpanel-setinplaceposition)

[ITextInputPanel::SetInPlaceVisibility Method](https://learn.microsoft.com/windows/desktop/api/peninputpanel/nf-peninputpanel-itextinputpanel-setinplacevisibility)