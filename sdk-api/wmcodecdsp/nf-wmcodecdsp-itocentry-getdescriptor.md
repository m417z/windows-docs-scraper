# ITocEntry::GetDescriptor

## Description

The **GetDescriptor** method retrieves the descriptor, previously set by a call to [SetDescriptor](https://learn.microsoft.com/windows/desktop/api/wmcodecdsp/nf-wmcodecdsp-itocentry-setdescriptor), of the entry.

## Parameters

### `pDescriptor` [out]

Pointer to a [TOC_ENTRY_DESCRIPTOR](https://learn.microsoft.com/windows/desktop/api/wmcodecdsp/ns-wmcodecdsp-toc_entry_descriptor) structure that receives the descriptor.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## See also

[ITocEntry](https://learn.microsoft.com/windows/desktop/api/wmcodecdsp/nn-wmcodecdsp-itocentry)

[SetDescriptor](https://learn.microsoft.com/windows/desktop/api/wmcodecdsp/nf-wmcodecdsp-itocentry-setdescriptor)