## Description

The **KsReadFile** function performs a read against the specified file object. It is assumed the caller is serializing access to the file for operations against a FO_SYNCHRONOUS_IO file object. The function attempts to use **FastIoDispatch** if possible, or generates a read request against the device object. All relevant statistics are updated.

## Parameters

### `FileObject` [in]

Specifies the file object to perform the read against.

### `Event` [in, optional]

Optionally contains the event to use in the read. If no event is passed, the call is assumed to be on a synchronous file object. If not, the caller is waiting for the file object's event, or it may be asynchronously completed. If the file has been opened for synchronous I/O, this must be **NULL**. If the variable is used, it must be an event allocated by the object manager.

### `PortContext` [in, optional]

Optionally contains context information for a completion port.

### `IoStatusBlock` [out]

Specifies the address where the status information is to be returned. This is always assumed to be a valid address, regardless of the requester mode.

### `Buffer` [out]

Specifies the buffer in which to place the data read. If the buffer needs to be probed and locked, an exception handler is used, along with *RequesterMode*.

### `Length` [in]

Specifies the size of the buffer passed.

### `Key` [in, optional]

Optionally contains a key, or zero if none

### `RequestorMode` [in]

Indicates the processor mode to place in the read IRP if one needs to be generated. Additionally, it is used if the buffer needs to be probed and locked. This variable also determines if a fast I/O call can be performed. If the requester mode is not KernelMode, but the previous mode was, then fast I/O cannot be used.

## Return value

The **KsReadFile** function returns STATUS_SUCCESS if successful, STATUS_PENDING if action is pending, or it returns a read error if unsuccessful.