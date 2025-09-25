# acmDriverEnum function

## Description

The **acmDriverEnum** function enumerates the available ACM drivers, continuing until there are no more drivers or the callback function returns **FALSE**.

## Parameters

### `fnCallback`

Procedure instance address of the application-defined callback function.

### `dwInstance`

A 64-bit (DWORD_PTR) or 32-bit (DWORD) application-defined value that is passed to the callback function along with ACM driver information.

### `fdwEnum`

Flags for enumerating ACM drivers. The following values are defined.

| Value | Meaning |
| --- | --- |
| ACM_DRIVERENUMF_DISABLED | Disabled ACM drivers should be included in the enumeration. Drivers can be disabled by the user through the Control Panel or by an application using the [acmDriverPriority](https://learn.microsoft.com/windows/desktop/api/msacm/nf-msacm-acmdriverpriority) function. If a driver is disabled, the *fdwSupport* parameter to the callback function will have the ACMDRIVERDETAILS_SUPPORTF_DISABLED flag set. |
| ACM_DRIVERENUMF_NOLOCAL | Only global drivers should be included in the enumeration. |

## Return value

Returns zero if successful or an error otherwise. Possible error values include the following.

| Return code | Description |
| --- | --- |
| **MMSYSERR_INVALFLAG** | At least one flag is invalid. |
| **MMSYSERR_INVALPARAM** | At least one parameter is invalid. |

## Remarks

The **acmDriverEnum** function will return MMSYSERR_NOERROR (zero) if no ACM drivers are installed. Moreover, the callback function will not be called.

## See also

[Audio Compression Functions](https://learn.microsoft.com/windows/desktop/Multimedia/audio-compression-functions)

[Audio Compression Manager](https://learn.microsoft.com/windows/desktop/Multimedia/audio-compression-manager)