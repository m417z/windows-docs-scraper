# IPenInputPanel::EnableTsf

## Description

[ The [PenInputPanel](https://learn.microsoft.com/windows/desktop/tablet/peninputpanel-class) has been replaced by the [Text Input Panel (TIP)](https://learn.microsoft.com/windows/desktop/tablet/text-input-panel-reference).]

Deprecated. Gets or sets a Boolean value that indicates whether the [PenInputPanel](https://learn.microsoft.com/windows/desktop/tablet/peninputpanel-class) object attempts to send text to the attached control through the [Text Services Framework](https://learn.microsoft.com/windows/desktop/TSF/text-services-framework) (TSF) and enables the use of the **correction** user interface.

## Parameters

### `Enable`

**TRUE** if the [PenInputPanel](https://learn.microsoft.com/windows/desktop/tablet/peninputpanel-class) object should attempt to send text to the attached control using TSF and that the correction user interface should be enabled; otherwise **FALSE**. The default value is **TRUE**.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **E_UNEXPECTED** | Unexpected parameter or property type. |
| **E_NOINTERFACE** | TSF interfaces are not exposed on the attached control. |
| **E_FAIL** | An unspecified error occurred. |

## Remarks

Calling this method with Enable set to **TRUE** causes the [PenInputPanel](https://learn.microsoft.com/windows/desktop/tablet/peninputpanel-class) object to attempt to start the TSF on the attached control.

**EnableTsf** should be used to enable the [PenInputPanel](https://learn.microsoft.com/windows/desktop/tablet/peninputpanel-class) to use the TSF insertion context rather than the [SendInput](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-sendinput) function to send the handwriting recognition results into the control. The result is that text can be inserted even if the field no longer has focus.

When you call **EnableTsf** with a value of **TRUE**, the [PenInputPanel](https://learn.microsoft.com/windows/desktop/tablet/peninputpanel-class) object sends an [EM_SETEDITSTYLE](https://learn.microsoft.com/windows/desktop/Controls/em-seteditstyle) message to the attached control. If the control does not support this message, results may be unpredictable. The [InkEdit](https://learn.microsoft.com/windows/desktop/tablet/inkedit-control) control does support TSF.

### Support for Legacy Applications

Support has been added to TSF and Microsoft Windows to provide a consistent user interface for all applications across the desktop. This new support enables legacy applications or controls that are not aware of TSF to take advantage of some advanced text services for free. For example, speech dictation and handwriting can now be used to enter text into a document in any application.

This new feature is available and enabled by default on Windows XP Tablet PC Edition. To enable or disable it:

1. In Control Panel, click **Regional and Language Options**.
2. On the **Languages** tab, click **Details**.
3. On the **Advanced** tab of the **Text Services and Input Languages** dialog box, select or clear **Extend support of advanced text services to all programs**.

If successful, text is sent to the attached control through TSF. Furthermore, if the control supports TSF (and is not simply receiving text from TSF just because Advanced Text Services has been enabled for all programs in Control Panel as noted above), then the correction user interface appears in the control and allows access to handwriting alternates. Calling this method with Enable set to **FALSE** causes the [PenInputPanel](https://learn.microsoft.com/windows/desktop/tablet/peninputpanel-class) object to attempt to shut down TSF on the attached control.

## See also

[IPenInputPanel](https://learn.microsoft.com/windows/win32/api/peninputpanel/nn-peninputpanel-ipeninputpanel)

[PenInputPanel](https://learn.microsoft.com/windows/desktop/tablet/peninputpanel-class)