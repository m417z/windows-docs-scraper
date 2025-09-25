# IPBDA_EIT::GetRecordEventId

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

Receives the unique identifier from an event record in an event information table (EIT) in a Protected Broadcast Device Architecture (PBDA) transport stream.

## Parameters

### `dwRecordIndex` [in]

Specifies the service record number, indexed from zero.
Call the [IPBDA_EIT::GetCountOfRecords](https://learn.microsoft.com/previous-versions/windows/desktop/api/dvbsiparser/nf-dvbsiparser-ipbda_eit-getcountofrecords) method to get the number of records in the EIT.

### `plwVal` [out]

Receives the event identifier.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IPBDA_EIT](https://learn.microsoft.com/previous-versions/windows/desktop/api/dvbsiparser/nn-dvbsiparser-ipbda_eit)