# acmFormatDetails function

## Description

The **acmFormatDetails** function queries the ACM for format details for a specific waveform-audio format tag.

## Parameters

### `had`

Handle to the ACM driver to query for waveform-audio format details for a format tag. If this parameter is **NULL**, the ACM uses the details from the first suitable ACM driver.

### `pafd`

Pointer to an [ACMFORMATDETAILS]() structure to contain the format details for the given format tag.

### `fdwDetails`

Flags for getting the waveform-audio format tag details. The following values are defined.

| Value | Meaning |
| --- | --- |
| ACM_FORMATDETAILSF_FORMAT |[ACMFORMATDETAILS]() structure was given and the remaining details should be returned. The **dwFormatTag** member of the **ACMFORMATDETAILS** structure must be initialized to the same format tag as **pwfx** specifies. This query type can be used to get a string description of an arbitrary format structure. If an application specifies an ACM driver handle for *had*, details on the format will be returned for that driver. If an application specifies **NULL** for *had*, the ACM finds the first acceptable driver to return the details.
| ACM_FORMATDETAILSF_INDEX | A format index for the format tag was given in the **dwFormatIndex** member of the **ACMFORMATDETAILS** structure. The format details will be returned in the structure defined by *pafd*. The index ranges from zero to one less than the **cStandardFormats** member returned in the **ACMFORMATTAGDETAILS** structure for a format tag. An application must specify a driver handle for *had* when retrieving format details with this flag. For information about which members should be initialized before calling this function, see the **ACMFORMATDETAILS** structure. |

## Return value

Returns zero if successful or an error otherwise. Possible error values include the following.

| Return code | Description |
| --- | --- |
| **ACMERR_NOTPOSSIBLE** | The details requested are not available. |
| **MMSYSERR_INVALFLAG** | At least one flag is invalid. |
| **MMSYSERR_INVALHANDLE** | The specified handle is invalid. |
| **MMSYSERR_INVALPARAM** | At least one parameter is invalid. |

## See also

[Audio Compression Functions](https://learn.microsoft.com/windows/desktop/Multimedia/audio-compression-functions)

[Audio Compression Manager](https://learn.microsoft.com/windows/desktop/Multimedia/audio-compression-manager)