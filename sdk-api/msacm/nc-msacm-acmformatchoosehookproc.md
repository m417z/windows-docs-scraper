# ACMFORMATCHOOSEHOOKPROC callback function

## Description

The **acmFormatChooseHookProc** function specifies a user-defined function that hooks the [acmFormatChoose](https://learn.microsoft.com/windows/desktop/api/msacm/nf-msacm-acmformatchoose) dialog box. The **acmFormatChooseHookProc** name is a placeholder for an application-defined name.

## Parameters

### `hwnd`

Window handle for the dialog box.

### `uMsg`

Window message.

### `wParam`

Message parameter.

### `lParam`

Message parameter.

## Remarks

If the hook function processes one of the WM_CTLCOLOR messages, this function must return a handle of the brush that should be used to paint the control background.

A hook function can optionally process the MM_ACM_FORMATCHOOSE message.

You should use this function the same way as you use the Common Dialog hook functions for customizing common dialog boxes.

## See also

[Audio Compression Functions](https://learn.microsoft.com/windows/desktop/Multimedia/audio-compression-functions)

[Audio Compression Manager](https://learn.microsoft.com/windows/desktop/Multimedia/audio-compression-manager)