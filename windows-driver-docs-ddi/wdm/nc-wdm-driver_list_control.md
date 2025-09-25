## Description

The *AdapterListControl* routine starts a direct memory access (DMA) scatter/gather operation.

## Parameters

### `DeviceObject` [in]

Caller-supplied pointer to a [DEVICE_OBJECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_device_object) structure. This is the device object for the target device, previously created by the driver's [AddDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-driver_add_device) routine.

### `Irp` [in]

Caller-supplied pointer to an [IRP](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_irp) structure that describes the I/O operation, if the driver has a [StartIo](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-driver_startio) routine. Otherwise, not used.

### `ScatterGather` [in]

Caller-supplied pointer to a [SCATTER_GATHER_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_scatter_gather_list) structure describing scatter/gather regions.

### `Context` [in]

Caller-supplied pointer to driver-defined context information, specified in a previous call to [AllocateAdapterChannel](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pallocate_adapter_channel).

## Remarks

To register an *AdapterListControl* routine for a specific device object, a driver must call [IoGetDmaAdapter](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iogetdmaadapter) to obtain an adapter object, then call [GetScatterGatherList](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-pget_scatter_gather_list) to request use of the adapter and to supply the *AdapterListControl* routine's address. When the adapter is free, the system calls the *AdapterListControl* routine.

### Examples

To define an *AdapterListControl* callback routine, you must first provide a function declaration that identifies the type of callback routine you're defining. Windows provides a set of callback function types for drivers. Declaring a function using the callback function types helps [Code Analysis for Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/code-analysis-for-drivers), [Static Driver Verifier](https://learn.microsoft.com/windows-hardware/drivers/devtest/static-driver-verifier) (SDV), and other verification tools find errors, and it's a requirement for writing drivers for the Windows operating system.

For example, to define an *AdapterListControl* callback routine that is named `MyAdapterListControl`, use the DRIVER_LIST_CONTROL type as shown in this code example:

```cpp
DRIVER_LIST_CONTROL MyAdapterListControl;
```

Then, implement your callback routine as follows:

```cpp
_Use_decl_annotations_
VOID
  MyAdapterListControl(
    struct _DEVICE_OBJECT  *DeviceObject,
    struct _IRP  *Irp,
    PSCATTER_GATHER_LIST  ScatterGather,
    PVOID  Context
    )
  {
      // Function body
  }
```

The DRIVER_LIST_CONTROL function type is defined in the Wdm.h header file. To more accurately identify errors when you run the code analysis tools, be sure to add the `_Use_decl_annotations_` annotation to your function definition. The `_Use_decl_annotations_` annotation ensures that the annotations that are applied to the DRIVER_LIST_CONTROL function type in the header file are used. For more information about the requirements for function declarations, see [Declaring Functions by Using Function Role Types for WDM Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/declaring-functions-using-function-role-types-for-wdm-drivers). For information about `_Use_decl_annotations_`, see [Annotating Function Behavior](https://learn.microsoft.com/visualstudio/code-quality/annotating-function-behavior).

For detailed information about implementing an *AdapterListControl* routine, see [Using Scatter/Gather DMA](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-scatter-gather-dma).