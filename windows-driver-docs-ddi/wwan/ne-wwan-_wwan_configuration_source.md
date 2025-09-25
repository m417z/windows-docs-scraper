# _WWAN_CONFIGURATION_SOURCE enumeration

## Description

The **WWAN_CONFIGURATION_SOURCE** enumeration specifies the creation source of a provisioned context.

## Constants

### `WwanUserProvisioned`

The context was created by an end user through the OS settings.

### `WwanAdminProvisioned`

The context was created by an enterprise IT admin from the OS.

### `WwanOperatorProvisioned`

The context was created by the mobile operator through OMA-DM or other channels.

### `WwanDeviceProvisioned`

The context was created by the OS APN database.

### `WwanModemProvisioned`

The context was created by the IHV or OEM.

### `WwanMaxProvisionSource`

The maximum value for this enumeration.

### `WwanModemOperatorProvisioned`

The context was created by the modem operator.

## Remarks

This enum is used in the [**WWAN_CONTEXT_V2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-_wwan_context_v2) and [**WWAN_SET_CONTEXT_V2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-_wwan_set_context_v2) structures.

## See also

[**WWAN_CONTEXT_V2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-_wwan_context_v2)

[**WWAN_SET_CONTEXT_V2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-_wwan_set_context_v2)