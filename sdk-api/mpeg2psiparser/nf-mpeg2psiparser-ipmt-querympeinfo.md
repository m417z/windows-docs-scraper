# IPMT::QueryMPEInfo

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

The **QueryMPEInfo** method returns the multi-protocol encapsulation (MPE) information in the PMT, if any.

## Parameters

### `ppMPEList` [out]

Address of a variable that receives a pointer to an array of [MPE_ELEMENT](https://learn.microsoft.com/previous-versions/windows/desktop/api/mpeg2structs/ns-mpeg2structs-mpe_element) structures. The client must free the array by calling the **CoTaskMemFree** function.

### `puiCount` [out]

Receives the number of elements returned in *ppMPEList*.

## Return value

The method returns an **HRESULT**. Possible values include those in the following table.

| Return code | Description |
| --- | --- |
| **E_OUTOFMEMORY** | Insufficient memory. |
| **E_POINTER** | NULL pointer argument. |
| **MPEG2_E_MALFORMED_TABLE** | Malformed table. |
| **MPEG2_S_MPE_INFO_FOUND** | MPE information was found in the PMT. |
| **MPEG2_S_MPE_INFO_NOT_FOUND** | MPE information was not found in the PMT. |

## Remarks

If the method succeeds, it returns one of the two success codes listed in the previous table. It returns MPEG2_S_MPE_INFO_FOUND if the PMT contains MPE information, or MPEG2_S_MPE_INFO_NOT_FOUND if the PMT does not contain any MPE information.

## See also

[IPMT Interface](https://learn.microsoft.com/windows/desktop/api/mpeg2psiparser/nn-mpeg2psiparser-ipmt)