# HW_INTERRUPT callback function

## Description

The Storport driver calls the **HwStorInterrupt** routine after the HBA generates an interrupt request.

## Parameters

### `DeviceExtension`

A pointer to the miniport driver's per HBA storage area.

## Return value

If the miniport driver finds that its HBA did not generate the interrupt, **HwStorInterrupt** should return **FALSE** as soon as possible. The **HwStorInterrupt** routine should return within 50 microseconds.

## Remarks

The name **HwStorInterrupt** is just a placeholder. The actual prototype of this routine is defined in *Storport.h* as follows:

``` c
typedef
BOOLEAN
HW_INTERRUPT (
  IN PVOID  DeviceExtension
  );

```

The **HwStorInterrupt** routine should return within 50 microseconds, ideally as short a time as possible. Therefore, all activity does not have to occur at high IRQL should be deferred to the [**HwStorDpcRoutine**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nc-storport-hw_dpc_routine) that is defined in the miniport driver and issued by using [**StorPortIssueDpc**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportissuedpc). The latency of the DPC is very low, and it will be called immediately after the return from high IRQL.

The port driver calls the **HwStorInterrupt** routine at DIRQL.

### Examples

To define an **HwStorInterrupt** callback function, you must first provide a function declaration that identifies the type of callback function you’re defining. Windows provides a set of callback function types for drivers. Declaring a function using the callback function types helps [Code Analysis for Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/code-analysis-for-drivers), [Static Driver Verifier](https://learn.microsoft.com/windows-hardware/drivers/devtest/static-driver-verifier) (SDV), and other verification tools find errors, and it’s a requirement for writing drivers for the Windows operating system.

 For example, to define a **HwStorInterrupt** callback routine that is named **MyHwInterrupt**, use the **HW_INTERRUPT** type as shown in this code example:

``` c
HW_INTERRUPT MyHwInterrupt;
```

Then, implement your callback routine as follows:

``` c
_Use_decl_annotations_
BOOLEAN
MyHwInterrupt (
  _In_ PVOID  DeviceExtension
  );
  {
      ...
  }
```

The **HW_INTERRUPT** function type is defined in the Storport.h header file. To more accurately identify errors when you run the code analysis tools, be sure to add the _Use_decl_annotations_ annotation to your function definition. The _Use_decl_annotations_ annotation ensures that the annotations that are applied to the **HW_INTERRUPT** function type in the header file are used. For more information about the requirements for function declarations, see [Declaring Functions Using Function Role Types for Storport Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/declaring-functions-by-using-function-role-types-for-storport-drivers). For information about _Use_decl_annotations_, see [Annotating Function Behavior](https://learn.microsoft.com/visualstudio/code-quality/annotating-function-behavior).

## See also

[**HwStorDpcRoutine**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nc-storport-hw_dpc_routine)

[**StorPortIssueDpc**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportissuedpc)