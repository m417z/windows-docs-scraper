## Description

The **WWAN_READY_INFO_REV1** structure represents the ready-state of the MB device. WWAN_READY_INFO_REV1 updates [WWAN_READY_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-_wwan_ready_info) by removing the *StatusFlags* field.

## Members

### `ReadyState`

The ready-state of the device.

### `EmergencyMode`

The emergency mode of the device. For more information, see [WWAN\_EMERGENCY\_MODE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ne-wwan-_wwan_emergency_mode).

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

## See also

[NDIS\_WWAN\_READY\_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndiswwan/ns-ndiswwan-_ndis_wwan_ready_info)

[WWAN\_EMERGENCY\_MODE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ne-wwan-_wwan_emergency_mode)

[WWAN\_LIST\_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-_wwan_list_header)

[WWAN\_READY\_STATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ne-wwan-_wwan_ready_state)