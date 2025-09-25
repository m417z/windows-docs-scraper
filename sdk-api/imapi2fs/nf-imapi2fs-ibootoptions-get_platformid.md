# IBootOptions::get_PlatformId

## Description

Retrieves the platform identifier that identifies the operating system architecture that the boot image supports.

## Parameters

### `pVal` [out]

Identifies the operating system architecture that the boot image supports. For possible values, see the [PlatformId](https://learn.microsoft.com/windows/desktop/api/imapi2fs/ne-imapi2fs-platformid) enumeration type.

## Return value

S_OK is returned on success, but other success codes may be returned as a result of implementation. The following error codes are commonly returned on operation failure, but do not represent the only possible error values:

| Return code | Description |
| --- | --- |
| **E_POINTER** | Pointer is not valid.<br><br>Value: 0x80004003 |

## See also

[IBootOptions](https://learn.microsoft.com/windows/desktop/api/imapi2fs/nn-imapi2fs-ibootoptions)

[IBootOptions::put_PlatformId](https://learn.microsoft.com/windows/desktop/api/imapi2fs/nf-imapi2fs-ibootoptions-put_platformid)