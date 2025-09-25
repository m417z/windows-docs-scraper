# ITextInputPanel::SetInPlaceVisibility

## Description

[[ITextInputPanel](https://learn.microsoft.com/windows/desktop/api/peninputpanel/nn-peninputpanel-itextinputpanel) is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions. Instead, use [IInputPanelConfiguration](https://learn.microsoft.com/windows/desktop/api/inputpanelconfiguration/nn-inputpanelconfiguration-iinputpanelconfiguration).

]

Shows or hides the Tablet PC Input Panel.

## Parameters

### `Visible`

**TRUE** to show the Input Panel; **FALSE** to hide the Input Panel.

## Return value

If the Input Panel can display, the method returns **S_OK**, otherwise **E_FAIL**. See the Remarks section for more information about when the Input Panel can and cannot be affected by the **ITextInputPanel::SetInPlaceVisibility Method**.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **E_FAIL** | An unspecified error occurred. |

## Remarks

The Input Panel is shown as specified by the [ITextInputPanel::CurrentInPlaceState Property](https://learn.microsoft.com/windows/desktop/api/peninputpanel/nf-peninputpanel-itextinputpanel-get_currentinplacestate) property.

Calling **ITextInputPanel::SetInPlaceVisibility Method** with the *Visible* parameter set to **TRUE** will fail if the Input Panel is already visible.

If the user has disabled in-place mode from the Input Panel options dialog, calling **ITextInputPanel::SetInPlaceVisibility Method** will fail.

Any ink already in the Input Panel, when visibility changes, is automatically inserted.

This method does not change the value of [ITextInputPanel::InPlaceVisibleOnFocus Property](https://learn.microsoft.com/windows/desktop/api/peninputpanel/nf-peninputpanel-itextinputpanel-get_inplacevisibleonfocus), and on the subsequent focus change, the behavior reverts to the behavior specified by the **ITextInputPanel::InPlaceVisibleOnFocus Property**.

The **ITextInputPanel::SetInPlaceVisibility Method** is a synchronous call. The Input Panel visibility will change before the call returns.

#### Examples

This C++ example implements an `EN_SETFOCUS` event handler for an Edit control, `IDC_EDIT1`. It first checks to if an [ITextInputPanel](https://learn.microsoft.com/windows/desktop/api/peninputpanel/nn-peninputpanel-itextinputpanel) object, `g_pTip`, has been created. If it exists, it prevents the Input Panel from showing by calling the **ITextInputPanel::SetInPlaceVisibility Method** with a value of **false** for the *Visible* parameter.

```cpp
void CCOMTIPDlg::OnEnSetfocusEdit1()
{
	if (NULL != g_pTip)
	{
		if (SUCCEEDED(g_pTip->SetInPlaceVisibility(false)))
		{
			TRACE("Successfully hid the Input Panel.\n");
		}
	}
}

```

## See also

[ITextInputPanel Interface](https://learn.microsoft.com/windows/desktop/api/peninputpanel/nn-peninputpanel-itextinputpanel)

[ITextInputPanel::DefaultInPlaceState Property](https://learn.microsoft.com/windows/desktop/api/peninputpanel/nf-peninputpanel-itextinputpanel-get_defaultinplacestate)

[ITextInputPanel::SetInPlaceHoverTargetPosition Method](https://learn.microsoft.com/windows/desktop/api/peninputpanel/nf-peninputpanel-itextinputpanel-setinplacehovertargetposition)

[ITextInputPanel::SetInPlacePosition Method](https://learn.microsoft.com/windows/desktop/api/peninputpanel/nf-peninputpanel-itextinputpanel-setinplaceposition)

[InPlaceState Enumeration](https://learn.microsoft.com/windows/win32/api/peninputpanel/ne-peninputpanel-inplacestate)