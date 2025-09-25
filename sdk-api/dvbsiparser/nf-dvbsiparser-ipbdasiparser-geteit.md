# IPBDASiParser::GetEIT

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

Gets the event information table (EIT) from the program and system information protocol (PSIP) tables in a Protected Broadcast Device Architecture (PBDA) transport stream.

## Parameters

### `dwSize` [in]

Reserved. Set to zero.

### `pBuffer` [in]

Reserved. Set to **NULL**.

### `ppEIT` [out]

Receives a pointer to the [IPBDA_EIT](https://learn.microsoft.com/previous-versions/windows/desktop/api/dvbsiparser/nn-dvbsiparser-ipbda_eit) interface. The caller must release the interface.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IPBDASiParser](https://learn.microsoft.com/previous-versions/windows/desktop/api/dvbsiparser/nn-dvbsiparser-ipbdasiparser)