# ENTRYPOINTS structure

The **ENTRYPOINTS** structure defines the entry points to the export functions that Network Monitor uses to operate the parser.

## Members

**Register**

Pointer to the implementation of the [*Register expert*](https://learn.microsoft.com/windows/win32/netmon2/register-expert) function.

**Deregister**

Pointer to the implementation of the [**Deregister**](https://learn.microsoft.com/windows/win32/netmon2/deregister) function.

**RecognizeFrame**

Pointer to the implementation of the [**RecognizeFrame**](https://learn.microsoft.com/windows/win32/netmon2/recognizeframe) export function.

**AttachProperties**

Pointer to the implementation of the [**AttachProperties**](https://learn.microsoft.com/windows/win32/netmon2/attachproperties) export function.

**FormatProperties**

Pointer to the implementation of the [**FormatProperties**](https://learn.microsoft.com/windows/win32/netmon2/formatproperties) export function.

## Remarks

The **CreateProtocol** function uses the **ENTRYPOINTS** structure to provide pointers to Network Monitor. The pointers must be specified in the order identified in the previous Members section.

The [**FormatProperties**](https://learn.microsoft.com/windows/win32/netmon2/formatproperties) function does not need to be implemented if Network Monitor will never display the protocol data. For example, **FormatProperties** does not need to be implemented if an export application uses the output from the parser, and Network Monitor does not display the output.

| For information on | See |
|-----------------------------------------------------------|---------------------------------------------------------|
| What parsers are, and how they work with Network Monitor. | [Parsers](https://learn.microsoft.com/windows/win32/netmon2/parsers) |
| How to implement **DllMain** includes an example. | [Implementing DllMain](https://learn.microsoft.com/windows/win32/netmon2/implementing-dllmain-parser) |

## Requirements

| Requirement | Value |
|-------------------------------------|-------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 2000 Professional \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows 2000 Server \[desktop apps only\]<br> |
| Header<br> | Netmon.h |

## See also

[AttachProperties](https://learn.microsoft.com/windows/win32/netmon2/attachproperties)

[CreateProtocol](https://learn.microsoft.com/windows/win32/netmon2/createprotocol)

[Deregister](https://learn.microsoft.com/windows/win32/netmon2/deregister)

[FormatProperties](https://learn.microsoft.com/windows/win32/netmon2/formatproperties)

[RecognizeFrame](https://learn.microsoft.com/windows/win32/netmon2/recognizeframe)

[Register](https://learn.microsoft.com/windows/win32/netmon2/register-parser)

