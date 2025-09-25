# PPARALLEL_READ callback

## Description

The PPARALLEL_READ-typed callback routine reads data from a parallel device. The system-supplied bus driver for parallel ports supplies this routine.

## Parameters

### `Context` [in]

Pointer to the device extension of a parallel device's physical device object ([PDO](https://learn.microsoft.com/windows-hardware/drivers/)).

### `Buffer` [out]

Pointer to a read buffer that the caller allocates.

### `NumBytesToRead` [in]

Specifies the number of bytes to read. Must less than or equal to the number of bytes in the caller-allocated read buffer.

### `NumBytesRead` [out]

Specifies the number of bytes that were actually read from the parallel device and saved in the caller-allocated read buffer.

### `Channel` [in]

Not used.

## Return value

| Return code | Description |
| --- | --- |
| **STATUS_SUCCESS** | The requested data was successfully transferred from the device. |
| **STATUS_*Xxx*** | An internal operation resulted in an NTSTATUS error. |

## Prototype

```cpp
typedef NTSTATUS ( *PPARALLEL_READ)(
  _In_  PVOID  Context,
  _Out_ PVOID  Buffer,
  _In_  ULONG  NumBytesToRead,
  _Out_ PULONG NumBytesRead,
  _In_  UCHAR  Channel
);
```

## Remarks

To obtain a pointer to the system-supplied PPARALLEL_READ callback, a kernel-mode driver uses an [IOCTL_INTERNAL_PARCLASS_CONNECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/parallel/ni-parallel-ioctl_internal_parclass_connect) request, which returns a [PARCLASS_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/parallel/ns-parallel-_parclass_information) structure. The **ParallelRead** member of the PARCLASS_INFORMATION structure is a pointer to this callback.

A client can only use this routine if it has a lock on a parallel port. A client obtains a lock on a parallel port by using an [IOCTL_INTERNAL_LOCK_PORT](https://learn.microsoft.com/windows-hardware/drivers/ddi/parallel/ni-parallel-ioctl_internal_lock_port) request.

The PPARALLEL_READ callback runs in the caller's thread at the IRQL of the caller.

## See also

[PPARALLEL_WRITE](https://learn.microsoft.com/windows-hardware/drivers/ddi/parallel/nc-parallel-pparallel_write)

[IOCTL_INTERNAL_LOCK_PORT](https://learn.microsoft.com/windows-hardware/drivers/ddi/parallel/ni-parallel-ioctl_internal_lock_port)