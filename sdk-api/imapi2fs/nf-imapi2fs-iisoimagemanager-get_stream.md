# IIsoImageManager::get_Stream

## Description

Retrieves the **IStream** object associated with the .iso image.

## Parameters

### `data` [out]

The **IStream** object associated with the .iso image.

## Return value

S_OK is returned on success, but other success codes may be returned as a result of implementation.

## Remarks

This method is supported in Windows Server 2003 with Service Pack 1 (SP1), Windows XP with Service Pack 2 (SP2), and Windows Vista via the Windows Feature Pack for Storage. All features provided by this update package are supported natively in Windows 7 and Windows Server 2008 R2.

## See also

[IIsoImageManager](https://learn.microsoft.com/windows/desktop/api/imapi2fs/nn-imapi2fs-iisoimagemanager)

[IIsoImageManager::SetStream](https://learn.microsoft.com/windows/desktop/api/imapi2fs/nf-imapi2fs-iisoimagemanager-setstream)