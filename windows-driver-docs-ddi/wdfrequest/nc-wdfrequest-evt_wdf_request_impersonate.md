# EVT_WDF_REQUEST_IMPERSONATE callback function

## Description

[Applies to UMDF only]

A driver's *EvtRequestImpersonate* event callback function performs tasks at the requested impersonation level, such as opening a protected file.

## Parameters

### `Request` [in]

A handle to a framework request object that represents the I/O request that requires impersonation.

### `Context` [in, optional]

A pointer to a context that was previously supplied in the [WdfRequestImpersonate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestimpersonate) method. This parameter is optional and can be NULL if a context is not required.

## Remarks

User-Mode Driver Framework (UMDF) does not allow a driver's *EvtRequestImpersonate* callback function to call any of the framework's object methods. This ensures that the driver does not expose the impersonation level to other driver callback functions or other drivers.

The **EVT_WDF_REQUEST_IMPERSONATE** function type is defined in the Wdfrequest.h header file. To more accurately identify errors when you run the code analysis tools, be sure to add the `_Use_decl_annotations_` annotation to your function definition. The `_Use_decl_annotations_` annotation ensures that the annotations that are applied to the **EVT_WDF_REQUEST_IMPERSONATE** function type in the header file are used.

The following restrictions also apply:

 - When the driver calls [**WdfRequestImpersonate**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestimpersonate) with `ImpersonationLevel = SecurityIdentification`, the callback cannot call **LoadLibrary** or perform any action requiring an access check.

 - The same principle applies to DLL delay load. Consider an example in which the driver impersonates at identification level, and the callback calls **GetUserNameW**. Because this API in turn delay loads another DLL and calls **GetUserNameExW**, the initial call might fail with **ERROR_PROC_NOT_FOUND** or **ERROR_BAD_IMPERSONATION_LEVEL**. In such a case, the callback should instead call **GetUserNameExW** directly.

For more information, see [Handling Client Impersonation in UMDF Drivers](https://learn.microsoft.com/windows-hardware/drivers/wdf/handling-client-impersonation-in-umdf-drivers).

#### Examples

To define an *EvtRequestImpersonate* callback function, you must first provide a function declaration that identifies the type of callback function you’re defining. Windows provides a set of callback function types for drivers. Declaring a function using the callback function types helps [Code Analysis for Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/code-analysis-for-drivers), [Static Driver Verifier](https://learn.microsoft.com/windows-hardware/drivers/devtest/static-driver-verifier) (SDV), and other verification tools find errors, and it’s a requirement for writing drivers for the Windows operating system.

For example, to define an *EvtRequestImpersonate* callback function that is named *MyRequestImpersonate*, use the **EVT_WDF_REQUEST_IMPERSONATE** type as shown in this code example:

```cpp
EVT_WDF_REQUEST_IMPERSONATE  MyRequestImpersonate;
```

Then, implement your callback function as follows:

```cpp
_Use_decl_annotations_
VOID
 MyRequestImpersonate (
    WDFREQUEST  Request
    PVOID  Context
    )
  {...}
```

For more information about the requirements for function declarations, see [Declaring Functions by Using Function Role Types for KMDF Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/declaring-functions-by-using-function-role-types-for-kmdf-drivers).

For information about _Use_decl_annotations_, see [Annotating Function Behavior](https://learn.microsoft.com/cpp/code-quality/annotating-function-behavior).

## See also

[WdfRequestImpersonate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestimpersonate)