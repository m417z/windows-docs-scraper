# CM_Power_Data_s structure (ntpoapi.h)

## Description

The **CM_POWER_DATA** structure contains information about a device's power management state and capabilities.

## Members

### `PD_Size`

The size, in bytes, of this structure.

### `PD_MostRecentPowerState`

A [DEVICE_POWER_STATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/ne-wudfddi-_device_power_state) value representing the device's most recent power state.

### `PD_Capabilities`

The device's power capabilities, represented by a combination of the following bit flags:

PDCAP_D0_SUPPORTED

PDCAP_D1_SUPPORTED

PDCAP_D2_SUPPORTED

PDCAP_D3_SUPPORTED

PDCAP_WAKE_FROM_D0_SUPPORTED

PDCAP_WAKE_FROM_D1_SUPPORTED

PDCAP_WAKE_FROM_D2_SUPPORTED

PDCAP_WAKE_FROM_D3_SUPPORTED

PDCAP_WARM_EJECT_SUPPORTED

### `PD_D1Latency`

The device's latency when returning the D0 state from the D1 state. For more information, see the **D1Latency** member of [DEVICE_CAPABILITIES](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_device_capabilities).

### `PD_D2Latency`

The device's latency when returning the D0 state from the D2 state. For more information, see the **D2Latency** member of **DEVICE_CAPABILITIES**.

### `PD_D3Latency`

The device's latency when returning the D0 state from the D3 state. For more information, see the **D3Latency** member of **DEVICE_CAPABILITIES**.

### `PD_PowerStateMapping`

An array of **DEVICE_POWER_STATE** values representing the maximum device power state achievable for each system power state. For more information, see the **DeviceState** member of [DEVICE_CAPABILITIES](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_device_capabilities).

### `PD_DeepestSystemWake`

Specifies the least-powered system state from which the device can wake the system. **PD_DeepestSystemWake** typically indicates one of the system sleeping states, S1, S2, or S3 (as specified by **PowerSystemSleeping1**, **PowerSystemSleeping2**, and **PowerSystemSleeping3**, respectively). Note, however, that some devices might be able to wake the system from the system hibernate state, S4 (as specified by **PowerSystemHibernate**), or even from the system shutdown state, S5 (as specified by **PowerSystemShutdown**).

## See also

[DEVICE_CAPABILITIES](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_device_capabilities)

[DEVICE_POWER_STATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/ne-wudfddi-_device_power_state)

[SetupDiGetDeviceRegistryProperty](https://learn.microsoft.com/windows/win32/api/setupapi/nf-setupapi-setupdigetdeviceregistrypropertya)