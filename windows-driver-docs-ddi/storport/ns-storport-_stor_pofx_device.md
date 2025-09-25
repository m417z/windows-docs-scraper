# _STOR_POFX_DEVICE structure

## Description

The **STOR_POFX_DEVICE** structure describes the power attributes of a storage device to the power management framework (PoFx).

## Members

### `Version`

The version number of this structure. Set this member to **STOR_POFX_DEVICE_VERSION_V1**.

### `Size`

The size of this structure. Set this value to **STOR_POFX_DEVICE_SIZE**.

### `ComponentCount`

The number of elements in the **Components** array. Set this member to 1. Currently, only a single component is supported for either a storage adapter or logical unit.

### `Flags`

The device power state capabilities flags. The miniport sets one or more of the PoFx device flags to enable or disable power state capabilities.

**Flags** is a bitwise OR combination of the following.

| Value | Meaning |
| --- | --- |
| **STOR_POFX_DEVICE_FLAG_DISABLE_INTERRUPTS_ON_D3** | Specifies that, when set, Storport will disable interrupts when putting the Adapter to D3 and will reactivate interrupts when resuming to D0. |
| **STOR_POFX_DEVICE_FLAG_ENABLE_D3_COLD** | Enables Storport to set the D3 Cold state for the adapter if it supports it. This flag applies to adapters only. |
| **STOR_POFX_DEVICE_FLAG_NO_D0** | Requests that a power up IRP not be sent to the device object for the adapter or unit. |
| **STOR_POFX_DEVICE_FLAG_NO_D3** | Requests that a power down IRP not be sent to the device object for the adapter or unit. |
| **STOR_POFX_DEVICE_FLAG_NO_DUMP_ACTIVE** | The miniport is not able to bring the storage device active in dump mode if the device has entered the idle state or the power off when idle state. This flag indicates whether a device is available for dump when it is idle. |

### `Components`

This member is the first element in an array of one or more [STOR_POFX_COMPONENT](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/ns-storport-_stor_pofx_component) elements. If the array contains more than one element, the additional elements immediately follow the **STOR_POFX_DEVICE** structure. The array contains one element for each component in the device. Currently, storage devices have only one component so additional component structures are unnecessary.

## Remarks

To register a storage adapter for Storport PoFx support, the miniport driver calls [StorPortEnablePassiveInitialization](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportenablepassiveinitialization) in its [HwStorInitialize](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nc-storport-hw_initialize) routine and implements a [HwStorPassiveInitializeRoutine](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nc-storport-hw_passive_initialize_routine). The miniport calls [StorPortInitializePoFxPower](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportinitializepofxpower) within it's **HwStorPassiveInitializeRoutine** to provide information about the adapter component.

To register a storage unit for Storport PoFx support, the miniport driver implements the [HwStorUnitControl](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nc-storport-hw_unit_control) callback routine and provides handling of the **ScsiUnitPoFxPowerInfo** unit control code. When the handling the **ScsiUnitPoFxPowerInfo** control code, the miniport calls [StorPortInitializePoFxPower](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportinitializepofxpower) if idle power management for the unit component is enabled.

The component for the storage device identified by its **Components** array index. Storage devices have only one component so the index of 0 is used. Routines such as [StorPortPoFxActivateComponent](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportpofxactivatecomponent) and [StorPortPoFxIdleComponent](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportpofxidlecomponent) use the array index of a component to identify the component.

## See also

[STOR_POFX_COMPONENT](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/ns-storport-_stor_pofx_component)

[StorPortInitializePoFxPower](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportinitializepofxpower)

[StorPortPoFxActivateComponent](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportpofxactivatecomponent)

[StorPortPoFxIdleComponent](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportpofxidlecomponent)