# IToc::SetContext

## Description

The **SetContext** method associates a caller-supplied context block with the table of contents.

## Parameters

### `dwContextSize` [in]

The size, in bytes, of the context block.

### `pbtContext` [in]

Pointer to the first byte of the context block.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

You can use this method to associate any information with the table of contents. The type of information you store in the context block is completely up to you. TOC Parser does not inspect or interpret the context block.

## See also

[GetContext](https://learn.microsoft.com/windows/desktop/api/wmcodecdsp/nf-wmcodecdsp-itoc-getcontext)

[IToc](https://learn.microsoft.com/windows/desktop/api/wmcodecdsp/nn-wmcodecdsp-itoc)