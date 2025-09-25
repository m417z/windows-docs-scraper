# IWDFInterrupt::SetPolicy

## Description

[**Warning:** UMDF 2 is the latest version of UMDF and supersedes UMDF 1. All new UMDF drivers should be written using UMDF 2. No new features are being added to UMDF 1 and there is limited support for UMDF 1 on newer versions of Windows 10. Universal Windows drivers must use UMDF 2. For more info, see [Getting Started with UMDF](https://learn.microsoft.com/windows-hardware/drivers/wdf/getting-started-with-umdf-version-2).]

The **SetPolicy** method specifies the interrupt priority, processor affinity, and affinity policy for a specified interrupt.

## Parameters

### `Policy` [in]

A [WDF_INTERRUPT_POLICY](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfinterrupt/ne-wudfinterrupt-_wdf_interrupt_policy)-typed enumerator that specifies a processor affinity policy for the interrupt.

### `Priority` [in]

A [WDF_INTERRUPT_PRIORITY](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfinterrupt/ne-wdfinterrupt-_wdf_interrupt_priority)-typed enumerator that specifies a priority for the interrupt.

### `TargetProcessorSet` [in]

A [**KAFFINITY**](https://learn.microsoft.com/windows-hardware/drivers/kernel/interrupt-affinity-and-priority#about-kaffinity)-typed value that specifies a processor affinity for the interrupt, if the *Policy* parameter is set to **WdfIrqPolicySpecifiedProcessors**.

## Remarks

Starting in Windows Vista, drivers can specify an interrupt's priority, processor affinity, and affinity policy. For more information about how to use the registry to override the values that **SetPolicy** sets, see [Interrupt Affinity and Priority](https://learn.microsoft.com/windows-hardware/drivers/kernel/interrupt-affinity-and-priority).

If a driver is running on an operating system version that is earlier than Windows Vista, the framework ignores the values that the driver specifies when it calls **SetPolicy**.

For more information about registry values and INF sections that specify an interrupt's priority, processor affinity, and affinity policy, see [Interrupt Affinity and Priority](https://learn.microsoft.com/windows-hardware/drivers/kernel/interrupt-affinity-and-priority).

If a driver calls **SetPolicy**, it must do so in its [IDriverEntry::OnDeviceAdd](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-idriverentry-ondeviceadd) callback function, after calling the [IWDFDevice3::CreateInterrupt](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfdevice3-createinterrupt) method.

For more information about handling interrupts in UMDF drivers, see [Accessing Hardware and Handling Interrupts](https://learn.microsoft.com/windows-hardware/drivers/wdf/accessing-hardware-and-handling-interrupts).

#### Examples

The following code example assigns a device interrupt to processor 0, with normal priority.

```
#define AFFINITY_MASK(n) ((ULONG_PTR)1 << (n))

pIWdfInterrupt->SetPolicy(
                          WdfIrqPolicySpecifiedProcessors,
                          WdfIrqPriorityNormal,
                          AFFINITY_MASK(0)
                          );

```

## See also

[IWDFInterrupt](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iwdfinterrupt)

[**KAFFINITY**](https://learn.microsoft.com/windows-hardware/drivers/kernel/interrupt-affinity-and-priority#about-kaffinity)

[WDF_INTERRUPT_POLICY](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfinterrupt/ne-wudfinterrupt-_wdf_interrupt_policy)

[WDF_INTERRUPT_PRIORITY](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfinterrupt/ne-wdfinterrupt-_wdf_interrupt_priority)