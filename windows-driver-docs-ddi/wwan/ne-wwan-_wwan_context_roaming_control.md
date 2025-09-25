# _WWAN_CONTEXT_ROAMING_CONTROL enumeration

## Description

The **WWAN_CONTEXT_ROAMING_CONTROL** enumeration specifies which roaming conditions apply to a provisioned context in a mobile broadband (MBB) modem.

## Constants

### `WwanContextRoamingControlHomeOnly`

Indicates that this context is allowed to be used only on the home network.

### `WwanContextRoamingControlPartnerOnly`

Indicates that this context is allowed to be used only on partner roaming networks.

### `WwanContextRoamingControlNonPartnerOnly`

Indicates that this context is allowed to be used only on non-partner roaming networks.

### `WwanContextRoamingControlHomeAndPartner`

Indicates that this context is allowed to be used only on both the home network and on partner roaming networks.

### `WwanContextRoamingControlHomeAndNonPartner`

Indicates that this context is allowed to be used only on both the home network and on non-partner roaming networks.

### `WwanContextRoamingControlPartnerAndNonPartner`

Indicates that this context is allowed to be used only on both partner and non-partner roaming networks.

### `WwanContextRoamingControlAllowAll`

Indicates that this context is allowed on all networks.

### `WwanContextRoamingControlMaximum`

The maximum value for this enumeration.

## Remarks

This enumeration is used in the [**WWAN_CONTEXT_V2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-_wwan_context_v2) and [**WWAN_SET_CONTEXT_V2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-_wwan_set_context_v2) structures.

## See also

[**WWAN_CONTEXT_V2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-_wwan_context_v2)

[**WWAN_SET_CONTEXT_V2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-_wwan_set_context_v2)