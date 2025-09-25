## Description

Register MCA driver with the HAL.

## Parameters

### `InformationClass` [in]

The HalMcaRegisterDriver to register MCA driver's callback routines with the HAL. There are two callback routines: ExceptionCallback and DpcCallback. The ExceptionCallback routine is called during the Machine Check Exception (MCE) handler non-restartable error processing, before it issues a bug check for the system. The DpcCallback routine is called when the MCA error is restartable. For Itanium systems, specify HalCmcRegisterDriver to register a driver's Corrected CPU Error DpcCallback routine, and HalCpeRegisterDriver to register a driver's Corrected Platform Error DpcCallback.

### `BufferSize` [in]

The size, in bytes, of the buffer that the caller supplies.

### `Buffer` [out]

A pointer to a caller-supplied buffer of type MCA_DRIVER_INFO, which is defined as follows.

```cpp
typedef struct _MCA_DRIVER_INFO {
  PDRIVER_EXCPTN_CALLBACK  ExceptionCallback; // NULL for Itanium corrected error registration
  PKDEFERRED_ROUTINE  DpcCallback;
  PVOID  DeviceContext;
} MCA_DRIVER_INFO, *PMCA_DRIVER_INFO;
```

This structure contains the following members:

- ExceptionCallback

 The driver-supplied routine to be called when Machine Check Exception (MCE) occurs for uncorrected errors. A driver explicitly cannot use any kernel services or spin lock routines. The handler is restricted to the same constraints as a driver that operates at the highest IRQL.

- DpcCallback

 A driver-supplied routine that is called for corrected errors that caused Machine Check Exception (MCE). This routine must be called at DISPATCH_LEVEL.

- DeviceContext

 The device-specific context for this MCA driver.

## Return value

Returns STATUS_SUCCESS if the registration is successful.

## Remarks

HalSetSystemInformation must be called before an MCA driver can use any of the other interface routines. Only one MCA driver can be registered with the HAL at any given time.

> Windows Vista and later versions of Windows do not support the type of Machine Check Architecture (MCA) and Machine Check Exception (MCE) reporting that is described in this topic. MCA and MCE reporting are supported through [Windows Hardware Error Architecture (WHEA)](https://learn.microsoft.com/windows-hardware/drivers/whea) instead.

## See also