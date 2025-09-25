# IFsiItem::FileSystemName

## Description

Retrieves the name of the item as modified to conform to the specified file system.

## Parameters

### `fileSystem` [in]

File system to which the name should conform. For possible values, see the [FsiFileSystems](https://learn.microsoft.com/windows/desktop/api/imapi2fs/ne-imapi2fs-fsifilesystems) enumeration type.

### `pVal` [out]

String that contains the name of the item as it conforms to the specified file system. The name in the [IFsiItem::get_Name](https://learn.microsoft.com/windows/desktop/api/imapi2fs/nf-imapi2fs-ifsiitem-get_name) property is modified if the characters used and its length do not meet the requirements of the specified file system type.

## Return value

S_OK is returned on success, but other success codes may be returned as a result of implementation. The following error codes are commonly returned on operation failure, but do not represent the only possible error values:

| Return code | Description |
| --- | --- |
| **E_POINTER** | Pointer is not valid.<br><br>Value: 0x80004003 |
| **IMAPI_E_INVALID_PARAM** | The value specified for parameter *%1!ls!* is not valid.<br><br>Value: 0xC0AAB101 |

## See also

[IFsiItem](https://learn.microsoft.com/windows/desktop/api/imapi2fs/nn-imapi2fs-ifsiitem)