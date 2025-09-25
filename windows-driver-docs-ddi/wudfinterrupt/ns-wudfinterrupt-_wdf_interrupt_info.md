# _WDF_INTERRUPT_INFO structure (wudfinterrupt.h)

## Description

[**Warning:** UMDF 2 is the latest version of UMDF and supersedes UMDF 1. All new UMDF drivers should be written using UMDF 2. No new features are being added to UMDF 1 and there is limited support for UMDF 1 on newer versions of Windows 10. Universal Windows drivers must use UMDF 2. For more info, see [Getting Started with UMDF](https://learn.microsoft.com/windows-hardware/drivers/wdf/getting-started-with-umdf-version-2).]

The [WDF_INTERRUPT_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfinterrupt/ns-wudfinterrupt-_wdf_interrupt_info) structure contains information about a device's interrupt resource.

## Members

### `Size`

The size, in bytes, of this structure.

### `Reserved1`

This member is reserved for future use.

### `TargetProcessorSet`

A [**KAFFINITY**](https://learn.microsoft.com/windows-hardware/drivers/kernel/interrupt-affinity-and-priority#about-kaffinity)-typed value that specifies the interrupt's processor affinity.

### `Reserved2`

This member is reserved for future use.

### `MessageNumber`

If the **MessageSignaled** member is TRUE, this is the interrupt's message number.

### `Vector`

The interrupt vector.

### `Irql`

The DIRQL at which the device interrupts.

### `Mode`

A [KINTERRUPT_MODE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ne-wdm-_kinterrupt_mode)-typed enumerator that indicates whether the interrupt is level-triggered or edge-triggered. The KINTERRUPT_MODE enumeration type is defined in Wudfwdm.h.

### `Polarity`

A [WDF_INTERRUPT_POLARITY](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfinterrupt/ne-wudfinterrupt-_wdf_interrupt_polarity)-typed enumerator that identifies the interrupt signal's polarity.

### `MessageSignaled`

A Boolean value that, if TRUE, indicates that the interrupt is message-signaled. If FALSE, the interrupt is not message-signaled.

### `ShareDisposition`

A CM_SHARE_DISPOSITION-typed enumerator that indicates whether the interrupt is being shared. The value is **CmResourceShareShared** if the interrupt is being shared or **CmResourceShareDeviceExclusive** if the interrupt is not being shared. The CM_SHARE_DISPOSITION enumeration type is defined in Wudfwdm.h.

### `Group`

A value that identifies the processor group that the **TargetProcessorSet** member applies to. This value is zero if the computer has only one processor group or if the operating system does not support processor groups. The **Group** member is available in version 1.9 and later versions of KMDF.

## Remarks

The [WDF_INTERRUPT_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfinterrupt/ns-wudfinterrupt-_wdf_interrupt_info) structure is used as input to the [IWDFInterrupt::GetInfo](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfinterrupt-getinfo) method. To initialize a **WDF_INTERRUPT_INFO** structure, your driver should call [WDF_INTERRUPT_INFO_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfinterrupt/nf-wudfinterrupt-wdf_interrupt_info_init) before calling **IWDFInterrupt::GetInfo**.

## See also

[IWDFInterrupt::GetInfo](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfinterrupt-getinfo)

[**KAFFINITY**](https://learn.microsoft.com/windows-hardware/drivers/kernel/interrupt-affinity-and-priority#about-kaffinity)

[KINTERRUPT_MODE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ne-wdm-_kinterrupt_mode)

[WDF_INTERRUPT_INFO_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfinterrupt/nf-wudfinterrupt-wdf_interrupt_info_init)

[WDF_INTERRUPT_POLARITY](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfinterrupt/ne-wudfinterrupt-_wdf_interrupt_polarity)