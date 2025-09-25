# _WWAN_PROVIDER structure

## Description

The WWAN_PROVIDER structure represents details about a network provider.

## Members

### `ProviderId`

A NULL-terminated numeric (0-9) string that represents the network provider identity.

For GSM-based networks, this string is a concatenation of a three-digit Mobile Country Code (MCC) and
a two or three-digit Mobile Network Code (MNC). GSM-based carriers may have more than one MNC, and hence
more than one
**ProviderId** .

For CDMA-based networks, this string is a five-digit System ID (SID). Generally a CDMA-based carrier
has more than one SID. Typically, the carrier has one SID for each market, which is usually divided
geographically within a nation by regulations, such as Metropolitan Statistical Areas (MSA) in the
United States of America. Miniport drivers of CDMA-based devices must specify
WWAN_CDMA_DEFAULT_PROVIDER_ID if this information is not available.

### `ProviderState`

A value that represents the various states that the network provider's entry can be tagged with.
The following table shows the possible values that miniport drivers should specify (one or more values
can be specified).

| Value | Meaning |
| --- | --- |
| WWAN_PROVIDER_STATE_HOME | The network provider is the home operator. |
| WWAN_PROVIDER_STATE_FORBIDDEN | The network provider is on the forbidden list. |
| WWAN_PROVIDER_STATE_PREFERRED | The network provider is on the preferred list. |
| WWAN_PROVIDER_STATE_VISIBLE | The network provider is visible. |
| WWAN_PROVIDER_STATE_REGISTERED | The network provider is currently registered by the device. |
| WWAN_PROVIDER_STATE_UNKNOWN | The network provider state is unknown. |

Some values in the previous table apply only to specific object identifiers (OIDs). The following
table shows the associations between those values and related OIDs.

| Value | OID |
| --- | --- |
| WWAN_PROVIDER_STATE_HOME | [OID_WWAN_HOME_PROVIDER](https://learn.microsoft.com/windows-hardware/drivers/network/oid-wwan-home-provider) |
| WWAN_PROVIDER_STATE_FORBIDDEN<br><br>WWAN_PROVIDER_STATE_PREFERRED | [OID_WWAN_PREFERRED_PROVIDERS](https://learn.microsoft.com/windows-hardware/drivers/network/oid-wwan-preferred-providers) |
| WWAN_PROVIDER_STATE_VISIBLE<br><br>WWAN_PROVIDER_STATE_REGISTERED<br><br>WWAN_PROVIDER_STATE_HOME<br><br>WWAN_PROVIDER_STATE_PREFERRED<br><br>WWAN_PROVIDER_STATE_FORBIDDEN | [OID_WWAN_VISIBLE_PROVIDERS](https://learn.microsoft.com/windows-hardware/drivers/network/oid-wwan-visible-providers) |

### `ProviderName`

A NULL-terminated string that represents the network provider's name. This member is limited to,
at most, WWAN_PROVIDERNAME_LEN characters.

For GSM-based networks, if the Preferred Presentation of Country Initials and Mobile Network Name
(PPCI&N) is longer than WWAN_PROVIDERNAME_LEN characters, the miniport driver should abbreviate the
network name.

This member is ignored when the MB Service sets the preferred provider list.

Miniport drivers should specify a **NULL** string for devices that do not have this
information.

### `WwanDataClass`

A bitmap that represents the data-class(es) that the device supports. For a detailed list of
values, see the
**WwanDataClass** member of
[WWAN_DEVICE_CAPS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-_wwan_device_caps).

This member can be ignored when queried for OID_WWAN_HOME_PROVIDER.

## See also

[NDIS_WWAN_HOME_PROVIDER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndiswwan/ns-ndiswwan-_ndis_wwan_home_provider)

[NDIS_WWAN_PREFERRED_PROVIDERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndiswwan/ns-ndiswwan-_ndis_wwan_preferred_providers)

[NDIS_WWAN_VISIBLE_PROVIDERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndiswwan/ns-ndiswwan-_ndis_wwan_visible_providers)

[WWAN_DEVICE_CAPS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-_wwan_device_caps)