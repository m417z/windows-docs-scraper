# HW_PASSIVE_INITIALIZE_ROUTINE callback function

## Description

The **HwStorPassiveInitializeRoutine** callback routine is called after the [**HwStorInitialize**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nc-storport-hw_initialize) routine when the current IRQL is at PASSIVE_LEVEL. The **HwStorPassiveInitializeRoutine** callback is set by calling the [**StorPortEnablePassiveInitialization**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportenablepassiveinitialization) routine. Initializing of the miniport's deferred procedure calls (DPCs) occurs in the **HwStorPassiveInitializeRoutine** callback.

## Parameters

### `DeviceExtension`

## Return value

The **HwStorPassiveInitializeRoutine** routine returns **TRUE** if the miniport successfully initialized the processing of DPCs, or **FALSE** if the initialization process failed.

## Remarks

The **HwStorPassiveInitializeRoutine** routine should initialize any DPCs that the miniport driver will use. The port driver calls **HwStorPassiveInitializeRoutine** at PASSIVE_LEVEL without any spin locks held. Interrupts are enabled while this routine is called.

The name **HwStorPassiveInitializeRoutine** is just a placeholder. The actual prototype for this callback routine is defined in *Storport.h* as follows:

``` c
typedef
BOOLEAN
(*PHW_PASSIVE_INITIALIZE_ROUTINE) (
  _In_ PVOID DeviceExtension
  );
```

The port driver calls the **HwStorPassiveInitializeRoutine** routine at PASSIVE IRQL without acquiring any spin locks.

### Examples

To define an **HwStorPassiveInitializeRoutine** callback function, you must first provide a function declaration that identifies the type of callback function you’re defining. Windows provides a set of callback function types for drivers. Declaring a function using the callback function types helps [Code Analysis for Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/code-analysis-for-drivers), [Static Driver Verifier](https://learn.microsoft.com/windows-hardware/drivers/devtest/static-driver-verifier) (SDV), and other verification tools find errors, and it’s a requirement for writing drivers for the Windows operating system.

 For example, to define a **HwStorPassiveInitializeRoutine** callback routine that is named **MyHwPassiveInitialize**, use the **HW_PASSIVE_INITIALIZE_ROUTINE** type as shown in this code example:

``` c
HW_PASSIVE_INITIALIZE_ROUTINE MyHwPassiveInitialize;
```

Then, implement your callback routine as follows:

``` c
_Use_decl_annotations_
BOOLEAN
MyHwPassiveInitialize (
  _In_ PVOID  DeviceExtension
  );
  {
      ...
  }
```

The **HW_PASSIVE_INITIALIZE_ROUTINE** function type is defined in the Storport.h header file. To more accurately identify errors when you run the code analysis tools, be sure to add the _Use_decl_annotations_ annotation to your function definition. The _Use_decl_annotations_ annotation ensures that the annotations that are applied to the **HW_PASSIVE_INITIALIZE_ROUTINE** function type in the header file are used. For more information about the requirements for function declarations, see [Declaring Functions Using Function Role Types for Storport Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/declaring-functions-by-using-function-role-types-for-storport-drivers). For information about _Use_decl_annotations_, see [Annotating Function Behavior](https://learn.microsoft.com/visualstudio/code-quality/annotating-function-behavior).

## See also

[**HwStorInitialize**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nc-storport-hw_initialize)

[**StorPortEnablePassiveInitialization**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportenablepassiveinitialization)