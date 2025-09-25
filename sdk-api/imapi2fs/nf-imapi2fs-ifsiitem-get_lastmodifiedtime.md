# IFsiItem::get_LastModifiedTime

## Description

Retrieves the date and time that the directory or file item was last modified in the file system image.

## Parameters

### `pVal` [out]

Date and time that the directory or file item was last modified in the file system image, according to UTC time.

## Return value

S_OK is returned on success, but other success codes may be returned as a result of implementation.

## Remarks

When implementing this method, a few things should be taken into consideration:

UDFS (UDF) will use the value provided by [IFsiItem::put_LastModifiedTime](https://learn.microsoft.com/windows/desktop/api/imapi2fs/nf-imapi2fs-ifsiitem-put_lastmodifiedtime) as both the *CreationTime* and *LastModifiedTime*.

CDFS (ISO 9660) uses the date/time of recording as the *CreationTime* and *LastModifiedTime*. As a result, CDFS sets the value of *LastModifiedTime* to 0.

## See also

[IFsiItem](https://learn.microsoft.com/windows/desktop/api/imapi2fs/nn-imapi2fs-ifsiitem)

[IFsiItem::put_LastModifiedTime](https://learn.microsoft.com/windows/desktop/api/imapi2fs/nf-imapi2fs-ifsiitem-put_lastmodifiedtime)