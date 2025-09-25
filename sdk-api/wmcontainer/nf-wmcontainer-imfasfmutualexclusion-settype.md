# IMFASFMutualExclusion::SetType

## Description

Sets the type of mutual exclusion that is represented by the Advanced Systems Format (ASF) mutual exclusion object.

## Parameters

### `guidType` [in]

The type of mutual exclusion that is represented by the ASF mutual exclusion object. For a list of predefined mutual exclusion type constants, see [ASF Mutual Exclusion Type GUIDs](https://learn.microsoft.com/windows/desktop/medfound/asf-mutual-exclusion-type-guids).

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

Sometimes, content must be made mutually exclusive in more than one way. For example, a video file might contain audio streams in several bit rates for each of several languages. To handle this type of complex mutual exclusion, you must configure more than one ASF mutual exclusion object. For more information, see [IMFASFMutualExclusion::AddRecord](https://learn.microsoft.com/windows/desktop/api/wmcontainer/nf-wmcontainer-imfasfmutualexclusion-addrecord).

## See also

[IMFASFMutualExclusion](https://learn.microsoft.com/windows/desktop/api/wmcontainer/nn-wmcontainer-imfasfmutualexclusion)

[IMFASFMutualExclusion::GetType](https://learn.microsoft.com/windows/desktop/api/wmcontainer/nf-wmcontainer-imfasfmutualexclusion-gettype)

[Using Mutual Exclusion for ASF Streams](https://learn.microsoft.com/windows/desktop/medfound/using-mutual-exclusion-for-asf-streams)