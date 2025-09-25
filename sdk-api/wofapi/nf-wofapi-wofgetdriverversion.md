# WofGetDriverVersion function

## Description

Used to query the version of the driver used to support a particular provider.

## Parameters

### `FileOrVolumeHandle` [in]

A handle to a file or volume opened with [CreateFile](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-createfilea) or a similar API.

### `Provider` [in]

Indicates which provider the version query is intended for. Multiple versions of Wof may exist on the same volume at the same time for different providers.

### `WofVersion` [out]

Pointer to a ULONG which will contain the version upon successful completion of this function.

## Return value

This function returns an HRESULT indicating success or the reason for failure. If no driver is attached on the specified volume for the specified provider, the function will fail with HRESULT_FROM_WIN32(ERROR_INVALID_FUNCTION).

## Remarks

On successful completion, the WofVersion value is updated to reflect the version of the WOF driver. This value includes the major and minor version numbers of the operating system in the high-order word, and the build number of the operating system in the low-order word. The major version can be extracted with HIBYTE(HIWORD(WofVersion)); the minor version can be extracted with LOBYTE(HIWORD(WofVersion)); the build number can be extracted with LOWORD(WofVersion).

QuickInfo

## See also

[FSCTL_GET_WOF_VERSION](https://learn.microsoft.com/windows-hardware/drivers/ifs/fsctl-get-wof-version)