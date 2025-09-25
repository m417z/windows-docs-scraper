## Description

The *ComponentIdleConditionCallback* callback routine notifies the driver that the specified component completed a transition from the active condition to the idle condition.

## Parameters

### `Context` [in]

A pointer to the device context. The device driver uses this context to store information about the current power state of the device. The device driver specified this pointer in the **DeviceContext** member of the [**PO_FX_DEVICE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_po_fx_device_v1) structure that the driver used to register the device with the power management framework (PoFx). This context is opaque to PoFx.

### `Component` [in]

The index that identifies the component. This parameter is an index into the **Components** array in the **PO_FX_DEVICE** structure that the device driver used to register the device with PoFx. If the **Components** array contains N elements, component indexes range from 0 to N–1.

## Remarks

When the driver no longer needs to access a component that is in the active condition, the driver should call the [PoFxIdleComponent](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-pofxidlecomponent) routine to switch the component to the idle condition. In response to the **PoFxIdleComponent** call, PoFx initiates the transition to the idle condition, and then calls the *ComponentIdleConditionCallback* routine to notify the driver when this transition is complete.

The driver must call **PoFxCompleteIdleCondition** in response to every *ComponentIdleConditionCallback* callback. The **PoFxCompleteIdleCondition** call can occur either during the *ComponentIdleConditionCallback* callback or after the callback returns. The driver should complete any work that requires access to the hardware component before the call to **PoFxCompleteIdleCondition**. After this call, the component might not stay in the F0 power state.

A component can be safely accessed only when the component is in the active condition. Do not rely on the Fx power state of a component to determine whether the component can be accessed. If the component is in the F0 state and is in the idle condition, the component might be about to switch to another Fx state.

### Examples

To define a *ComponentIdleConditionCallback* callback routine, you must first provide a function declaration that identifies the type of callback routine you're defining. Windows provides a set of callback function types for drivers. Declaring a function using the callback function types helps [Code Analysis for Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/code-analysis-for-drivers), [Static Driver Verifier](https://learn.microsoft.com/windows-hardware/drivers/devtest/static-driver-verifier) (SDV), and other verification tools find errors, and it's a requirement for writing drivers for the Windows operating system.

For example, to define a *ComponentIdleConditionCallback* callback routine that is named `MyComponentIdleConditionCallback`, use the PO_FX_COMPONENT_IDLE_CONDITION_CALLBACK type as shown in this code example:

```cpp
PO_FX_COMPONENT_IDLE_CONDITION_CALLBACK MyComponentIdleConditionCallback;
```

Then, implement your callback routine as follows:

```cpp
_Use_decl_annotations_
VOID
  MyComponentIdleConditionCallback(
    PVOID Context,
    ULONG Component
    )
  {
      // Function body
  }
```

The PO_FX_COMPONENT_IDLE_CONDITION_CALLBACK function type is defined in the Wdm.h header file. To more accurately identify errors when you run the code analysis tools, be sure to add the `_Use_decl_annotations_` annotation to your function definition. The `_Use_decl_annotations_` annotation ensures that the annotations that are applied to the PO_FX_COMPONENT_IDLE_CONDITION_CALLBACK function type in the header file are used. For more information about the requirements for function declarations, see [Declaring Functions by Using Function Role Types for WDM Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/declaring-functions-using-function-role-types-for-wdm-drivers). For information about `_Use_decl_annotations_`, see [Annotating Function Behavior](https://learn.microsoft.com/visualstudio/code-quality/annotating-function-behavior).

## See also

[**PO_FX_DEVICE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_po_fx_device_v1)

[PoFxCompleteIdleCondition](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-pofxcompleteidlecondition)