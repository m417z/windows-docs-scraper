# _WWAN_REGISTRATION_STATE structure

## Description

The WWAN_REGISTRATION_STATE structure represents the registration state of the MB device.

## Members

### `uNwError`

A network specific error, in the event of a registration failure. For more information about this
member, see the following
"Remarks" section.

### `RegisterState`

The registration state of the device. For a list of defined values, see
[WWAN_REGISTER_STATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ne-wwan-_wwan_register_state).

The
**WwanRegisterStatePartner** value indicates the device is roaming on a preferred partner network
provider, whereas
**WwanRegisterStateRoaming** value indicates the device is just roaming. If the partner
characterization of the roaming state is not available, the miniport driver should report
**WwanRegisterStateRoaming**.

### `RegisterMode`

The registration mode of the device. For a list of defined values, see
[WWAN_REGISTER_MODE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ne-wwan-_wwan_register_mode).

### `ProviderId`

A NULL-terminated numeric (0-9) string that represents the network provider identity.

For GSM-based networks, this string is a concatenation of a three-digit Mobile Country Code (MCC) and
a two or three-digit Mobile Network Code (MNC). GSM-based carriers may have more than one MNC, and hence
more than one
**ProviderId** .

For CDMA-based networks, this string is a five-digit System ID (SID). Generally, a CDMA-based carrier
has more than one SID. Typically, a carrier has one SID for each market, which is usually divided
geographically within a nation by regulations, such as Metropolitan Statistical Areas (MSA) in the
United States of America. Miniport drivers of CDMA-based devices must specify
WWAN_CDMA_DEFAULT_PROVIDER_ID if this information is not available.

When processing a
*query* request, and the registration state is in automatic register mode, this member contains the
provider ID that the device is currently associated with (if applicable). When the registration state is
in manual register mode, this member contains the provider ID that the device is requested to register
with (even if the provider is unavailable).

When processing a
*set* request and the registration state is in manual mode, this contains the provider ID selected
by the MB Service for the device to register with. When the registration state is in automatic register
mode, this parameter is ignored.

CDMA 1xRTT providers must be set to WWAN_CDMA_DEFAULT_PROVIDER_ID if the provider ID is not
available.

### `ProviderName`

A NULL-terminated string that represents the network provider's name. This member is limited to,
at most, WWAN_PROVIDERNAME_LEN characters.

For GSM-based networks, if the Preferred Presentation of Country Initials and Mobile Network Name
(PPCI&N) is longer than twenty characters, the miniport driver should abbreviate the network
name.

This member is ignored when the MB Service sets the preferred provider list.

Miniport drivers should specify a **NULL** string for devices that do not have this
information.

### `RoamingText`

A NULL-terminated string to inform the user that the device is roaming. This member is limited to
at most WWAN_ROAMTEXT_LEN characters.

This text should provide additional information to the user when the registration state is either
**WwanRegisterStatePartner** or
**WwanRegisterStateRoaming**. This member is optional.

### `WwanRegFlags`

Registration flags.

| Value | Meaning |
| --- | --- |
| WWAN_REG_FLAGS_NONE | No registration flags. |
| WWAN_REG_FLAGS_NO_MANUAL_REG | No manual attach. |
| WWAN_REG_FLAGS_PS_AUTO_ATTACH | Indicates that the MB device manages its own packet context. The MB Service will not send a packet detach to the miniport driver, but may send a packet attach. |

### `CurrentCellularClass`

The current cellular class of the registered network. For networks that only support a single cellular class this member should be set to that cellular class. For multi-mode capable networks the miniport driver sends NDIS_STATUS_WWAN_REGISTER_STATE notifications to the MB service when the network changes its cellular class.

### `PreferredDataClasses`

A bitmask that represents the data access technologies that are preferred for a connection.

## Remarks

*Query* and
*set* OID requests as well as unsolicited status events use the
**uNwError** member. If there is no network specific error or the network specific error is not known,
miniport drivers should set this member to zero. The
"Status Indication Structure" section in
[MB Operational Semantics](https://learn.microsoft.com/windows-hardware/drivers/network/mb-operational-semantics) shows the
registration cause code failure values that are defined in the
*3GPP TS 24.008 Specification*.

The following points provide guidelines on returning network specific error in different
scenarios:

* If network registration fails because of network specific error, miniport drivers should return the
  network specific error in response to
  *query* requests. In this case, miniport drivers should set the
  **uStatus** member of the NDIS_WWAN_REGISTRATION_STATE structure to WWAN_STATUS_SUCCESS and set the
  **uNwError** member to the network specific error code.
* If a
  *set* request fails, miniport drivers should return the network specific error code. In this case,
  miniport drivers should set the
  **uStatus** member of the NDIS_WWAN_REGISTRATION_STATE structure to WWAN_STATUS_FAILURE and set the
  **uNwError** member to the network specific error code.
* Whenever the device registration state changes because the network de-registers the device (for
  example, the network de-registered the device because the device's subscription expired) then
  unsolicited status events should include the network specific error. In this case, the miniport driver
  should set the
  **uStatus** member of the NDIS_WWAN_REGISTRATION_STATE structure to WWAN_STATUS_SUCCESS and set the
  **uNwError** member to the network specific error code.

To return a network specific error when processing OID_WWAN_REGISTER_STATE requests, miniport drivers
should set the
**uStatus** member of the NDIS_WWAN_REGISTRATION_STATE structure to WWAN_STATUS_FAILURE and set the
**uNwError** member to the network specific error code.

Miniport drivers can provide additional error codes as defined by the GSM standards specification of
packet-attach error codes returned by the network. For example, miniport drivers can communicate the 3GPP
specification TS 24.008 packet-attach error codes, such as error code 12 (Location area not allowed), to
the MB Service through the
**uNwError** member.

Miniport drivers must report the cause code at the earliest possible instance. For example, if the MB
device encounters one of these codes when attempting to register the device on with a network provider,
the miniport driver should report it at that time.

Miniport drivers connected to a multi-mode network should indicate the cellular class change through a [NDIS_STATUS_WWAN_REGISTER_STATE](https://learn.microsoft.com/windows-hardware/drivers/network/ndis-status-wwan-register-state) notification.

## See also

[NDIS_WWAN_REGISTRATION_STATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndiswwan/ns-ndiswwan-_ndis_wwan_registration_state)

[WWAN_REGISTER_MODE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ne-wwan-_wwan_register_mode)

[WWAN_REGISTER_STATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ne-wwan-_wwan_register_state)