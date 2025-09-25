# IDebugDataSpaces3::ReadHandleData

## Description

The **ReadHandleData** method retrieves information about a system object specified by a system handle.

## Parameters

### `Handle` [in]

Specifies the system handle of the object whose data is requested. See Handles for information about system handles.

### `DataType` [in]

Specifies the data type to return for the system handle. The following table contains the valid values, along with the corresponding return type:

| Value | Description |
| --- | --- |
| DEBUG_HANDLE_DATA_TYPE_BASIC | Returns basic information about the system object.<br><br>In this case, the argument *Buffer* can be considered to have type [PDEBUG_HANDLE_DATA_BASIC](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/ns-dbgeng-_debug_handle_data_basic). |
| DEBUG_HANDLE_DATA_TYPE_TYPE_NAME | Returns the name of the object type. For example, "Process" or "Thread".<br><br>In this case, the argument *Buffer* can be considered to have type PSTR. |
| DEBUG_HANDLE_DATA_TYPE_OBJECT_NAME | Returns the name of the object. This includes its location in the object directory.<br><br>In this case, the argument *Buffer* can be considered to have type PSTR. |
| DEBUG_HANDLE_DATA_TYPE_HANDLE_COUNT | Returns the number of handles held by the object. This is similar to the field [DEBUG_HANDLE_DATA_BASIC](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/ns-dbgeng-_debug_handle_data_basic).**HandleCount**.<br><br>In this case, the argument *Buffer* can be considered to have type PULONG. |
| DEBUG_HANDLE_DATA_TYPE_TYPE_NAME_WIDE | Returns the name of the object type.<br><br>In this case, the argument *Buffer* can be considered to have type PWSTR |
| DEBUG_HANDLE_DATA_TYPE_OBJECT_NAME_WIDE | Returns the name of the object.<br><br>In this case, the argument *Buffer* can be considered to have type PWSTR. |

### `Buffer` [out, optional]

Receives the object data. Upon successful completion of the method, the contents of this buffer may be accessed by casting *Buffer* to the type specified in the above table.

If *Buffer* is **NULL**, this information is not returned.

### `BufferSize` [in]

Specifies the size in bytes of the buffer *Buffer*. This is the maximum number of bytes that will be returned.

### `DataSize` [out, optional]

Receives the size of the data in bytes. If *DataSize* is **NULL**, this information is not returned.

## Return value

| Return code | Description |
| --- | --- |
| **S_OK** | The method was successful. |

This method can also return error values. See [Return Values](https://learn.microsoft.com/windows-hardware/drivers/debugger/hresult-values) for more details.

## Remarks

This method is only available in user-mode debugging.

## See also

Handles

[IDebugDataSpaces2](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugdataspaces2)

[IDebugDataSpaces3](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugdataspaces3)

[IDebugDataSpaces4](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugdataspaces4)