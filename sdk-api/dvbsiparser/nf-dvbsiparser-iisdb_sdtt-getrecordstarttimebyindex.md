# IISDB_SDTT::GetRecordStartTimeByIndex

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

Gets an event start time from a schedule record in
in an Integrated Services Digital Broadcasting
(ISDB) software download
trigger table
(SDTT).

## Parameters

### `dwRecordIndex` [in]

Specifies the record number,
indexed from zero. Call the [IISDB_SDTT::GetCountOfRecords](https://learn.microsoft.com/previous-versions/windows/desktop/api/dvbsiparser/nf-dvbsiparser-iisdb_sdtt-getcountofrecords) method to get the number of records in the SDTT.

### `dwIndex` [in]

Index to the schedules for the selected content.

### `pmdtVal` [out]

Receives the event start time.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IISDB_SDTT](https://learn.microsoft.com/previous-versions/windows/desktop/api/dvbsiparser/nn-dvbsiparser-iisdb_sdtt)

[IISDB_SDTT::GetCountOfRecords](https://learn.microsoft.com/previous-versions/windows/desktop/api/dvbsiparser/nf-dvbsiparser-iisdb_sdtt-getcountofrecords)