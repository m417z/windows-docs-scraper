# IFaxAccountOutgoingArchive::GetMessage

## Description

Returns a fax message from the archive of outbound faxes for a particular fax account, by using the fax message ID.

## Parameters

### `bstrMessageId` [in]

Type: **BSTR**

Specifies a null-terminated string that contains the message ID of the fax to retrieve from the archive of outbound faxes.

### `pFaxOutgoingMessage`

Type: **[IFaxOutgoingMessage](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/nn-faxcomex-ifaxoutgoingmessage)****

A [IFaxOutgoingMessage](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/nn-faxcomex-ifaxoutgoingmessage) object.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[FaxAccountOutgoingArchive](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxaccountoutgoingarchive)

[IFaxAccountOutgoingArchive](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/nn-faxcomex-ifaxaccountoutgoingarchive)