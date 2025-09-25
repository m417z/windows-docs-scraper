# IMFASFSplitter::Flush

## Description

Resets the Advanced Systems Format (ASF) splitter and releases all pending samples.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

Any samples waiting to be retrieved when **Flush** is called are lost.

## See also

[IMFASFSplitter](https://learn.microsoft.com/windows/desktop/api/wmcontainer/nn-wmcontainer-imfasfsplitter)