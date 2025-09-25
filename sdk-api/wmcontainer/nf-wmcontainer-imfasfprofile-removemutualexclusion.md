# IMFASFProfile::RemoveMutualExclusion

## Description

Removes an Advanced Systems Format (ASF) mutual exclusion object from the profile.

## Parameters

### `dwMutexIndex` [in]

The index of the mutual exclusion object to remove from the profile.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

When a mutual exclusion object is removed from the profile, the ASF profile object reassigns the mutual exclusion indexes so that they are sequential starting with zero. Any previously stored indexes are no longer valid after calling this method.

## See also

[ASF Profile](https://learn.microsoft.com/windows/desktop/medfound/asf-profile)

[IMFASFProfile](https://learn.microsoft.com/windows/desktop/api/wmcontainer/nn-wmcontainer-imfasfprofile)

[IMFASFProfile::AddMutualExclusion](https://learn.microsoft.com/windows/desktop/api/wmcontainer/nf-wmcontainer-imfasfprofile-addmutualexclusion)

[IMFASFProfile::GetMutualExclusion](https://learn.microsoft.com/windows/desktop/api/wmcontainer/nf-wmcontainer-imfasfprofile-getmutualexclusion)