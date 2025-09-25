# ADsPropSetHwnd function

## Description

The **ADsPropSetHwnd** function is used to notify the notification object of the property page window handle.

## Parameters

### `hNotifyObj` [in]

The handle of the notification object. To obtain this handle, call [ADsPropCreateNotifyObj](https://learn.microsoft.com/windows/desktop/api/adsprop/nf-adsprop-adspropcreatenotifyobj).

### `hPage` [in]

A window handle of the property page.

## Return value

Returns zero if the notification object does not exist or nonzero otherwise.

## Remarks

An Active Directory Domain Services property sheet extension normally calls this function while processing the [WM_INITDIALOG](https://learn.microsoft.com/windows/desktop/dlgbox/wm-initdialog) message.

If the property sheet extension uses the [ADsPropShowErrorDialog](https://learn.microsoft.com/windows/desktop/api/adsprop/nf-adsprop-adspropshowerrordialog) function, the extension should use [ADsPropSetHwndWithTitle](https://learn.microsoft.com/windows/desktop/api/adsprop/nf-adsprop-adspropsethwndwithtitle) rather than **ADsPropSetHwnd**.

## See also

[ADsPropCreateNotifyObj](https://learn.microsoft.com/windows/desktop/api/adsprop/nf-adsprop-adspropcreatenotifyobj)

[ADsPropSetHwndWithTitle](https://learn.microsoft.com/windows/desktop/api/adsprop/nf-adsprop-adspropsethwndwithtitle)

[ADsPropShowErrorDialog](https://learn.microsoft.com/windows/desktop/api/adsprop/nf-adsprop-adspropshowerrordialog)

[WM_INITDIALOG](https://learn.microsoft.com/windows/desktop/dlgbox/wm-initdialog)