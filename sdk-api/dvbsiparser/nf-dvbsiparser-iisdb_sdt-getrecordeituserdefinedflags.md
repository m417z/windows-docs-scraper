# IISDB_SDT::GetRecordEITUserDefinedFlags

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

Returns the EIT_user_defined_flags field value from a service descriptor
in an Integrated Services Digital Broadcasting (ISDB)
service description table (SDT).

## Parameters

### `dwRecordIndex` [in]

Specifies the record number,
indexed from zero. Call the [IDVB_SDT::GetCountOfRecords](https://learn.microsoft.com/previous-versions/windows/desktop/api/dvbsiparser/nf-dvbsiparser-idvb_sdt-getcountofrecords) method to get the number of records in the SDT.

### `pbVal` [out]

Receives the EIT_user_defined_flags field value.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IDVB_SDT::GetCountOfRecords](https://learn.microsoft.com/previous-versions/windows/desktop/api/dvbsiparser/nf-dvbsiparser-idvb_sdt-getcountofrecords)

[IISDB_SDT](https://learn.microsoft.com/previous-versions/windows/desktop/api/dvbsiparser/nn-dvbsiparser-iisdb_sdt)