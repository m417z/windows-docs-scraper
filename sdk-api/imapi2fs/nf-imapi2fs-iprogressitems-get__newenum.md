# IProgressItems::get__NewEnum

## Description

Retrieves the list of progress items from the collection.

## Parameters

### `NewEnum` [out]

An **IEnumVariant** interface that you use to enumerate the progress items contained within the collection. Each item of the enumeration is a VARIANT whose type is **VT_DISPATCH**. Query the **pdispVal** member to retrieve the [IProgressItem](https://learn.microsoft.com/windows/desktop/api/imapi2fs/nn-imapi2fs-iprogressitem) interface.

## Return value

S_OK is returned when the number of requested elements (*celt*) are returned successfully or the number of returned items (*pceltFetched*) is less than the number of requested elements. The *celt* and *pceltFetched* parameters are defined by **IEnumVariant**.

Other success codes may be returned as a result of implementation. The following error codes are commonly returned on operation failure, but do not represent the only possible error values:

| Return code | Description |
| --- | --- |
| **E_POINTER** | Pointer is not valid.<br><br>Value: 0x80004003 |
| **E_OUTOFMEMORY** | Failed to allocate the required memory.<br><br>Value: 0x8007000E |

## Remarks

The enumeration is a snapshot of the progress items contained in the collection at the time of the call.

To retrieve a single item, see the [IProgressItems::get_Item](https://learn.microsoft.com/windows/desktop/api/imapi2fs/nf-imapi2fs-iprogressitems-get_item) property.

## See also

[IFileSystemImageResult](https://learn.microsoft.com/windows/desktop/api/imapi2fs/nn-imapi2fs-ifilesystemimageresult)

[IProgressItem](https://learn.microsoft.com/windows/desktop/api/imapi2fs/nn-imapi2fs-iprogressitem)

[IProgressItems](https://learn.microsoft.com/windows/desktop/api/imapi2fs/nn-imapi2fs-iprogressitems)