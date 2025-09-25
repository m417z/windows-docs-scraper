# IMFASFMutualExclusion::Clone

## Description

Creates a copy of the Advanced Systems Format mutual exclusion object.

## Parameters

### `ppIMutex` [out]

Receives a pointer to the [IMFASFMutualExclusion](https://learn.microsoft.com/windows/desktop/api/wmcontainer/nn-wmcontainer-imfasfmutualexclusion) interface of the new object. The caller must release the interface.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

The cloned object is a new object, completely independent of the object from which it was cloned.

## See also

[IMFASFMutualExclusion](https://learn.microsoft.com/windows/desktop/api/wmcontainer/nn-wmcontainer-imfasfmutualexclusion)

[Using Mutual Exclusion for ASF Streams](https://learn.microsoft.com/windows/desktop/medfound/using-mutual-exclusion-for-asf-streams)