# _IFaxAccountNotify::OnIncomingMessageAdded

## Description

Called by the fax service when an incoming message is added to the inbound fax archive.

## Parameters

### `pFaxAccount` [in]

Type: **[IFaxAccount](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/nn-faxcomex-ifaxaccount)***

An [IFaxAccount](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/nn-faxcomex-ifaxaccount) object.

### `bstrMessageId` [in]

Type: **BSTR**

A null-terminated string that contains the ID of the message added to the inbound fax archive.

### `fAddedToReceiveFolder` [in]

Type: **VARIANT_BOOL**

A value that indicates whether the message was successfully added to the received folder.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

To implement this functionality in Visual Basic, select and implement the appropriate event procedure.

## See also

[IFaxAccountNotify](https://learn.microsoft.com/windows/win32/api/faxcomex/nn-faxcomex-_ifaxaccountnotify)