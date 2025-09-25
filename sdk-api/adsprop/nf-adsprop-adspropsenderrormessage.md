# ADsPropSendErrorMessage function

## Description

The **ADsPropSendErrorMessage** function adds an error message to a list of error messages displayed by calling
the [ADsPropShowErrorDialog](https://learn.microsoft.com/windows/desktop/api/adsprop/nf-adsprop-adspropshowerrordialog) function.

## Parameters

### `hNotifyObj` [in]

The handle of the notification object. To obtain this handle, call [ADsPropCreateNotifyObj](https://learn.microsoft.com/windows/desktop/api/adsprop/nf-adsprop-adspropcreatenotifyobj).

### `pError` [out]

Pointer to an [ADSPROPERROR](https://learn.microsoft.com/windows/desktop/api/adsprop/ns-adsprop-adsproperror) structure which contains data about the error message.

## Return value

Returns nonzero if successful or zero otherwise.

## Remarks

The error messages added by the **ADsPropSendErrorMessage** function are accumulated until [ADsPropShowErrorDialog](https://learn.microsoft.com/windows/desktop/api/adsprop/nf-adsprop-adspropshowerrordialog) is called. **ADsPropShowErrorDialog** combines and displays the accumulated error messages. When the error dialog is dismissed, the accumulated error messages are deleted.

## See also

[ADSPROPERROR](https://learn.microsoft.com/windows/desktop/api/adsprop/ns-adsprop-adsproperror)

[ADsPropShowErrorDialog](https://learn.microsoft.com/windows/desktop/api/adsprop/nf-adsprop-adspropshowerrordialog)

[Messages in Active Directory Domain Services](https://learn.microsoft.com/windows/desktop/AD/messages-in-active-directory-domain-services)

[WM_ADSPROP_NOTIFY_ERROR](https://learn.microsoft.com/windows/desktop/AD/wm-adsprop-notify-error)