# AttachProperties callback function

The **AttachProperties** export function maps the properties to a location within a piece of recognized data. **AttachProperties** must be implemented for each parser that the parser DLL supports.

## Parameters

*hFrame* \[in\]

Handle of the frame that is being parsed.

*lpFrame* \[in\]

Pointer to the first byte in a frame.

*lpProtocol* \[in\]

Pointer to the start of the recognized data.

*MacType* \[in\]

MAC value of the first protocol in a frame. The *MacType* can be one of the following:

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

The remaining number of bytes in a frame starting at the beginning of the recognized data.

*hPreviousProtocol* \[in\]

Handle of the previous protocol.

*nPreviousProtocolOffset* \[in\]

Offset of the previous protocol starting at the beginning of the frame.

*lpInstData* \[in\]

Pointer to the instance data that the previous protocol provides. Instance data cannot be longer than a DWORD\_PTR in length.

## Return value

If the function is successful, the return value is a pointer to the first byte after the recognized data in a frame or **NULL** if the recognized data is the last piece of data in a frame.

If the function is unsuccessful, the return value is a pointer to the recognized data. The *lpProtocol* parameter passes the pointer to the parser DLL.

## Remarks

Network Monitor calls the **AttachProperties** function for each parser that recognizes a piece of data in a frame. Note that the parser determines which properties exist in the recognized data, and where each property is located.

During the implementation of **AttachProperties**, call [AttachPropertyInstance](https://learn.microsoft.com/windows/win32/netmon2/attachpropertyinstance) to use the data as it exists in the capture. You can also call [AttachPropertyInstanceEx](https://learn.microsoft.com/windows/win32/netmon2/attachpropertyinstanceex) function to modify the property data. However, it is advised that you use the data as it exists in the capture.

The **AttachPropertyInstanceEx** and **AttachPropertyInstance** functions are called only for the properties that exist in the recognized data. Note that Network Monitor has a [*property database*](https://learn.microsoft.com/windows/win32/netmon2/p) for the parser that contains a description of all the properties that the parser supports.

**Instance data**

Instance data is information that is passed from one parser to another. Instance data can be any data that is less than or equal to a DWORD\_PTR in length, or a pointer to data, such as raw frame data, that does not need to be allocated by or freed by the parser. In the *lpInstData* parameter of the **AttachProperties** and [RecognizeFrame](https://learn.microsoft.com/windows/win32/netmon2/recognizeframe) functions, Network Monitor provides a pointer to the instance data of the previous protocol. You can set the instance data for your parser during your implementation of **RecognizeFrame**.

| For information on | See |
|-------------------------------------------------------------|--------------------------------------------------------------------|
| What parsers are, and how they work with Network Monitor. | [Parsers](https://learn.microsoft.com/windows/win32/netmon2/parsers) |
| What entry points are included in the parser DLL. | [Parser DLL Architecture](https://learn.microsoft.com/windows/win32/netmon2/parser-dll-architecture) |
| How to recognize data. | [Implementing RecognizeFrame](https://learn.microsoft.com/windows/win32/netmon2/implementing-recognizeframe) |
| How to create a property database. | [Implementing Register](https://learn.microsoft.com/windows/win32/netmon2/implementing-register) |
| How to implement **AttachProperties** includes an example. | [Implementing AttachProperties](https://learn.microsoft.com/windows/win32/netmon2/implementing-attachproperties) |

## Requirements

| Requirement | Value |
|-------------------------------------|-------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 2000 Professional \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows 2000 Server \[desktop apps only\]<br> |
| Header<br> | Netmon.h |

## See also

[AttachPropertyInstance](https://learn.microsoft.com/windows/win32/netmon2/attachpropertyinstance)

[AttachPropertyInstanceEx](https://learn.microsoft.com/windows/win32/netmon2/attachpropertyinstanceex)

[RecognizeFrame](https://learn.microsoft.com/windows/win32/netmon2/recognizeframe)

