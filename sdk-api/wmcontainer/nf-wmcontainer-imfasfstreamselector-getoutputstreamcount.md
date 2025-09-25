# IMFASFStreamSelector::GetOutputStreamCount

## Description

Retrieves the number of streams associated with an output.

## Parameters

### `dwOutputNum` [in]

The output number for which to retrieve the stream count.

### `pcStreams` [out]

Receives the number of streams associated with the output.

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