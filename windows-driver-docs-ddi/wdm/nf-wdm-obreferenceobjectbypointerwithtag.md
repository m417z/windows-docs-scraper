## Description

The **ObReferenceObjectByPointerWithTag** routine increments the reference count of the specified object, and writes a four-byte tag value to the object to support [object reference tracing](https://learn.microsoft.com/windows-hardware/drivers/debugger/object-reference-tracing).

## Parameters

### `Object` [in]

A pointer to the object. The caller obtains this pointer either when it creates the object, or from a previous call to the [ObReferenceObjectByHandleWithTag](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-obreferenceobjectbyhandlewithtag) routine after it opens the object.

### `DesiredAccess` [in]

Specifies the types of access to the object that the caller requests. This parameter is a bitmask of type [ACCESS_MASK](https://learn.microsoft.com/windows-hardware/drivers/kernel/access-mask). The interpretation of this field depends on the object type. Do not use any generic access rights.

### `ObjectType` [in, optional]

A pointer to an opaque structure that specifies the object type. This parameter points to an [OBJECT_TYPE](https://learn.microsoft.com/windows-hardware/drivers/kernel/eprocess) structure. Set *ObjectType* to **NULL** or to one of the following pointer values, which are declared in the Wdm.h header file: ***ExEventObjectType**, ***ExSemaphoreObjectType**, ***IoFileObjectType**, ***PsProcessType**, ***PsThreadType**, ***SeTokenObjectType**, ***TmEnlistmentObjectType**, ***TmResourceManagerObjectType**, ***TmTransactionManagerObjectType**, or ***TmTransactionObjectType**. This parameter can be **NULL** if *AccessMode* is **KernelMode**. If *ObjectType* is not **NULL**, the routine verifies that the supplied object type matches the object type of the object that the *Handle* parameter specifies.

### `AccessMode` [in]

Indicates the access mode to use for the access check. Set this parameter to one of the following **MODE** enumeration values:

- **UserMode**

- **KernelMode**

Lower-level drivers should specify **KernelMode**.

### `Tag` [in]

Specifies a four-byte, custom tag value. For more information, see the following Remarks section.

## Return value

**ObReferenceObjectByPointerWithTag** returns STATUS_SUCCESS if the call is successful. Possible error return values include the following:

| Return code | Description |
|---|---|
| **STATUS_OBJECT_TYPE_MISMATCH** | The *ObjectType* parameter specifies the wrong object type for the object that the *Object* parameter points to, or *ObjectType* is **NULL** but *AccessMode* is **UserMode**. |

## Remarks

This routine does access validation of the specified object. If access can be granted, the routine increments the object reference count. This increment prevents the object from being deleted while the caller uses the object. When the object is no longer needed, the caller should decrement the reference count by calling the [ObDereferenceObjectWithTag](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-obdereferenceobjectwithtag) or [ObDereferenceObjectDeferDeleteWithTag](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-obdereferenceobjectdeferdeletewithtag) routine.

For more information about object references, see [Life Cycle of an Object](https://learn.microsoft.com/windows-hardware/drivers/kernel/life-cycle-of-an-object).

The [ObReferenceObjectByPointer](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-obreferenceobjectbypointer) routine is similar to **ObReferenceObjectByPointerWithTag**, except that it does not enable the caller to write a custom tag to an object. In Windows 7 and later versions of Windows, **ObReferenceObjectByPointer** always writes a default tag value ('tlfD') to the object. A call to **ObReferenceObjectByPointer** has the same effect as a call to **ObReferenceObjectByPointerWithTag** that specifies *Tag* = 'tlfD'.

To view an object reference trace in the [Windows debugging tools](https://learn.microsoft.com/windows-hardware/drivers/debugger), use the [!obtrace](https://learn.microsoft.com/windows-hardware/drivers/debugger/-obtrace) kernel-mode debugger extension. In Windows 7, the [!obtrace](https://learn.microsoft.com/windows-hardware/drivers/debugger/-obtrace) extension is enhanced to display object reference tags, if object reference tracing is enabled. By default, object reference tracing is turned off. Use the [Global Flags Editor](https://learn.microsoft.com/windows-hardware/drivers/debugger/gflags) (Gflags) to enable object reference tracing. For more information, see [Object Reference Tracing with Tags](https://learn.microsoft.com/windows-hardware/drivers/kernel/object-reference-tracing-with-tags).

## See also

[ACCESS_MASK](https://learn.microsoft.com/windows-hardware/drivers/kernel/access-mask)

[OBJECT_TYPE](https://learn.microsoft.com/windows-hardware/drivers/kernel/eprocess)

[ObDereferenceObjectDeferDeleteWithTag](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-obdereferenceobjectdeferdeletewithtag)

[ObDereferenceObjectWithTag](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-obdereferenceobjectwithtag)

[ObReferenceObjectByPointer](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-obreferenceobjectbypointer)

[ZwClose](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ntclose)