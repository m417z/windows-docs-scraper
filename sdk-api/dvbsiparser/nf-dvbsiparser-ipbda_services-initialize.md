# IPBDA_Services::Initialize

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

Initializes an object that retrieves service records from a Program and System Information Protocol (PSIP) table in a Protected Broadcast Device Architecture (PBDA) transport stream.

## Parameters

### `size` [in]

Specifies the size of the buffer used to initialize the object.

### `pBuffer` [in]

Pointer to the buffer containing the service data used for initialization.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IPBDA_Services](https://learn.microsoft.com/previous-versions/windows/desktop/api/dvbsiparser/nn-dvbsiparser-ipbda_services)