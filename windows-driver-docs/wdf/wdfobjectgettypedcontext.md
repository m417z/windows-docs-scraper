# WdfObjectGetTypedContext macro

\[Applies to KMDF and UMDF\]

The **WdfObjectGetTypedContext** macro returns a pointer to an object's context space.

## Parameters

*Handle*
A handle to a framework object.

*Type*
The symbol name of a driver-defined structure that describes an object's context space.

## Return value

**WdfObjectGetTypedContext** returns a pointer to the specified object's context space.

## Remarks

You can use the **WdfObjectGetTypedContext** macro to obtain a pointer to any framework object's context space. Use this macro as an alternative to calling an object-specific context accessor method that is created by the [**WDF_DECLARE_CONTEXT_TYPE**](https://learn.microsoft.com/windows-hardware/drivers/wdf/wdf-declare-context-type) macro or the [**WDF_DECLARE_CONTEXT_TYPE_WITH_NAME**](https://learn.microsoft.com/windows-hardware/drivers/wdf/wdf-declare-context-type-with-name) macro. Note that if you use **WdfObjectGetTypedContext**, you still must use WDF_DECLARE_CONTEXT_TYPE or WDF_DECLARE_CONTEXT_TYPE_WITH_NAME to declare your object context.

For more information about these macros, see [Framework Object Context Space](https://learn.microsoft.com/windows-hardware/drivers/wdf/framework-object-context-space).

## Examples

The following code example defines a context structure (MY_REQUEST_CONTEXT) for a request object and then registers the structure.

```cpp
typedef struct _MY_REQUEST_CONTEXT {
  LIST_ENTRY ListEntry;
  WDFMEMORY Memory;
} MY_REQUEST_CONTEXT, *PMY_REQUEST_CONTEXT;

WDF_DECLARE_CONTEXT_TYPE(MY_REQUEST_CONTEXT)
```

The following code example creates a request object and obtains a pointer to its context space.

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
                          &MyRequestObjectAttributes,
                          NULL,
                          &Request
                          );

if (!NT_SUCCESS(status)) {
    return status;
}
pMyContext = WdfObjectGetTypedContext(
                                      Request,
                                      MY_REQUEST_CONTEXT
                                      );
```

## Requirements

|  |  |
| --- | --- |
| Target platform | [Universal](https://go.microsoft.com/fwlink/p/?linkid=531356) |
| Minimum KMDF version | 1.0 |
| Minimum UMDF version | 2.0 |
| Header | Wdfobject.h (include Wdf.h) |
| Library | Wdf01000.sys (KMDF); WUDFx02000.dll (UMDF) |
| IRQL | Any level |

## See also

[**WDF_DECLARE_CONTEXT_TYPE**](https://learn.microsoft.com/windows-hardware/drivers/wdf/wdf-declare-context-type)

[**WDF_DECLARE_CONTEXT_TYPE_WITH_NAME**](https://learn.microsoft.com/windows-hardware/drivers/wdf/wdf-declare-context-type-with-name)

