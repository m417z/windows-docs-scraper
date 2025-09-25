# IMFASFProfile::GetMutualExclusionCount

## Description

Retrieves the number of Advanced Systems Format (ASF) mutual exclusion objects that are associated with the profile.

## Parameters

### `pcMutexs` [out]

Receives the number of mutual exclusion objects.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

Multiple mutual exclusion objects may be required for streams that are mutually exclusive in more than one way. For more information, see [IMFASFMutualExclusion::AddRecord](https://learn.microsoft.com/windows/desktop/api/wmcontainer/nf-wmcontainer-imfasfmutualexclusion-addrecord).

## See also

[ASF Profile](https://learn.microsoft.com/windows/desktop/medfound/asf-profile)

[IMFASFProfile](https://learn.microsoft.com/windows/desktop/api/wmcontainer/nn-wmcontainer-imfasfprofile)

[IMFASFProfile::GetMutualExclusion](https://learn.microsoft.com/windows/desktop/api/wmcontainer/nf-wmcontainer-imfasfprofile-getmutualexclusion)