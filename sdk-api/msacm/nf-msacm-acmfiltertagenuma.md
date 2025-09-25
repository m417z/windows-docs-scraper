# acmFilterTagEnumA function

## Description

The **acmFilterTagEnum** function enumerates waveform-audio filter tags available from an ACM driver. This function continues enumerating until there are no more suitable filter tags or the callback function returns **FALSE**.

## Parameters

### `had`

Handle to the ACM driver to query for waveform-audio filter tag details. If this parameter is **NULL**, the ACM uses the details from the first suitable ACM driver.

### `paftd`

Pointer to the [ACMFILTERTAGDETAILS](https://learn.microsoft.com/windows/win32/api/msacm/nf-msacm-acmfiltertagdetails) structure that contains the filter tag details when it is passed to the **fnCallback** function. When your application calls **acmFilterTagEnum**, the **cbStruct** member of this structure must be initialized.

### `fnCallback`

Procedure instance address of the application-defined callback function.

### `dwInstance`

A 64-bit (DWORD_PTR) or 32-bit (DWORD) application-defined value that is passed to the callback function along with ACM filter tag details.

### `fdwEnum`

Reserved; must be zero.

## Return value

Returns zero if successful or an error otherwise. Possible error values include the following.

| Return code | Description |
| --- | --- |
| **MMSYSERR_INVALFLAG** | At least one flag is invalid. |
| **MMSYSERR_INVALHANDLE** | The specified handle is invalid. |
| **MMSYSERR_INVALPARAM** | At least one parameter is invalid. |

## Remarks

This function will return MMSYSERR_NOERROR (zero) if no suitable ACM drivers are installed. Moreover, the callback function will not be called.

> [!NOTE]
> The msacm.h header defines acmFilterTagEnum as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[Audio Compression Functions](https://learn.microsoft.com/windows/desktop/Multimedia/audio-compression-functions)

[Audio Compression Manager](https://learn.microsoft.com/windows/desktop/Multimedia/audio-compression-manager)