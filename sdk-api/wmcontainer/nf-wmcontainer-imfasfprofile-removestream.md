# IMFASFProfile::RemoveStream

## Description

Removes a stream from the Advanced Systems Format (ASF) profile object.

## Parameters

### `wStreamNumber` [in]

Stream number of the stream to remove.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

After a stream is removed, the ASF profile object reassigns stream indexes so that the index values are sequential starting from zero. Any previously stored stream index numbers are no longer valid after deleting a stream.

## See also

[ASF Profile](https://learn.microsoft.com/windows/desktop/medfound/asf-profile)

[IMFASFProfile](https://learn.microsoft.com/windows/desktop/api/wmcontainer/nn-wmcontainer-imfasfprofile)

[IMFASFProfile::GetStream](https://learn.microsoft.com/windows/desktop/api/wmcontainer/nf-wmcontainer-imfasfprofile-getstream)

[IMFASFProfile::SetStream](https://learn.microsoft.com/windows/desktop/api/wmcontainer/nf-wmcontainer-imfasfprofile-setstream)