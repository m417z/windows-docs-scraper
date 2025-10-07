# WDF_DECLARE_CONTEXT_TYPE macro

\[Applies to KMDF and UMDF\]

The WDF_DECLARE_CONTEXT_TYPE macro creates a name and an accessor method for a driver's object-specific context space.

## Parameters

*_contexttype*
The structure type name of a driver-defined structure that describes the contents of an object's context space.

## Return value

This macro does not return a value.

## Remarks

For more information about using this macro, see [Framework Object Context Space](https://learn.microsoft.com/windows-hardware/drivers/wdf/framework-object-context-space).

## Examples

The following code example defines a context structure (MY_REQUEST_CONTEXT) for a request object, registers the structure, and then invokes the WDF_DECLARE_CONTEXT_TYPE macro. The macro creates an accessor method for the context structure and names the method **WdfObjectGet_MY_REQUEST_CONTEXT**.

```cpp
typedef struct _MY_REQUEST_CONTEXT {
  LIST_ENTRY ListEntry;
  WDFMEMORY Memory;
} MY_REQUEST_CONTEXT, *PMY_REQUEST_CONTEXT;

WDF_DECLARE_CONTEXT_TYPE(MY_REQUEST_CONTEXT)
```

The following code example creates a request object, and then it uses the **WdfObjectGet_MY_REQUEST_CONTEXT** accessor method to obtain a pointer to the object's context space.

```cpp
WDFREQUEST Request;
WDF_OBJECT_ATTRIBUTES MyRequestObjectAttributes;
PMY_REQUEST_CONTEXT pMyContext;

WDF_OBJECT_ATTRIBUTES_INIT(&MyRequestObjectAttributes);
WDF_OBJECT_ATTRIBUTES_SET_CONTEXT_TYPE(
                                       &MyRequestObjectAttributes,
                                       MY_REQUEST_CONTEXT
                                       );
status = WdfRequestCreate(
                          &MyRequestObjectAttributes
                          NULL,
                          &Request
                          );
if (!NT_SUCCESS(status)) {
    return status;
}
pMyContext = WdfObjectGet_MY_REQUEST_CONTEXT(Request);
```

## Requirements

|  |  |
| --- | --- |
| Target platform | [Universal](https://go.microsoft.com/fwlink/p/?linkid=531356) |
| Minimum KMDF version | 1.0 |
| Minimum UMDF version | 2.0 |
| Header | Wdfobject.h (include Wdf.h) |

## See also

[**WdfObjectGetTypedContext**](https://learn.microsoft.com/windows-hardware/drivers/wdf/wdfobjectgettypedcontext)

[**WDF_DECLARE_CONTEXT_TYPE_WITH_NAME**](https://learn.microsoft.com/windows-hardware/drivers/wdf/wdf-declare-context-type-with-name)

