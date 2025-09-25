# acmDriverOpen function

## Description

The **acmDriverOpen** function opens the specified ACM driver and returns a driver instance handle that can be used to communicate with the driver.

## Parameters

### `phad`

Pointer to a buffer that receives the new driver instance handle that can be used to communicate with the driver.

### `hadid`

Handle to the driver identifier of an installed and enabled ACM driver.

### `fdwOpen`

Reserved; must be zero.

## Return value

Returns zero if successful or an error otherwise. Possible error values include the following.

| Return code | Description |
| --- | --- |
| **MMSYSERR_INVALFLAG** | At least one flag is invalid. |
| **MMSYSERR_INVALHANDLE** | The specified handle is invalid. |
| **MMSYSERR_INVALPARAM** | At least one parameter is invalid. |
| **MMSYSERR_NOMEM** | The system is unable to allocate resources. |
| **MMSYSERR_NOTENABLED** | The driver is not enabled. |

## See also

[Audio Compression Functions](https://learn.microsoft.com/windows/desktop/Multimedia/audio-compression-functions)

[Audio Compression Manager](https://learn.microsoft.com/windows/desktop/Multimedia/audio-compression-manager)