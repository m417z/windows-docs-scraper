# IVssWriterComponents::GetWriterInfo

## Description

The
**GetWriterInfo** method gets the instance and class identifier of the writer responsible for the components.

## Parameters

### `pidInstance` [out]

Identifier of the writer instance.

### `pidWriter` [out]

Identifier of the writer class.

## Return value

The following are the valid return codes for this method.

| Value | Meaning |
| --- | --- |
| **S_OK** | Successfully returned the component. |
| **E_INVALIDARG** | One of the parameter values is not valid. |
| **E_OUTOFMEMORY** | The caller is out of memory or other system resources. |
| **VSS_E_INVALID_XML_DOCUMENT** | The XML document is not valid. Check the event log for details. For more information, see [Event and Error Handling Under VSS](https://learn.microsoft.com/windows/desktop/VSS/event-and-error-handling-under-vss). |

## See also

[IVssWriterComponents](https://learn.microsoft.com/windows/desktop/api/vswriter/nl-vswriter-ivsswritercomponents)