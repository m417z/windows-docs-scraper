## Description

The **NDIS_WWAN_UE_POLICY_INFO** structure represents the UE policy information of the MB device.

## Members

### `Header`

The header with type, revision, and size information about the **NDIS_WWAN_UE_POLICY_INFO** structure. The MB Service sets the header with the values that are shown in the following table when it sends the data structure to the miniport driver for set operations. Miniport drivers must set the header with the same values when they send the data structure to the MB service.

| Header submember | Value |
| --- | --- |
| Type | NDIS_OBJECT_TYPE_DEFAULT |
| Revision | NDIS_WWAN_UE_POLICY_INFO_REVISION_1 |
| Size | sizeof(NDIS_WWAN_UE_POLICY_INFO) |

For more information about these members, see [**NDIS_OBJECT_HEADER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header).

### `uStatus`

The status of system capability.

### `UePolicyInfo`

A formatted [**WWAN_UE_POLICY_INFO**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-wwan_ue_policy_info) structure containing the UE policy information.

## Remarks

## See also

[**WWAN_UE_POLICY_INFO**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-wwan_ue_policy_info)

[OID_WWAN_UE_POLICY](https://learn.microsoft.com/windows-hardware/drivers/network/oid-wwan-ue-policy)