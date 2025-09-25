# _WWAN_STRUCT_TYPE enumeration

## Description

> [!IMPORTANT]
> ### Bias-free communication
>
> Microsoft supports a diverse and inclusive environment. This article contains references to terminology that the Microsoft [style guide for bias-free communication](https://learn.microsoft.com/style-guide/bias-free-communication) recognizes as exclusionary. The word or phrase is used in this article for consistency because it currently appears in the software. When the software is updated to remove the language, this article will be updated to be in alignment.

The WWAN_STRUCT_TYPE enumeration lists the different types of the list elements that follow the
WWAN_LIST_HEADER object in memory.

## Constants

### `WwanStructTN`

The elements are NULL-terminated strings of Telephone Number (TNs), with each string having
WWAN_TN_LEN characters.

[OID_WWAN_READY_INFO](https://learn.microsoft.com/windows-hardware/drivers/network/oid-wwan-ready-info) uses this value to
represent a list of TNs assigned to the device.

### `WwanStructContext`

The elements are of type
[WWAN_CONTEXT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-_wwan_context).

[OID_WWAN_PROVISIONED_CONTEXTS](https://learn.microsoft.com/windows-hardware/drivers/network/oid-wwan-provisioned-contexts) uses this value to represent a list of provisioned
contexts.

### `WwanStructProvider`

The elements are of type
[WWAN_PROVIDER](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-_wwan_provider).

Both [OID_WWAN_PREFERRED_PROVIDERS](https://learn.microsoft.com/windows-hardware/drivers/network/oid-wwan-preferred-providers) and
[OID_WWAN_VISIBLE_PROVIDERS](https://learn.microsoft.com/windows-hardware/drivers/network/oid-wwan-visible-providers) use this
value to represent a list of network providers for WWAN 1.0 miniport drivers.

### `WwanStructSmsPdu`

The elements are of type
[WWAN_SMS_PDU_RECORD](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-_wwan_sms_pdu_record).

### `WwanStructReserved0`

The value is reserved for future use. Do not use.

### `WwanStructReserved1`

The value is reserved for future use. Do not use.

### `WwanStructReserved2`

The value is reserved for future use. Do not use.

### `WwanStructSmsCdma`

The elements are of type
[WWAN_SMS_CDMA_RECORD](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-_wwan_sms_cdma_record).

### `WwanStructReserved3`

The value is reserved for future use. Do not use.

### `WwanStructDeviceServiceEntry`

The elements are of type
[WWAN_DEVICE_SERVICE_ENTRY](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-_wwan_device_service_entry).

### `WwanStructProvider2`

The elements are of type
[WWAN_PROVIDER2](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-_wwan_provider2).

The following OIDs use this value to represent a list of network providers for WWAN 2.0 miniport drivers:

[OID_WWAN_PREFERRED_PROVIDERS](https://learn.microsoft.com/windows-hardware/drivers/network/oid-wwan-preferred-providers)

[OID_WWAN_VISIBLE_PROVIDERS](https://learn.microsoft.com/windows-hardware/drivers/network/oid-wwan-visible-providers)

[OID_WWAN_PREFERRED_MULTICARRIER_PROVIDERS](https://learn.microsoft.com/windows-hardware/drivers/network/oid-wwan-preferred-multicarrier-providers)

### `WwanStructDeviceServiceGuid`

The elements are of type
GUID.

### `WwanStructDeviceServiceCommandId`

The elements are of type ULONG.

### `WwanStructCellularClass`

The elements are of type [WWAN_CELLULAR_CLASS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ne-wwan-_wwan_cellular_class).

### `WwanStructDeviceSlotMap`

The elements are of type [WWAN_DEVICE_SLOT_MAPPING_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-_wwan_device_slot_mapping_info).

### `WwanStructUiccApplication`

The elements are of type BYTE for a UICC application ID.

### `WwanStructRegisterAcquisitionOrder`

The elements are of type ULONG.

### `WwanStructRegistrationState`

The elements are of type [WWAN_REGISTRATION_STATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-_wwan_registration_state).

### `WwanStructSignalState`

The elements are of type [WWAN_SIGNAL_STATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-_wwan_signal_state).

### `WwanStructUiccTerminalCapability`

The elements are of type **WWAN_UICC_TERMINAL_CAPABILITY_TLV**. For more info about low level UICC operations, see [MB low level UICC access](https://learn.microsoft.com/windows-hardware/drivers/network/mb-low-level-uicc-access#mbimcidmsuiccterminalcapability).

### `WwanStructSarConfig`

The elements are of type [**WWAN_SAR_CONFIG_INDICES**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-_wwan_sar_config_indices). For more info about MB SAR operations, see [MB SAR Platform Support](https://learn.microsoft.com/windows-hardware/drivers/network/mb-sar-platform-support#mbimcidmssarconfig).

### `WwanStructContextV2`

The elements are of type [**WWAN_CONTEXT_V2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-_wwan_context_v2).

### `WwanStructNetworkBlacklistProvider`

The elements are of type [**WWAN_NETWORK_BLACKLIST_PROVIDER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-_wwan_network_blacklist_provider). For more info about network blacklist providers, see [MB Network Blacklist Operations](https://learn.microsoft.com/windows-hardware/drivers/network/mb-network-blacklist-operations).

### `WwanStructMPDPChildInterface`

### `WwanStructSNSSAI`

The elements are of type [**WWAN_SINGLE_NSSAI**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-wwan_single_nssai).

### `WwanStructRejectedSNSSAI`

The elements are of type [**WWAN_REJECTED_SNSSAI**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-wwan_rejected_snssai).

### `WwanStructProvisionedContextV2`

The elements are of type [**WWAN_PROVISIONED_CONTEXT_V2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-wwan_provisioned_context_v2).

### `WwanStructTaiSinglePlmnNonConsecutive`

The elements are of type [**WWAN_TAI_LIST_SINGLE_PLMN**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-wwan_tai_list_single_plmn) and the tracking area code (TAC) values are nonconsecutive.

### `WwanStructTaiSinglePlmnConsecutive`

The elements are of type [**WWAN_TAI_LIST_SINGLE_PLMN**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-wwan_tai_list_single_plmn) and the tracking area code (TAC) values are consecutive.

### `WwanStructTaiMultiPlmn`

The elements are of type [**WWAN_TAI_LIST_MULTI_PLMN**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-wwan_tai_list_multi_plmn).

### `WwanStructMax`

The total number of supported types.

### `WwanStructDeviceCellularClass`

The elements are of type [WWAN_CELLULAR_CLASS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ne-wwan-_wwan_cellular_class).

[OID_WWAN_DEVICE_CAPS](https://learn.microsoft.com/windows-hardware/drivers/network/oid-wwan-device-caps) uses this value to represent multiple cellular classes supported by the miniport driver.

### `WwanStructProvisionedContextV2`

The elements are of type [**WWAN_PROVISIONED_CONTEXT_V2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-wwan_provisioned_context_v2).

### `WwanStructTaiSinglePlmnNonConsecutive`

The elements are of type nonconsecutive [**WWAN_TAI_LIST_SINGLE_PLMN**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-wwan_tai_list_single_plmn).

### `WwanStructTaiSinglePlmnConsecutive`

The elements are of type consecutive [**WWAN_TAI_LIST_SINGLE_PLMN**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-wwan_tai_list_single_plmn).

### `WwanStructTaiMultiPlmn`

The elements are of type [**WWAN_TAI_LIST_MULTI_PLMN**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-wwan_tai_list_multi_plmn).

## See also

[OID_WWAN_PREFERRED_PROVIDERS](https://learn.microsoft.com/windows-hardware/drivers/network/oid-wwan-preferred-providers)

[OID_WWAN_PROVISIONED_CONTEXTS](https://learn.microsoft.com/windows-hardware/drivers/network/oid-wwan-provisioned-contexts)

[OID_WWAN_READY_INFO](https://learn.microsoft.com/windows-hardware/drivers/network/oid-wwan-ready-info)

[OID_WWAN_VISIBLE_PROVIDERS](https://learn.microsoft.com/windows-hardware/drivers/network/oid-wwan-visible-providers)

[WWAN_CONTEXT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-_wwan_context)

[WWAN_LIST_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-_wwan_list_header)

[WWAN_PROVIDER](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-_wwan_provider)

[WWAN_SMS_CDMA_RECORD](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-_wwan_sms_cdma_record)

[WWAN_SMS_PDU_RECORD](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-_wwan_sms_pdu_record)