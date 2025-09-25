# IMFASFSplitter::GetFlags

## Description

Retrieves the option flags that are set on the ASF splitter.

## Parameters

### `pdwFlags` [out]

Receives the option flags. This value is a bitwise **OR** of zero or more members of the [MFASF_SPLITTERFLAGS](https://learn.microsoft.com/windows/desktop/api/wmcontainer/ne-wmcontainer-mfasf_splitterflags) enumeration.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_INVALIDARG** | *pdwFlags* is **NULL**. |

## See also

[IMFASFSplitter](https://learn.microsoft.com/windows/desktop/api/wmcontainer/nn-wmcontainer-imfasfsplitter)

[IMFASFSplitter::SetFlags](https://learn.microsoft.com/windows/desktop/api/wmcontainer/nf-wmcontainer-imfasfsplitter-setflags)