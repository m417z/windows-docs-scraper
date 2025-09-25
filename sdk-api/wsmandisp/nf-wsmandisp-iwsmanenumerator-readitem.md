# IWSManEnumerator::ReadItem

## Description

Retrieves an item from the resource and returns an XML representation of the item.

## Parameters

### `resource` [out]

The XML representation of the item.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

To start an enumeration, use [IWSManSession.Enumerate](https://learn.microsoft.com/windows/desktop/api/wsmandisp/nf-wsmandisp-iwsmansession-enumerate). To perform a WS-Eventing:Pull operation that continues reading items in the enumeration, use **IWSManEnumerator.ReadItem**.

To limit the number of items that are read, set the [Session.BatchItems](https://learn.microsoft.com/windows/desktop/WinRM/session-batchitems) property.

Be aware that freeing the enumeration object clears pending enumeration requests.

## See also

[Enumerator.ReadItem](https://learn.microsoft.com/windows/desktop/WinRM/enumerator-readitem)

[IWSManEnumerator](https://learn.microsoft.com/windows/desktop/api/wsmandisp/nn-wsmandisp-iwsmanenumerator)