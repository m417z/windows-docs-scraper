# ICAT::GetTableDescriptorByIndex

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

This topic applies to Update Rollup 2 for Microsoft Windows XP Media Center Edition 2005 and later.

The **GetTableDescriptorByIndex** method retrieves a table descriptor for the CAT.

## Parameters

### `dwIndex` [in]

Specifies which descriptor to retrieve, indexed from zero. Call the [ICAT::GetCountOfTableDescriptors](https://learn.microsoft.com/windows/desktop/api/mpeg2psiparser/nf-mpeg2psiparser-icat-getcountoftabledescriptors) method to get the number of table descriptors in the CAT.

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

[ICAT Interface](https://learn.microsoft.com/windows/desktop/api/mpeg2psiparser/nn-mpeg2psiparser-icat)