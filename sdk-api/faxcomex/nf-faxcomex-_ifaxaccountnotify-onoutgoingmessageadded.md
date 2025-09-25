# _IFaxAccountNotify::OnOutgoingMessageAdded

## Description

The fax service calls the **IFaxAccountNotify::OnOutgoingMessageAdded** method when an outgoing message is added to the outbound fax archive.

## Parameters

### `pFaxAccount` [in]

Type: **[IFaxAccount](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/nn-faxcomex-ifaxaccount)***

A [IFaxAccount](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/nn-faxcomex-ifaxaccount) object.

### `bstrMessageId` [in]

Type: **BSTR**

Null-terminated string that contains the ID of the message added to the outbound fax archive.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

To implement this functionality in Visual Basic, select and implement the appropriate event procedure.

## See also

[IFaxAccountNotify](https://learn.microsoft.com/windows/win32/api/faxcomex/nn-faxcomex-_ifaxaccountnotify)