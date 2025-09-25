# IFsiNamedStreams::get_Item

## Description

Retrieves a single named stream associated with a file in the file system image.

## Parameters

### `index` [in]

This value indicates the position of the named stream within the collection.
The index number is zero-based, i.e. the first item is at location 0 of the collection.

### `item` [out, optional]

Pointer to a pointer to an [IFsiFileItem2](https://learn.microsoft.com/windows/desktop/api/imapi2fs/nn-imapi2fs-ifsifileitem2) object representing the named stream at the position specified by *index*. This parameter is set to **NULL** if the specified index is not within the collection boundary.

## Return value

S_OK is returned on success, but other success codes may be returned as a result of implementation. The following error codes are commonly returned on operation failure, but do not represent the only possible error values:

| Return code/value | Description |
| --- | --- |
| **E_POINTER**<br><br>Value: 0x80004003 | Pointer is not valid. |
| **IMAPI_E_INVALID_PARAM**<br><br>Value: 0xC0AAB101 | The value specified for parameter '*%1!ls!*' is invalid. |

## Remarks

If the index number is negative or out of range, this method returns the **IMAPI_E_INVALID_PARAM**.

To fetch an **IEnumVARIANT** enumerator for all named streams associated with a file, use the [IFsiNamedStreams::get__NewEnum](https://learn.microsoft.com/windows/desktop/api/imapi2fs/nf-imapi2fs-ifsinamedstreams-get__newenum) method.

This method is supported in Windows Server 2003 with Service Pack 1 (SP1), Windows XP with Service Pack 2 (SP2), and Windows Vista via the Windows Feature Pack for Storage. All features provided by this update package are supported natively in Windows 7 and Windows Server 2008 R2.

## See also

[IFsiNamedStreams](https://learn.microsoft.com/windows/desktop/api/imapi2fs/nn-imapi2fs-ifsinamedstreams)