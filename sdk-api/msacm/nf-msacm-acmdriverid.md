# acmDriverID function

## Description

The **acmDriverID** function returns the handle of an ACM driver identifier associated with an open ACM driver instance or stream handle.

## Parameters

### `hao`

Handle to the open driver instance or stream handle. This is the handle of an ACM object, such as **HACMDRIVER** or **HACMSTREAM**.

### `phadid`

Pointer to a buffer that receives a handle identifying the installed driver that is associated with *hao*.

### `fdwDriverID`

Reserved; must be zero.

## Return value

Returns zero if successful or an error otherwise. Possible error values include the following.

| Return code | Description |
| --- | --- |
| **MMSYSERR_INVALFLAG** | At least one flag is invalid. |
| **MMSYSERR_INVALHANDLE** | The specified handle is invalid. |
| **MMSYSERR_INVALPARAM** | At least one parameter is invalid. |

## See also

[Audio Compression Functions](https://learn.microsoft.com/windows/desktop/Multimedia/audio-compression-functions)

[Audio Compression Manager](https://learn.microsoft.com/windows/desktop/Multimedia/audio-compression-manager)