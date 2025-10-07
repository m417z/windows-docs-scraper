# WdfObjectGetCustomTypeData macro

\[Applies to KMDF and UMDF\]

The **WdfObjectGetCustomTypeData** macro retrieves the data that the driver previously associated with a framework object and custom type.

## Parameters

*Handle* \[in\]
A handle to a framework object.

*Type* \[in\]
The symbol name of a custom type.

## Return value

**WdfObjectGetCustomTypeData** returns the data that the driver associated with a framework object and custom type in a previous call to [**WdfObjectAddCustomTypeWithData**](https://learn.microsoft.com/windows-hardware/drivers/wdf/wdfobjectaddcustomtypewithdata).

## Remarks

For more information about object driver types, see [Framework Object Custom Types](https://learn.microsoft.com/windows-hardware/drivers/wdf/framework-object-custom-types).

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

[**WdfObjectIsCustomType**](https://learn.microsoft.com/windows-hardware/drivers/wdf/wdfobjectiscustomtype)

