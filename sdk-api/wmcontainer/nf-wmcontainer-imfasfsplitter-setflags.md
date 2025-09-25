# IMFASFSplitter::SetFlags

## Description

Sets option flags on the Advanced Systems Format (ASF) splitter.

## Parameters

### `dwFlags` [in]

A bitwise combination of zero or more members of the [MFASF_SPLITTERFLAGS](https://learn.microsoft.com/windows/desktop/api/wmcontainer/ne-wmcontainer-mfasf_splitterflags) enumeration.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **MF_E_NOT_INITIALIZED** | The splitter is not initialized. |
| **E_INVALIDARG** | The *dwFlags* parameter does not contain a valid flag. |
| **MF_E_INVALIDREQUEST** | The MFASF_SPLITTER_REVERSE flag is set, but the content cannot be parsed in reverse. |

## Remarks

This method can only be called after the splitter is initialized.

## See also

[ASF Splitter](https://learn.microsoft.com/windows/desktop/medfound/asf-splitter)

[IMFASFSplitter](https://learn.microsoft.com/windows/desktop/api/wmcontainer/nn-wmcontainer-imfasfsplitter)

[IMFASFSplitter::GetFlags](https://learn.microsoft.com/windows/desktop/api/wmcontainer/nf-wmcontainer-imfasfsplitter-getflags)