# _WWAN_SET_REGISTER_STATE structure

## Description

The WWAN_SET_REGISTER_STATE structure represents the command to set the MB device's registration mode
and the network provider it should register with.

## Members

### `ProviderId`

A NULL-terminated numeric (0-9) string that represents the network provider identity.

For GSM-based networks, this string is a concatenation of a three-digit Mobile Country Code (MCC) and
a two or three-digit Mobile Network Code (MNC). GSM-based carriers may have more than one MNC, and hence
more than one
**ProviderId** .

For CDMA-based networks, this string is a five-digit System ID (SID). Generally, a CDMA-based carrier
has more than one SID. Typically, the carrier has one SID for each market, which is usually divided
geographically within a nation by regulations, such as Metropolitan Statistical Areas (MSA) in the
United States of America. Miniport drivers of CDMA-based devices must specify
WWAN_CDMA_DEFAULT_PROVIDER_ID if this information is not available.

### `RegisterAction`

The registration action that the miniport driver is requested to perform. If this member is set to
**WwanRegisterActionAutomatic**, the
**ProviderId** member should be ignored.

### `WwanDataClass`

A bitmap that represents the data access technologies that are preferred for a connection. For a
detailed list of values, see the
**WwanDataClass** member of
[WWAN_DEVICE_CAPS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-_wwan_device_caps).

When multiple data-classes are set as preferred, miniport drivers are expected register to the
highest available data-class technology that is currently visible. Miniport drivers should attempt to
register the best available data-class as requested. If the device cannot register the data-class
specified in this member, it should register the best available data-class.

## See also

[NDIS_WWAN_SET_REGISTER_STATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndiswwan/ns-ndiswwan-_ndis_wwan_set_register_state)

[WWAN_REGISTER_ACTION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ne-wwan-_wwan_register_action)