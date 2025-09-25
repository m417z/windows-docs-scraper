# IIsdbSiParser2::GetEMM

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

Gets the entitlement management message (EMM) table from an Integrated Services Digital Broadcast (ISDB) transport stream. An EMM contains conditional access data, such as contract
information for subscribers, keys to decrypt common information, and the
authorization levels or services of specific decoders.

## Parameters

### `pid` [in]

Specifies the packet identifier (PID) of the transport stream packet that transmits the EMM.

### `wTableIdExt` [in]

Value of the table_id field for the EMM. This field value identifies a subtable in the EMM.

### `ppEMM` [out]

Receives a pointer to the [IISDB_EMM](https://learn.microsoft.com/previous-versions/windows/desktop/api/dvbsiparser/nn-dvbsiparser-iisdb_emm) interface. Use this interface to retrieve the information in the table.
The caller must release the interface.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IISDB_EMM](https://learn.microsoft.com/previous-versions/windows/desktop/api/dvbsiparser/nn-dvbsiparser-iisdb_emm)

[IIsdbSiParser2](https://learn.microsoft.com/previous-versions/windows/desktop/api/dvbsiparser/nn-dvbsiparser-iisdbsiparser2)