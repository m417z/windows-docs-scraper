## Description

The *PowerCompletion* callback routine completes the processing of a power IRP.

## Parameters

### `DeviceObject` [in]

A pointer to the target [DEVICE_OBJECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_device_object) for the completed power IRP.

### `MinorFunction` [in]

Specifies the minor function code in the power IRP. For more information, see the list of supported **IRP_MN_*XXX*** codes in the Remarks section.

### `PowerState` [in]

Specifies the [device power state](https://learn.microsoft.com/windows-hardware/drivers/kernel/device-power-states) or [system power state](https://learn.microsoft.com/windows-hardware/drivers/kernel/system-power-states) that was passed to the [PoRequestPowerIrp](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-porequestpowerirp) routine.

### `Context` [in, optional]

A pointer to the context that was passed to **PoRequestPowerIrp**.

### `IoStatus` [in]

A pointer to the [IO_STATUS_BLOCK](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_io_status_block) structure for the completed IRP.

## Remarks

A driver that sends a power IRP might need to perform additional tasks after all other drivers have completed the IRP. If so, the sending driver should register a *PowerCompletion* callback routine during the call to the [PoRequestPowerIrp](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-porequestpowerirp) routine that allocates the IRP.

A driver's *PowerCompletion* callback routine is used only for [IRP_MJ_POWER](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mj-power) IRPs that have minor IRP codes of [IRP_MN_SET_POWER](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mn-set-power), [IRP_MN_QUERY_POWER](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mn-query-power), and [IRP_MN_WAIT_WAKE](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mn-wait-wake). For more information, see [Sending IRP_MN_QUERY_POWER or IRP_MN_SET_POWER for Device Power States](https://learn.microsoft.com/windows-hardware/drivers/kernel/sending-irp-mn-query-power-or-irp-mn-set-power-for-device-power-states) and [Wait/Wake Callback Routines](https://learn.microsoft.com/windows-hardware/drivers/kernel/wait-wake-callback-routines).

The I/O manager calls the sending driver's *PowerCompletion* routine only after the I/O manager has called all the [IoCompletion](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-io_completion_routine) routines that were set by other drivers as they passed the IRP down the stack. The *PowerCompletion* routine performs any additional tasks that the sender of the IRP requires after all other drivers have completed the IRP. The *PowerCompletion* routine should not free the IRP—the power manager does that.

The *PowerCompletion* routine is called at IRQL = PASSIVE_LEVEL or IRQL = DISPATCH_LEVEL.

### Examples

To define a *PowerCompletion* callback routine, you must first provide a function declaration that identifies the type of callback routine you're defining. Windows provides a set of callback function types for drivers. Declaring a function using the callback function types helps [Code Analysis for Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/code-analysis-for-drivers), [Static Driver Verifier](https://learn.microsoft.com/windows-hardware/drivers/devtest/static-driver-verifier) (SDV), and other verification tools find errors, and it's a requirement for writing drivers for the Windows operating system.

For example, to define a *PowerCompletion* callback routine that is named `MyPowerCompletion`, use the REQUEST_POWER_COMPLETE type as shown in this code example:

```cpp
REQUEST_POWER_COMPLETE MyPowerCompletion;
```

Then, implement your callback routine as follows:

```cpp
_Use_decl_annotations_
VOID
  MyPowerCompletion(
    PDEVICE_OBJECT DeviceObject,
    UCHAR MinorFunction,
    POWER_STATE PowerState,
    PVOID Context,
    PIO_STATUS_BLOCK IoStatus
    )
  {
      // Function body
  }
```

The REQUEST_POWER_COMPLETE function type is defined in the Wdm.h header file. To more accurately identify errors when you run the code analysis tools, be sure to add the `_Use_decl_annotations_` annotation to your function definition. The `_Use_decl_annotations_` annotation ensures that the annotations that are applied to the REQUEST_POWER_COMPLETE function type in the header file are used. For more information about the requirements for function declarations, see [Declaring Functions by Using Function Role Types for WDM Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/declaring-functions-using-function-role-types-for-wdm-drivers). For information about `_Use_decl_annotations_`, see [Annotating Function Behavior](https://learn.microsoft.com/visualstudio/code-quality/annotating-function-behavior).

## See also

[**DEVICE_OBJECT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_device_object)

[**IO_STATUS_BLOCK**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_io_status_block)

[IRP_MJ_POWER](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mj-power)

[IRP_MN_QUERY_POWER](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mn-query-power)

[IRP_MN_SET_POWER](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mn-set-power)

[IRP_MN_WAIT_WAKE](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mn-wait-wake)

[IoCompletion](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-io_completion_routine)

[PoRequestPowerIrp](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-porequestpowerirp)