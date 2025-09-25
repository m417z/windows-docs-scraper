# IIsdbLogoTransmissionDescriptor::GetDownloadDataId

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

Gets the value of the download_data_id field from an Integrated Services Digital Broadcasting (ISDB) logo transmission descriptor. This field identifies the downloaded data and has the same value as the table_id_extensions field in the common data table that contains the logo data.

## Parameters

### `pwVal` [out]

Receives the download data identifier.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IIsdbLogoTransmissionDescriptor](https://learn.microsoft.com/previous-versions/windows/desktop/api/dvbsiparser/nn-dvbsiparser-iisdblogotransmissiondescriptor)