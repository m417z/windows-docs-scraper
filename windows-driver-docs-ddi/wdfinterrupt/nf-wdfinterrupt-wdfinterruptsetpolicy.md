# WdfInterruptSetPolicy function

## Description

[Applies to KMDF and UMDF]

The **WdfInterruptSetPolicy** method specifies the interrupt priority, processor affinity, and affinity policy for a specified interrupt.

## Parameters

### `Interrupt` [in]

A handle to a framework interrupt object.

### `Policy` [in]

A [WDF_INTERRUPT_POLICY](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfinterrupt/ne-wdfinterrupt-_wdf_interrupt_policy)-typed enumerator that specifies a processor affinity policy for the interrupt.

### `Priority` [in]

A [WDF_INTERRUPT_PRIORITY](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfinterrupt/ne-wdfinterrupt-_wdf_interrupt_priority)-typed enumerator that specifies a priority for the interrupt.

### `TargetProcessorSet` [in]

A [**KAFFINITY**](https://learn.microsoft.com/windows-hardware/drivers/kernel/interrupt-affinity-and-priority#about-kaffinity)-typed value that specifies a processor affinity for the interrupt, if the *Policy* parameter is set to **WdfIrqPolicySpecifiedProcessors**.

## Remarks

A bug check occurs if the driver supplies an invalid object handle.

Windows Vista and later versions of the operating system allow drivers to specify an interrupt's priority, processor affinity, and affinity policy. For information about how to use the registry to override the values that **WdfInterruptSetPolicy** sets, see [Interrupt Affinity and Priority](https://learn.microsoft.com/windows-hardware/drivers/kernel/interrupt-affinity-and-priority).

If a driver is running on an operating system version that is earlier than Windows Vista, the framework ignores the values that the driver specifies when it calls **WdfInterruptSetPolicy**.

For more information about registry values and INF sections that specify an interrupt's priority, processor affinity, and affinity policy, see [Interrupt Affinity and Priority](https://learn.microsoft.com/windows-hardware/drivers/kernel/interrupt-affinity-and-priority).

If a driver calls **WdfInterruptSetPolicy**, it typically does so in its [EvtDriverDeviceAdd](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdriver/nc-wdfdriver-evt_wdf_driver_device_add) callback function, after calling [WdfInterruptCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfinterrupt/nf-wdfinterrupt-wdfinterruptcreate).

If your driver creates interrupts in [EvtDevicePrepareHardware](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdf_device_prepare_hardware), do not use **WdfInterruptSetPolicy** or [WdfInterruptSetExtendedPolicy](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfinterrupt/nf-wdfinterrupt-wdfinterruptsetextendedpolicy). Instead, apply policy in [EvtDeviceFilterAddResourceRequirements](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdffdo/nc-wdffdo-evt_wdf_device_filter_resource_requirements), by directly manipulating the interrupt resource requirement that this callback function receives in its *IoResourceRequirementsList* parameter.

For more information about handling interrupts in framework-based drivers, see [Handling Hardware Interrupts](https://learn.microsoft.com/windows-hardware/drivers/wdf/handling-hardware-interrupts).

#### Examples

The following code example assigns a device interrupt to processor 0, with normal priority.

```cpp
#define AFFINITY_MASK(n) ((ULONG_PTR)1 << (n))

WdfInterruptSetPolicy(
                      Interrupt,
                      WdfIrqPolicySpecifiedProcessors,
                      WdfIrqPriorityNormal,
                      AFFINITY_MASK(0)
                      );
```

## See also

[EvtDriverDeviceAdd](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdriver/nc-wdfdriver-evt_wdf_driver_device_add)

[WdfInterruptCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfinterrupt/nf-wdfinterrupt-wdfinterruptcreate)

[WdfInterruptSetExtendedPolicy](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfinterrupt/nf-wdfinterrupt-wdfinterruptsetextendedpolicy)