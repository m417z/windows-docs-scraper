## Description

Contains information that describes an IKE/AuthIP Quick Mode (QM) failure. [FWPM_NET_EVENT_IKEEXT_QM_FAILURE0](https://learn.microsoft.com/windows/win32/api/fwpmtypes/ns-fwpmtypes-fwpm_net_event_ikeext_qm_failure0) is also available.

## Members

### `failureErrorCode`

Windows error code for the failure.

### `failurePoint`

An [IPSEC_FAILURE_POINT](https://learn.microsoft.com/windows/desktop/api/ipsectypes/ne-ipsectypes-ipsec_failure_point) value that indicates the IPsec state when the failure occurred.

### `keyingModuleType`

 An [IKEEXT_KEY_MODULE_TYPE](https://learn.microsoft.com/windows/desktop/api/iketypes/ne-iketypes-ikeext_key_module_type) value that specifies the type of keying module.

### `qmState`

An [IKEEXT_QM_SA_STATE](https://learn.microsoft.com/windows/desktop/api/iketypes/ne-iketypes-ikeext_qm_sa_state) value that specifies the QM state when the failure occurred.

### `saRole`

An [IKEEXT_SA_ROLE](https://learn.microsoft.com/windows/desktop/api/iketypes/ne-iketypes-ikeext_sa_role) value that specifies the SA role when the failure occurred.

### `saTrafficType`

 An [IPSEC_TRAFFIC_TYPE](https://learn.microsoft.com/windows/desktop/api/ipsectypes/ne-ipsectypes-ipsec_traffic_type) value that specifies the type of traffic.

### `localSubNet`

An [FWP_CONDITION_VALUE0](https://learn.microsoft.com/windows/desktop/api/fwptypes/ns-fwptypes-fwp_condition_value0) structure that contains values that conditions can use when testing for matches.

Available when **saTrafficType** is **IPSEC_TRAFFIC_TYPE_TUNNEL**.

### `remoteSubNet`

An [FWP_CONDITION_VALUE0](https://learn.microsoft.com/windows/desktop/api/fwptypes/ns-fwptypes-fwp_condition_value0) structure that contains values that conditions can use when testing for matches.

Available when **saTrafficType** is **IPSEC_TRAFFIC_TYPE_TUNNEL**.

### `qmFilterId`

Quick Mode filter ID.

### `mmSaLuid`

A LUID representing the main mode security association.

### `mmProviderContextKey`

A GUID representing the main mode provider context.

## Remarks

**FWPM_NET_EVENT_IKEEXT_QM_FAILURE1** is a specific implementation of **FWPM_NET_EVENT_IKEEXT_QM_FAILURE**. For more info, see [WFP Version-Independent Names and Targeting Specific Versions of Windows](https://learn.microsoft.com/windows/win32/fwp/wfp-version-independent-names-and-targeting-specific-versions-of-windows).

## See also