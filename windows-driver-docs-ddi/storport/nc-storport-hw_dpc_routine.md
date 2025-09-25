# HW_DPC_ROUTINE callback function

## Description

The **HwStorDpcRoutine** routine is a routine that is deferred for execution at DISPATCH IRQL by means of the deferred procedure call (DPC) mechanism.

## Parameters

### `Dpc`

A pointer to a Storport DPC context.

### `HwDeviceExtension`

A pointer to the per-adapter device extension.

### `SystemArgument1`

A pointer to caller-supplied information.

### `SystemArgument2`

A pointer to caller-supplied information.

## Remarks

When a miniport driver calls [**StorPortInitializeDpc**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportinitializedpc) to initialize a DPC it must load the **HwDpcRoutine** parameter of the **StorPortInitializeDpc** routine with a pointer to the **HwStorDpcRoutine** routine.

Any particular instance of a DPC routine is guaranteed to be synchronized with other instances of the DPC routine. A DPC routine can synchronize itself with the [**HwStorStartIo**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nc-storport-hw_startio) routine or with the [**HwStorInterrupt**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nc-storport-hw_interrupt) routine by acquiring the appropriate spin lock with a call to [**StorPortAcquireSpinLock**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportacquirespinlock). For more information about the management of spin locks within DPC routines, see [**StorPortIssueDpc**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportissuedpc).

The name **HwStorDpcRoutine** is just a placeholder. The actual prototype of this routine is defined in *storport.h* as follows:

``` c
typedef
BOOLEAN
HW_DPC_ROUTINE (
  _In_  PSTOR_DPC Dpc,
  _In_  PVOID HwDeviceExtension,
  _In_opt_  PVOID SystemArgument1,
  _In_opt_  PVOID SystemArgument2
  );
```

The port driver calls the **HwStorDpcRoutine** routine at DISPATCH IRQL.

### Examples

To define an **HwStorDpcRoutine** callback function, you must first provide a function declaration that identifies the type of callback function you’re defining. Windows provides a set of callback function types for drivers. Declaring a function using the callback function types helps [Code Analysis for Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/code-analysis-for-drivers), [Static Driver Verifier](https://learn.microsoft.com/windows-hardware/drivers/devtest/static-driver-verifier) (SDV), and other verification tools find errors, and it’s a requirement for writing drivers for the Windows operating system.

 For example, to define a **HwStorDpcRoutine** callback routine that is named **MyHwDpcRoutine**, use the **HW_DPC_ROUTINE** type as shown in this code example:

``` c
HW_DPC_ROUTINE MyHwDpcRoutine;
```

Then, implement your callback routine as follows:

``` c
_Use_decl_annotations_
BOOLEAN
MyHwDpcRoutine (
  _In_  PSTOR_DPC Dpc,
  _In_  PVOID HwDeviceExtension,
  _In_opt_  PVOID SystemArgument1,
  _In_opt_  PVOID SystemArgument2
  );
  {
      ...
  }
```

The **HW_DPC_ROUTINE** function type is defined in the Storport.h header file. To more accurately identify errors when you run the code analysis tools, be sure to add the _Use_decl_annotations_ annotation to your function definition. The _Use_decl_annotations_ annotation ensures that the annotations that are applied to the **HW_DPC_ROUTINE** function type in the header file are used. For more information about the requirements for function declarations, see [Declaring Functions Using Function Role Types for Storport Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/declaring-functions-by-using-function-role-types-for-storport-drivers). For information about _Use_decl_annotations_, see [Annotating Function Behavior](https://learn.microsoft.com/visualstudio/code-quality/annotating-function-behavior).

## See also

When a miniport driver calls to initialize a DPC it must load the **HwDpcRoutine** parameter of the **StorPortInitializeDpc** routine with a pointer to the **HwStorDpcRoutine** routine.

Any particular instance of a DPC routine is guaranteed to be synchronized with other instances of the DPC routine. A DPC routine can synchronize itself with the routine or with the routine by acquiring the appropriate spin lock with a call to . For more information about the management of spin locks within DPC routines, see .

[**HwStorInterrupt**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nc-storport-hw_interrupt)

[**HwStorStartIo**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nc-storport-hw_startio)

[**StorPortAcquireSpinLock**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportacquirespinlock)

[**StorPortInitializeDpc**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportinitializedpc)

[**StorPortIssueDpc**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportissuedpc)