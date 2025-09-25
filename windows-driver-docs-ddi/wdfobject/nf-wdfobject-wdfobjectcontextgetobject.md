# WdfObjectContextGetObject function

## Description

[Applies to KMDF and UMDF]

The **WdfObjectContextGetObject** method returns a handle to the framework object that a specified context space belongs to.

## Parameters

### `ContextPointer` [in]

A pointer to object context space. The driver can obtain this pointer by calling [WdfObjectGetTypedContext](https://learn.microsoft.com/windows-hardware/drivers/wdf/wdfobjectgettypedcontext).

## Return value

**WdfObjectContextGetObject** returns a handle to a framework object.

## Remarks

For more information about object context space, see [Framework Object Context Space](https://learn.microsoft.com/windows-hardware/drivers/wdf/framework-object-context-space).

For more information about the cleanup rules for a framework object hierarchy, see [Framework Object Life Cycle](https://learn.microsoft.com/windows-hardware/drivers/wdf/framework-object-life-cycle).

#### Examples

The following code example obtains a handle to the framework object that a specified context space belongs to.

```cpp
WDFDEVICE  device;

device = WdfObjectContextGetObject(DeviceContext);
```

## See also

[WdfObjectGetTypedContext](https://learn.microsoft.com/windows-hardware/drivers/wdf/wdfobjectgettypedcontext)