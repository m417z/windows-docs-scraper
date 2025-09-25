# _IFaxServerNotify2::OnGeneralServerConfigChanged

## Description

Called by the fax service when the [IFaxServer2::Configuration](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxserver2-configuration-vb) property changes.

## Parameters

### `pFaxServer`

Type: **[IFaxServer2](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/nn-faxcomex-ifaxserver2)***

A [IFaxServer2](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/nn-faxcomex-ifaxserver2) object.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

To implement this functionality in Visual Basic, select and implement the appropriate event procedure. For an example, see [Registering for Fax Events](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-registering-for-fax-events).

## See also

[IFaxServerNotify2](https://learn.microsoft.com/windows/win32/api/faxcomex/nn-faxcomex-_ifaxservernotify2)