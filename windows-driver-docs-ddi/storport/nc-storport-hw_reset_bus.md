# HW_RESET_BUS callback function

## Description

The **HwStorResetBus** routine is called by the port driver to clear error conditions.

## Parameters

### `DeviceExtension`

A pointer to the miniport driver's per HBA storage area.

### `PathId`

Identifies the SCSI bus to be reset.

## Return value

If the bus is successfully reset, **HwStorResetBus** returns **TRUE**.

## Remarks

The name **HwStorResetBus** is just a placeholder. The actual prototype of this routine is defined in *Storport.h* as follows:

``` c
typedef
BOOLEAN
HW_RESET_BUS (
  _In_ PVOID  DeviceExtension,
  _In ULONG  PathId
  );
```

The port driver pauses all device IO queues for the adapter and then calls the **HwStorResetBus** routine at IRQL DISPATCH_LEVEL after acquiring the StartIo spin lock. A miniport driver is responsible for completing SRBs received by [**HwStorStartIo**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nc-storport-hw_startio) for **PathId** during this routine and setting their status to SRB_STATUS_BUS_RESET if necessary.

In addition to the StartIo spin lock being taken and subsequently released after **HwStorResetBus** returns, if the miniport has requested multiple channel support through PERF_CONFIGURATION_DATA, all channel tokens will be taken and, on return of the callback, released. This ensures that no IO’s are dispatched to [**HwStorStartIo**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nc-storport-hw_startio) during the reset bus phase.

### Examples

To define an **HwStorResetBus** callback function, you must first provide a function declaration that identifies the type of callback function you’re defining. Windows provides a set of callback function types for drivers. Declaring a function using the callback function types helps [Code Analysis for Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/code-analysis-for-drivers), [Static Driver Verifier](https://learn.microsoft.com/windows-hardware/drivers/devtest/static-driver-verifier) (SDV), and other verification tools find errors, and it’s a requirement for writing drivers for the Windows operating system.

 For example, to define a **HwStorResetBus** callback routine that is named **MyHwResetBus**, use the **HW_RESET_BUS** type as shown in this code example:

``` c
HW_RESET_BUS MyHwResetBus;
```

Then, implement your callback routine as follows:

``` c
_Use_decl_annotations_
BOOLEAN
MyHwResetBus (
  _In_ PVOID  DeviceExtension,
  _In_ ULONG  PahtId
  );
  {
      ...
  }
```

The **HW_RESET_BUS** function type is defined in the Storport.h header file. To more accurately identify errors when you run the code analysis tools, be sure to add the _Use_decl_annotations_ annotation to your function definition. The _Use_decl_annotations_ annotation ensures that the annotations that are applied to the **HW_RESET_BUS** function type in the header file are used. For more information about the requirements for function declarations, see [Declaring Functions Using Function Role Types for Storport Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/declaring-functions-by-using-function-role-types-for-storport-drivers). For information about _Use_decl_annotations_, see [Annotating Function Behavior](https://learn.microsoft.com/visualstudio/code-quality/annotating-function-behavior).