# _WWAN_READY_INFO structure

## Description

The WWAN_READY_INFO structure represents the ready-state of the MB device.

## Members

### `ReadyState`

The ready-state of the device.

### `EmergencyMode`

The emergency mode of the device. For more information, see [WWAN_EMERGENCY_MODE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ne-wwan-_wwan_emergency_mode).

### `SubscriberId`

A NULL-terminated string of digits that represents the identity of the subscriber.

For GSM-based devices, this member represents the International Mobile Subscriber Identity (IMSI) string (up to 15 digits in length).

For CDMA-based devices, this represents the Mobile Identification Number (MIN) string or the International Roaming MIN (IRM) string (both 10 digits in length).

Miniport drivers must specify this string when the device ready-state changes to **WwanReadyStateInitialized**. Miniport drivers should also specify this string when the device ready-state changes to **WwanReadyStateBadSim**, **WwanReadyStateFailure**, or **WwanReadyStateDeviceLocked**, if possible, for identification purposes.

For single-carrier multi-mode functions, the GSM **SubscriberId** format must be used. This does not apply to multi-carrier multi-mode functions as the **SubscriberId** may change.

### `SimIccId`

A NULL-terminated string of digits that represents the International Circuit Card (ICC) ID of the SIM. The ICC ID varies from between 15 to 20 digits in length and is represented in alphanumeric characters. Miniport drivers must specify this string when the device ready-state changes to **WwanReadyStateInitialized** and also when the device is locked, waiting for entry of PIN1 and PUK1 keys.

Miniport drivers must specify this value for all devices where **WwanCellularClass** equals **WwanCellularClassGsm**. Miniport drivers of CDMA-based devices must specify this value for devices where **SimClass** equals **WwanSimClassSimRemovable**.

### `CdmaShortMsgSize`

The SMS character length that is supported by the network or the device, whichever is less, if the device is CDMA-based.

CDMA-based devices that support SMS should specify their carrier-specific maximum SMS character length to be greater than WWAN_CDMA_SHORT_MSG_SIZE_UNKNOWN and less than WWAN_CDMA_SHORT_MSG_SIZE_MAX.

CDMA-based devices that do not support SMS should set this member to WWAN_CDMA_SHORT_MSG_SIZE_UNKNOWN.

This member does not apply to GSM-based devices. Miniport drivers of GSM-based devices should specify WWAN_CDMA_SHORT_MSG_SIZE_UNKNOWN.

### `TNListHeader`

A list of telephone numbers (TNs) that are assigned to the subscriber identity.

Each element in the list is a string of WCHARs, with a fixed size of WWAN_TN_LEN.

Each TN stored in a list element is a NULL-terminated value.

In GSM-based devices the TNs are called Mobile Station ISDN Number (MSISDNs). In CDMA-based devices they are called Mobile Directory Numbers (MDNs).

Miniport drivers should not specify this value until the device ready-state changes to **WwanReadyStateInitialized**.

### `StatusFlags`

SIM status flags.

|Value|Meaning|
|---|---|
|WWAN_READY_STATUS_MASK_IS_ESIM 0x00000001| **0**: The current SIM is not an eSIM. **1**: The current SIM is an eSIM. Valid only when the ReadyState is MBIMSubscriberReadyStateInitialized or MBIMSubscriberReadyStateNoEsimProfile.|
|WWAN_READY_STATUS_MASK_SIM_REMOVABILITY_KNOWN 0x00000002|**0**: SIM removability is unknown. **1**: SIM removability is known.|
|WWAN_READY_STATUS_MASK_SIM_FORMFACTOR 0x00000004|**0**: The current SIM is embedded. **1**: The current SIM is removable.Valid only when the ReadyState is MBIMSubscriberReadyStateInitialized, MBIMSubscriberReadyStateNoEsimProfile, or MBIMSubscriberReadyStateDeviceLocked.|
|WWAN_READY_STATUS_MASK_SIM_SLOT_ACTIVE 0x00000008| **0**: The indication came from the currently inactive slot. **1**: The indication came from the currently active slot. This bit may be set independent of the WWAN_READY_STATUS_MASK_MASKS_IS_VALID bit.|
|WWAN_READY_STATUS_MASK_MASKS_IS_VALID 0x80000000|Indicates whether other status bits (except for WWAN_READY_STATUS_MASK_SIM_SLOT_ACTIVE) are invalid. If the bit is **0**, other bits are invalid and should be ignored. If the bit is **1**, other status bits are valid.

### `SlotId`

A ULONG value that specifies the SIM card slot ID.

## See also

[NDIS_WWAN_READY_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndiswwan/ns-ndiswwan-_ndis_wwan_ready_info)

[WWAN_EMERGENCY_MODE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ne-wwan-_wwan_emergency_mode)

[WWAN_LIST_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-_wwan_list_header)

[WWAN_READY_STATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ne-wwan-_wwan_ready_state)