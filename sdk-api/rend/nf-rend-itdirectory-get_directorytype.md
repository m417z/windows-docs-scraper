# ITDirectory::get_DirectoryType

## Description

[Rendezvous IP Telephony Conferencing controls and interfaces are not available for use in Windows Vista, Windows Server 2008, and subsequent versions of the operating system. The RTC Client API
provides similar functionality.]

The
**get_DirectoryType** method gets
[DIRECTORY_TYPE](https://learn.microsoft.com/windows/desktop/api/rend/ne-rend-directory_type) indicator of the type of the directory.

## Parameters

### `pDirectoryType` [out]

Pointer to type of the directory.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Method succeeded. |
| **E_POINTER** | The *pDirectoryType* parameter is not a valid pointer. |

## See also

[DIRECTORY_TYPE](https://learn.microsoft.com/windows/desktop/api/rend/ne-rend-directory_type)

[ITDirectory](https://learn.microsoft.com/windows/desktop/api/rend/nn-rend-itdirectory)