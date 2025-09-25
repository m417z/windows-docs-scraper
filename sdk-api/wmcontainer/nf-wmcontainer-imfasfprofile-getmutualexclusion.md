# IMFASFProfile::GetMutualExclusion

## Description

Retrieves an Advanced Systems Format (ASF) mutual exclusion object from the profile.

## Parameters

### `dwMutexIndex` [in]

Index of the mutual exclusion object in the profile.

### `ppIMutex` [out]

Receives a pointer to the [IMFASFMutualExclusion](https://learn.microsoft.com/windows/desktop/api/wmcontainer/nn-wmcontainer-imfasfmutualexclusion) interface of the ASF mutual exclusion object. The caller must release the interface.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

This method does not create a copy of the mutual exclusion object. The returned pointer refers to the mutual exclusion contained in the profile object. You must not make any changes to the mutual exclusion object using this pointer, because doing so can affect the profile object in unexpected ways.

To change the configuration of the mutual exclusion object in the profile, you must first clone the mutual exclusion object by calling [IMFASFMutualExclusion::Clone](https://learn.microsoft.com/windows/desktop/api/wmcontainer/nf-wmcontainer-imfasfmutualexclusion-clone). Make whatever changes are required to the clone of the object, remove the old mutual exclusion object from the profile by calling the [IMFASFProfile::RemoveMutualExclusion](https://learn.microsoft.com/windows/desktop/api/wmcontainer/nf-wmcontainer-imfasfprofile-removemutualexclusion) method, and then add the updated object by calling the [IMFASFProfile::AddMutualExclusion](https://learn.microsoft.com/windows/desktop/api/wmcontainer/nf-wmcontainer-imfasfprofile-addmutualexclusion) method.

## See also

[ASF Profile](https://learn.microsoft.com/windows/desktop/medfound/asf-profile)

[IMFASFMutualExclusion](https://learn.microsoft.com/windows/desktop/api/wmcontainer/nn-wmcontainer-imfasfmutualexclusion)

[IMFASFProfile](https://learn.microsoft.com/windows/desktop/api/wmcontainer/nn-wmcontainer-imfasfprofile)

[IMFASFProfile::AddMutualExclusion](https://learn.microsoft.com/windows/desktop/api/wmcontainer/nf-wmcontainer-imfasfprofile-addmutualexclusion)

[IMFASFProfile::GetMutualExclusionCount](https://learn.microsoft.com/windows/desktop/api/wmcontainer/nf-wmcontainer-imfasfprofile-getmutualexclusioncount)

[IMFASFProfile::RemoveMutualExclusion](https://learn.microsoft.com/windows/desktop/api/wmcontainer/nf-wmcontainer-imfasfprofile-removemutualexclusion)