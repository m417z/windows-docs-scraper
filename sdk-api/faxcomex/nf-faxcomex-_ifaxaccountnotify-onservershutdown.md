# _IFaxAccountNotify::OnServerShutDown

## Description

Called by the fax service when it shuts down.

## Parameters

### `pFaxServer`

Type: **[IFaxAccount](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/nn-faxcomex-ifaxaccount)***

A [IFaxAccount](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/nn-faxcomex-ifaxaccount) object.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

To implement this functionality in Visual Basic, select and implement the appropriate event procedure.

## See also

[IFaxServerNotify2](https://learn.microsoft.com/windows/win32/api/faxcomex/nn-faxcomex-_ifaxservernotify2)

[_IFaxAccountNotify](https://learn.microsoft.com/windows/win32/api/faxcomex/nn-faxcomex-_ifaxaccountnotify)