# IToc::GetContext

## Description

The **GetContext** method retrieves a block of bytes that was previously associated with the table of contents by a call to [SetContext](https://learn.microsoft.com/windows/desktop/api/wmcodecdsp/nf-wmcodecdsp-itoc-setcontext).

## Parameters

### `pdwContextSize` [in, out]

If *pbtContext* is **NULL**, this is an output parameter that receives the size, in bytes, of the context block. If *pbtContext* is not **NULL**, this is an input parameter that specifies the size, in bytes, of the caller-allocated buffer pointed to by *pbtContext*.

### `pbtContext` [out]

NULL, or a pointer to a caller-allocated buffer that, on successful completion, receives the context block.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **MF_E_BUFFERTOOSMALL** | The method returns this error code if *pbtContext* is not **NULL** and the context block is larger than the size specified by *bdwContextSize*. In that case, *pdwContextSize* serves as an output parameter and receives the size, in bytes, of the required buffer. |

## See also

[IToc](https://learn.microsoft.com/windows/desktop/api/wmcodecdsp/nn-wmcodecdsp-itoc)