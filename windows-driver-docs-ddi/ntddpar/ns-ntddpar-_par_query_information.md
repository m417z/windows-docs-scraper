# _PAR_QUERY_INFORMATION structure

## Description

The PAR_QUERY_INFORMATION structure specifies the operating status of a parallel port.

## Members

### `Status`

Specifies the operating status of a parallel port. The value of **Status** is a bitwise OR of one or more of the following flags:

#### PARALLEL_INIT

#### PARALLEL_AUTOFEED

#### PARALLEL_PAPER_EMPTY

#### PARALLEL_OFF_LINE

#### PARALLEL_POWER_OFF

#### PARALLEL_NOT_CONNECTED

#### PARALLEL_BUSY

#### PARALLEL_SELECTED

## Syntax

```cpp
typedef struct _PAR_QUERY_INFORMATION {
  UCHAR Status;
} PAR_QUERY_INFORMATION, *PPAR_QUERY_INFORMATION;
```

## Remarks

This structure is used with an [IOCTL_PAR_QUERY_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddpar/ni-ntddpar-ioctl_par_query_information) request.

## See also

[IOCTL_PAR_SET_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddpar/ni-ntddpar-ioctl_par_set_information)

[IOCTL_PAR_QUERY_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddpar/ni-ntddpar-ioctl_par_query_information)

[PAR_SET_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddpar/ns-ntddpar-_par_set_information)