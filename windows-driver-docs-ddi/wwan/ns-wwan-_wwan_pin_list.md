# _WWAN_PIN_LIST structure

## Description

The WWAN_PIN_LIST structure represents a list of descriptions of Personal Identification Numbers
(PINs).

## Members

### `WwanPinDescPin1`

Description for PIN1. For GSM-based devices, this is a Subscriber Identity Module (SIM) PIN. For
CDMA-based devices, power-on device lock is reported as PIN1.

### `WwanPinDescPin2`

Description for PIN2. This is a SIM PIN2 that protects certain SIM functionality.

### `WwanPinDescDeviceSimPin`

Description for the device-to-SIM-card PIN. This is a PIN that locks the device to a specific
SIM.

### `WwanPinDescDeviceFirstSimPin`

Description for the device-to-very-first-SIM-card PIN. This is a PIN that locks the device to the
very first inserted SIM.

### `WwanPinDescNetworkPin`

Description for the network personalization PIN. This is a PIN that allows the device to be
personalized to a network. For more information about this PIN type, see section 22.022 of the 3GPP
specification.

### `WwanPinDescNetworkSubsetPin`

Description for network subset personalization PIN. This is a PIN that allows the device to be
personalized to a subset of a network. For more information about this PIN type, see section 22.022 of
the 3GPP specification.

### `WwanPinDescSvcProviderPin`

Description for Service Provider (SP) personalization PIN. This is a PIN that allows the device to
be personalized to a service provider. For more information about this PIN type, see section 22.022 of
the 3GPP specification.

### `WwanPinDescCorporatePin`

Description for corporate personalization PIN. This is a PIN that allows the device to be
personalized to a specific company. For more information about this PIN type, see section 22.022 of the
3GPP specification.

### `WwanPinDescSubsidyLock`

Description for subsidy unlock PIN. This is a PIN that allows the device to be restricted to
operate on a specific network. For more information about this PIN type, see section 22.022 of the 3GPP
specification.

### `WwanPinDescCustom`

Description for custom PIN. This is a custom vendor-defined PIN type. It is not included in the
above list.

## See also

[NDIS_WWAN_PIN_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndiswwan/ns-ndiswwan-_ndis_wwan_pin_list)

[WWAN_PIN_DESC](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-_wwan_pin_desc)