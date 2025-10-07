# WDF_OBJECT_ATTRIBUTES_SET_CONTEXT_TYPE macro

\[Applies to KMDF and UMDF\]

The WDF_OBJECT_ATTRIBUTES_SET_CONTEXT_TYPE macro inserts an object's driver-defined context information into the object's [**WDF_OBJECT_ATTRIBUTES**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/ns-wdfobject-_wdf_object_attributes) structure.

## Parameters

*_attributes*
A pointer to an object's [**WDF_OBJECT_ATTRIBUTES**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/ns-wdfobject-_wdf_object_attributes) structure.

*_contexttype*
The structure type name of a driver-defined structure that describes the contents of an object's context space.

## Return value

This macro does not return a value.

## Remarks

You should use the WDF_OBJECT_ATTRIBUTES_SET_CONTEXT_TYPE macro after calling [**WDF_OBJECT_ATTRIBUTES_INIT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/nf-wdfobject-wdf_object_attributes_init).

For more information about using the WDF_OBJECT_ATTRIBUTES_SET_CONTEXT_TYPE macro, see [Framework Object Context Space](https://learn.microsoft.com/windows-hardware/drivers/wdf/framework-object-context-space).

For a code example that uses this macro, see [**WDF_DECLARE_CONTEXT_TYPE**](https://learn.microsoft.com/windows-hardware/drivers/wdf/wdf-declare-context-type).

## Requirements

|  |  |
| --- | --- |
| Target platform | [Universal](https://go.microsoft.com/fwlink/p/?linkid=531356) |
| Minimum KMDF version | 1.0 |
| Minimum UMDF version | 2.0 |
| Header | Wdfobject.h (include Wdf.h) |

## See also

[**WDF_DECLARE_CONTEXT_TYPE**](https://learn.microsoft.com/windows-hardware/drivers/wdf/wdf-declare-context-type)

[**WDF_OBJECT_ATTRIBUTES**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/ns-wdfobject-_wdf_object_attributes)

[**WDF_OBJECT_ATTRIBUTES_INIT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/nf-wdfobject-wdf_object_attributes_init)

[**WDF_OBJECT_ATTRIBUTES_INIT_CONTEXT_TYPE**](https://learn.microsoft.com/windows-hardware/drivers/wdf/wdf-object-attributes-init-context-type)

