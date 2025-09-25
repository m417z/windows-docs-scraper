# FWPM_PROVIDER_CONTEXT0 structure

## Description

The **FWPM_PROVIDER_CONTEXT0** structure stores the state associated with a provider context.
[FWPM_PROVIDER_CONTEXT2](https://learn.microsoft.com/windows/win32/api/fwpmtypes/ns-fwpmtypes-fwpm_provider_context2) is available.

## Members

### `providerContextKey`

Uniquely identifies the provider context. If the GUID is zero-initialized in the call to [FwpmProviderContextAdd0](https://learn.microsoft.com/windows/win32/api/fwpmu/nf-fwpmu-fwpmprovidercontextadd0), Base Filtering Engine (BFE) will generate one.

### `displayData`

Allows provider contexts to be annotated in a human-readable form. The [FWPM_DISPLAY_DATA0](https://learn.microsoft.com/windows/win32/api/fwptypes/ns-fwptypes-fwpm_display_data0) structure is required.

### `flags`

Possible values:

| Provider context flag | Meaning |
| ----- | ------- |
| FWPM_PROVIDER_CONTEXT_FLAG_PERSISTENT | The object is persistent, that is, it survives across BFE stop/start. |

### `providerKey`

GUID of the policy provider that manages this object.

### `providerData`

An [FWP_BYTE_BLOB](https://learn.microsoft.com/windows/win32/api/fwptypes/ns-fwptypes-fwp_byte_blob) structure that contains optional provider-specific data that allows providers to store additional context info with the object.

### `type`

A [FWPM_PROVIDER_CONTEXT_TYPE](https://learn.microsoft.com/windows/win32/api/fwpmtypes/ne-fwpmtypes-fwpm_provider_context_type) value specifying the type of provider context..

### `keyingPolicy`

Available when **type** is **FWPM_IPSEC_KEYING_CONTEXT**.

See [IPSEC_KEYING_POLICY0](https://learn.microsoft.com/windows/win32/api/ipsectypes/ns-ipsectypes-ipsec_keying_policy0) for more information.

### `ikeQmTransportPolicy`

Available when **type** is **FWPM_IPSEC_IKE_QM_TRANSPORT_CONTEXT**.

See [IPSEC_TRANSPORT_POLICY0](https://learn.microsoft.com/windows/win32/api/ipsectypes/ns-ipsectypes-ipsec_transport_policy0) for more information.

### `ikeQmTunnelPolicy`

Available when **type** is **FWPM_IPSEC_IKE_QM_TUNNEL_CONTEXT**.

See [IPSEC_TUNNEL_POLICY0](https://learn.microsoft.com/windows/win32/api/ipsectypes/ns-ipsectypes-ipsec_tunnel_policy0) for more information.

### `authipQmTransportPolicy`

Available when **type** is **FWPM_IPSEC_AUTHIP_QM_TRANSPORT_CONTEXT**.

See [IPSEC_TRANSPORT_POLICY0](https://learn.microsoft.com/windows/win32/api/ipsectypes/ns-ipsectypes-ipsec_transport_policy0) for more information.

### `authipQmTunnelPolicy`

Available when **type** is **FWPM_IPSEC_AUTHIP_QM_TUNNEL_CONTEXT**.

See [IPSEC_TUNNEL_POLICY0](https://learn.microsoft.com/windows/win32/api/ipsectypes/ns-ipsectypes-ipsec_tunnel_policy0) for more information.

### `ikeMmPolicy`

Available when **type** is **FWPM_IPSEC_IKE_MM_CONTEXT**.

See [IKEEXT_POLICY0](https://learn.microsoft.com/windows/win32/api/iketypes/ns-iketypes-ikeext_policy0) for more information.

### `authIpMmPolicy`

Available when **type** is **FWPM_IPSEC_AUTHIP_MM_CONTEXT**.

See [IKEEXT_POLICY0](https://learn.microsoft.com/windows/win32/api/iketypes/ns-iketypes-ikeext_policy0) for more information.

### `dataBuffer`

Available when **type** is **FWPM_GENERAL_CONTEXT**.

See [FWP_BYTE_BLOB](https://learn.microsoft.com/windows/win32/api/fwptypes/ns-fwptypes-fwp_byte_blob) for more information.

### `classifyOptions`

Available when **type** is **FWPM_CLASSIFY_OPTIONS_CONTEXT**.

See [FWPM_CLASSIFY_OPTIONS0](https://learn.microsoft.com/windows/win32/api/fwpmtypes/ns-fwpmtypes-fwpm_classify_options0) for more information.

### `providerContextId`

LUID identifying the context. This is the context value stored in the **FWPS_FILTER0** structure for filters that reference a provider context. The **FWPS_FILTER0** structure is documented in the WDK.

## Remarks

The first seven elements of the union are information supplied when adding objects.

The last element is additional information returned when getting/enumerating objects.

## See also

[Windows Filtering Platform API Structures](https://learn.microsoft.com/windows/desktop/FWP/fwp-structs)