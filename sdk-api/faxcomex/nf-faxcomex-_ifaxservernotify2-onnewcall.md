# _IFaxServerNotify2::OnNewCall

## Description

The fax service calls the **IFaxServerNotify2::OnNewCall** method when there is a new incoming fax call.

## Parameters

### `pFaxServer`

Type: **[IFaxServer2](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/nn-faxcomex-ifaxserver2)***

A [IFaxServer2](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/nn-faxcomex-ifaxserver2) object.

### `lCallId`

Type: **long**

Long value that specifies the call's ID.

### `lDeviceId`

Type: **long**

Long value that specifies the device ID of the device receiving the new incoming fax call.

### `bstrCallerId`

Type: **long**

Null-terminated string that identifies the calling device for the new incoming fax call.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

To implement this functionality in Visual Basic, select and implement the appropriate event procedure. For an example, see [Registering for Fax Events](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-registering-for-fax-events).

## See also

[IFaxServerNotify2](https://learn.microsoft.com/windows/win32/api/faxcomex/nn-faxcomex-_ifaxservernotify2)