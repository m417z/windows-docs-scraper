# IDebugBreakpoint::SetDataParameters

## Description

The **SetDataParameters** method sets the parameters for a processor breakpoint.

## Parameters

### `Size` [in]

The size, in bytes, of the memory block whose access triggers the breakpoint. For more information about restrictions on the value of *Size* based on the processor type, see [Valid Parameters for Processor Breakpoints](https://learn.microsoft.com/windows-hardware/drivers/debugger/controlling-breakpoint-flags-and-parameters).

### `AccessType` [in]

The type of access that triggers the breakpoint. For a list of possible value, see [Valid Parameters for Processor Breakpoints](https://learn.microsoft.com/windows-hardware/drivers/debugger/controlling-breakpoint-flags-and-parameters).

## Return value

| Return code | Description |
| --- | --- |
| **S_OK** | The method was successful. |
| **E_NOINTERFACE** | The breakpoint is not a processor breakpoint. For more information about the breakpoint type, see [GetType](https://learn.microsoft.com/windows-hardware/drivers/ddi/extsfns/nf-extsfns-idebugfaentrytags-gettype). |

This method can also return other error values. For more information, see [Return Values](https://learn.microsoft.com/windows-hardware/drivers/debugger/hresult-values).

## Remarks

For more information about breakpoint properties, see [Controlling Breakpoint Flags and Parameters](https://learn.microsoft.com/windows-hardware/drivers/debugger/controlling-breakpoint-flags-and-parameters).