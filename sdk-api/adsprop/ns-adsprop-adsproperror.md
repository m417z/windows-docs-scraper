# ADSPROPERROR structure

## Description

The
**ADSPROPERROR** structure is used to pass error
data to the notification object with the [ADsPropSendErrorMessage](https://learn.microsoft.com/windows/desktop/api/adsprop/nf-adsprop-adspropsenderrormessage) function or the [WM_ADSPROP_NOTIFY_ERROR](https://learn.microsoft.com/windows/desktop/AD/wm-adsprop-notify-error) message.

## Members

### `hwndPage`

Contains the window handle of the property page that generated the error.

### `pszPageTitle`

Pointer to a NULL-terminated Unicode string that contains the title of the property page that generated the error.

### `pszObjPath`

Pointer to a NULL-terminated Unicode string that contains the ADsPath of the directory object that the error occurred on.

### `pszObjClass`

Pointer to a NULL-terminated Unicode string that contains the class name of the directory object that the error occurred on.

### `hr`

Contains an **HRESULT** value that specifies the code of the error that occurred. If *hr* is not equal to **S_OK**, then *pszError* is ignored. If *hr* is equal to **S_OK**, then *pszError* contains an error message.

### `pszError`

Pointer to a NULL-terminated Unicode string that contains the error message to be displayed in the error dialog box. This member is ignored if *hr* is not equal to **S_OK**. In this case, the error dialog box will display a system-defined message for the error specified by *hr*.

## See also

[ADsPropSendErrorMessage](https://learn.microsoft.com/windows/desktop/api/adsprop/nf-adsprop-adspropsenderrormessage)

[WM_ADSPROP_NOTIFY_ERROR](https://learn.microsoft.com/windows/desktop/AD/wm-adsprop-notify-error)