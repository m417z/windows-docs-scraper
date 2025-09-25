# acmFilterEnumA function

## Description

The **acmFilterEnum** function enumerates waveform-audio filters available for a given filter tag from an ACM driver. This function continues enumerating until there are no more suitable filters for the filter tag or the callback function returns **FALSE**.

## Parameters

### `had`

Handle to the ACM driver to query for waveform-audio filter details. If this parameter is **NULL**, the ACM uses the details from the first suitable ACM driver.

### `pafd`

Pointer to the [ACMFILTERDETAILS](https://learn.microsoft.com/windows/win32/api/msacm/nf-msacm-acmfilterdetails) structure that contains the filter details when it is passed to the function specified by *fnCallback*. When your application calls **acmFilterEnum**, the **cbStruct**, **pwfltr**, and **cbwfltr** members of this structure must be initialized. The **dwFilterTag** member must also be initialized to either WAVE_FILTER_UNKNOWN or a valid filter tag.

### `fnCallback`

Procedure-instance address of the application-defined callback function.

### `dwInstance`

A 32-bit (DWORD), 64-bit (DWORD_PTR) application-defined value that is passed to the callback function along with ACM filter details.

### `fdwEnum`

Flags for enumerating the filters for a given filter tag. The following values are defined.

| Value | Meaning |
| --- | --- |
| ACM_FILTERENUMF_DWFILTERTAG |[ACMFILTERDETAILS](https://learn.microsoft.com/windows/win32/api/msacm/nf-msacm-acmfilterdetails) structure is valid. The enumerator will enumerate only a filter that conforms to this attribute. The **dwFilterTag** member of the **ACMFILTERDETAILS** structure must be equal to the **dwFilterTag** member of the **WAVEFILTER** structure.

## Return value

Returns zero if successful or an error otherwise. Possible error values include the following.

| Return code | Description |
| --- | --- |
| **ACMERR_NOTPOSSIBLE** | The details for the filter cannot be returned. |
| **MMSYSERR_INVALFLAG** | At least one flag is invalid. |
| **MMSYSERR_INVALHANDLE** | The specified handle is invalid. |
| **MMSYSERR_INVALPARAM** | At least one parameter is invalid. |

## Remarks

The **acmFilterEnum** function will return MMSYSERR_NOERROR (zero) if no suitable ACM drivers are installed. Moreover, the callback function will not be called.

The following functions should not be called from within the callback function: **acmDriverAdd**, **acmDriverRemove**, and **acmDriverPriority**.

> [!NOTE]
> The msacm.h header defines acmFilterEnum as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[Audio Compression Functions](https://learn.microsoft.com/windows/desktop/Multimedia/audio-compression-functions)

[Audio Compression Manager](https://learn.microsoft.com/windows/desktop/Multimedia/audio-compression-manager)