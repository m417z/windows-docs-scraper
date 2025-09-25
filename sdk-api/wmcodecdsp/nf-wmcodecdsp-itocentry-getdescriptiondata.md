# ITocEntry::GetDescriptionData

## Description

The **GetDescriptionData** method gets a description data block that was previously associated with the entry by a call to [SetDescriptionData](https://learn.microsoft.com/windows/desktop/api/wmcodecdsp/nf-wmcodecdsp-itocentry-setdescriptiondata).

## Parameters

### `pdwDescriptionDataSize` [in, out]

If *pbtDescriptionData* is **NULL**, this is an output parameter that receives the size, in bytes, of the description data block. If *pbtDescriptionData* is not **NULL**, this is an input parameter that specifies the size, in bytes, of the caller-allocated buffer pointed to by *pbtDescriptionData*.

### `pbtDescriptionData` [out]

NULL, or a pointer to a caller-allocated buffer that, on successful completion, receives the description data block.

### `pGuidType` [out]

Pointer to a variable that receives a globally unique identifier (GUID) that identifies the type of data in the description data block. See Remarks.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **MF_E_BUFFERTOOSMALL** | The method returns this error code if *pbtDescriptionData* is not **NULL** and the context block is larger than the size specified by *pdwDescriptionDataSize*. In that case, *pdwDescriptionDataSize* serves as an output parameter and receives the size, in bytes, of the required buffer. |

## Remarks

You can associate only one description data block with a given entry at a given time. However, you might want to design different types of description data blocks and identify each type of block with a globally unique identifier (GUID). That way, when you call [SetDescriptionData](https://learn.microsoft.com/windows/desktop/api/wmcodecdsp/nf-wmcodecdsp-itocentry-setdescriptiondata), you can mark the data block as being of a specific type. When you call **GetDescriptionData**, you can determine the type of the data block retrieved by inspecting the value returned in *pGuidType*.

## See also

[ITocEntry](https://learn.microsoft.com/windows/desktop/api/wmcodecdsp/nn-wmcodecdsp-itocentry)

[SetDescriptionData](https://learn.microsoft.com/windows/desktop/api/wmcodecdsp/nf-wmcodecdsp-itocentry-setdescriptiondata)