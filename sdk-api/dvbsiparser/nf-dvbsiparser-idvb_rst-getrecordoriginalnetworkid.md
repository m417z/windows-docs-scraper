# IDVB_RST::GetRecordOriginalNetworkId

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

This topic applies to Update Rollup 2 for Microsoft Windows XP Media Center Edition 2005 and later.

The **GetRecordOriginalNetworkId** method returns the original network identifier for a record in the RST.

## Parameters

### `dwRecordIndex` [in]

Specifies the record number, indexed from zero. Call the [IDVB_RST::GetCountOfRecords](https://learn.microsoft.com/previous-versions/windows/desktop/api/dvbsiparser/nf-dvbsiparser-idvb_rst-getcountofrecords) method to get the number of records in the RST.

### `pwVal` [out]

Pointer to a variable that receives the original_network_id field. This value identifies the network_id of the originating delivery system.

## Return value

The method returns an **HRESULT**. Possible values include those in the following table.

| Return code | Description |
| --- | --- |
| **E_POINTER** | NULL pointer argument. |
| **MPEG2_E_OUT_OF_BOUNDS** | Index out of bounds. |
| **S_OK** | The method succeeded. |

## See also

[IDVB_RST Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/dvbsiparser/nn-dvbsiparser-idvb_rst)