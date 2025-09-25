# IMFASFStreamSelector::GetOutputCount

## Description

Retrieves the number of outputs for the Advanced Systems Format (ASF) content.

## Parameters

### `pcOutputs` [out]

Receives the number of outputs.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

Outputs are streams in the ASF data section that will be parsed.

## See also

[IMFASFStreamSelector](https://learn.microsoft.com/windows/desktop/api/wmcontainer/nn-wmcontainer-imfasfstreamselector)