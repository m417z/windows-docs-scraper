# HW_FREE_ADAPTER_RESOURCES callback function

## Description

The **HwStorFreeAdapterResources** callback routine allows the Storport virtual miniport driver to free resources when the virtual adapter is being removed. This is the last callback routine for the adapter.

## Parameters

### `DeviceExtension`

A pointer to the virtual miniport driver's per-adapter storage area.

## Remarks

The name **HwStorFreeAdapterResources** is placeholder text for the actual routine name. The actual prototype of this routine is defined in *Storport.h* as follows:

``` c
typedef
VOID
(*PHW_FREE_ADAPTER_RESOURCES) (
  IN PVOID  DeviceExtension
  );
```

The port driver calls the Storport virtual miniport's **HwStorFreeAdapterResources** at PASSIVE_LEVEL.

### Examples

To define an **HwStorFreeAdapterResources** callback function, you must first provide a function declaration that identifies the type of callback function you’re defining. Windows provides a set of callback function types for drivers. Declaring a function using the callback function types helps [Code Analysis for Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/code-analysis-for-drivers), [Static Driver Verifier](https://learn.microsoft.com/windows-hardware/drivers/devtest/static-driver-verifier) (SDV), and other verification tools find errors, and it’s a requirement for writing drivers for the Windows operating system.

 For example, to define a **HwStorFreeAdapterResources** callback routine that is named **MyHwAdapterFreeResources**, use the **HW_FREE_ADAPTER_RESOURCES** type as shown in this code example:

``` c
HW_FREE_ADAPTER_RESOURCES MyHwAdapterFreeResources;
```

Then, implement your callback routine as follows:

``` c
_Use_decl_annotations_
VOID
MyHwAdapterFreeResources (
  _In_ PVOID  DeviceExtension
  );
  {
      ...
  }
```

The **HW_FREE_ADAPTER_RESOURCES** function type is defined in the *Storport.h* header file. To more accurately identify errors when you run the code analysis tools, be sure to add the _Use_decl_annotations_ annotation to your function definition. The _Use_decl_annotations_ annotation ensures that the annotations that are applied to the **HW_FREE_ADAPTER_RESOURCES** function type in the header file are used. For more information about the requirements for function declarations, see [Declaring Functions Using Function Role Types for Storport Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/declaring-functions-by-using-function-role-types-for-storport-drivers). For information about _Use_decl_annotations_, see [Annotating Function Behavior](https://learn.microsoft.com/visualstudio/code-quality/annotating-function-behavior).