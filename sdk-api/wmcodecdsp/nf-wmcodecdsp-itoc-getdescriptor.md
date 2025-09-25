# IToc::GetDescriptor

## Description

The **GetDescriptor** method retrieves the descriptor, previously set by [SetDescriptor](https://learn.microsoft.com/windows/desktop/api/wmcodecdsp/nf-wmcodecdsp-itoc-setdescriptor), of the table of contents.

## Parameters

### `pDescriptor` [out]

Pointer to a [TOC_DESCRIPTOR](https://learn.microsoft.com/windows/desktop/api/wmcodecdsp/ns-wmcodecdsp-toc_descriptor) structure that receives the descriptor.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## See also

[IToc](https://learn.microsoft.com/windows/desktop/api/wmcodecdsp/nn-wmcodecdsp-itoc)