## Description

The **FWPM_PROVIDER_CONTEXT2** structure stores the state associated with a provider context. [FWPM_PROVIDER_CONTEXT0](https://learn.microsoft.com/windows/win32/api/fwpmtypes/ns-fwpmtypes-fwpm_provider_context0) is available.

## Members

### `providerContextKey`

Type: **GUID**

Uniquely identifies the provider context. If the GUID is zero-initialized in the call to [FwpmProviderContextAdd2](https://learn.microsoft.com/windows/win32/api/fwpmu/nf-fwpmu-fwpmprovidercontextadd2), then Base Filtering Engine (BFE) will generate one.

### `displayData`

Type: **[FWPM_DISPLAY_DATA0](https://learn.microsoft.com/windows/win32/api/fwptypes/ns-fwptypes-fwpm_display_data0)**

Allows provider contexts to be annotated in a human-readable form. The [FWPM_DISPLAY_DATA0](https://learn.microsoft.com/windows/win32/api/fwptypes/ns-fwptypes-fwpm_display_data0) structure is required.

### `flags`

Type: **UINT32**

Possible values:

| Provider context flag | Meaning |
| - | - |
| FWPM_PROVIDER_CONTEXT_FLAG_PERSISTENT | The object is persistent, that is, it survives across BFE stop/start. |
| FWPM_PROVIDER_CONTEXT_FLAG_DOWNLEVEL | Reserved for internal use. |

### `providerKey`

Type: **GUID\***

GUID of the policy provider that manages this object.

### `providerData`

Type: **[FWP_BYTE_BLOB](https://learn.microsoft.com/windows/win32/api/fwptypes/ns-fwptypes-fwp_byte_blob)**

Optional provider-specific data that allows providers to store additional context info with the object.

### `type`

Type: **[FWPM_PROVIDER_CONTEXT_TYPE](https://learn.microsoft.com/windows/win32/api/fwpmtypes/ne-fwpmtypes-fwpm_provider_context_type)**

The type of provider context.

### `keyingPolicy`

Type: **[IPSEC_KEYING_POLICY1](https://learn.microsoft.com/windows/win32/api/ipsectypes/ns-ipsectypes-ipsec_keying_policy1)\***

Available when **type** is **FWPM_IPSEC_KEYING_CONTEXT**.

### `ikeQmTransportPolicy`

Type: **[IPSEC_TRANSPORT_POLICY2](https://learn.microsoft.com/windows/win32/api/ipsectypes/ns-ipsectypes-ipsec_transport_policy2)\***

Available when **type** is **FWPM_IPSEC_IKE_QM_TRANSPORT_CONTEXT**.

### `ikeQmTunnelPolicy`

Type: **[IPSEC_TUNNEL_POLICY2](https://learn.microsoft.com/windows/win32/api/ipsectypes/ns-ipsectypes-ipsec_tunnel_policy2)\***

Available when **type** is **FWPM_IPSEC_IKE_QM_TUNNEL_CONTEXT**.

### `authipQmTransportPolicy`

Type: **[IPSEC_TRANSPORT_POLICY2](https://learn.microsoft.com/windows/win32/api/ipsectypes/ns-ipsectypes-ipsec_transport_policy2)\***

 [case()][unique]

### `authipQmTunnelPolicy`

Type: **[IPSEC_TUNNEL_POLICY2](https://learn.microsoft.com/windows/win32/api/ipsectypes/ns-ipsectypes-ipsec_tunnel_policy2)\***

Available when **type** is **FWPM_IPSEC_AUTHIP_QM_TRANSPORT_CONTEXT**.

### `ikeMmPolicy`

Type: **[IKEEXT_POLICY2](https://learn.microsoft.com/windows/win32/api/iketypes/ns-iketypes-ikeext_policy2)\***

Available when **type** is **FWPM_IPSEC_IKE_MM_CONTEXT**.

### `authIpMmPolicy`

Type: **[IKEEXT_POLICY2](https://learn.microsoft.com/windows/win32/api/iketypes/ns-iketypes-ikeext_policy2)\***

Available when **type** is **FWPM_IPSEC_AUTHIP_MM_CONTEXT**.

### `dataBuffer`

Type: **[FWP_BYTE_BLOB](https://learn.microsoft.com/windows/win32/api/fwptypes/ns-fwptypes-fwp_byte_blob)\***

Available when **type** is **FWPM_GENERAL_CONTEXT**.

### `classifyOptions`

Type: **[FWPM_CLASSIFY_OPTIONS0](https://learn.microsoft.com/windows/win32/api/fwpmtypes/ns-fwpmtypes-fwpm_classify_options0)\***

Available when **type** is **FWPM_CLASSIFY_OPTIONS_CONTEXT**.

### `ikeV2QmTunnelPolicy`

Type: **[IPSEC_TUNNEL_POLICY2](https://learn.microsoft.com/windows/win32/api/ipsectypes/ns-ipsectypes-ipsec_tunnel_policy2)\***

Available when **type** is **FWPM_IPSEC_IKEV2_QM_TUNNEL_CONTEXT**.

### `ikeV2QmTransportPolicy`

Type: **[IPSEC_TRANSPORT_POLICY2](https://learn.microsoft.com/windows/win32/api/ipsectypes/ns-ipsectypes-ipsec_transport_policy2)\***

Available when **type** is **FWPM_IPSEC_IKEV2_QM_TRANSPORT_CONTEXT**.

### `ikeV2MmPolicy`

Type: **[IKEEXT_POLICY2](https://learn.microsoft.com/windows/win32/api/iketypes/ns-iketypes-ikeext_policy2)\***

Available when **type** is **FWPM_IPSEC_IKEV2_MM_CONTEXT**.

### `idpOptions`

Type: **[IPSEC_DOSP_OPTIONS0](https://learn.microsoft.com/windows/win32/api/ipsectypes/ns-ipsectypes-ipsec_dosp_options0)\***

Available when **type** is **FWPM_IPSEC_DOSP_CONTEXT**.

### `providerContextId`

Type: **UINT64**

LUID identifying the context. This is the context value stored in the **FWPS_FILTER1** structure for filters that reference a provider context. The **FWPS_FILTER1** structure is documented in the WDK.

## Remarks

The first seven elements of the union are information supplied when adding objects.

The last element is additional information returned when getting/enumerating objects.

## See also

[FWPM_DISPLAY_DATA0](https://learn.microsoft.com/windows/win32/api/fwptypes/ns-fwptypes-fwpm_display_data0)

[FWPM_PROVIDER_CONTEXT_TYPE](https://learn.microsoft.com/windows/win32/api/fwpmtypes/ne-fwpmtypes-fwpm_provider_context_type)

[FWP_BYTE_BLOB](https://learn.microsoft.com/windows/win32/api/fwptypes/ns-fwptypes-fwp_byte_blob)

[FwpmProviderContextAdd2](https://learn.microsoft.com/windows/win32/api/fwpmu/nf-fwpmu-fwpmprovidercontextadd2)

[IKEEXT_POLICY2](https://learn.microsoft.com/windows/win32/api/iketypes/ns-iketypes-ikeext_policy2)

[IPSEC_DOSP_OPTIONS0](https://learn.microsoft.com/windows/win32/api/ipsectypes/ns-ipsectypes-ipsec_dosp_options0)

[IPSEC_KEYING_POLICY0](https://learn.microsoft.com/windows/win32/api/ipsectypes/ns-ipsectypes-ipsec_keying_policy0)

[IPSEC_TRANSPORT_POLICY2](https://learn.microsoft.com/windows/win32/api/ipsectypes/ns-ipsectypes-ipsec_transport_policy2)

[IPSEC_TUNNEL_POLICY2](https://learn.microsoft.com/windows/win32/api/ipsectypes/ns-ipsectypes-ipsec_tunnel_policy2)

[Windows Filtering Platform API Structures](https://learn.microsoft.com/windows/desktop/FWP/fwp-structs)