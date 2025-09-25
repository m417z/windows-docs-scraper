# ISCTE_EAS::GetTableDescriptorByTag

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

The **GetTableDescriptorByTag** method searches the EAS table for a descriptor with the specified descriptor tag.

## Parameters

### `bTag` [in]

The descriptor tag to search for.

### `pdwCookie` [in, out]

A pointer to a variable that specifies the start position in the descriptor list. This parameter can be **NULL**. If the value is **NULL**, the search starts from the first descriptor in the list. Otherwise, the search starts from the position given in **pdwCookie*. When the method returns, the *pdwCookie* parameter contains the position of the next matching descriptor, if any. You can use this parameter to iterate through the descriptor list, looking for every instance of a particular descriptor tag.

### `ppDescriptor` [out]

Receives a pointer to the [IGenericDescriptor](https://learn.microsoft.com/windows/desktop/api/mpeg2psiparser/nn-mpeg2psiparser-igenericdescriptor) interface. Use this interface to retrieve the information in the descriptor. The caller must release the interface.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **MPEG2_E_NOT_PRESENT** | The specified tag was not found. |
| **MPEG2_E_OUT_OF_BOUNDS** | Index out of bounds. |
| **MPEG2_E_UNINITIALIZED** | The [ISCTE_EAS::Initialize](https://learn.microsoft.com/previous-versions/windows/desktop/api/atscpsipparser/nf-atscpsipparser-iscte_eas-initialize) method was not called. |
| **MPEG2_S_MORE_DATA_AVAILABLE** | The record contains at least one more descriptor with this tag. |
| **MPEG2_S_NO_MORE_DATA_AVAILABLE** | The record does not contain any more descriptors with this tag. |
| **S_OK** | The method succeeded. |

## See also

[ISCTE_EAS Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/atscpsipparser/nn-atscpsipparser-iscte_eas)