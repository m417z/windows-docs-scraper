# IMFASFSplitter::SelectStreams

## Description

Sets the streams to be parsed by the Advanced Systems Format (ASF) splitter.

## Parameters

### `pwStreamNumbers` [in]

An array of variables containing the list of stream numbers to select.

### `wNumStreams` [in]

The number of valid elements in the stream number array.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_INVALIDARG** | *pwStreamNumbers* is **NULL** and *wNumStreams* contains a value greater than zero. |
| **MF_E_INVALIDSTREAMNUMBER** | Invalid stream number was passed in the array. |

## Remarks

Calling this method supersedes any previous stream selections; only the streams specified in the *pwStreamNumbers* array will be selected.

By default, no streams are selected by the splitter.

You can obtain a list of the currently selected streams by calling the [IMFASFSplitter::GetSelectedStreams](https://learn.microsoft.com/windows/desktop/api/wmcontainer/nf-wmcontainer-imfasfsplitter-getselectedstreams) method.

## See also

[ASF Splitter](https://learn.microsoft.com/windows/desktop/medfound/asf-splitter)

[IMFASFSplitter](https://learn.microsoft.com/windows/desktop/api/wmcontainer/nn-wmcontainer-imfasfsplitter)