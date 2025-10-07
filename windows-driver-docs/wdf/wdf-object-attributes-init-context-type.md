# WDF_OBJECT_ATTRIBUTES_INIT_CONTEXT_TYPE macro

\[Applies to KMDF and UMDF\]

The **WDF_OBJECT_ATTRIBUTES_INIT_CONTEXT_TYPE** macro initializes a driver's [**WDF_OBJECT_ATTRIBUTES**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/ns-wdfobject-_wdf_object_attributes) structure and inserts an object's driver-defined context information into the structure.

## Parameters

*_attributes*
A pointer to a [**WDF_OBJECT_ATTRIBUTES**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/ns-wdfobject-_wdf_object_attributes) structure.

*_contexttype*
The structure type name of a driver-defined structure that describes the contents of an object's context space.

## Return value

This macro does not return a value.

## Remarks

Before calling **WDF_OBJECT_ATTRIBUTES_INIT_CONTEXT_TYPE**, you must call [**WDF_DECLARE_CONTEXT_TYPE**](https://learn.microsoft.com/windows-hardware/drivers/wdf/wdf-declare-context-type) or [**WDF_DECLARE_CONTEXT_TYPE_WITH_NAME**](https://learn.microsoft.com/windows-hardware/drivers/wdf/wdf-declare-context-type-with-name) globally (not within a function).

The **WDF_OBJECT_ATTRIBUTES_INIT_CONTEXT_TYPE** macro combines the [**WDF_OBJECT_ATTRIBUTES_INIT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/nf-wdfobject-wdf_object_attributes_init) function and the [**WDF_OBJECT_ATTRIBUTES_SET_CONTEXT_TYPE**](https://learn.microsoft.com/windows-hardware/drivers/wdf/wdf-object-attributes-set-context-type) macro.

## Examples

The following code example defines a WDM_NDIS_REQUEST context structure. Then, the example invokes the [**WDF_DECLARE_CONTEXT_TYPE_WITH_NAME**](https://learn.microsoft.com/windows-hardware/drivers/wdf/wdf-declare-context-type-with-name) macro to register the structure and specify that the context accessor method will be named **RequestGetMyContext**. Then, in a function, the example allocates a [**WDF_OBJECT_ATTRIBUTES**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/ns-wdfobject-_wdf_object_attributes) structure, and then initializes the **WDF_OBJECT_ATTRIBUTES** structure.

```cpp
typedef struct _WDM_NDIS_REQUEST
{
   PMP_ADAPTER  Adapter;
   NDIS_OID  Oid;
   NDIS_REQUEST_TYPE  RequestType;
   PVOID  InformationBuffer;
   ULONG  InformationBufferLength;
   PULONG  BytesReadOrWritten;
   PULONG  BytesNeeded;
} WDM_NDIS_REQUEST, *PWDM_NDIS_REQUEST;

WDF_DECLARE_CONTEXT_TYPE_WITH_NAME(WDM_NDIS_REQUEST, RequestGetMyContext);

// above are in global space

...

WDF_OBJECT_ATTRIBUTES  attributes;

WDF_OBJECT_ATTRIBUTES_INIT_CONTEXT_TYPE( &attributes, WDM_NDIS_REQUEST );
```

## Requirements

|  |  |
| --- | --- |
| Target platform | [Universal](https://go.microsoft.com/fwlink/p/?linkid=531356) |
| Minimum KMDF version | 1.0 |
| Minimum UMDF version | 2.0 |
| Header | Wdfobject.h (include Wdf.h) |

## See also

[**WDF_OBJECT_ATTRIBUTES**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/ns-wdfobject-_wdf_object_attributes)

[**WDF_OBJECT_ATTRIBUTES_INIT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/nf-wdfobject-wdf_object_attributes_init)

[**WDF_OBJECT_ATTRIBUTES_SET_CONTEXT_TYPE**](https://learn.microsoft.com/windows-hardware/drivers/wdf/wdf-object-attributes-set-context-type)

