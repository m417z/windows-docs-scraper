# IATSC_MGT::GetTableDescriptorByIndex

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

This topic applies to Update Rollup 2 for Microsoft Windows XP Media Center Edition 2005 and later.

The **GetTableDescriptorByIndex** method returns a table-wide descriptor for the MGT.

## Parameters

### `dwIndex` [in]

Specifies which descriptor to retrieve, indexed from zero. Call the [IATSC_MGT::GetCountOfTableDescriptors](https://learn.microsoft.com/previous-versions/windows/desktop/api/atscpsipparser/nf-atscpsipparser-iatsc_mgt-getcountoftabledescriptors) method to get the number of table descriptors in the MGT.

### `ppDescriptor` [out]

Receives a pointer to the [IGenericDescriptor](https://learn.microsoft.com/windows/desktop/api/mpeg2psiparser/nn-mpeg2psiparser-igenericdescriptor) interface. Use this interface to retrieve the information in the descriptor. The caller must release the interface.

## Return value

The method returns an **HRESULT**. Possible values include those in the following table.

| Return code | Description |
| --- | --- |
| **E_POINTER** | NULL pointer argument. |
| **MPEG2_E_OUT_OF_BOUNDS** | Index out of bounds. |
| **S_OK** | The method succeeded. |

## See also

[IATSC_MGT Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/atscpsipparser/nn-atscpsipparser-iatsc_mgt)