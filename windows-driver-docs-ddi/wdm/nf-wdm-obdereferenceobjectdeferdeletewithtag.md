## Description

The **ObDereferenceObjectDeferDeleteWithTag** routine decrements the reference count for the specified object, defers deletion of the object to avoid deadlocks, and writes a four-byte tag value to the object to support [object reference tracing](https://learn.microsoft.com/windows-hardware/drivers/debugger/object-reference-tracing).

## Parameters

### `Object` [in]

A pointer to the object. The caller obtains this pointer either when it creates the object, or from a previous call to the [ObReferenceObjectByHandleWithTag](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-obreferenceobjectbyhandlewithtag) routine after it opens the object.

### `Tag` [in]

Specifies a four-byte, custom tag value. For more information, see the following Remarks section.

## Remarks

**ObDereferenceObjectDeferDeleteWithTag** is similar to [ObDereferenceObjectWithTag](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-obdereferenceobjectwithtag) except that, when the reference count of the object reaches zero, **ObDereferenceObjectDeferDeleteWithTag** passes the object deletion request to a worker thread. The worker thread, which runs at IRQL = PASSIVE_LEVEL, later deletes the object.

If the immediate deletion of an object by the current thread might cause a deadlock, do not call **ObDereferenceObjectWithTag** to dereference the object. Instead, call **ObDereferenceObjectDeferDeleteWithTag** to dereference the object.

For example, such a deadlock can occur if **ObDereferenceObjectWithTag** is used to dereference a [Kernel Transaction Manager](https://learn.microsoft.com/windows-hardware/drivers/kernel/windows-kernel-mode-kernel-transaction-manager) (KTM) object when a higher-level driver on the driver stack is holding a lock.

For more information about object permanence and object attributes, see [ObDereferenceObjectWithTag](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-obdereferenceobjectwithtag). For more information about object references, see [Life Cycle of an Object](https://learn.microsoft.com/windows-hardware/drivers/kernel/life-cycle-of-an-object).

The [ObDereferenceObjectDeferDelete](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-obdereferenceobjectdeferdelete) routine is similar to **ObDereferenceObjectDeferDeleteWithTag**, except that it does not enable the caller to write a custom tag to an object. In Windows 7 and later versions of Windows, **ObDereferenceObjectDeferDelete** always writes a default tag value ('tlfD') to the object. A call to **ObDereferenceObjectDeferDelete** has the same effect as a call to **ObDereferenceObjectDeferDeleteWithTag** that specifies *Tag* = 'tlfD'.

To view an object reference trace in the [Windows debugging tools](https://learn.microsoft.com/windows-hardware/drivers/debugger), use the [!obtrace](https://learn.microsoft.com/windows-hardware/drivers/debugger/-obtrace) kernel-mode debugger extension. In Windows 7, the [!obtrace](https://learn.microsoft.com/windows-hardware/drivers/debugger/-obtrace) extension is enhanced to display object reference tags, if object reference tracing is enabled. By default, object reference tracing is turned off. Use the [Global Flags Editor](https://learn.microsoft.com/windows-hardware/drivers/debugger/gflags) (Gflags) to enable object reference tracing. For more information, see [Object Reference Tracing with Tags](https://learn.microsoft.com/windows-hardware/drivers/kernel/object-reference-tracing-with-tags).

## See also

[ObDereferenceObjectDeferDelete](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-obdereferenceobjectdeferdelete)

[ObDereferenceObjectWithTag](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-obdereferenceobjectwithtag)

[ObReferenceObjectByHandleWithTag](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-obreferenceobjectbyhandlewithtag)