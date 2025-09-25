# IISDB_LDT::GetRecordDescriptionId

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

Gets the record description ID from an Integrated services Digital Broadcasting System
(IDBS) linked description table (LDT). The description ID field identifies a collected description in the LDT.

## Parameters

### `dwRecordIndex` [in]

Specifies the record number, indexed from zero.
Call the [IISDB_LDT::GetCountOfRecords](https://learn.microsoft.com/previous-versions/windows/desktop/api/dvbsiparser/nf-dvbsiparser-iisdb_ldt-getcountofrecords) method to get the number of records in the LDT.

### `pwVal` [out]

Receives the description_id field.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IISDB_LDT](https://learn.microsoft.com/previous-versions/windows/desktop/api/dvbsiparser/nn-dvbsiparser-iisdb_ldt)

[IISDB_LDT::GetCountOfRecords](https://learn.microsoft.com/previous-versions/windows/desktop/api/dvbsiparser/nf-dvbsiparser-iisdb_ldt-getcountofrecords)