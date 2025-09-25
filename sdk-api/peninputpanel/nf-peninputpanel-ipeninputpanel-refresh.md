# IPenInputPanel::Refresh

## Description

[**Refresh** is no longer available for use as of Windows XP Tablet PC Edition. Instead, use [Text Input Panel (TIP)](https://learn.microsoft.com/windows/desktop/tablet/text-input-panel-reference).]

Updates and restores the [PenInputPanel](https://learn.microsoft.com/windows/desktop/tablet/peninputpanel-class) properties based on Tablet PC Input Panel settings, automatically positions the pen input panel, and sets the user interface to the default panel.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **E_UNEXPECTED** | Unexpected parameter or property type. |
| **E_FAIL** | An unspecified error occurred. |

## Remarks

The **Refresh** method restores the default panel. For example, if the [DefaultPanel](https://learn.microsoft.com/windows/desktop/api/peninputpanel/nf-peninputpanel-ipeninputpanel-get_defaultpanel) property is set to [Keyboard](https://learn.microsoft.com/windows/desktop/api/peninputpanel/ne-peninputpanel-paneltype) and the [CurrentPanel](https://learn.microsoft.com/windows/desktop/api/peninputpanel/nf-peninputpanel-ipeninputpanel-get_currentpanel) property is set to **Handwriting**, the **Refresh** method sets the pen input panel to **Keyboard**. If the **DefaultPanel** property is set to **Default**, the **Refresh** method does not change the pen input panel.

The **Refresh** method automatically positions the pen input panel relative to the control to which it is attached.

The **Refresh** method updates the pen input panel using the Input Panel settings. For instance, you can make changes to the [PenInputPanel](https://learn.microsoft.com/windows/desktop/tablet/peninputpanel-class) object, and then call **Refresh** to restore the settings to those copied from the Input Panel.

The [PenInputPanel](https://learn.microsoft.com/windows/desktop/tablet/peninputpanel-class) object is updated automatically whenever the Input Panel settings change.

Calling **Refresh** while the pen input panel does not have focus will generate an error.

**Note** Normally, you won't need to call **Refresh** because all of the above is executed during activation of the pen input panel. However, if the [AutoShow](https://learn.microsoft.com/windows/desktop/api/peninputpanel/nf-peninputpanel-ipeninputpanel-get_autoshow) property is set to **FALSE**, you can disable activation of the pen input panel. Therefore, the **Refresh** method is needed.

## See also

[IPenInputPanel](https://learn.microsoft.com/windows/win32/api/peninputpanel/nn-peninputpanel-ipeninputpanel)

[PenInputPanel](https://learn.microsoft.com/windows/desktop/tablet/peninputpanel-class)