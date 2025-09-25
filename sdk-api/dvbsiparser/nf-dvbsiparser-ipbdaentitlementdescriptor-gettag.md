# IPBDAEntitlementDescriptor::GetTag

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

Gets the tag that uniquely identifies an entitlement descriptor in a Protected Broadcast Driver Architecture (PBDA) transport stream.

## Parameters

### `pbVal` [out]

Receives the tag value. For PBDA entitlement descriptors, this value is 0x80.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IPBDAEntitlementDescriptor](https://learn.microsoft.com/previous-versions/windows/desktop/api/dvbsiparser/nn-dvbsiparser-ipbdaentitlementdescriptor)