# IDVB_BAT::GetRecordDescriptorByIndex

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

This topic applies to Update Rollup 2 for Microsoft Windows XP Media Center Edition 2005 and later.

The **GetRecordDescriptorByIndex** method retrieves a descriptor for a specified record in the BAT.

## Parameters

### `dwRecordIndex` [in]

Specifies the record number, indexed from zero. Call the [IDVB_BAT::GetCountOfRecords](https://learn.microsoft.com/previous-versions/windows/desktop/api/dvbsiparser/nf-dvbsiparser-idvb_bat-getcountofrecords) method to get the number of records in the BAT.

### `dwIndex` [in]

Specifies which descriptor to retrieve, indexed from zero. Call the [IDVB_BAT::GetRecordCountOfDescriptors](https://learn.microsoft.com/previous-versions/windows/desktop/api/dvbsiparser/nf-dvbsiparser-idvb_bat-getrecordcountofdescriptors) method to get the number of descriptors for a particular record.

### `ppDescriptor` [out]

Address of a variable that receives an [IGenericDescriptor](https://learn.microsoft.com/windows/desktop/api/mpeg2psiparser/nn-mpeg2psiparser-igenericdescriptor) interface pointer. Use this interface to retrieve the information in the descriptor. The caller must release the interface.

## Return value

The method returns an **HRESULT**. Possible values include those in the following table.

| Return code | Description |
| --- | --- |
| **E_POINTER** | NULL pointer argument. |
| **MPEG2_E_OUT_OF_BOUNDS** | Index out of bounds. |
| **S_OK** | The method succeeded. |

## See also

[IDVB_BAT Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/dvbsiparser/nn-dvbsiparser-idvb_bat)