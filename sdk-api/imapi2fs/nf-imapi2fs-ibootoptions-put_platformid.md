# IBootOptions::put_PlatformId

## Description

Sets the platform identifier that identifies the operating system architecture that the boot image supports.

## Parameters

### `newVal` [in]

Identifies the operating system architecture that the boot image supports. For possible values, see the [PlatformId](https://learn.microsoft.com/windows/desktop/api/imapi2fs/ne-imapi2fs-platformid) enumeration type. The default value is **PlatformX86** for Intel x86–based platforms.

## Return value

S_OK is returned on success, but other success codes may be returned as a result of implementation.

## See also

[IBootOptions](https://learn.microsoft.com/windows/desktop/api/imapi2fs/nn-imapi2fs-ibootoptions)

[IBootOptions::get_PlatformId](https://learn.microsoft.com/windows/desktop/api/imapi2fs/nf-imapi2fs-ibootoptions-get_platformid)