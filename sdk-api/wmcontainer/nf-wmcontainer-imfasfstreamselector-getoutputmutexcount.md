# IMFASFStreamSelector::GetOutputMutexCount

## Description

Retrieves the number of mutual exclusion objects associated with an output.

## Parameters

### `dwOutputNum` [in]

Output number for which to retrieve the count of mutually exclusive relationships.

### `pcMutexes` [out]

Receives the number of mutual exclusions.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## See also

[IMFASFStreamSelector](https://learn.microsoft.com/windows/desktop/api/wmcontainer/nn-wmcontainer-imfasfstreamselector)

[IMFASFStreamSelector::GetOutputMutex](https://learn.microsoft.com/windows/desktop/api/wmcontainer/nf-wmcontainer-imfasfstreamselector-getoutputmutex)