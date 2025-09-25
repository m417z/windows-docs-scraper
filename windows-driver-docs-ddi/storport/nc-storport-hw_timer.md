# HW_TIMER callback function

## Description

The **HwStorTimer** routine is called after the interval that is specified when the miniport driver called [**StorPortNotification**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportnotification) with **RequestTimerCall** specified for the **NotificationType** parameter.

## Parameters

### `DeviceExtension`

A pointer to the miniport driver's per HBA storage area.

## Remarks

The name **HwStorTimer** is only a placeholder. The actual prototype of this routine is defined in *Srb.h* as follows:

``` c
typedef
VOID
HW_TIMER (
  _In_ PVOID  DeviceExtension
  );
```

If the miniport opts into multi-channel support, the StartIo spin lock is still taken. However, if the miniport has requested multiple channel support via [**PERF_CONFIGURATION_DATA**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/ns-storport-_perf_configuration_data), the StartIo spin lock is not taken or checked before the call to [**HwStorStartIo**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nc-storport-hw_startio) in the miniport. This means that the **HwStorStartIo** callback is not synchronized with the callback to the **HwStorTimer** routine when multi-channel support is used. The miniport must do this on its own by using a compiler interlocked intrinsic, for example using [**InterlockedCompareExchange**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-interlockedcompareexchange).

A **HwStorTimer** routine is optional.

To define an **HwStorTimer** callback function, you must first provide a function declaration that identifies the type of callback function you’re defining. Windows provides a set of callback function types for drivers. Declaring a function using the callback function types helps [Code Analysis for Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/code-analysis-for-drivers), [Static Driver Verifier](https://learn.microsoft.com/windows-hardware/drivers/devtest/static-driver-verifier) (SDV), and other verification tools find errors, and it’s a requirement for writing drivers for the Windows operating system.

 For example, to define a **HwStorTimer** callback routine that is named **MyHwTimer**, use the following **HW_TIMER** type and implement your callback routine as follows:

``` c
HW_TIMER MyHwTimer;

_Use_decl_annotations_
VOID
MyHwTimer (
  _In_ PVOID  DeviceExtension
  );
  {
      ...
  }
```

The **HW_TIMER** function type is defined in the Storport.h header file. To more accurately identify errors when you run the code analysis tools, be sure to add the _Use_decl_annotations_ annotation to your function definition. The _Use_decl_annotations_ annotation ensures that the annotations that are applied to the **HW_TIMER** function type in the header file are used. For more information about the requirements for function declarations, see [Declaring Functions Using Function Role Types for Storport Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/declaring-functions-by-using-function-role-types-for-storport-drivers). For information about _Use_decl_annotations_, see [Annotating Function Behavior](https://learn.microsoft.com/visualstudio/code-quality/annotating-function-behavior).

## See also

[**StorPortNotification**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportnotification)