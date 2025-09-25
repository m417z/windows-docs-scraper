# IFsiNamedStreams::get__NewEnum

## Description

Retrieves an **IEnumVARIANT** list of the named streams associated with a file in the file system image.

## Parameters

### `NewEnum` [out, optional]

Pointer to a pointer to an **IEnumVariant** interface that is used to enumerate the named streams associated with a file. The items of the enumeration are variants whose type is **VT_BSTR**. Use the **bstrVal** member to retrieve the path to the named stream.

## Return value

S_OK is returned when the number of requested elements (*celt*) are returned successfully or the number of returned items (*pceltFetched*) is less than the number of requested elements. The *celt* and *pceltFetched* parameters are defined by **IEnumVariant**.

Other success codes may be returned as a result of implementation. The following error codes are commonly returned on operation failure, but do not represent the only possible error values:

| Return code/value | Description |
| --- | --- |
| **E_POINTER**<br><br>Value: 0x80004003 | Pointer is not valid. |
| **E_OUTOFMEMORY**<br><br>Value: 0x8007000EL | Failed to allocate required memory. |

## Remarks

The enumeration is a snapshot of the named streams associated with the file at the time of the call and will not reflect named streams that are added or removed later on.

To retrieve a single named stream, use the [IFsiNamedStreams::get_Item](https://learn.microsoft.com/windows/desktop/api/imapi2fs/nf-imapi2fs-ifsinamedstreams-get_item) method.

This method is supported in Windows Server 2003 with Service Pack 1 (SP1), Windows XP with Service Pack 2 (SP2), and Windows Vista via the Windows Feature Pack for Storage. All features provided by this update package are supported natively in Windows 7 and Windows Server 2008 R2.

## See also

[IFsiNamedStreams](https://learn.microsoft.com/windows/desktop/api/imapi2fs/nn-imapi2fs-ifsinamedstreams)