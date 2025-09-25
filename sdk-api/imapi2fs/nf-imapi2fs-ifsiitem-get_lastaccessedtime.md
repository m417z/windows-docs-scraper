# IFsiItem::get_LastAccessedTime

## Description

Retrieves the date and time the directory or file item was last accessed in the file system image.

## Parameters

### `pVal` [out]

Date and time that the item directory or file was last accessed in the file system image, according to UTC time.

## Return value

S_OK is returned on success, but other success codes may be returned as a result of implementation.

## Remarks

UDFS (UDF) uses the *LastAccessedTime* value for the *CreationTime*, as IMAPI does not currently support the *CreationTime* extended attribute.

CDFS (ISO 9660) sets the *LastAccessedTime* value retrieved by this method to 0, as only the recording time is stored within the File/Directory descriptor.

## See also

[IFsiItem](https://learn.microsoft.com/windows/desktop/api/imapi2fs/nn-imapi2fs-ifsiitem)

[IFsiItem::put_LastAccessedTime](https://learn.microsoft.com/windows/desktop/api/imapi2fs/nf-imapi2fs-ifsiitem-put_lastaccessedtime)