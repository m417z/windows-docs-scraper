# IPSEC_SA_CONTEXT1 structure

## Description

The **IPSEC_SA_CONTEXT1** structure encapsulates an inbound and outbound security association (SA) pair.
[IPSEC_SA_CONTEXT0](https://learn.microsoft.com/windows/desktop/api/ipsectypes/ns-ipsectypes-ipsec_sa_context0) is available.

## Members

### `saContextId`

Identifies the SA context.

### `inboundSa`

An [IPSEC_SA_DETAILS1](https://learn.microsoft.com/windows/desktop/api/ipsectypes/ns-ipsectypes-ipsec_sa_details1) structure that contains information about the inbound SA.

### `outboundSa`

An [IPSEC_SA_DETAILS1](https://learn.microsoft.com/windows/desktop/api/ipsectypes/ns-ipsectypes-ipsec_sa_details1) structure that contains information about the outbound SA.

## See also

[Windows Filtering Platform API Structures](https://learn.microsoft.com/windows/desktop/FWP/fwp-structs)