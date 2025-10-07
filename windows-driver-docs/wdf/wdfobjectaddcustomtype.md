# WdfObjectAddCustomType macro

\[Applies to KMDF and UMDF\]

The **WdfObjectAddCustomType** macro associates a framework object with a custom type.

## Parameters

*_handle*
A handle to a framework object.

*_type*
The driver-defined name for the custom type.

## Return value

**WdfObjectAddCustomType** returns STATUS_SUCCESS if the operation succeeds. Otherwise, this method might return one of the following values:

| Return code | Description |
| --- | --- |
| **STATUS_OBJECT_PATH_INVALID** | The specified handle cannot have a custom type added to it. |
| **STATUS_INSUFFICIENT_RESOURCES** | The custom type could not be allocated. |
| **STATUS_OBJECT_NAME_EXISTS** | The driver has already added the specified custom type. |
| **STATUS_DELETE_PENDING** | The object that the Handle parameter specifies is being deleted. In this situation, the framework does not add the custom type. |

## Remarks

**WdfObjectAddCustomType** is a simplified version of [**WdfObjectAddCustomTypeWithData**](https://learn.microsoft.com/windows-hardware/drivers/wdf/wdfobjectaddcustomtypewithdata).

For more information about object driver types, see [Framework Object Custom Types](https://learn.microsoft.com/windows-hardware/drivers/wdf/framework-object-custom-types).

## Examples

This example code shows how to add a custom type to a queue.

```cpp
NTSTATUS                status;
WDF_IO_QUEUE_CONFIG     queueConfig;
WDFQUEUE                queue;

WDF_IO_QUEUE_CONFIG_INIT(&queueConfig,
                         WdfIoQueueDispatchParallel);

status = WdfIoQueueCreate(device,
                          &queueConfig,
                          WDF_NO_OBJECT_ATTRIBUTES,
                          &queue);

if (!NT_SUCCESS(status)) {
     TraceEvents(TRACE_LEVEL_ERROR, DBG_INFO,
                 "Failed to create queue, status=0x%x\n", status);
     goto Done;
}

status = WdfObjectAddCustomType(queue, TEST_TYPE1);

if (!NT_SUCCESS(status)) {
    TraceEvents(TRACE_LEVEL_ERROR, DBG_INFO,
                "Failed to add TEST_TYPE1 to WDFOBJECT 0x%p, status=0x%x\n",
    queue, status);
    goto Done;
}

End:
    return status;
```

## Requirements

|  |  |
| --- | --- |
| Target platform | [Universal](https://go.microsoft.com/fwlink/p/?linkid=531356) |
| Minimum KMDF version | 1.11 |
| Minimum UMDF version | 2.0 |
| Header | Wdfobject.h (include Wdf.h) |

## See also

[**WDF_DECLARE_CUSTOM_TYPE**](https://learn.microsoft.com/windows-hardware/drivers/wdf/wdf-declare-custom-type)

[**WdfObjectAddCustomTypeWithData**](https://learn.microsoft.com/windows-hardware/drivers/wdf/wdfobjectaddcustomtypewithdata)

[**WdfObjectGetCustomTypeData**](https://learn.microsoft.com/windows-hardware/drivers/wdf/wdfobjectgetcustomtypedata)

[**WdfObjectIsCustomType**](https://learn.microsoft.com/windows-hardware/drivers/wdf/wdfobjectiscustomtype)

