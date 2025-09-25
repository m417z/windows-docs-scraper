# ACMFILTERCHOOSEHOOKPROC callback function

## Description

The **acmFilterChooseHookProc** function specifies a user-defined function that hooks the [acmFilterChoose](https://learn.microsoft.com/windows/desktop/api/msacm/nf-msacm-acmfilterchoose) dialog box.

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

To customize the dialog box selections, a hook function can optionally process the MM_ACM_FILTERCHOOSE message.

You should use this function the same way as you use the Common Dialog hook functions for customizing common dialog boxes.

## See also

[Audio Compression Functions](https://learn.microsoft.com/windows/desktop/Multimedia/audio-compression-functions)

[Audio Compression Manager](https://learn.microsoft.com/windows/desktop/Multimedia/audio-compression-manager)