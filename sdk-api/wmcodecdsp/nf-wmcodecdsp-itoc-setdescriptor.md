# IToc::SetDescriptor

## Description

The **SetDescriptor** method associates a descriptor with the table of contents.

## Parameters

### `pDescriptor` [in]

Pointer to a [TOC_DESCRIPTOR](https://learn.microsoft.com/windows/desktop/api/wmcodecdsp/ns-wmcodecdsp-toc_descriptor) structure that contains the descriptor.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## See also

[GetDescriptor](https://learn.microsoft.com/windows/desktop/api/wmcodecdsp/nf-wmcodecdsp-itoc-getdescriptor)

[IToc](https://learn.microsoft.com/windows/desktop/api/wmcodecdsp/nn-wmcodecdsp-itoc)