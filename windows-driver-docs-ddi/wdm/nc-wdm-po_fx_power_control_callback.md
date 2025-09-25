## Description

The *PowerControlCallback* callback routine performs a power control operation that is requested by the power management framework (PoFx).

## Parameters

### `DeviceContext`

### `PowerControlCode` [in]

A pointer to the power control code. This code is a GUID value that specifies the requested operation.

### `InBuffer` [in, optional]

A pointer to the buffer that contains the input data for the operation. The format for the data in this buffer depends on the power control code specified by the *PowerControlCode* parameter. The *InBuffer* parameter is optional and can be specified as NULL if the specified operation requires no input data.

### `InBufferSize` [in]

The size, in bytes, of the input buffer that is pointed to by the *InBuffer* parameter. If *InBuffer* is NULL, this parameter is zero.

### `OutBuffer` [out, optional]

A pointer to the buffer to which the callback routine writes the output data from the operation. The format for the data in this buffer depends on the power control code specified by the *PowerControlCode* parameter. The *OutBuffer* parameter is optional and can be specified as NULL if the specified operation produces no output data.

### `OutBufferSize` [in]

The size, in bytes, of the output buffer that is pointed to by the *OutBuffer* parameter. If *OutBuffer* is NULL, this parameter is zero.

### `BytesReturned` [out, optional]

A pointer to a location into which the routine writes the number of bytes of data that were written to the buffer that is pointed to by *OutBuffer*. The number of bytes written must be less than or equal to *OutBufferSize*. This parameter is optional and can be specified as NULL if the caller does not need to know how many bytes were written to the output buffer.

## Return value

The *PowerControlCallback* routine returns STATUS_SUCCESS if the call is successful. Otherwise, it returns an appropriate error code.

## Remarks

PoFx calls this routine to send a power control request directly to the device driver. A power control request is similar to an I/O control request (IOCTL). Unlike an IOCTL, however, a power control request is sent directly to the driver and is not observed by other device drivers in the device stack. During a *PowerControlCallback* call, the driver synchronously performs the requested operation.

This routine is optional. A device driver that does not support power control operations is not required to implement a *PowerControlCallback* routine.

The device driver can call the [PoFxPowerControl](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-pofxpowercontrol) routine to send a power control request to PoFx.

For more information about power control requests, see [PoFxPowerControl](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-pofxpowercontrol).

### Examples

To define a *PowerControlCallback* callback routine, you must first provide a function declaration that identifies the type of callback routine you're defining. Windows provides a set of callback function types for drivers. Declaring a function using the callback function types helps [Code Analysis for Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/code-analysis-for-drivers), [Static Driver Verifier](https://learn.microsoft.com/windows-hardware/drivers/devtest/static-driver-verifier) (SDV), and other verification tools find errors, and it's a requirement for writing drivers for the Windows operating system.

For example, to define a *PowerControlCallback* callback routine that is named `MyPowerControlCallback`, use the PO_FX_POWER_CONTROL_CALLBACK type as shown in this code example:

```cpp
PO_FX_POWER_CONTROL_CALLBACK MyPowerControlCallback;
```

Then, implement your callback routine as follows:

```cpp
_Use_decl_annotations_
NTSTATUS
  MyPowerControlCallback(
    PVOID Context,
    LPCGUID PowerControlCode,
    PVOID InBuffer,
    SIZE_T InBufferSize,
    PVOID OutBuffer,
    SIZE_T OutBufferSize,
    PSIZE_T BytesReturned
    )
  {
      // Function body
  }
```

The PO_FX_POWER_CONTROL_CALLBACK function type is defined in the Wdm.h header file. To more accurately identify errors when you run the code analysis tools, be sure to add the `_Use_decl_annotations_` annotation to your function definition. The `_Use_decl_annotations_` annotation ensures that the annotations that are applied to the PO_FX_POWER_CONTROL_CALLBACK function type in the header file are used. For more information about the requirements for function declarations, see [Declaring Functions by Using Function Role Types for WDM Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/declaring-functions-using-function-role-types-for-wdm-drivers). For information about `_Use_decl_annotations_`, see [Annotating Function Behavior](https://learn.microsoft.com/visualstudio/code-quality/annotating-function-behavior).

## See also

[**PO_FX_DEVICE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_po_fx_device_v1)

[PoFxPowerControl](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-pofxpowercontrol)