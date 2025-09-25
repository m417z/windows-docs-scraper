# IDVB_TOT::GetTableDescriptorByTag

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

This topic applies to Update Rollup 2 for Microsoft Windows XP Media Center Edition 2005 and later.

The **GetTableDescriptorByTag** method searches the TOT for a descriptor with the specified descriptor tag.

## Parameters

### `bTag` [in]

Specifies the descriptor tag for which to search.

### `pdwCookie` [in, out]

Pointer to a variable that specifies the start position in the descriptor list. This parameter is optional. If the value of *pdwCookie* is **NULL**, the search starts from the first descriptor in the list. Otherwise, the search starts from the position given in *pdwCookie*. When the method returns, the *pdwCookie* parameter contains the position of the next matching descriptor, if any. You can use this parameter to iterate through the descriptor list, looking for every instance of a particular descriptor tag.

### `ppDescriptor` [out]

Address of a variable that receives an [IGenericDescriptor](https://learn.microsoft.com/windows/desktop/api/mpeg2psiparser/nn-mpeg2psiparser-igenericdescriptor) interface pointer. Use this interface to retrieve the information in the descriptor. The caller must release the interface.

## Return value

The method returns an **HRESULT**. Possible values include those in the following table.

| Return code | Description |
| --- | --- |
| **MPEG2_E_OUT_OF_BOUNDS** | Index out of bounds. |
| **MPEG2_E_NOT_PRESENT** | The specified tag was not found. |
| **MPEG2_S_MORE_DATA_AVAILABLE** | The record contains at least one more descriptor with this tag. |
| **MPEG2_S_NO_MORE_DATA_AVAILABLE** | The record does not contain any more descriptors with this tag. |
| **S_OK** | The method succeeded. |

## Remarks

If the value of *pdwCookie* is not **NULL**, the method returns either MPEG2_S_NO_MORE_DATA_AVAILABLE or MPEG2_S_MORE_DATA_AVAILABLE to indicate whether the MGT contains additional tags that match the search criteria.

## See also

[IDVB_TOT Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/dvbsiparser/nn-dvbsiparser-idvb_tot)