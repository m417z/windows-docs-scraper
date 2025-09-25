## Description

The *SynchCritSection* routine is used to access hardware resources or driver data that are shared with a driver's [InterruptService](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-kservice_routine) routine.

## Parameters

### `SynchronizeContext` [in]

Caller-supplied context information, specified by the driver's call to [KeSynchronizeExecution](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kesynchronizeexecution).

## Return value

If the routine's operation succeeds, the routine should return **TRUE**; otherwise, it should return **FALSE**. (Success and failure of this routine are driver-defined.) The specified return value becomes the return value for **KeSynchronizeExecution**.

## Remarks

Drivers must use *SynchCritSection* routines to access hardware resources or driver data that can also be accessed by an *InterruptService* routine (ISR).

The system calls a driver's *SynchCritSection* routine when the driver calls [KeSynchronizeExecution](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kesynchronizeexecution). When a driver calls **KeSynchronizeExecution**, it specifies the address of a *SynchCritSection* routine, context information for the routine, and an interrupt object pointer. The **KeSynchronizeExecution** routine acquires the interrupt object's spin lock, then calls the *SynchCritSection* routine.

A driver's *SynchCritSection* routine executes at the same IRQL as the ISR with which it is associated. Specifically, it executes at some system-assigned [DIRQL](https://learn.microsoft.com/windows-hardware/drivers/), as specified by the *SynchronizeIrql* parameter to [IoConnectInterrupt](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ioconnectinterrupt). (Other devices, with higher DIRQL values, can interrupt a *SynchCritSection* routine.)

### Examples

To define a *SynchCritSection* callback routine, you must first provide a function declaration that identifies the type of callback routine you're defining. Windows provides a set of callback function types for drivers. Declaring a function using the callback function types helps [Code Analysis for Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/code-analysis-for-drivers), [Static Driver Verifier](https://learn.microsoft.com/windows-hardware/drivers/devtest/static-driver-verifier) (SDV), and other verification tools find errors, and it's a requirement for writing drivers for the Windows operating system.

For example, to define a *SynchCritSection* callback routine that is named `MySynchCritSection`, use the KSYNCHRONIZE_ROUTINE type as shown in this code example:

```cpp
KSYNCHRONIZE_ROUTINE MySynchCritSection;
```

Then, implement your callback routine as follows:

```cpp
_Use_decl_annotations_
BOOLEAN
  MySynchCritSection(
    PVOID  SynchronizeContext
    )
  {
      // Function body
  }
```

The KSYNCHRONIZE_ROUTINE function type is defined in the Wdm.h header file. To more accurately identify errors when you run the code analysis tools, be sure to add the `_Use_decl_annotations_` annotation to your function definition. The `_Use_decl_annotations_` annotation ensures that the annotations that are applied to the KSYNCHRONIZE_ROUTINE function type in the header file are used. For more information about the requirements for function declarations, see [Declaring Functions by Using Function Role Types for WDM Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/declaring-functions-using-function-role-types-for-wdm-drivers). For information about `_Use_decl_annotations_`, see [Annotating Function Behavior](https://learn.microsoft.com/visualstudio/code-quality/annotating-function-behavior).