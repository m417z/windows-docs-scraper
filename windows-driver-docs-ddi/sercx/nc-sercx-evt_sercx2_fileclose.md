# EVT_SERCX2_FILECLOSE callback function

## Description

The *EvtSerCx2FileClose* event callback function is called by version 2 of the serial framework extension (SerCx2) to notify the serial controller driver that the client released the file object that represents the logical connection to the serial controller device.

## Parameters

### `Device` [in]

A WDFDEVICE handle to the framework device object that represents the serial controller. The serial controller driver created this object in its [EvtDriverDeviceAdd](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdriver/nc-wdfdriver-evt_wdf_driver_device_add) callback function. For more information, see [SerCx2InitializeDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nf-sercx-sercx2initializedevice).

## Remarks

Your serial controller driver can, as an option, implement this function. If implemented, the driver registers this function in the call to the [SerCx2InitializeDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nf-sercx-sercx2initializedevice) method that finishes the initialization of the framework device object for the serial controller.

For more information, see [Framework File Objects](https://learn.microsoft.com/windows-hardware/drivers/wdf/framework-file-objects).

#### Examples

To define an *EvtSerCx2FileClose* callback function, you must first provide a function declaration that identifies the type of callback function you're defining. Windows provides a set of callback function types for drivers. Declaring a function using the callback function types helps [Code Analysis for Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/code-analysis-for-drivers), [Static Driver Verifier](https://learn.microsoft.com/windows-hardware/drivers/devtest/static-driver-verifier) (SDV), and other verification tools find errors, and it's a requirement for writing drivers for the Windows operating system.

For example, to define an *EvtSerCx2FileClose* callback function that is named `MyFileClose`, use the **EVT_SERCX2_FILECLOSE** function type, as shown in this code example:

```cpp
EVT_SERCX2_FILECLOSE  MyFileClose;
```

Then, implement your callback function as follows:

```cpp
_Use_decl_annotations_
VOID
  MyFileClose(
    WDFDEVICE  Device
    )
  {...}
```

The **EVT_SERCX2_FILECLOSE** function type is defined in the Sercx.h header file. To more accurately identify errors when you run the code analysis tools, be sure to add the _Use_decl_annotations_ annotation to your function definition. The _Use_decl_annotations_ annotation ensures that the annotations that are applied to the **EVT_SERCX2_FILECLOSE** function type in the header file are used. For more information about the requirements for function declarations, see [Declaring Functions by Using Function Role Types for KMDF Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/declaring-functions-by-using-function-role-types-for-kmdf-drivers). For more information about _Use_decl_annotations_, see [Annotating Function Behavior](https://learn.microsoft.com/previous-versions/visualstudio/visual-studio-2015/code-quality/annotating-function-behavior).

## See also

[SerCx2InitializeDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nf-sercx-sercx2initializedevice)