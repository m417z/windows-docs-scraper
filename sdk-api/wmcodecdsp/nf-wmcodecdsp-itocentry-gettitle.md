# ITocEntry::GetTitle

## Description

The **GetTitle** method retrieves the title, set by a previous call to [SetTitle](https://learn.microsoft.com/windows/desktop/api/wmcodecdsp/nf-wmcodecdsp-itocentry-settitle), of the entry.

## Parameters

### `pwTitleSize` [in, out]

If *pwszTitle* is **NULL**, this is an output parameter that receives the size, in wide characters, of the buffer required to receive the title. If *pwszTitle* is not **NULL**, this is an input parameter that specifies the size, in wide characters, of the caller-allocated buffer pointed to by *pwszTitle*.

### `pwszTitle` [out]

**NULL**, or a pointer to a caller-allocated buffer that, on successful completion, receives the title. The title is null-terminated.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **MF_E_BUFFERTOOSMALL** | The method returns this error code if *pwszTitle* is not **NULL** and the title, including its NULL terminator, is larger than the size specified by *pwTitleSize*. In that case, *pwTitleSize* serves as an output parameter and receives the size of the required buffer. |

## See also

[ITocEntry](https://learn.microsoft.com/windows/desktop/api/wmcodecdsp/nn-wmcodecdsp-itocentry)

[SetTitle](https://learn.microsoft.com/windows/desktop/api/wmcodecdsp/nf-wmcodecdsp-itocentry-settitle)