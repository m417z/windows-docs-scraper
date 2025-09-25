# acmFilterChooseA function

## Description

The **acmFilterChoose** function creates an ACM-defined dialog box that enables the user to select a waveform-audio filter.

## Parameters

### `pafltrc`

Pointer to an [ACMFILTERCHOOSE](https://learn.microsoft.com/windows/win32/api/msacm/nf-msacm-acmfilterchoose) structure that contains information used to initialize the dialog box. When **acmFilterChoose** returns, this structure contains information about the user's filter selection.

The **pwfltr** member of this structure must contain a valid pointer to a memory location that will contain the returned filter header structure. The **cbwfltr** member must be filled in with the size, in bytes, of this memory buffer.

## Return value

Returns MMSYSERR_NOERROR if successful or an error otherwise. Possible error values include the following.

| Return code | Description |
| --- | --- |
| **ACMERR_CANCELED** | The user chose the Cancel button or the Close command on the System menu to close the dialog box. |
| **ACMERR_NOTPOSSIBLE** | The buffer identified by the [ACMFILTERCHOOSE](https://learn.microsoft.com/windows/win32/api/msacm/nf-msacm-acmfilterchoose) structure is too small to contain the selected filter. |
| **MMSYSERR_INVALFLAG** | At least one flag is invalid. |
| **MMSYSERR_INVALHANDLE** | The specified handle is invalid. |
| **MMSYSERR_INVALPARAM** | At least one parameter is invalid. |
| **MMSYSERR_NODRIVER** | A suitable driver is not available to provide valid filter selections. |

## See also

[Audio Compression Functions](https://learn.microsoft.com/windows/desktop/Multimedia/audio-compression-functions)

[Audio Compression Manager](https://learn.microsoft.com/windows/desktop/Multimedia/audio-compression-manager)

## Remarks

> [!NOTE]
> The msacm.h header defines ACMFILTERCHOOSE as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).