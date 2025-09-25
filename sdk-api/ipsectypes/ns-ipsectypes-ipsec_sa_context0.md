# IPSEC_SA_CONTEXT0 structure

## Description

The **IPSEC_SA_CONTEXT0** structure encapsulates an inbound and outbound SA pair.
[IPSEC_SA_CONTEXT1](https://learn.microsoft.com/windows/desktop/api/ipsectypes/ns-ipsectypes-ipsec_sa_context1) is available.

## Members

### `saContextId`

Identifies the SA context.

### `inboundSa`

An [IPSEC_SA_DETAILS0](https://learn.microsoft.com/windows/desktop/api/ipsectypes/ns-ipsectypes-ipsec_sa_details0) structure that contains information about the inbound SA.

### `outboundSa`

An [IPSEC_SA_DETAILS0](https://learn.microsoft.com/windows/desktop/api/ipsectypes/ns-ipsectypes-ipsec_sa_details0) structure that contains information about the outbound SA.

## See also

[Windows Filtering Platform API Structures](https://learn.microsoft.com/windows/desktop/FWP/fwp-structs)