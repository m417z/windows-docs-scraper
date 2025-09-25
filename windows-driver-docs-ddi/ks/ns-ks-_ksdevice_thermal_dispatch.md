# _KSDEVICE_THERMAL_DISPATCH structure

## Description

The **KSDEVICE_THERMAL_DISPATCH** structure is used by the miniport driver in the API call to register thermal notification callbacks. This structure contains the callback function pointers for active and passive cooling interfaces.

## Members

### `ActiveCooling`

The active thermal callback notification.

The routine is defined as follows:

```cpp
_IRQL_requires_max_(PASSIVE_LEVEL)
typedef
void
(*PFNKSDEVICETHERMALACTIVECOOLING)(
    _In_  PKSDEVICE KsDevice,
    _In_  BOOLEAN Engaged,
    _Out_ KSDEVICE_THERMAL_STATE* DeviceThermalState
);
```

#### KsDevice

[in] A [KSDEVICE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_ksdevice) object representing the device managed by KS.

#### Engaged

[in] Indicates whether to engage or disengage active cooling. If **TRUE**, the driver must engage active cooling (for example, by turning the fan on). If **FALSE**, the driver must disengage active cooling (for example, by turning the fan off).

#### DeviceThermalState

[out] Return value: Avstream-determined thermal state. If the state changes the pipeline is notified of the change. The pipeline notifies any app registered for thermal notifications.

### `PassiveCooling`

The passive thermal callback notification.

The routine is defined as follows:

```cpp
_IRQL_requires_max_(PASSIVE_LEVEL)
typedef
void
(*PFNKSDEVICETHERMALPASSIVECOOLING)(
    _In_  PKSDEVICE KsDevice,
    _In_  ULONG Percentage,
    _Out_ KSDEVICE_THERMAL_STATE* DeviceThermalState
);
```

#### KsDevice

[in] A [KSDEVICE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_ksdevice) object representing the device managed by KS.

#### Percentage

[in] The percentage of full performance at which the device is permitted to operate. A parameter value of 100 indicates that the device is under no cooling restrictions and can operate at full performance level. A parameter value of zero indicates that the device must operate at its lowest thermal level. A parameter value between 0 and 100 indicates the degree to which the device's performance must be throttled to reduce heat generation. This parameter value is a threshold that the device must not exceed.

#### DeviceThermalState

[out] Return value: Avstream-determined thermal state. If the state changes the pipeline is notified of the change. The pipeline notifies any app registered for thermal notifications.