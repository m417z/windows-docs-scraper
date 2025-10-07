# RecognizeFrame callback function

The **RecognizeFrame** export function indicates whether a piece of data is recognized as the protocol that the parser detects. The **RecognizeFrame** export function must be implemented for each parser that the parser DLL supports.

## Parameters

*hFrame* \[in\]

Handle to the frame that contains the data.

*lpFrame* \[in\]

Pointer to the first byte of a frame. The pointer provides a way to view data that other parsers recognize.

*lpProtocol* \[in\]

Pointer to the start of the unclaimed data. Typically, the unclaimed data is located in the middle of a frame because a previous parser has claimed data before this parser. The parser must test the unclaimed data first.

*MacType* \[in\]

MAC value of the first protocol in a frame. Typically, the *MacType* value is used when the parser must identify the first protocol in a frame. The *MacType* value can be one of the following:

| Value | Meaning |
|-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|-------------------------|
|

**MAC\_TYPE\_ETHERNET**

| 802.3 <br> |
|

**MAC\_TYPE\_TOKENRING**

| 802.5 <br> |
|

**MAC\_TYPE\_FDDI**

| ANSI X3T9.5 <br> |

*BytesLeft* \[in\]

The remaining number of bytes from a location in a frame to the end of the frame.

*hPreviousProtocol* \[in\]

Handle of the previous protocol.

*nPreviousProtocolOffset* \[in\]

Offset of the previous protocol beginning of the frame.

*ProtocolStatusCode* \[out\]

Protocol status indicator. The parser DLL must set one of the following status codes.

| Value | Meaning |
|--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
|

**PROTOCOL\_STATUS\_RECOGNIZED**

| The parser recognizes the data but does not know which protocol follows. After setting the code, return a pointer to the remaining unclaimed data that follow the recognized protocol. Network Monitor uses the [*follow set*](https://learn.microsoft.com/windows/win32/netmon2/f) of the protocol to continue parsing. <br> |
|

**PROTOCOL\_STATUS\_NOT\_RECOGNIZED**

| The parser does not recognize the data. After setting this code, return the pointer to the beginning of the data using the pointer that the *lpProtocol* parameter passes to the parser DLL. Network Monitor uses the *follow set* of the previous protocol to continue parsing. <br> |
|

**PROTOCOL\_STATUS\_CLAIMED**

| The parser recognizes the data and claims the remaining data. After setting the code, return **NULL** for Network Monitor to terminate parsing a frame. <br> |
|

**PROTOCOL\_STATUS\_NEXT\_PROTOCOL**

| The parser recognizes the data and knows which protocol follows. After setting the code, set the *phNextProtocol* parameter, and return a pointer to the remaining unclaimed data that follow the recognized protocol. Network Monitor continues parsing the frame. <br> |

*phNextProtocol* \[out\]

Pointer to the handle of the next protocol. This parameter is set when a protocol identifies the protocol that follows a protocol. To obtain the handle of the next protocol, call the [GetProtocolFromTable](https://learn.microsoft.com/windows/win32/netmon2/getprotocolfromtable) function.

*lpInstData* \[in, out\]

On input, a pointer to the instance data from the previous protocol.

On output, a pointer to the instance data for the current protocol. Instance data cannot be longer than a DWORD\_PTR in length.

## Return value

If the function is successful, the return value is a pointer to the first byte after the recognized parser data. If the parser claims all the remaining data, the return value is **NULL**.

If the function is unsuccessful, the return value is an initial pointer that the *lpProtocol* parameter passes-in.

## Remarks

The **RecognizeFrame** function determines whether the parser recognizes the raw data starting at the *lpProtocol* pointer.

- If the protocol recognizes the data, the **RecognizeFrame** function returns a pointer to the remaining data, or returns **NULL** if the current protocol is the last protocol in a frame.
- If the protocol does not recognize the data, the **RecognizeFrame** function returns the pointer passed to the parser DLL in the *lpProtocol* parameter.

> [!Note]
> *RecognizeFrame* can be called before the [*Register*](https://learn.microsoft.com/windows/win32/netmon2/register-parser) function is called to register the protocol properties. For that reason, the implementation of the *RecognizeFrame* function does not rely on any properties or structures that are created or initialized during the implementation of the protocol **Register** function.

**Handoff Set and Follow Set**

A parser can use a handoff set or follow set to identify for Network Monitor the protocol that follows recognized data.

- If information is available in recognized data, the parser uses its handoff set to obtain a handle to the next protocol, and then passes that handle to Network Monitor.
- If information is not available, the parser does not pass a handle, and Network Monitor uses the parser follow set to determine which protocol follows.

**Passing information between protocols**

Use the *lpInstData* parameter to pass information between protocols. On input, you can retrieve the information from the previous protocol. On output, you can pass information to the next protocol.

Instance data can be any data that is less than or equal to a DWORD\_PTR in length, or a pointer to data, such as raw frame data, that does not need to be allocated by or freed by the parser.

| For Information on | See |
|-----------------------------------------------------------|---------------------------------------------------------------------------------------------------------------------------|
| What parsers are, and how they work with Network Monitor. | [Parsers](https://learn.microsoft.com/windows/win32/netmon2/parsers) |
| Which entry points are included in the parser DLL. | [Parser DLL Architecture](https://learn.microsoft.com/windows/win32/netmon2/parser-dll-architecture) |
| How to implement **RecognizeFrame** includes an example. | [Implementing RecognizeFrame](https://learn.microsoft.com/windows/win32/netmon2/implementing-recognizeframe) |
| How to specify a handoff set and follow set. | [Specifying a Handoff Set](https://learn.microsoft.com/windows/win32/netmon2/specifying-a-handoff-set)[Specifying a Follow Set](https://learn.microsoft.com/windows/win32/netmon2/specifying-a-follow-set)<br> |

## Requirements

| Requirement | Value |
|-------------------------------------|-------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 2000 Professional \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows 2000 Server \[desktop apps only\]<br> |
| Header<br> | Netmon.h |

## See also

[GetProtocolFromTable](https://learn.microsoft.com/windows/win32/netmon2/getprotocolfromtable)

