# _WUDF_INTERRUPT_CONFIG structure

## Description

[**Warning:** UMDF 2 is the latest version of UMDF and supersedes UMDF 1. All new UMDF drivers should be written using UMDF 2. No new features are being added to UMDF 1 and there is limited support for UMDF 1 on newer versions of Windows 10. Universal Windows drivers must use UMDF 2. For more info, see [Getting Started with UMDF](https://learn.microsoft.com/windows-hardware/drivers/wdf/getting-started-with-umdf-version-2).]

 The **WUDF_INTERRUPT_CONFIG** structure contains configuration information for a device interrupt.

## Members

### `Size`

The size, in bytes, of this structure.

### `ShareVector`

A [WDF_TRI_STATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdftypes/ne-wdftypes-_wdf_tri_state)-typed value. If this value is **WdfTrue**, the interrupt vector can be shared. If the value is **WdfFalse**, the interrupt vector cannot be shared. If the value is **WdfDefault** and the interrupt is level-triggered, the Plug and Play manager uses the bus driver's value. If the value is **WdfDefault** and the interrupt is not level-triggered, the interrupt vector cannot be shared.

### `AutomaticSerialization`

A Boolean value that, if TRUE, indicates that the framework will synchronize execution of the interrupt object's [OnInterruptWorkItem](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfinterrupt/nc-wudfinterrupt-wudf_interrupt_workitem) callback function with other callback functions that use the framework's [callback synchronization](https://learn.microsoft.com/windows-hardware/drivers/wdf/specifying-a-callback-synchronization-mode) functionality. See Remarks for more information.

### `OnInterruptIsr`

A pointer to the driver's [OnInterruptIsr](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfinterrupt/nc-wudfinterrupt-wudf_interrupt_isr) callback function, or NULL.

### `OnInterruptEnable`

A pointer to the driver's [OnInterruptEnable](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfinterrupt/nc-wudfinterrupt-wudf_interrupt_enable) callback function, or NULL.

### `OnInterruptDisable`

A pointer to the driver's [OnInterruptDisable](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfinterrupt/nc-wudfinterrupt-wudf_interrupt_disable) callback function, or NULL.

### `OnInterruptWorkItem`

A pointer to the driver's [OnInterruptWorkItem](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfinterrupt/nc-wudfinterrupt-wudf_interrupt_workitem) callback function, or NULL.

### `InterruptRaw`

A pointer to the [CM_PARTIAL_RESOURCE_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_cm_partial_resource_descriptor) structure that describes the [raw resources](https://learn.microsoft.com/windows-hardware/drivers/wdf/raw-and-translated-resources) that the system assigned to the interrupt. This member is only used if the interrupt is created in the [OnPrepareHardware](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-ipnpcallbackhardware2-onpreparehardware) callback.

### `InterruptTranslated`

A pointer to the [CM_PARTIAL_RESOURCE_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_cm_partial_resource_descriptor) structure that describes the [translated resources](https://learn.microsoft.com/windows-hardware/drivers/wdf/raw-and-translated-resources) that the system assigned to the interrupt. This member is only used if the interrupt is created in the [OnPrepareHardware](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-ipnpcallbackhardware2-onpreparehardware) callback.

## Remarks

The **WUDF_INTERRUPT_CONFIG** structure is used as input to [IWDFDevice3::CreateInterrupt](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfdevice3-createinterrupt).

To initialize a **WUDF_INTERRUPT_CONFIG** structure, your driver should first call [WUDF_INTERRUPT_CONFIG_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfinterrupt/nf-wudfinterrupt-wudf_interrupt_config_init) and then fill in structure members that **WUDF_INTERRUPT_CONFIG_INIT** does not initialize.

Before setting **AutomaticSerialization** to TRUE, the driver must call [IWDFDeviceInitialize::SetLockingConstraint](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfdeviceinitialize-setlockingconstraint) with the *LockType* parameter set to **WdfDeviceLevel**.

Your driver should include Wudfwdm.h, which contains the definition of CM_PARTIAL_RESOURCE_DESCRIPTOR.

UMDF supports edge-triggered, line-based interrupts and message-signaled interrupts (MSI) on all framework-supported operating systems. Because these types of interrupt resources are not shared, a driver that uses them should set the **ShareVector** member of this structure to WdfFalse or WdfUseDefault. If the driver specifies an invalid **ShareVector** value, the driver fails to start.

## See also

[IWDFDevice3::CreateInterrupt](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfdevice3-createinterrupt)

[IWDFDeviceInitialize::SetLockingConstraint](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfdeviceinitialize-setlockingconstraint)

[WUDF_INTERRUPT_CONFIG_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfinterrupt/nf-wudfinterrupt-wudf_interrupt_config_init)