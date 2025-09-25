# IFsiItem::put_LastModifiedTime

## Description

Sets the date and time that the item was last modified in the file system image.

## Parameters

### `newVal` [in]

Date and time that the directory or file item was last modified in the file system image, according to UTC time. Defaults to the time the item was added to the image.

## Return value

S_OK is returned on success, but other success codes may be returned as a result of implementation. The following error codes are commonly returned on operation failure, but do not represent the only possible error values:

| Return code | Description |
| --- | --- |
| **IMAPI_E_READONLY** | FileSystemImage object is in read only mode.<br><br>Value: 0xC0AAB102 |
| **E_OUTOFMEMORY** | Failed to allocate necessary memory.<br><br>Value: 0x8007000E |

## Remarks

The last modified time is propagated to the attribute that users see when viewing the properties of a directory or a file.

When implementing this method, a few things should be taken into consideration:

UDFS (UDF) will use the value provided by **IFsiItem::put_LastModifiedTime** as both the *CreationTime* and *LastModifiedTime*.

CDFS (ISO 9660) uses the date/time of recording as the *CreationTime* and *LastModifiedTime*. As a result, CDFS sets the value of *LastModifiedTime* to 0.

## See also

[IFsiItem](https://learn.microsoft.com/windows/desktop/api/imapi2fs/nn-imapi2fs-ifsiitem)

[IFsiItem::get_LastModifiedTime](https://learn.microsoft.com/windows/desktop/api/imapi2fs/nf-imapi2fs-ifsiitem-get_lastmodifiedtime)