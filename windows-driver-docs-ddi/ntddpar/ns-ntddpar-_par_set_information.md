# _PAR_SET_INFORMATION structure

## Description

The PAR_SET_INFORMATION structure specifies the initial operating status of a parallel port.

## Members

### `Init`

Specifies the operating status of the parallel port. Must be set to PARALLEL_INIT.

## Syntax

```cpp
typedef struct _PAR_SET_INFORMATION {
  UCHAR Init;
} PAR_SET_INFORMATION, *PPAR_SET_INFORMATION;
```

## Remarks

This structure is used with an [IOCTL_PAR_SET_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddpar/ni-ntddpar-ioctl_par_set_information) request.

## See also

[IOCTL_PAR_SET_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddpar/ni-ntddpar-ioctl_par_set_information)

[PAR_QUERY_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddpar/ns-ntddpar-_par_query_information)

[IOCTL_PAR_QUERY_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddpar/ni-ntddpar-ioctl_par_query_information)