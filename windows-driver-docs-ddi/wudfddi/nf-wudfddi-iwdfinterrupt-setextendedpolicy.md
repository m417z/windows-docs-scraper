# IWDFInterrupt::SetExtendedPolicy

## Description

[**Warning:** UMDF 2 is the latest version of UMDF and supersedes UMDF 1. All new UMDF drivers should be written using UMDF 2. No new features are being added to UMDF 1 and there is limited support for UMDF 1 on newer versions of Windows 10. Universal Windows drivers must use UMDF 2. For more info, see [Getting Started with UMDF](https://learn.microsoft.com/windows-hardware/drivers/wdf/getting-started-with-umdf-version-2).]

The **SetExtendedPolicy** method specifies the interrupt priority, processor affinity, affinity policy, and processor group for a specified interrupt.

## Parameters

### `PolicyAndGroup` [in]

A pointer to a caller-allocated [WDF_INTERRUPT_EXTENDED_POLICY](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfinterrupt/ns-wdfinterrupt-_wdf_interrupt_extended_policy) structure that the driver has previously initialized by calling [WDF_INTERRUPT_EXTENDED_POLICY_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfinterrupt/nf-wdfinterrupt-wdf_interrupt_extended_policy_init).

## Remarks

This method is equivalent to KMDF’s [WdfInterruptSetExtendedPolicy](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfinterrupt/nf-wdfinterrupt-wdfinterruptsetextendedpolicy). See the Remarks section of **WdfInterruptSetExtendedPolicy** for more information about this method.

If a driver is running on an operating system version that is earlier than Windows 7, the framework ignores the value that the driver specifies for the processor group number when it calls **SetExtendedPolicy**.

For more information about handling interrupts in UMDF drivers, see [Accessing Hardware and Handling Interrupts](https://learn.microsoft.com/windows-hardware/drivers/wdf/accessing-hardware-and-handling-interrupts).

#### Examples

The following code example calls [WDF_INTERRUPT_EXTENDED_POLICY_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfinterrupt/nf-wdfinterrupt-wdf_interrupt_extended_policy_init) to initialize a [WDF_INTERRUPT_EXTENDED_POLICY](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfinterrupt/ns-wdfinterrupt-_wdf_interrupt_extended_policy) structure; sets values for the policy, priority, and target processor set; and calls **SetExtendedPolicy**. The example sets normal priority for the interrupt and assigns the interrupt to processor 0 in processor group 2.

```

IWDFInterrupt* pInterrupt;

#define AFFINITY_MASK(n) ((ULONG_PTR)1 << (n))

WDF_INTERRUPT_EXTENDED_POLICY myExtendedPolicy;

WDF_INTERRUPT_EXTENDED_POLICY_INIT(&myExtendedPolicy);
myExtendedPolicy.Policy = WdfIrqPolicySpecifiedProcessors;
myExtendedPolicy.Priority = WdfIrqPriorityNormal;
myExtendedPolicy.TargetProcessorSetAndGroup.Mask = AFFINITY_MASK(0);
myExtendedPolicy.TargetProcessorSetAndGroup.Group = 2;

pInterrupt->SetExtendedPolicy(
                              &myExtendedPolicy
 );
```

## See also

[IWDFInterrupt](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iwdfinterrupt)

[WDF_INTERRUPT_EXTENDED_POLICY](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfinterrupt/ns-wdfinterrupt-_wdf_interrupt_extended_policy)

[WDF_INTERRUPT_EXTENDED_POLICY_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfinterrupt/nf-wdfinterrupt-wdf_interrupt_extended_policy_init)