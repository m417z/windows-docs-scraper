# KsSetMajorFunctionHandler function

## Description

The **KsSetMajorFunctionHandler** function sets the handler for a specified major function to use the internal dispatching. It routes through a KSDISPATCH_TABLE contained in the opaque object header to be the first element within a structure pointed to by a **FsContext** within a file object. The dispatching assumes the table and **FsContext** structure are initialized by the device using **KsAllocateObjectHeader**.

## Parameters

### `DriverObject` [in]

Specifies the driver object whose major function is to be handled.

### `MajorFunction` [in]

Specifies the major function identifier to be handled. This sets the major function pointer in the driver object to an internal function that then dispatches to the **KSDISPATCH_TABLE** function. The pointer to this table is assumed to be the first element in a structure pointed to by **FsContext** in the file object of the specific IRP being dispatched. The valid major function identifiers are as listed.

| Identifier | Description |
| --- | --- |
| IRP_MJ_CREATE | Create IRP. In this instance, a create request could be used for either creating a new instance of a filter, or for creating some object such as a pin under a filter or a clock under a pin. This assumes that the first element in the driver object's extent contains a KSDEVICE_HEADER structure that is used to find the type of object to create, based on the name passed. If a parent file object is specified, then that object's KSDISPATCH_TABLE.ChildCreateHandlerTable in the **FsContext** is looked at to determine what handler to use for the create, or use the device object's table. |
| IRP_MJ_CLOSE | Close IRP. |
| IRP_MJ_DEVICE_CONTROL | Device control IRP. |
| IRP_MJ_READ | Read IRP. |
| IRP_MJ_WRITE | Write IRP. |
| IRP_MJ_FLUSH_BUFFERS | Flush IRP. |
| IRP_MJ_QUERY_SECURITY | Query security information. |
| IRP_MJ_SET_SECURITY | Set security information. |
| KSDISPATCH_FASTIO | This flag may be added to the MajorFunction identifier in order to specify that the entry refers to the fast I/O dispatch table, rather than the typical major function entry. This is valid only with IRP_MJ_READ, IRP_MJ_WRITE or IRP_MJ_DEVICE_CONTROL. The driver is responsible for creating the DriverObject->FastIoDispatch table. As with normal dispatching, if a handler is set for the driver object, all file objects must handle that fast I/O, even if the entry just points to DispatchFastIoDeviceControlFailure or a similar function. |

## Return value

Returns STATUS_SUCCESS if the MajorFunction identifier is valid.

## Remarks

If a major function handler is set for a driver object, all file objects must handle that major function, even if the entry just points to **KsDispatchInvalidDeviceRequest**.

```cpp
KSDISPATCH_FASTIO
```

This flag may be used to specify that the fast I/O entry should be set rather than the IRP-based entry.