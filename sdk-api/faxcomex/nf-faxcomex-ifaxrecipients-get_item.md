# IFaxRecipients::get_Item

## Description

The [Item](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxrecipients-item) method returns a [FaxRecipient](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxrecipient) object from the [FaxRecipients](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxrecipients) collection.

## Parameters

### `lIndex` [in]

Type: **LONG**

A **LONG** value that specifies the item to retrieve from the fax recipient collection. Valid values for this parameter are in the range from 1 to *n*, where *n* is the number of recipients returned by a call to the [IFaxRecipients::get_Count](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxrecipients-count-vb) method.

### `ppFaxRecipient` [out, retval]

Type: **[IFaxRecipient](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/nn-faxcomex-ifaxrecipient)****

Address of a pointer to a [IFaxRecipient](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/nn-faxcomex-ifaxrecipient) interface.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[Broadcasting a Fax](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-broadcasting-a-fax)

[FaxRecipients](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxrecipients)

[IFaxRecipients](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/nn-faxcomex-ifaxrecipients)