# acmFilterDetails function

## Description

The **acmFilterDetails** function queries the ACM for details about a filter with a specific waveform-audio filter tag.

## Parameters

### `had`

Handle to the ACM driver to query for waveform-audio filter details for a filter tag. If this parameter is **NULL**, the ACM uses the details from the first suitable ACM driver.

### `pafd`

Pointer to the [ACMFILTERDETAILS]() structure that is to receive the filter details for the given filter tag.

### `fdwDetails`

Flags for getting the details. The following values are defined.

| Value | Meaning |
| --- | --- |
| ACM_FILTERDETAILSF_FILTER |[ACMFILTERDETAILS]() structure was given and the remaining details should be returned. The **dwFilterTag** member of the **ACMFILTERDETAILS** structure must be initialized to the same filter tag **pwfltr** specifies. This query type can be used to get a string description of an arbitrary filter structure. If an application specifies an ACM driver handle for *had*, details on the filter will be returned for that driver. If an application specifies **NULL** for *had*, the ACM finds the first acceptable driver to return the details.
| ACM_FILTERDETAILSF_INDEX | A filter index for the filter tag was given in the **dwFilterIndex** member of the **ACMFILTERDETAILS** structure. The filter details will be returned in the structure defined by *pafd*. The index ranges from zero to one less than the **cStandardFilters** member returned in the **ACMFILTERTAGDETAILS** structure for a filter tag. An application must specify a driver handle for *had* when retrieving filter details with this flag. For information about what members should be initialized before calling this function, see the **ACMFILTERDETAILS** structure. |

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