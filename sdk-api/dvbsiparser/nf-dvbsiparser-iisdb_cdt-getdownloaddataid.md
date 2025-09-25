# IISDB_CDT::GetDownloadDataId

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

Receives the download_data_id field value
for a logo transmission descriptor from an Integrated Services Digital Broadcasting (ISDB) common data table (CDT).
The download_data_id field identifies the data to be downloaded.

## Parameters

### `pwVal` [out]

Receives the download_data_id field value. This value is the same as the value of the table_id_extension field for the CDT containing the logo data.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IISDB_CDT](https://learn.microsoft.com/previous-versions/windows/desktop/api/dvbsiparser/nn-dvbsiparser-iisdb_cdt)