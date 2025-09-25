# IFaxRecipients::Add

## Description

The **IFaxRecipients::Add** method adds a new [FaxRecipient](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxrecipient) object to the [FaxRecipients](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxrecipients) collection.

## Parameters

### `bstrFaxNumber`

Type: **BSTR**

Specifies the fax number of the fax recipient.

### `bstrRecipientName` [optional]

Type: **BSTR**

Specifies the name of the fax recipient.

### `ppFaxRecipient` [out, retval]

Type: **[IFaxRecipient](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/nn-faxcomex-ifaxrecipient)****

A [FaxRecipient](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxrecipient) object.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[Broadcasting a Fax](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-broadcasting-a-fax)

[FaxRecipients](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxrecipients)

[IFaxRecipients](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/nn-faxcomex-ifaxrecipients)