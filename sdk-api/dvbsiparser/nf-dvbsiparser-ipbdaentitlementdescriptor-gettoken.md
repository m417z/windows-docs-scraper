# IPBDAEntitlementDescriptor::GetToken

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

Gets the entitlement token from the entitlement descriptor in a Protected Broadcast Driver Architecture (PBDA) transport stream.

## Parameters

### `ppbTokenBuffer` [out]

Pointer to a buffer that receives the entitlement token. The caller must free this memory after use.

### `pdwTokenLength` [out]

Receives the entitlement token length.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IPBDAEntitlementDescriptor](https://learn.microsoft.com/previous-versions/windows/desktop/api/dvbsiparser/nn-dvbsiparser-ipbdaentitlementdescriptor)