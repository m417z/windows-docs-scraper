# WdfObjectIsCustomType macro

\[Applies to KMDF and UMDF\]

The **WdfObjectIsCustomType** macro determines whether a framework object is of a specified custom type.

## Parameters

*Handle* \[in\]
A handle to a framework object.

*Type* \[in\]
The symbol name of a custom type.

## Return value

Returns TRUE if the specified object is of the specified custom type. Otherwise, returns FALSE.

## Remarks

For more information about object custom types, see [Framework Object Custom Types](https://learn.microsoft.com/windows-hardware/drivers/wdf/framework-object-custom-types).

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

[**WdfObjectAddCustomTypeWithData**](https://learn.microsoft.com/windows-hardware/drivers/wdf/wdfobjectaddcustomtypewithdata)

[**WdfObjectGetCustomTypeData**](https://learn.microsoft.com/windows-hardware/drivers/wdf/wdfobjectgetcustomtypedata)

