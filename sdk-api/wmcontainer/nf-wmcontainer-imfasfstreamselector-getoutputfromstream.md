# IMFASFStreamSelector::GetOutputFromStream

## Description

Retrieves the output number associated with a stream.

## Parameters

### `wStreamNum` [in]

The stream number for which to retrieve an output number.

### `pdwOutput` [out]

Receives the output number.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **MF_E_INVALIDREQUEST** | Invalid stream number. |

## Remarks

Outputs are streams in the ASF data section that will be parsed.

## See also

[IMFASFStreamSelector](https://learn.microsoft.com/windows/desktop/api/wmcontainer/nn-wmcontainer-imfasfstreamselector)