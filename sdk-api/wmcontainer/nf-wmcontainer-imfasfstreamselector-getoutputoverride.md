# IMFASFStreamSelector::GetOutputOverride

## Description

Retrieves the manual output override selection that is set for a stream.

## Parameters

### `dwOutputNum` [in]

Stream number for which to retrieve the output override selection.

### `pSelection` [out]

Receives the output override selection. The value is a member of the [ASF_SELECTION_STATUS](https://learn.microsoft.com/windows/desktop/api/wmcontainer/ne-wmcontainer-asf_selection_status) enumeration.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## See also

[IMFASFStreamSelector](https://learn.microsoft.com/windows/desktop/api/wmcontainer/nn-wmcontainer-imfasfstreamselector)