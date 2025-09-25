# _WDF_OBJECT_ATTRIBUTES structure

## Description

[Applies to KMDF and UMDF]

The WDF_OBJECT_ATTRIBUTES structure describes attributes that can be associated with any framework object.

## Members

### `Size`

The size, in bytes, of this structure.

### `EvtCleanupCallback`

A pointer to the driver's [EvtCleanupCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/nc-wdfobject-evt_wdf_object_context_cleanup) callback function, or **NULL**.

### `EvtDestroyCallback`

A pointer to the driver's [EvtDestroyCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/nc-wdfobject-evt_wdf_object_context_destroy) callback function, or **NULL**.

### `ExecutionLevel`

A [WDF_EXECUTION_LEVEL](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/ne-wdfobject-_wdf_execution_level)-typed value that specifies the maximum IRQL at which the framework will call the object's event callback functions. For a list of framework objects for which the driver can specify an **ExecutionLevel** value, see [WDF_EXECUTION_LEVEL](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/ne-wdfobject-_wdf_execution_level).

### `SynchronizationScope`

A [WDF_SYNCHRONIZATION_SCOPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/ne-wdfobject-_wdf_synchronization_scope)-typed value that specifies how the framework will synchronize execution of the object's event callback functions. For a list of framework objects for which the driver can specify a **SynchronizationScope** value, see [WDF_SYNCHRONIZATION_SCOPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/ne-wdfobject-_wdf_synchronization_scope).

### `ParentObject`

A handle to the object's parent object, or **NULL** if the object does not have a driver-specified parent.

See [Summary of Framework Objects](https://learn.microsoft.com/windows-hardware/drivers/wdf/summary-of-framework-objects) for a table that shows the objects that allow a driver-specified parent. The table also shows the default parent of each object.

### `ContextSizeOverride`

If not zero, this value overrides the **ContextSize** member of the [WDF_OBJECT_CONTEXT_TYPE_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/ns-wdfobject-_wdf_object_context_type_info) structure that the **ContextTypeInfo** member references. This value is optional and can be zero. If the value is not zero, it must specify a size, in bytes, that is larger than the value that is specified for the **ContextSize** member of the WDF_OBJECT_CONTEXT_TYPE_INFO structure. For more information, see the following Remarks section.

### `ContextTypeInfo`

A pointer to a [WDF_OBJECT_CONTEXT_TYPE_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/ns-wdfobject-_wdf_object_context_type_info) structure. The [WDF_OBJECT_ATTRIBUTES_SET_CONTEXT_TYPE](https://learn.microsoft.com/windows-hardware/drivers/wdf/wdf-object-attributes-set-context-type) macro sets this pointer.

## Remarks

The WDF_OBJECT_ATTRIBUTES structure is used as an input argument to several methods that create framework objects.

To initialize a WDF_OBJECT_ATTRIBUTES structure, the driver must call [WDF_OBJECT_ATTRIBUTES_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/nf-wdfobject-wdf_object_attributes_init).

Additionally, if you are defining object-specific context information for an object, you must use the [WDF_OBJECT_ATTRIBUTES_SET_CONTEXT_TYPE](https://learn.microsoft.com/windows-hardware/drivers/wdf/wdf-object-attributes-set-context-type) macro.

Alternatively, you can use the [WDF_OBJECT_ATTRIBUTES_INIT_CONTEXT_TYPE](https://learn.microsoft.com/windows-hardware/drivers/wdf/wdf-object-attributes-init-context-type) macro instead of the WDF_OBJECT_ATTRIBUTES_INIT and WDF_OBJECT_ATTRIBUTES_SET_CONTEXT_TYPE macros.

For more information about using these macros, see [Framework Object Context Space](https://learn.microsoft.com/windows-hardware/drivers/wdf/framework-object-context-space).

Use the **ContextSizeOverride** member of WDF_OBJECT_ATTRIBUTES if you want to create [object context space](https://learn.microsoft.com/windows-hardware/drivers/wdf/framework-object-context-space) that has a variable length. For example, you might define a context space structure that contains an array, as follows:

```
typedef struct _MY_REQUEST_CONTEXT {
  ULONG  ByteCount;
  BYTE  Bytes[1];
} MY_REQUEST_CONTEXT, *PMY_REQUEST_CONTEXT;

WDF_DECLARE_CONTEXT_TYPE(MY_REQUEST_CONTEXT);
```

When your driver creates an object that uses the context space structure, it can use the **ContextSizeOverride** member to specify the context size that is needed for each individual object. For example, your driver might calculate the number of bytes that are needed in the array from the preceding example and then use **ContextSizeOverride** to specify the extra bytes, as follows:

```
WDF_OBJECT_ATTRIBUTES MyRequestObjectAttributes;
PMY_REQUEST_CONTEXT pMyContext;

WDF_OBJECT_ATTRIBUTES_INIT_CONTEXT_TYPE(
                                        &MyRequestObjectAttributes,
                                        MY_REQUEST_CONTEXT
                                        );
MyRequestObjectAttributes.ContextSizeOverride =
                          sizeof(MY_REQUEST_CONTEXT) + Num_Extra_Bytes - 1;
```

The driver can then create an object with a customized context size.

```
status = WdfRequestCreate(
                          &MyRequestObjectAttributes,
                          ioTarget,
                          &newRequest
                          );
```

For more information about the cleanup rules for a framework object hierarchy, see [Framework Object Life Cycle](https://learn.microsoft.com/windows-hardware/drivers/wdf/framework-object-life-cycle).

## See also

[WDF_OBJECT_ATTRIBUTES_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/nf-wdfobject-wdf_object_attributes_init)

[WDF_OBJECT_ATTRIBUTES_INIT_CONTEXT_TYPE](https://learn.microsoft.com/windows-hardware/drivers/wdf/wdf-object-attributes-init-context-type)

[WDF_OBJECT_ATTRIBUTES_SET_CONTEXT_TYPE](https://learn.microsoft.com/windows-hardware/drivers/wdf/wdf-object-attributes-set-context-type)

[WdfObjectAllocateContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/nf-wdfobject-wdfobjectallocatecontext)