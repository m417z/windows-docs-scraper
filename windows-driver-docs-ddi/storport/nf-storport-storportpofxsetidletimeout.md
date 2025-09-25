## Description

A miniport can call **StorPortPoFxSetIdleTimeout** to set the idle timeout value for an adapter, which is the amount of time that an adapter can be idle before it gets the Device Power Not Required notification.

## Parameters

### `HwDeviceExtension`

[in] Pointer to the miniport's device extension.

### `Address`

[in] Must be set to NULL because this function is only supported for adapters. Do not pass in the address of a unit.

### `IdleTimeoutInMS`

The idle timeout interval to use, in milliseconds.

## Return value

**StorPortPoFxSetIdleTimeout** returns STOR_STATUS_SUCCESS if runtime power has been disabled or if the idle timeout value was set successfully. Otherwise, it returns an error code such as one of the following.

| Error code | Meaning |
| ---------- | ------- |
| STOR_STATUS_INVALID_PARAMETER | A unit address was passed in. |
| STOR_STATUS_UNSUCCESSFUL | The [**StorPortInitializePoFxPower**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportinitializepofxpower) function was not previously successfully called for the adapter, or an idle timeout value was not set. |

## Remarks

If the STOR_POFX_DEVICE_FLAG_IDLE_TIMEOUT flag was specified and the **AdapterIdleTimeoutInMS** set when the adapter was registered for runtime power management, that value will be overridden by **IdleTimeoutInMS** value passed to this function. See [**STOR_POFX_DEVICE_V3**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/ns-storport-_stor_pofx_device_v3) for information on how to register for runtime power management.

A miniport can only call this function if it previously called [**StorPortInitializePoFxPower**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportinitializepofxpower) for the adapter.

## See also

[**STOR_POFX_DEVICE_V3**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/ns-storport-_stor_pofx_device_v3)

[**StorPortInitializePoFxPower**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportinitializepofxpower)