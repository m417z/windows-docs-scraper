# acmFormatEnum function

## Description

The **acmFormatEnum** function enumerates waveform-audio formats available for a given format tag from an ACM driver. This function continues enumerating until there are no more suitable formats for the format tag or the callback function returns **FALSE**.

## Parameters

### `had`

Handle to the ACM driver to query for waveform-audio format details. If this parameter is **NULL**, the ACM uses the details from the first suitable ACM driver.

### `pafd`

Pointer to an [ACMFORMATDETAILS](https://learn.microsoft.com/windows/win32/api/msacm/nf-msacm-acmformatdetails) structure to contain the format details passed to the **fnCallback** function. This structure must have the **cbStruct**, **pwfx**, and **cbwfx** members of the **ACMFORMATDETAILS** structure initialized. The **dwFormatTag** member must also be initialized to either WAVE_FORMAT_UNKNOWN or a valid format tag.

The **fdwSupport** member of the structure must be initialized to zero.

To find the required size of the **pwfx** buffer, call [acmMetrics](https://learn.microsoft.com/windows/desktop/api/msacm/nf-msacm-acmmetrics) with the ACM_METRIC_MAX_SIZE_FORMAT flag.

### `fnCallback`

Address of an application-defined callback function. See [acmFormatEnumCallback](https://learn.microsoft.com/windows/desktop/api/msacm/nc-msacm-acmformatenumcb). This parameter cannot be **NULL**.

### `dwInstance`

A 64-bit (DWORD_PTR) or 32-bit (DWORD) application-defined value that is passed to the callback function along with ACM format details.

### `fdwEnum`

Flags for enumerating the formats for a given format tag. The following values are defined.

| Value | Meaning |
| --- | --- |
| ACM_FORMATENUMF_CONVERT |[ACMFORMATDETAILS](https://learn.microsoft.com/windows/win32/api/msacm/nf-msacm-acmformatdetails) structure is valid. The enumerator will only enumerate destination formats that can be converted from the given **pwfx** format.If this flag is used, the **wFormatTag** member of the **WAVEFORMATEX** structure cannot be WAVE_FORMAT_UNKNOWN.

| ACM_FORMATENUMF_HARDWARE | The enumerator should only enumerate formats that are supported as native input or output formats on one or more of the installed waveform-audio devices. This flag provides a way for an application to choose only formats native to an installed waveform-audio device. This flag must be used with one or both of the ACM_FORMATENUMF_INPUT and ACM_FORMATENUMF_OUTPUT flags. Specifying both ACM_FORMATENUMF_INPUT and ACM_FORMATENUMF_OUTPUT will enumerate only formats that can be opened for input or output. This is true regardless of whether this flag is specified. |
| ACM_FORMATENUMF_INPUT | Enumerator should enumerate only formats that are supported for input (recording). |
| ACM_FORMATENUMF_NCHANNELS |[ACMFORMATDETAILS](https://learn.microsoft.com/windows/win32/api/msacm/nf-msacm-acmformatdetails) structure is valid. The enumerator will enumerate only a format that conforms to this attribute.
| ACM_FORMATENUMF_NSAMPLESPERSEC | The **nSamplesPerSec** member of the **WAVEFORMATEX** structure pointed to by the **pwfx** member of the **ACMFORMATDETAILS** structure is valid. The enumerator will enumerate only a format that conforms to this attribute. |
| ACM_FORMATENUMF_OUTPUT | Enumerator should enumerate only formats that are supported for output (playback). |
| ACM_FORMATENUMF_SUGGEST |[ACMFORMATDETAILS](https://learn.microsoft.com/windows/win32/api/msacm/nf-msacm-acmformatdetails) structure is valid. The enumerator will enumerate all suggested destination formats for the given **pwfx** format. This mechanism can be used instead of the [acmFormatSuggest](https://learn.microsoft.com/windows/desktop/api/msacm/nf-msacm-acmformatsuggest) function to allow an application to choose the best suggested format for conversion. The **dwFormatIndex** member will always be set to zero on return.If this flag is used, the **wFormatTag** member of the **WAVEFORMATEX** structure cannot be WAVE_FORMAT_UNKNOWN.

| ACM_FORMATENUMF_WBITSPERSAMPLE | The **wBitsPerSample** member of the **WAVEFORMATEX** structure pointed to by the **pwfx** member of the **ACMFORMATDETAILS** structure is valid. The enumerator will enumerate only a format that conforms to this attribute. |
| ACM_FORMATENUMF_WFORMATTAG | The **wFormatTag** member of the **WAVEFORMATEX** structure pointed to by the **pwfx** member of the **ACMFORMATDETAILS** structure is valid. The enumerator will enumerate only a format that conforms to this attribute. The **dwFormatTag** member of the **ACMFORMATDETAILS** structure must be equal to the **wFormatTag** member.The value of **wFormatTag** cannot be WAVE_FORMAT_UNKNOWN in this case. |

## Return value

Returns zero if successful or an error otherwise. Possible error values include the following.

| Return code | Description |
| --- | --- |
| **ACMERR_NOTPOSSIBLE** | The details for the format cannot be returned. |
| **MMSYSERR_INVALFLAG** | At least one flag is invalid. |
| **MMSYSERR_INVALHANDLE** | The specified handle is invalid. |
| **MMSYSERR_INVALPARAM** | At least one parameter is invalid. |

## Remarks

This function will return MMSYSERR_NOERROR (zero) if no suitable ACM drivers are installed. Moreover, the callback function will not be called.

#### Examples

The following example shows how to enumerate formats that have the WAVE_FORMAT_MPEGLAYER3 format tag.

```cpp

MMRESULT EnumerateMP3Codecs()
{
    DWORD cbMaxSize = 0;
    MMRESULT result = MMSYSERR_NOERROR;
    ACMFORMATDETAILS acmFormatDetails;

    // Buffer to hold the format information.
    BYTE *pFormat = NULL;   // Caller allocated.

    // Find the largest format buffer needed.
    result = acmMetrics(NULL, ACM_METRIC_MAX_SIZE_FORMAT, &cbMaxSize);
    if (result != MMSYSERR_NOERROR)
    {
        return result;
    }

    // Allocate the format buffer.
    pFormat = new BYTE[cbMaxSize];
    if (pFormat == NULL)
    {
        return MMSYSERR_NOMEM;
    }

    ZeroMemory(pFormat, cbMaxSize);

    // Ask for WAVE_FORMAT_MPEGLAYER3 formats.
    WAVEFORMATEX* pWaveFormat = (WAVEFORMATEX*)pFormat;
    pWaveFormat->wFormatTag = WAVE_FORMAT_MPEGLAYER3;

    // Set up the acmFormatDetails structure.
    ZeroMemory(&acmFormatDetails, sizeof(acmFormatDetails));
    acmFormatDetails.cbStruct = sizeof(ACMFORMATDETAILS);
    acmFormatDetails.pwfx = pWaveFormat;
    acmFormatDetails.cbwfx = cbMaxSize;

    // For the ACM_FORMATENUMF_WFORMATTAG request, the format
    // tag in acmFormatDetails must match the format tag in
    // the pFormat buffer.
    acmFormatDetails.dwFormatTag = WAVE_FORMAT_MPEGLAYER3;

    result = acmFormatEnum(NULL, &acmFormatDetails, acmFormatEnumCallback,
        0, ACM_FORMATENUMF_WFORMATTAG);

    delete [] pFormat;

    return result;
}

```

The next example shows the callback function for the previous example. The callback function is called once for each matching format or until the callback returns **FALSE**.

```cpp

BOOL CALLBACK acmFormatEnumCallback(
  HACMDRIVERID       hadid,
  LPACMFORMATDETAILS pafd,
  DWORD_PTR          dwInstance,
  DWORD              fdwSupport
)
{
    BOOL bContinue = TRUE;
    MPEGLAYER3WAVEFORMAT *pMP3WaveFormat = NULL;

    if (pafd->pwfx->wFormatTag == WAVE_FORMAT_MPEGLAYER3)
    {
        pMP3WaveFormat = (MPEGLAYER3WAVEFORMAT*)pafd->pwfx;

        // TODO: Examine the format.

        // To halt the enumeration, set bContinue to FALSE.
    }

    return bContinue;
}

```

## See also

[Audio Compression Functions](https://learn.microsoft.com/windows/desktop/Multimedia/audio-compression-functions)

[Audio Compression Manager](https://learn.microsoft.com/windows/desktop/Multimedia/audio-compression-manager)