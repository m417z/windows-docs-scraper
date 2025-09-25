# IISDB_EMM::GetIndividualEmmMessage

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

Gets an individual message from an Integrated Services
Digital Broadcasting (ISDB) entitlement management message (EMM) table.

## Parameters

### `pUnknown` [in]

Pointer to the **IUnknown** interface for the object that contains the EMM table.

### `pwLength` [out]

Receives the length of the buffer required to hold the message.

### `ppbMessage` [out]

Pointer to a memory block allocated to receive the message object.
The caller is responsible for freeing this memory.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IISDB_EMM](https://learn.microsoft.com/previous-versions/windows/desktop/api/dvbsiparser/nn-dvbsiparser-iisdb_emm)