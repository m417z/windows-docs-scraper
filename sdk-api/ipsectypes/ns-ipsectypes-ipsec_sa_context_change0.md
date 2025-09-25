# IPSEC_SA_CONTEXT_CHANGE0 structure

## Description

The **IPSEC_SA_CONTEXT_CHANGE0** structure contains information about an IPsec security association (SA) context change.

## Members

### `changeType`

Type: [IPSEC_SA_CONTEXT_EVENT_TYPE0](https://learn.microsoft.com/windows/desktop/api/ipsectypes/ne-ipsectypes-ipsec_sa_context_event_type0)

The type of IPsec SA context change event.

### `saContextId`

Type: **UINT64**

Identifier of the IPsec SA context that changed.

## See also

[IPSEC_SA_CONTEXT_EVENT_TYPE0](https://learn.microsoft.com/windows/desktop/api/ipsectypes/ne-ipsectypes-ipsec_sa_context_event_type0)