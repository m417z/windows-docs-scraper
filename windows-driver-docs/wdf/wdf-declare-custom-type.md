# WDF_DECLARE_CUSTOM_TYPE macro

\[Applies to KMDF and UMDF\]

The **WDF_DECLARE_CUSTOM_TYPE** macro creates a name and an accessor method for a driver's custom type.

## Parameters

*_customtype*
The driver-defined name of a custom type.

## Return value

This macro does not return a value.

## Remarks

When calling **WDF_DECLARE_CUSTOM_TYPE**, a driver defines its own custom type name. When selecting a custom type name, choose a name that is specific to the domain of the driver. As a convention, do not start your custom type name with the prefix *Wdf*.

For more information about object custom types, see [Framework Object Custom Types](https://learn.microsoft.com/windows-hardware/drivers/wdf/framework-object-custom-types).

## Examples

The following code example calls the **WDF_DECLARE_CUSTOM_TYPE** macro to declare the MY_CUSTOM_TYPE custom type name. The driver must put this line in an area of the driver that declares global data, typically a header file.

```cpp
WDF_DECLARE_CUSTOM_TYPE(MY_CUSTOM_TYPE)
```

The following code example creates a request object, and then it uses the [**WdfObjectAddCustomType**](https://learn.microsoft.com/windows-hardware/drivers/wdf/wdfobjectaddcustomtype) method to associate the **MY_CUSTOM_TYPE** custom type with the request object.

```cpp
WDFREQUEST Request;
WDF_OBJECT_ATTRIBUTES MyRequestObjectAttributes;

WDF_OBJECT_ATTRIBUTES_INIT(&MyRequestObjectAttributes);

status = WdfRequestCreate(
                          &MyRequestObjectAttributes
                          NULL,
                          &Request
                          );

if (!NT_SUCCESS(status)) {
    return status;
}

status = WdfObjectAddCustomType(
                          Request,
                          MY_CUSTOM_TYPE
                          );

if (!NT_SUCCESS(status)) {
    return status;
}
```

## Requirements

|  |  |
| --- | --- |
| Target platform | [Universal](https://go.microsoft.com/fwlink/p/?linkid=531356) |
| Minimum KMDF version | 1.11 |
| Minimum UMDF version | 2.0 |
| Header | Wdfobject.h (include Wdf.h) |

## See also

[**WdfObjectAddCustomType**](https://learn.microsoft.com/windows-hardware/drivers/wdf/wdfobjectaddcustomtype)

[**WdfObjectAddCustomTypeWithData**](https://learn.microsoft.com/windows-hardware/drivers/wdf/wdfobjectaddcustomtypewithdata)

[**WdfObjectGetCustomTypeData**](https://learn.microsoft.com/windows-hardware/drivers/wdf/wdfobjectgetcustomtypedata)

[**WdfObjectIsCustomType**](https://learn.microsoft.com/windows-hardware/drivers/wdf/wdfobjectiscustomtype)

