# WdfInterruptSetExtendedPolicy function

## Description

[Applies to KMDF and UMDF]

The **WdfInterruptSetExtendedPolicy** method specifies the interrupt priority, processor affinity, affinity policy, and processor group for a specified interrupt.

## Parameters

### `Interrupt` [in]

A handle to a framework interrupt object.

### `PolicyAndGroup` [in]

A pointer to a [WDF_INTERRUPT_EXTENDED_POLICY](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfinterrupt/ns-wdfinterrupt-_wdf_interrupt_extended_policy) structure that the caller allocates and initializes.

## Remarks

A bug check occurs if the driver supplies an invalid object handle.

Windows Vista and later versions of the operating system allow drivers to use the [WdfInterruptSetPolicy](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfinterrupt/nf-wdfinterrupt-wdfinterruptsetpolicy) method to specify an interrupt's priority, processor affinity, and affinity policy. In addition, versions 1.9 and later of KMDF allow drivers to use the **WdfInterruptSetExtendedPolicy** method to specify an interrupt's priority, processor affinity, affinity policy, and processor group.

For information about how to use the registry to override the values that **WdfInterruptSetExtendedPolicy** sets, see [Interrupt Affinity and Priority](https://learn.microsoft.com/windows-hardware/drivers/kernel/interrupt-affinity-and-priority).

If a driver is running on an operating system version that is earlier than Windows 7, the framework ignores the value that the driver specifies for the processor group number when it calls **WdfInterruptSetExtendedPolicy**.

If a driver is running on an operating system version that is earlier than Windows Vista, the framework ignores all values that the driver specifies when it calls [WdfInterruptSetPolicy](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfinterrupt/nf-wdfinterrupt-wdfinterruptsetpolicy) or **WdfInterruptSetExtendedPolicy**.

For more information about registry values and INF sections that specify an interrupt's priority, processor affinity, and affinity policy, see [Interrupt Affinity and Priority](https://learn.microsoft.com/windows-hardware/drivers/kernel/interrupt-affinity-and-priority).

If a driver calls **WdfInterruptSetExtendedPolicy**, it typically does so in its [EvtDriverDeviceAdd](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdriver/nc-wdfdriver-evt_wdf_driver_device_add) callback function, after calling [WdfInterruptCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfinterrupt/nf-wdfinterrupt-wdfinterruptcreate).

If your driver creates interrupts in [EvtDevicePrepareHardware](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdf_device_prepare_hardware), do not use [WdfInterruptSetPolicy](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfinterrupt/nf-wdfinterrupt-wdfinterruptsetpolicy) or **WdfInterruptSetExtendedPolicy**. Instead, you can instead apply policy in [EvtDeviceFilterAddResourceRequirements](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdffdo/nc-wdffdo-evt_wdf_device_filter_resource_requirements), by directly manipulating the interrupt resource requirement that this callback function receives in its *IoResourceRequirementsList* parameter.

For more information about handling interrupts in framework-based drivers, see [Handling Hardware Interrupts](https://learn.microsoft.com/windows-hardware/drivers/wdf/handling-hardware-interrupts).

#### Examples

The following code example calls [WDF_INTERRUPT_EXTENDED_POLICY_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfinterrupt/nf-wdfinterrupt-wdf_interrupt_extended_policy_init) to initialize a [WDF_INTERRUPT_EXTENDED_POLICY](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfinterrupt/ns-wdfinterrupt-_wdf_interrupt_extended_policy) structure; sets values for the policy, priority, and target processor set; and calls **WdfInterruptSetExtendedPolicy**. The example sets normal priority for the interrupt and assigns the interrupt to processor 0 in processor group 2.

```cpp
#define AFFINITY_MASK(n) ((ULONG_PTR)1 << (n))

WDF_INTERRUPT_EXTENDED_POLICY myExtendedPolicy;

WDF_INTERRUPT_EXTENDED_POLICY_INIT(&myExtendedPolicy);
myExtendedPolicy.Policy = WdfIrqPolicySpecifiedProcessors;
myExtendedPolicy.Priority = WdfIrqPriorityNormal;
myExtendedPolicy.TargetProcessorSetAndGroup.Mask = AFFINITY_MASK(0);
myExtendedPolicy.TargetProcessorSetAndGroup.Group = 2;

WdfInterruptSetExtendedPolicy(
                              Interrupt,
                              &myExtendedPolicy
 );
```

## See also

[WdfInterruptSetPolicy](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfinterrupt/nf-wdfinterrupt-wdfinterruptsetpolicy)