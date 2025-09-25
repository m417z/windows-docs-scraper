## Description

The **WWAN_UE_POLICY_INFO** structure represents the UE policy information of the MB device.

## Members

### `RawTdOnlyData`

A [**WWAN_OFFSET_SIZE_ELEMENT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-wwan_offset_size_element) structure. The first 4 bytes are the offset to the data buffer that contains the raw data of MBIM_TLV_TYPE_URSP_RULES_TD_ONLY, in bytes, calculated from the beginning of **WWAN_UE_POLICY_INFO**.
The second 4 bytes are the size of the raw data of MBIM_TLV_TYPE_URSP_RULES_TD_ONLY, in bytes.

## Remarks

**WWAN_UE_POLICY_INFO** is used by the [**NDIS_WWAN_UE_POLICY_INFO**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndiswwan/ns-ndiswwan-ndis_wwan_ue_policy_info) structure.

## See also

[**NDIS_WWAN_UE_POLICY_INFO**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndiswwan/ns-ndiswwan-ndis_wwan_ue_policy_info)

[OID_WWAN_UE_POLICY](https://learn.microsoft.com/windows-hardware/drivers/network/oid-wwan-ue-policy)