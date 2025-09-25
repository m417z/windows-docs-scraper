# IToc::GetDescription

## Description

The **GetDescription** method retrieves the description, set by a previous call to [SetDescription](https://learn.microsoft.com/windows/desktop/api/wmcodecdsp/nf-wmcodecdsp-itoc-setdescription), of the table of contents.

## Parameters

### `pwDescriptionSize` [in, out]

If *pwszDescription* is **NULL**, this is an output parameter that receives the size, in wide characters, of the buffer required to receive the description. If *pwszDescription* is not **NULL**, this is an input parameter that specifies the size, in wide characters, of the caller-allocated buffer pointed to by *pwszDescription*.

### `pwszDescription` [out]

**NULL**, or a pointer to a caller-allocated buffer that, on successful completion, receives the description. The description is null-terminated.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **MF_E_BUFFERTOOSMALL** | The method returns this error code if *pwszDescription* is not **NULL** and the description, including its NULL terminator, is larger than the size specified by *pwDescriptionSize*. In that case, *pwDescriptionSize* serves as an output parameter and receives the size of the required buffer. |

## See also

[IToc](https://learn.microsoft.com/windows/desktop/api/wmcodecdsp/nn-wmcodecdsp-itoc)