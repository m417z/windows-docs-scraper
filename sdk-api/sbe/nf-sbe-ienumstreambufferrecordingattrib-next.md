# IEnumStreamBufferRecordingAttrib::Next

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

The **Next** method returns a specified number of attributes in the enumeration sequence.

## Parameters

### `cRequest` [in]

The number of attributes to retrieve.

### `pStreamBufferAttribute` [in, out]

Pointer to an array of size *cRequest*. The array is filled with [STREAMBUFFER_ATTRIBUTE](https://learn.microsoft.com/previous-versions/windows/desktop/api/sbe/ns-sbe-streambuffer_attribute) structures.

### `pcReceived` [out]

Pointer to a variable that receives the number of attributes that are returned in the *pStreamBufferAttribute* array. This parameter can be **NULL** if *cRequest* is 1.

## Return value

Returns an **HRESULT** value. Possible values include the following.

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | Invalid argument. |
| **E_POINTER** | **NULL** pointer argument. |
| **S_FALSE** | Did not retrieve as many attributes as requested (reached the end of the enumeration). |
| **S_OK** | Success. |

## Remarks

The caller allocates the array of [STREAMBUFFER_ATTRIBUTE](https://learn.microsoft.com/previous-versions/windows/desktop/api/sbe/ns-sbe-streambuffer_attribute) structures, but the method allocates buffers for the attributes and the attribute names, which are contained in the **pszName** and **pbAttribute** members of each structure. The caller must release those buffers, by calling **CoTaskMemFree**.

## See also

[IEnumStreamBufferRecordingAttrib Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/sbe/nn-sbe-ienumstreambufferrecordingattrib)