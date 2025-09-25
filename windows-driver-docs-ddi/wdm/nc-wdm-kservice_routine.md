## Description

The *InterruptService* routine (ISR) quickly services a device interrupt and schedules post-interrupt processing of received data, if necessary.

## Parameters

### `Interrupt` [in]

Caller-supplied pointer to the [KINTERRUPT](https://learn.microsoft.com/windows-hardware/drivers/kernel/eprocess#kinterrupt) structure for the interrupt.

### `ServiceContext` [in]

Caller-supplied pointer to context information, specified in a previous call to [IoConnectInterrupt](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ioconnectinterrupt) or [IoConnectInterruptEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ioconnectinterruptex).

## Return value

If the routine determines that the interrupt did not come from one of the driver's devices, it must return **FALSE**. Otherwise, the routine must service the interrupt and return **TRUE**.

## Remarks

To register an ISR for a specific interrupt vector and processor affinity, a driver must call [IoConnectInterrupt](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ioconnectinterrupt) or [IoConnectInterruptEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ioconnectinterruptex).

A driver's *InterruptService* routine (ISR) executes in an interrupt context, at some system-assigned DIRQL, as specified by the *SynchronizeIrql* parameter to **IoConnectInterrupt**. (Other devices, with higher DIRQL values, can interrupt the ISR.)

Before the system calls an ISR, it acquires the interrupt's spin lock (the *SpinLock* parameter to **IoConnectInterrupt**), so the ISR cannot simultaneously execute on another processor. After the ISR returns, the system releases the spin lock.

An ISR must first determine if the interrupt came from one of the driver's devices, by examining context information supplied by *Context*. If the interrupt is not from one of the driver's devices, the routine must immediately return **FALSE** so the I/O manager can call other drivers that have registered ISRs for the same processor and interrupt vector.

For more information about implementing ISRs, see [Interrupt Service Routines](https://learn.microsoft.com/windows-hardware/drivers/kernel/interrupt-service-routines).

### Examples

To define an *InterruptService* callback routine, you must first provide a function declaration that identifies the type of callback routine you're defining. Windows provides a set of callback function types for drivers. Declaring a function using the callback function types helps [Code Analysis for Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/code-analysis-for-drivers), [Static Driver Verifier](https://learn.microsoft.com/windows-hardware/drivers/devtest/static-driver-verifier) (SDV), and other verification tools find errors, and it's a requirement for writing drivers for the Windows operating system.

For example, to define an *InterruptService* callback routine that is named `MyInterruptService`, use the KSERVICE_ROUTINE type as shown in this code example:

```cpp
KSERVICE_ROUTINE MyInterruptService;
```

Then, implement your callback routine as follows:

```cpp
_Use_decl_annotations_
BOOLEAN
  MyInterruptService(
    struct _KINTERRUPT  *Interrupt,
    PVOID  ServiceContext
    )
  {
      // Function body
  }
```

The KSERVICE_ROUTINE function type is defined in the Wdm.h header file. To more accurately identify errors when you run the code analysis tools, be sure to add the `_Use_decl_annotations_` annotation to your function definition. The `_Use_decl_annotations_` annotation ensures that the annotations that are applied to the KSERVICE_ROUTINE function type in the header file are used. For more information about the requirements for function declarations, see [Declaring Functions by Using Function Role Types for WDM Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/declaring-functions-using-function-role-types-for-wdm-drivers). For information about `_Use_decl_annotations_`, see [Annotating Function Behavior](https://learn.microsoft.com/visualstudio/code-quality/annotating-function-behavior).