# ORPC\_DBG\_BUFFER structure

The **ORPC\_DBG\_BUFFER** structure is the buffer format used to marshalled RPC data to the methods of the [**IOrpcDebugNotify**](https://learn.microsoft.com/windows/win32/com/iorpcdebugnotify) interface.

## Members

**alwaysOrSometimes**

A value that controls debugger spawning. **alwaysOrSometimes** can be one of the following values:

| Value | Meaning |
|-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
|

**ORPC\_DEBUG\_ALWAYS**

0x00000000

| If set, COM will always raise the client or server notification on the receiver.<br> |
|

**ORPC\_DEBUG\_IF\_HOOK\_ENABLED**

0x00000001

| If set, COM will only raise the client or server notification on the receiver if COM debugging has been enabled by calling [**DllDebugObjectRPCHook**](https://learn.microsoft.com/windows/win32/com/dlldebugobjectrpchook) in that process with **fTrace** set to **TRUE**. <br> |

**verMajor**

The major version number of the data format specification.

**verMinor**

The minor version number of the data format specification.

**cbRemaining**

The number of bytes, inclusive of **cbRemaining**, that follow in this structure.

**guidSemantic**

A GUID that determines which members of the union are present below. **guidSemantic** can take one of the following values:

| Value | Meaning |
|-----------------------------------------------------------------------------------------------------------------|----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| 9CADE560-8F43-101A-B07B-00DD01113F11 | Determines if single stepping is to be performed by the debugger. Only the **fStopOnOtherSide** member of the union is present below.<br> |
| D62AEDFA-57EA-11ce-A964-00AA006C3706 | Determines if RPC marshalled data and debugging opcodes are passed to the receiver. All of the members of the union are present below with the exception of **fStopOnOtherSide**.<br> |

**fStopOnOtherSide**

If **TRUE**, single stepping is performed by the debugger and it should step out of the server and continue execution once the other side is reached. Otherwise, single stepping is not performed and debugger execution stops on the other side.

**wDebuggingOpCode**

A value that allows for one of a series of operations to be specified. **wDebuggingOpCode** can take one of the following values:

| Value | Meaning |
|-----------------------------------------------------------------------------------|------------------------------------------------------------------------------------------------------|
| 0x0000 | No operation.<br> |
| 0x0001 | If set, single step semantics are identical to **fStopOnOtherSide** when set to **TRUE**.<br> |

**cExtent**

Padding. Do not use.

**padding**

Padding. Do not use.

**cb**

The size, in bytes of the data in **rgbData**.

**guidExtent**

A **GUID** that determines the type of data in **rgbData**. **guidExtent** can take one of the following values:

| Value | Meaning |
|-----------------------------------------------------------------------------------------------------------------|-----------------------------------------------------------|
| 53199051-57EB-11ce-A964-00AA006C3706 | **rgbData** is a marshalled interface pointer.<br> |

**rgbData**

A **BYTE** buffer used to pass RPC marshalled COM data between the client and server debuggers. The contents of **rgbData** are determined by the **GUID** in **guidExtent**.

| guidExtent Value | rgbData contents |
|--------------------------------------|-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| 53199051-57EB-11ce-A964-00AA006C3706 | A marshalled interface pointer that results from calling [**CoMarshalInterface**](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-comarshalinterface). The marshalled pointer is converted into its corresponding interface pointer using [**CoUnmarshalInterface**](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-counmarshalinterface). |

## Remarks

This members of this structure have 1-byte alignment and are always transmitted in little-endian byte order.

## Requirements

| Requirement | Value |
|-------------------------------------|--------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 2000 Professional \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows 2000 Server \[desktop apps only\]<br> |
| Header<br> | N/A |

## See also

[**ORPC\_DBG\_ALL**](https://learn.microsoft.com/windows/win32/com/orpc-dbg-all)

[**ORPC\_INIT\_ARGS**](https://learn.microsoft.com/windows/win32/com/orpc-init-args)

[**DllDebugObjectRPCHook**](https://learn.microsoft.com/windows/win32/com/dlldebugobjectrpchook)

[**IOrpcDebugNotify**](https://learn.microsoft.com/windows/win32/com/iorpcdebugnotify)

