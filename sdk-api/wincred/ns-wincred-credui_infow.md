# CREDUI_INFOW structure

## Description

The **CREDUI_INFO** structure is used to pass information to the
[CredUIPromptForCredentials](https://learn.microsoft.com/windows/desktop/api/wincred/nf-wincred-creduipromptforcredentialsa) function that creates a dialog box used to obtain credentials information.

## Members

### `cbSize`

Set to the size of the CREDUI_INFO structure.

### `hwndParent`

Specifies the handle to the parent window of the dialog box. The dialog box is modal with respect to the parent window. If this member is **NULL**, the desktop is the parent window of the dialog box.

### `pszMessageText`

Pointer to a string containing a brief message to display in the dialog box. The length of this string should not exceed CREDUI_MAX_MESSAGE_LENGTH.

### `pszCaptionText`

Pointer to a string containing the title for the dialog box. The length of this string should not exceed CREDUI_MAX_CAPTION_LENGTH.

### `hbmBanner`

Bitmap to display in the dialog box. If this member is **NULL**, a default bitmap is used. The bitmap size is limited to 320x60 pixels.

## Remarks

> [!NOTE]
> The wincred.h header defines CREDUI_INFO as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).