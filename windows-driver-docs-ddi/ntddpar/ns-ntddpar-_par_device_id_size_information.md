# _PAR_DEVICE_ID_SIZE_INFORMATION structure

## Description

The PAR_DEVICE_ID_SIZE_INFORMATION structure specifies the size, in bytes, of a buffer that can hold the IEEE 1284 device ID of a parallel device and a **NULL** terminator.

## Members

### `DeviceIdSize`

Specifies the size, in bytes, of a buffer that can hold the IEEE 1284 device ID of a parallel device and a **NULL** terminator.

## Syntax

```cpp
typedef struct _PAR_DEVICE_ID_SIZE_INFORMATION {
  ULONG DeviceIdSize;
} PAR_DEVICE_ID_SIZE_INFORMATION, *PPAR_DEVICE_ID_SIZE_INFORMATION;
```

## See also

[IOCTL_PAR_QUERY_DEVICE_ID](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddpar/ni-ntddpar-ioctl_par_query_device_id)

[IOCTL_PAR_QUERY_DEVICE_ID_SIZE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddpar/ni-ntddpar-ioctl_par_query_device_id_size)