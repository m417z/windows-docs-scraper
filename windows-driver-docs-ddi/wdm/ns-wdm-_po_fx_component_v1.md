# _PO_FX_COMPONENT_V1 structure

## Description

The **PO_FX_COMPONENT** structure describes the power state attributes of a component in a device.

## Members

### `Id`

A component ID that uniquely identifies this component with respect to the other components in the device. The driver should specify a nonzero value for this member if the power management framework (PoFx) requires a component ID to distinguish this component from other, similar components in the same device. This member is optional. If this member is not used, it must be set to all zeros.

### `IdleStateCount`

The number of elements in the array that is pointed to by the **IdleStates** member. Additionally, this member specifies the number of Fx power states that the component supports. A component must support at least one Fx state (F0).

### `DeepestWakeableIdleState`

The index of the deepest Fx state from which the component can wake. Specify 0 for F0, 1 for F1, and so on. This index must be less than **IdleStateCount**.

### `IdleStates`

A pointer to a [PO_FX_COMPONENT_IDLE_STATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_po_fx_component_idle_state) array. The length of this array is specified by the **IdleStateCount** member. Each array element specifies the attributes of an Fx power state that is supported by the component. Element 0 describes F0, element 1 describes F1, and so on.

## Remarks

When a device driver registers a device with PoFx, the driver supplies a [PO_FX_DEVICE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_po_fx_device_v1) structure that holds the registration information. This structure contains an array of **PO_FX_COMPONENT** structures. The elements in this array describe the power attributes of the individual components in the device. PoFx uses the information in this array to manage the power settings of these components.

The **Id** member contains a component ID that PoFx can use to uniquely identify a component. Do not confuse the component ID with the component index, which a routine such as [PoFxActivateComponent](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-pofxactivatecomponent) uses to identify a component in a registered device. A component index is an index into the **Components** array in the **PO_FX_DEVICE** structure that the device driver used to register the device with PoFx. If the **Components** array contains N elements, component indexes are integer values in the range 0 to N–1. In contrast, a component ID is a GUID value.

The **Flags** member may be set to the **PO_FX_COMPONENT_FLAG_F0_ON_DX** value if the driver specified support for **PO_FX_VERSION_V2** during registration with PoFx (that is, during the call to the [PoFxRegisterDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-pofxregisterdevice) routine, the driver specified the value **PO_FX_VERSION_V2** for the **Version** member of the [PO_FX_DEVICE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_po_fx_device_v1) structure that was passed to the *Device* parameter). If the **PO_FX_COMPONENT_FLAG_F0_ON_DX** flag is specified, PoFx will place the component into the F0 power state during Dx transitions and for wait/wake IRPs.
Before dispatching a Dx IRP or wait/wake IRP to the device stack (whichever event happens first), the power manager will transition the component into the F0 state. The component will be kept in F0 until the wake/wait IRP is canceled or completed, or the Dx IRP is completed and driver has called the [PoFxReportDevicePoweredOn](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-pofxreportdevicepoweredon) routine (whichever event happens last).

### Component dependencies

PoFx supports logical component dependencies within a device (but not across different devices). During device registration for each component, the driver can supply a number (the *ProviderCount* member) and an array of component indexes (the *Providers* member) this component depends on; these are known as *providers*. PoFx guarantees that the component will not become active until all of its providers are active.

Component dependencies form a directed graph where an edge points from a dependent component to a provider and represents a dependency. During device registration, PoFx validates the dependency graph: cycles and repeated edges are not allowed and the depth of the graph for the depth-first search traversal cannot exceed four. PoFx also sets the components’ active reference count according to the dependency graph; that is, each provider’s active reference count is incremented once for each component that depends on it.

During the component activation, PoFx asynchronously activates all providers first. After a component is active, PoFx checks every dependent component and continues their activation if necessary.

When the component transitions to the idle state, PoFx first makes the dependent components idle. After the driver completes the [ComponentIdleConditionCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-po_fx_component_idle_condition_callback) and the platform extension plug-in (PEP) is notified that the component is idle, PoFx recursively traverses the dependency graph in breadth-first traversal and asynchronously idles each provider.

## See also

[Component-Level Power Management](https://learn.microsoft.com/windows-hardware/drivers/kernel/component-level-power-management)

[PO_FX_COMPONENT_IDLE_STATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_po_fx_component_idle_state)

[PO_FX_DEVICE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_po_fx_device_v1)