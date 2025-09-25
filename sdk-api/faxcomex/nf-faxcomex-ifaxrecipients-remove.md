# IFaxRecipients::Remove

## Description

The **IFaxRecipients::Remove** method removes an item from the [FaxRecipients](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxrecipients) collection.

## Parameters

### `lIndex` [out, retval]

Type: **LONG**

A **LONG** that specifies the index of the item to remove from the collection. Valid values for this parameter are in the range from 1 to *n*, where *n* is the number of recipients returned by a call to the [IFaxRecipients::get_Count](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxrecipients-count-vb) method.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[Broadcasting a Fax](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-broadcasting-a-fax)

[FaxRecipients](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxrecipients)

[IFaxRecipients](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/nn-faxcomex-ifaxrecipients)