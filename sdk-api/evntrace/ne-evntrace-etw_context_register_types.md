## Description

Specifies the set of CPU registers to be collected when Context Register Tracing is enabled. This enumeration is used by the [TRACE_CONTEXT_REGISTER_INFO](https://learn.microsoft.com/windows/win32/api/evntrace/ns-evntrace-trace_context_register_info)
structure.

## Constants

### `EtwContextRegisterTypeNone`

No register types.

### `EtwContextRegisterTypeControl`

Control register types. The exact registers vary by architecture.

### `EtwContextRegisterTypeInteger`

Integer register types. The exact registers vary by architecture.

## Remarks

On AMD64, the integer registers include Rax, Rbx, Rcx, Rsi, Rbp, R8, and others. On AMD64, the control registers include Rip, SegCs, SegSs, Rsp, and EFlags. For more information on supported registers, see [CONTEXT structure](https://learn.microsoft.com/windows/win32/api/winnt/ns-winnt-context).

## See also