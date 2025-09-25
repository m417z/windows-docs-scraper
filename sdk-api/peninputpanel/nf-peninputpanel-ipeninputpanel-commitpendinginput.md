# IPenInputPanel::CommitPendingInput

## Description

Deprecated. The [PenInputPanel](https://learn.microsoft.com/windows/desktop/tablet/peninputpanel-class) has been replaced by the [Text Input Panel (TIP)](https://learn.microsoft.com/windows/desktop/tablet/text-input-panel-reference).

Sends collected ink to the recognizer and posts the recognition result.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **E_UNEXPECTED** | Unexpected parameter or property type. |
| **E_FAIL** | An unspecified error occurred. |

## Remarks

The writing pad sends the collected ink to the recognizer and clears the writing pad. The East Asian multibox sends recognized characters and clears multiboxes. The recognition result is sent to the control to which the [PenInputPanel](https://learn.microsoft.com/windows/desktop/tablet/peninputpanel-class) object is attached.

If there is no pending input or the [CurrentPanel](https://learn.microsoft.com/windows/desktop/api/peninputpanel/nf-peninputpanel-ipeninputpanel-get_currentpanel) property is [Keyboard](https://learn.microsoft.com/windows/desktop/api/peninputpanel/ne-peninputpanel-paneltype), **CommitPendingInput** does nothing. If the [PenInputPanel](https://learn.microsoft.com/windows/desktop/tablet/peninputpanel-class) object is inactive, calling this method generates an error.

Starting with Microsoft Windows XP Tablet PC Edition 2005, ink is recognized as the user is entering. Therefore, the **CommitPendingInput** function sends the already recognized text to the edit control; it does not force recognition to occur.

Starting with Windows XP Tablet PC Edition 2005, if the [PenInputPanel](https://learn.microsoft.com/windows/desktop/tablet/peninputpanel-class) object is inactive, **CommitPendingInput** does not generate an error, it simply returns.

## See also

[IPenInputPanel](https://learn.microsoft.com/windows/win32/api/peninputpanel/nn-peninputpanel-ipeninputpanel)

[PenInputPanel](https://learn.microsoft.com/windows/desktop/tablet/peninputpanel-class)