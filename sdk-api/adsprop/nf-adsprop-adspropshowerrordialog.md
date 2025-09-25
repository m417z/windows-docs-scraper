# ADsPropShowErrorDialog function

## Description

The **ADsPropShowErrorDialog** function displays a dialog box that contains the error messages accumulated through calls to the [ADsPropSendErrorMessage](https://learn.microsoft.com/windows/desktop/api/adsprop/nf-adsprop-adspropsenderrormessage) function or the [WM_ADSPROP_NOTIFY_ERROR](https://learn.microsoft.com/windows/desktop/AD/wm-adsprop-notify-error).

## Parameters

### `hNotifyObj` [in]

The handle of the notification object. To obtain this handle, call [ADsPropCreateNotifyObj](https://learn.microsoft.com/windows/desktop/api/adsprop/nf-adsprop-adspropcreatenotifyobj).

### `hPage` [in]

The window handle of the property page.

## Return value

Returns zero if the notification object does not exist or nonzero otherwise.

## Remarks

The error messages added by the [ADsPropSendErrorMessage](https://learn.microsoft.com/windows/desktop/api/adsprop/nf-adsprop-adspropsenderrormessage) function are accumulated until **ADsPropShowErrorDialog** is called. **ADsPropShowErrorDialog** combines and displays the accumulated error messages. When the error dialog is dismissed, the accumulated error messages are deleted.

## See also

[ADSPROPERROR](https://learn.microsoft.com/windows/desktop/api/adsprop/ns-adsprop-adsproperror)

[ADsPropSendErrorMessage](https://learn.microsoft.com/windows/desktop/api/adsprop/nf-adsprop-adspropsenderrormessage)

[Messages in Active Directory Domain Services](https://learn.microsoft.com/windows/desktop/AD/messages-in-active-directory-domain-services)

[WM_ADSPROP_NOTIFY_ERROR](https://learn.microsoft.com/windows/desktop/AD/wm-adsprop-notify-error)