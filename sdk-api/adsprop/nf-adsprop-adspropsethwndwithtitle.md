# ADsPropSetHwndWithTitle function

## Description

The **ADsPropSetHwndWithTitle** function is used to notify the notification object of the property page window handle.This function includes the title of the property page which enables the error dialog displayed by [ADsPropShowErrorDialog](https://learn.microsoft.com/windows/desktop/api/adsprop/nf-adsprop-adspropshowerrordialog) to provide more useful information to the user.

## Parameters

### `hNotifyObj` [in]

The handle of the notification object. To obtain this handle, call [ADsPropCreateNotifyObj](https://learn.microsoft.com/windows/desktop/api/adsprop/nf-adsprop-adspropcreatenotifyobj).

### `hPage` [in]

A window handle of the property page.

### `ptzTitle` [in]

Pointer to a NULL-terminated string that contains the property page title.

## Return value

Returns zero if the notification object does not exist or nonzero otherwise.

## Remarks

An Active Directory Domain Services property sheet extension normally calls this function while processing the [WM_INITDIALOG](https://learn.microsoft.com/windows/desktop/dlgbox/wm-initdialog) message.

If the property sheet extension uses the [ADsPropShowErrorDialog](https://learn.microsoft.com/windows/desktop/api/adsprop/nf-adsprop-adspropshowerrordialog) function, the extension should use **ADsPropSetHwndWithTitle** rather than [ADsPropSetHwnd](https://learn.microsoft.com/windows/desktop/api/adsprop/nf-adsprop-adspropsethwnd).

## See also

[ADsPropCreateNotifyObj](https://learn.microsoft.com/windows/desktop/api/adsprop/nf-adsprop-adspropcreatenotifyobj)

[ADsPropSetHwnd](https://learn.microsoft.com/windows/desktop/api/adsprop/nf-adsprop-adspropsethwnd)

[ADsPropShowErrorDialog](https://learn.microsoft.com/windows/desktop/api/adsprop/nf-adsprop-adspropshowerrordialog)

[WM_INITDIALOG](https://learn.microsoft.com/windows/desktop/dlgbox/wm-initdialog)