# IMFASFStreamSelector::GetOutputMutex

## Description

Retrieves a mutual exclusion object for an output.

## Parameters

### `dwOutputNum` [in]

Output number for which to retrieve a mutual exclusion object.

### `dwMutexNum` [in]

Mutual exclusion number. This is an index of mutually exclusive relationships associated with the output. Set to a number between 0, and 1 less than the number of mutual exclusion objects retrieved by calling [IMFASFStreamSelector::GetOutputMutexCount](https://learn.microsoft.com/windows/desktop/api/wmcontainer/nf-wmcontainer-imfasfstreamselector-getoutputmutexcount).

### `ppMutex` [out]

Receives a pointer to the mutual exclusion object's **IUnknown** interface. The caller must release the interface.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

Outputs are streams in the ASF data section that will be parsed.

## See also

[IMFASFStreamSelector](https://learn.microsoft.com/windows/desktop/api/wmcontainer/nn-wmcontainer-imfasfstreamselector)

[IMFASFStreamSelector::GetOutputMutexCount](https://learn.microsoft.com/windows/desktop/api/wmcontainer/nf-wmcontainer-imfasfstreamselector-getoutputmutexcount)

[IMFASFStreamSelector::SetOutputMutexSelection](https://learn.microsoft.com/windows/desktop/api/wmcontainer/nf-wmcontainer-imfasfstreamselector-setoutputmutexselection)