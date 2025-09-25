## Description

Receives messages that allow you to customize drawing of the sample page in the **Page Setup** dialog box. The *PagePaintHook* hook procedure is an application-defined or library-defined callback function used with the [PageSetupDlg](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms646937(v=vs.85)) function.

The **LPPAGEPAINTHOOK** type defines a pointer to this callback function. *PagePaintHook* is a placeholder for the application-defined or library-defined function name.

## Parameters

### `unnamedParam1`

A handle to the **Page Setup** dialog box.

### `unnamedParam2`

The identifier of the message being received.

### `unnamedParam3`

Additional information about the message. The exact meaning depends on the value of the *unnamedParam2* parameter.

### `unnamedParam4`

Additional information about the message. The exact meaning depends on the value of the *unnamedParam2* parameter.

## Return value

If the hook procedure returns **TRUE** for any of the first three messages of a drawing sequence ([WM_PSD_PAGESETUPDLG](https://learn.microsoft.com/windows/desktop/dlgbox/wm-psd-pagesetupdlg), [WM_PSD_FULLPAGERECT](https://learn.microsoft.com/windows/desktop/dlgbox/wm-psd-fullpagerect), or [WM_PSD_MINMARGINRECT](https://learn.microsoft.com/windows/desktop/dlgbox/wm-psd-minmarginrect)), the dialog box sends no more messages and does not draw in the sample page until the next time the system needs to redraw the sample page. If the hook procedure returns **FALSE** for all three messages, the dialog box sends the remaining messages of the drawing sequence.

If the hook procedure returns **TRUE** for any of the remaining messages in a drawing sequence, the dialog box does not draw the corresponding portion of the sample page. If the hook procedure returns **FALSE** for any of these messages, the dialog box draws that portion of the sample page.

## Remarks

The **Page Setup** dialog box includes an image of a sample page that shows how the user's selections affect the appearance of the printed output. The image consists of a rectangle that represents the selected paper or envelope type, with a dotted-line rectangle representing the current margins, and partial (Greek text) characters to show how text looks on the printed page. When you use the [PageSetupDlg](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms646937(v=vs.85)) function to create a **Page Setup** dialog box, you can provide a *PagePaintHook* hook procedure to customize the appearance of the sample page.

To enable the hook procedure, use the [PAGESETUPDLG](https://learn.microsoft.com/windows/win32/api/commdlg/ns-commdlg-pagesetupdlga) structure that you passed to the creation function. Specify the pointer to the hook procedure in the **lpfnPagePaintHook** member and specify the **PSD_ENABLEPAGEPAINTHOOK** flag in the **Flags** member.

Whenever the dialog box is about to draw the contents of the sample page, the hook procedure receives the following messages in the order in which they are listed.

| Message | Meaning |
| --- | --- |
| [WM_PSD_PAGESETUPDLG](https://learn.microsoft.com/windows/desktop/dlgbox/wm-psd-pagesetupdlg) | The dialog box is about to draw the sample page. The hook procedure can use this message to prepare to draw the contents of the sample page. |
| [WM_PSD_FULLPAGERECT](https://learn.microsoft.com/windows/desktop/dlgbox/wm-psd-fullpagerect) | The dialog box is about to draw the sample page. This message specifies the bounding rectangle of the sample page. |
| [WM_PSD_MINMARGINRECT](https://learn.microsoft.com/windows/desktop/dlgbox/wm-psd-minmarginrect) | The dialog box is about to draw the sample page. This message specifies the margin rectangle. |
| [WM_PSD_MARGINRECT](https://learn.microsoft.com/windows/desktop/dlgbox/wm-psd-marginrect) | The dialog box is about to draw the margin rectangle. |
| [WM_PSD_GREEKTEXTRECT](https://learn.microsoft.com/windows/desktop/dlgbox/wm-psd-greektextrect) | The dialog box is about to draw the Greek text inside the margin rectangle. |
| [WM_PSD_ENVSTAMPRECT](https://learn.microsoft.com/windows/desktop/dlgbox/wm-psd-envstamprect) | The dialog box is about to draw in the envelope-stamp rectangle of an envelope sample page. This message is sent for envelopes only. |
| [WM_PSD_YAFULLPAGERECT](https://learn.microsoft.com/windows/desktop/dlgbox/wm-psd-yafullpagerect) | The dialog box is about to draw the return address portion of an envelope sample page. This message is sent for envelopes and other paper sizes. |

## See also

[Common Dialog Box Library](https://learn.microsoft.com/windows/desktop/dlgbox/common-dialog-box-library)

**Conceptual**

[PAGESETUPDLG](https://learn.microsoft.com/windows/win32/api/commdlg/ns-commdlg-pagesetupdlga)

[PageSetupDlg](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms646937(v=vs.85))

**Reference**