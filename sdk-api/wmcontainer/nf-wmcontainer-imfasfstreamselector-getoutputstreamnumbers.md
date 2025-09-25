# IMFASFStreamSelector::GetOutputStreamNumbers

## Description

Retrieves the stream numbers for all of the streams that are associated with an output.

## Parameters

### `dwOutputNum` [in]

The output number for which to retrieve stream numbers.

### `rgwStreamNumbers` [out]

Address of an array that receives the stream numbers associated with the output. The caller allocates the array. The array size must be at least as large as the value returned by the [IMFASFStreamSelector::GetOutputStreamCount](https://learn.microsoft.com/windows/desktop/api/wmcontainer/nf-wmcontainer-imfasfstreamselector-getoutputstreamcount) method.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **MF_E_INVALIDREQUEST** | Invalid output number. |

## Remarks

An output is a stream in an ASF data section that will be parsed. If mutual exclusion is used, mutually exclusive streams share the same output.

## See also

[IMFASFStreamSelector](https://learn.microsoft.com/windows/desktop/api/wmcontainer/nn-wmcontainer-imfasfstreamselector)