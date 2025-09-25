# WdfVerifierDbgBreakPoint function

## Description

[Applies to KMDF and UMDF]

The **WdfVerifierDbgBreakPoint** function breaks into a kernel debugger, if a debugger is running.

## Remarks

The **WdfVerifierDbgBreakPoint** function breaks into a kernel debugger if one of the following is true:

* **DbgBreakOnError** is set to a non-zero value in the registry.
* **VerifierOn** is set to a non-zero value and **DbgBreakOnError** is not set.
* Driver Verifier is enabled, the driver was built with framework version 1.9 or later, and neither **VerifierOn** nor **DbgBreakOnError** is set.

For more information about registry entries that you can use to debug your driver, see [Registry Entries for Debugging Framework-Based Drivers](https://learn.microsoft.com/windows-hardware/drivers/wdf/registry-values-for-debugging-kmdf-drivers).

For more information about debugging your driver, see [Debugging a KMDF Driver](https://learn.microsoft.com/windows-hardware/drivers/wdf/debugging-driver-installation).

#### Examples

The following code example shows how a driver might handle a failure to obtain an I/O request's output buffer.

```cpp
Status = WdfRequestRetrieveOutputMemory(
                                        Request,
                                        &memory
                                        );
if( !NT_SUCCESS(Status) ) {
    KdPrint(("EvtIoRead could not get request memory buffer. Status: 0x%x\n",Status));
    WdfVerifierDbgBreakPoint();
    WdfRequestCompleteWithInformation(
                                      Request,
                                      Status,
                                      0L
                                      );
    return;
}
```

## See also

[WdfVerifierKeBugCheck](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfverifier/nf-wdfverifier-wdfverifierkebugcheck)