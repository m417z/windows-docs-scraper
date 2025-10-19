# IBackgroundCopyGroup::get_Size

## Description

[**IBackgroundCopyGroup** is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions. Instead, use the [BITS interfaces](https://learn.microsoft.com/windows/desktop/Bits/bits-interfaces).]

Use the **get_Size** method to retrieve the size of all files in the group to download.

## Parameters

### `pdwSize` [out]

Total size, in bytes, of all files in the group to download, or 0 if QMGR cannot determine the size.

## Return value

This method returns the following **HRESULT** values, as well as others.

| Return code | Description |
| --- | --- |
| **S_OK** | Successfully retrieved the size of the group. |

## See also

[IBackgroundCopyGroup](https://learn.microsoft.com/windows/desktop/api/qmgr/nn-qmgr-ibackgroundcopygroup)