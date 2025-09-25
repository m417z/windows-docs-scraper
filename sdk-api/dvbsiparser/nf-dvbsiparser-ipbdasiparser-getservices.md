# IPBDASiParser::GetServices

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

Retrieves a list of services from the program and system information protocol (PSIP) tables in a Protected Broadcast Device Architecture (PBDA) transport stream.

## Parameters

### `dwSize` [in]

Size of the buffer that receives the service list, in bytes.

### `pBuffer` [in]

Receives the buffer for services.

### `ppServices` [out]

Receives an [IPBDA_Services](https://learn.microsoft.com/previous-versions/windows/desktop/api/dvbsiparser/nn-dvbsiparser-ipbda_services) interface pointer. The caller must release this interface.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IPBDASiParser](https://learn.microsoft.com/previous-versions/windows/desktop/api/dvbsiparser/nn-dvbsiparser-ipbdasiparser)

[IPBDA_Services](https://learn.microsoft.com/previous-versions/windows/desktop/api/dvbsiparser/nn-dvbsiparser-ipbda_services)