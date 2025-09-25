# GetNtmsMediaPoolNameW function

## Description

[[Removable Storage Manager](https://learn.microsoft.com/previous-versions/windows/desktop/bb540725(v=vs.85)) is no longer available as of Windows 7 and Windows Server 2008 R2.]

The
**GetNtmsMediaPoolName** function retrieves the specified media pool's full name hierarchy.

## Parameters

### `hSession` [in]

Handle to the session returned by the
[OpenNtmsSession](https://learn.microsoft.com/windows/desktop/api/ntmsapi/nf-ntmsapi-openntmssessiona) function.

### `lpPoolId` [in]

Unique identifier of the media pool whose name is to be retrieved.

### `lpNameBuf` [out]

Pointer to a buffer that receives the name of the media pool.

### `lpdwBufSize` [in, out]

Size of the *lpBufName* buffer, on input. On output, the number of characters in the full name hierarchy.

## Return value

This function returns one of the following values.

| Value | Meaning |
| --- | --- |
| **ERROR_INSUFFICIENT_BUFFER** | The buffer size is not large enough. The correct size is returned in *lpdwBufSize*. |
| **ERROR_INVALID_HANDLE** | The value specified in the *hSession* parameter is **NULL** or is not valid. |
| **ERROR_INVALID_MEDIA_POOL** | The media pool ID is missing or is not valid. |
| **ERROR_INVALID_PARAMETER** | The parameter is missing or is not valid. |
| **ERROR_NOT_ENOUGH_MEMORY** | The memory allocation failed. |
| **ERROR_SUCCESS** | The function was successful. |

## See also

[CreateNtmsMediaPool](https://learn.microsoft.com/windows/desktop/api/ntmsapi/nf-ntmsapi-createntmsmediapool)

[Media Services Functions](https://learn.microsoft.com/previous-versions/windows/desktop/rsm/removable-storage-manager-functions)

## Remarks

> [!NOTE]
> The ntmsapi.h header defines GetNtmsMediaPoolName as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).