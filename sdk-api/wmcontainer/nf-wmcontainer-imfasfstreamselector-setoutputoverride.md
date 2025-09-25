# IMFASFStreamSelector::SetOutputOverride

## Description

Sets the selection status of an output, overriding other selection criteria.

## Parameters

### `dwOutputNum` [in]

Output number for which to set selection.

### `Selection` [in]

Member of the [ASF_SELECTION_STATUS](https://learn.microsoft.com/windows/desktop/api/wmcontainer/ne-wmcontainer-asf_selection_status) enumeration specifying the level of selection for the output.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## See also

[IMFASFStreamSelector](https://learn.microsoft.com/windows/desktop/api/wmcontainer/nn-wmcontainer-imfasfstreamselector)