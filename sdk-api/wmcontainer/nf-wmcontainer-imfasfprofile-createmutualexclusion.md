# IMFASFProfile::CreateMutualExclusion

## Description

Creates a new Advanced Systems Format (ASF) mutual exclusion object. Mutual exclusion objects can be added to a profile by calling the [AddMutualExclusion](https://learn.microsoft.com/windows/desktop/api/wmcontainer/nf-wmcontainer-imfasfprofile-addmutualexclusion) method.

## Parameters

### `ppIMutex` [out]

Receives a pointer to the [IMFASFMutualExclusion](https://learn.microsoft.com/windows/desktop/api/wmcontainer/nn-wmcontainer-imfasfmutualexclusion) interface of the new object. The caller must release the interface.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

The ASF mutual exclusion object created by this method is not associated with the profile. Call [IMFASFProfile::AddMutualExclusion](https://learn.microsoft.com/windows/desktop/api/wmcontainer/nf-wmcontainer-imfasfprofile-addmutualexclusion) after configuring the object to make this association.

## See also

[ASF Profile](https://learn.microsoft.com/windows/desktop/medfound/asf-profile)

[IMFASFMutualExclusion](https://learn.microsoft.com/windows/desktop/api/wmcontainer/nn-wmcontainer-imfasfmutualexclusion)

[IMFASFProfile](https://learn.microsoft.com/windows/desktop/api/wmcontainer/nn-wmcontainer-imfasfprofile)