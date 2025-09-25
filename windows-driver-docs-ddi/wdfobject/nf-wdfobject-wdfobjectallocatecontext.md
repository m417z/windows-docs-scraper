# WdfObjectAllocateContext function

## Description

[Applies to KMDF and UMDF]

The **WdfObjectAllocateContext** method allocates context space for a specified framework object.

## Parameters

### `Handle` [in]

A handle to a framework object.

### `ContextAttributes` [in]

A pointer to a caller-supplied [WDF_OBJECT_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/ns-wdfobject-_wdf_object_attributes) structure that describes the context space.

### `Context` [out]

A pointer to a location that receives a pointer to the allocated context space.

## Return value

**WdfObjectAllocateContext** returns STATUS_SUCCESS if the operation succeeds. Otherwise, this method might return one of the following values:

| Return code | Description |
| --- | --- |
| **STATUS_INVALID_PARAMETER** | An invalid parameter was detected. |
| **STATUS_OBJECT_NAME_INVALID** | The **ContextTypeInfo** member of the WDF_OBJECT_ATTRIBUTES structure that the *ContextAttributes* parameter specified was invalid. |
| **STATUS_INSUFFICIENT_RESOURCES** | Context space could not be allocated. |
| **STATUS_OBJECT_NAME_EXISTS** | The driver has already allocated context space that matches the **ContextTypeInfo** member of the WDF_OBJECT_ATTRIBUTES structure that *ContextAttributes* specifies. In this situation, the pointer in the *Context* parameter receives a pointer to the existing context space and does not allocate duplicate context space. |
| **STATUS_DELETE_PENDING** | The object that the *Handle* parameter specifies is being deleted. In this situation, the framework does not allocate context space. |

This method might also return other [NTSTATUS values](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values).

A bug check occurs if the driver supplies an invalid object handle.

## Remarks

Typically, drivers create object context space by specifying a [WDF_OBJECT_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/ns-wdfobject-_wdf_object_attributes) structure when they call a framework object's creation method, such as [WdfDeviceCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdevicecreate).

If you want your driver to allocate more than one type of context space to some of its objects, the driver can call **WdfObjectAllocateContext** one or more times after it has called an object's creation method. Each call to **WdfObjectAllocateContext** must specify a different context type. (The **ContextTypeInfo** member of the WDF_OBJECT_ATTRIBUTES structure identifies the context type.)

If your driver calls **WdfObjectAllocateContext** more than once for a given object, you can provide separate [EvtCleanupCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/nc-wdfobject-evt_wdf_object_context_cleanup) and [EvtDestroyCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/nc-wdfobject-evt_wdf_object_context_destroy) callback functions for each context.

When calling **WdfObjectAllocateContext**, do not specify a **ParentObject** in the [WDF_OBJECT_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/ns-wdfobject-_wdf_object_attributes) structure.

When the framework allocates context space for an object, it also zero-initializes the context space.

For more information about object context space, see [Framework Object Context Space](https://learn.microsoft.com/windows-hardware/drivers/wdf/framework-object-context-space).

For more information about the cleanup rules for a framework object hierarchy, see [Framework Object Life Cycle](https://learn.microsoft.com/windows-hardware/drivers/wdf/framework-object-life-cycle).

#### Examples

The following code example creates context space for a request object. The context space is based on the example's REQUEST_CONTEXT structure.

```cpp
typedef struct _REQUEST_CONTEXT {
  WDFMEMORY InputMemoryBuffer;
  WDFMEMORY OutputMemoryBuffer;
} REQUEST_CONTEXT, *PREQUEST_CONTEXT;

PREQUEST_CONTEXT  reqContext = NULL;
WDF_OBJECT_ATTRIBUTES  attributes;

WDF_OBJECT_ATTRIBUTES_INIT_CONTEXT_TYPE(
                                        &attributes,
                                        REQUEST_CONTEXT
                                        );
status = WdfObjectAllocateContext(
                                  Request,
                                  &attributes,
                                  &reqContext
                                  );
```

## See also

[WDF_OBJECT_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfobject/ns-wdfobject-_wdf_object_attributes)

[WDF_OBJECT_ATTRIBUTES_INIT_CONTEXT_TYPE](https://learn.microsoft.com/windows-hardware/drivers/wdf/wdf-object-attributes-init-context-type)

[WdfDeviceCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdevicecreate)