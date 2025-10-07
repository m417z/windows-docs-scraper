# WdfObjectAddCustomTypeWithData macro

\[Applies to KMDF and UMDF\]

The **WdfObjectAddCustomTypeWithData** macro associates a framework object with a custom type, and optionally associates this pair with a data buffer and event callback functions.

## Parameters

*_handle*
A handle to a framework object.

*_type*
The driver-defined name for the custom type.

*_data*
A pointer to a driver-supplied data buffer, or NULL. This parameter is optional.

*_cleanup*
A pointer to the driver's [*EvtCleanupCallback*](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/nc-wdfobject-evt_wdf_object_context_cleanup) callback function, or NULL. This parameter is optional.

*_destroy*
A pointer to the driver's [*EvtDestroyCallback*](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/nc-wdfobject-evt_wdf_object_context_destroy) callback function, or NULL. This parameter is optional.

## Return value

**WdfObjectAddCustomTypeWithData** returns STATUS_SUCCESS if the operation succeeds. Otherwise, this method might return one of the following values:

| Return code | Description |
| --- | --- |
| **STATUS_OBJECT_PATH_INVALID** | The specified handle cannot have a custom type added to it. |
| **STATUS_INSUFFICIENT_RESOURCES** | The custom type could not be allocated. |
| **STATUS_OBJECT_NAME_EXISTS** | The driver has already added the specified custom type. |
| **STATUS_DELETE_PENDING** | The object that the Handle parameter specifies is being deleted. In this situation, the framework does not add the custom type. |

## Remarks

If your driver calls **WdfObjectAddCustomTypeWithData** with a pointer to a data buffer, the driver can provide an [*EvtCleanupCallback*](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/nc-wdfobject-evt_wdf_object_context_cleanup) or [*EvtDestroyCallback*](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/nc-wdfobject-evt_wdf_object_context_destroy) callback function to deallocate the memory buffer when the object is deleted.

For more information about object custom types, see [Framework Object Custom Types](https://learn.microsoft.com/windows-hardware/drivers/wdf/framework-object-custom-types).

For a code example, see [**WdfObjectAddCustomType**](https://learn.microsoft.com/windows-hardware/drivers/wdf/wdfobjectaddcustomtype).

## Requirements

|  |  |
| --- | --- |
| Target platform | [Universal](https://go.microsoft.com/fwlink/p/?linkid=531356) |
| Minimum KMDF version | 1.11 |
| Minimum UMDF version | 2.0 |
| Header | Wdfobject.h (include Wdf.h) |

## See also

[**WDF_DECLARE_CUSTOM_TYPE**](https://learn.microsoft.com/windows-hardware/drivers/wdf/wdf-declare-custom-type)

[**WdfObjectAddCustomType**](https://learn.microsoft.com/windows-hardware/drivers/wdf/wdfobjectaddcustomtype)

[**WdfObjectGetCustomTypeData**](https://learn.microsoft.com/windows-hardware/drivers/wdf/wdfobjectgetcustomtypedata)

[**WdfObjectIsCustomType**](https://learn.microsoft.com/windows-hardware/drivers/wdf/wdfobjectiscustomtype)

