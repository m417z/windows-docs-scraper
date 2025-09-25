# IPBDA_EIT::Initialize

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

Initializes an object that gets data from an event information table (EIT) in a Protected Broadcast Device Architecture (PBDA) transport stream. This method is called internally by the [IPBDASiParser::GetEIT](https://learn.microsoft.com/previous-versions/windows/desktop/api/dvbsiparser/nf-dvbsiparser-ipbdasiparser-geteit) method, so applications typically should not call it.

## Parameters

### `size` [in]

Specifies the buffer size for data used to initialize each section.

### `pBuffer` [in]

Specifies the buffer used to initialize each section.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IPBDA_EIT](https://learn.microsoft.com/previous-versions/windows/desktop/api/dvbsiparser/nn-dvbsiparser-ipbda_eit)