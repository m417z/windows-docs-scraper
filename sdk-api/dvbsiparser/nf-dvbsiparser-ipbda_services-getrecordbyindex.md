# IPBDA_Services::GetRecordByIndex

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

Gets a service record at a given position from a Program and System Information Protocol (PSIP) table in a Protected Broadcast Device Architecture (PBDA) transport stream.

## Parameters

### `dwRecordIndex` [in]

Specifies the service record number, indexed from zero.
Call the [IPBDA_Services::GetCountOfRecords](https://learn.microsoft.com/previous-versions/windows/desktop/api/dvbsiparser/nf-dvbsiparser-ipbda_services-getcountofrecords) method to get the number of records in the PSIP table.

### `pul64ServiceIdx` [out]

Receives the service record at the position given by *dwRecordIndex*.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IPBDA_Services](https://learn.microsoft.com/previous-versions/windows/desktop/api/dvbsiparser/nn-dvbsiparser-ipbda_services)

[IPBDA_Services::GetCountOfRecords](https://learn.microsoft.com/previous-versions/windows/desktop/api/dvbsiparser/nf-dvbsiparser-ipbda_services-getcountofrecords)