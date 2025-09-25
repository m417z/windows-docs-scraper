# STOR_POFX_COMPONENT_V2 structure

## Description

The **STOR_POFX_COMPONENT_V2** structure describes the power state attributes of a storage device component.

## Members

### `Version`

The version number of this structure. Set this member to **STOR_POFX_DEVICE_VERSION_V2**.

### `Size`

The size of this structure. Set this value to **STOR_POFX_COMPONENT_V2_SIZE**.

### `FStateCount`

The number of elements in the array that is pointed to by the **FStates** member. Additionally, this member specifies the number of functional power states (F-state) that the component supports. A component must support at least one F-state (F0).

### `DeepestWakeableFState`

The index of the deepest F-state from which the component can wake. Specify 0 for F0, 1 for F1, and so on. This index must be less than **FStateCount**.

### `Id`

A component ID that uniquely identifies this component with respect to the other components in the device. The driver should specify a nonzero value for this member if the power management framework (PoFx) requires a component ID to distinguish this component from other, similar components in the same device. The component IDs supported by Storport are STORPORT_POFX_ADAPTER_GUID (identifies an adapter) and STORPORT_POFX_LUN_GUID (identifies a unit).

### `DeepestAdapterPowerRequiredFState`

The deepest F-State that this component can be in where the adapter still requires power. This is only relevant for components whose ID is STOR_POFX_LUN_GUID.

### `DeepestCrashDumpReadyFState`

The deepest F-State that the component can be in where the miniport can power up the component in the event a crash occurs and a crash dump needs to be written.

### `FStates`

An array of [**STOR_POFX_COMPONENT_IDLE_STATE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/ns-storport-_stor_pofx_component_idle_state) structures. The length of this array is specified by the **FStateCount** member. Each array element specifies the attributes of an F-state that is supported by the component. Element 0 describes F0, element 1 describes F1, and so on. When more than one idle state structure is required, the additional structures are allocated at the end of the **STOR_ POFX_COMPONENT_V2** structure and the **FStateCount** is set to 1, which is the value of ANYSIZE_ARRAY, plus the count of the additional structures.

## Remarks

When a miniport driver registers a device with the Storport power management framework, the miniport driver supplies a [**STOR_POFX_DEVICE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/ns-storport-_stor_pofx_device) structure that holds the registration information. This structure contains an array of **STOR_ POFX_COMPONENT** structures. The elements in this array describe the power attributes of the individual components in the device. The power settings of these components are managed based on the information in this array.

The **Id** member contains a component ID that uniquely identifies a component. The component ID is not the same as the component index, which a routine such as [**StorPortPoFxActivateComponent**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportpofxactivatecomponent) uses to identify a component in a registered device. A component index is an index into the **Components** array in the STOR_POFX_DEVICE structure that the device driver used to register the device. If the **Components** array contains N elements, component indexes are integer values in the range 0 to N–1. In contrast, a component ID is a GUID value.

The ID for the single adapter device component is defined in *storport.h* as STORPORT_POFX_ADAPTER_GUID. The ID for the single unit device component is STORPORT_POFX_LUN_GUID. Use these identifiers when describing either an adapter component or a unit component in the **Id** member.

The F-state requirements are as follows:

* For an adapter device component, the miniport must specify a single component and up to eight F-states for the adapter. [**StorPortInitializePoFxPower**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportinitializepofxpower) should be called by the miniport only within the context of the miniport's passive initialization routine.
* For a unit device component, the miniport must specify a single component for the unit, and can specify up to two F-states. The unit device must have the F0 state specified and can optionally have one additional F-state. **StorPortInitializePoFxPower** should be called by the miniport only within the context of the miniport's [**ScsiUnitPoFxPowerInfo** Unit Control](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nc-storport-hw_unit_control).

For a unit device component, if an additional F-state is included in the **FStates** array, the size member remains set to **STOR_POFX_COMPONENT_SIZE** and does not include the size of the additional [**STOR_POFX_COMPONENT_IDLE_STATE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/ns-storport-_stor_pofx_component_idle_state) structure.

## See also

[**HW_UNIT_CONTROL**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nc-storport-hw_unit_control)

[**STOR_POFX_COMPONENT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/ns-storport-_stor_pofx_component)

[**STOR_POFX_COMPONENT_IDLE_STATE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/ns-storport-_stor_pofx_component_idle_state)

[**STOR_POFX_DEVICE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/ns-storport-_stor_pofx_device)

[**StorPortInitializePoFxPower**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportinitializepofxpower)

[**StorPortPoFxActivateComponent**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportpofxactivatecomponent)