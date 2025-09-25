# IMFASFStreamSelector::SetOutputMutexSelection

## Description

Selects a mutual exclusion record to use for a mutual exclusion object associated with an output.

## Parameters

### `dwOutputNum` [in]

The output number for which to set a stream.

### `dwMutexNum` [in]

Index of the mutual exclusion for which to select.

### `wSelectedRecord` [in]

Record of the specified mutual exclusion to select.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

An output is a stream in an Advanced Systems Format (ASF) data section that will be parsed. If mutual exclusion is used, mutually exclusive streams share the same output.

An ASF file can contain multiple mutually exclusive relationships, such as a file with both language based and bit-rate based mutual exclusion. If an output is involved in multiple mutually exclusive relationships, a record from each must be selected.

## See also

[IMFASFStreamSelector](https://learn.microsoft.com/windows/desktop/api/wmcontainer/nn-wmcontainer-imfasfstreamselector)

[IMFASFStreamSelector::GetOutputMutex](https://learn.microsoft.com/windows/desktop/api/wmcontainer/nf-wmcontainer-imfasfstreamselector-getoutputmutex)