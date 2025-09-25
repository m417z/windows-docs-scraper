# _PARCLASS_INFORMATION structure

## Description

The PARCLASS_INFORMATION structure specifies information about a parallel port, pointers to callback routines to operate a parallel port, and pointers to callback routines to read and write to a parallel device.

## Members

### `Controller`

Specifies the base I/O address allocated to a parallel port.

### `EcrController`

### `SpanOfController`

Specifies the range in bytes of I/O address space allocated to a parallel port.

### `DetermineIeeeModes`

Pointer to the [PDETERMINE_IEEE_MODES](https://learn.microsoft.com/windows-hardware/drivers/ddi/parallel/nc-parallel-pdetermine_ieee_modes) callback routine that determines which IEEE protocols a parallel device supports.

### `NegotiateIeeeMode`

Pointer to the [PNEGOTIATE_IEEE_MODE](https://learn.microsoft.com/windows-hardware/drivers/ddi/parallel/nc-parallel-pnegotiate_ieee_mode) callback routine that negotiates the fastest protocol that the system-supplied bus driver for parallel ports supports from among those specified by the caller.

### `TerminateIeeeMode`

Pointer to the [PTERMINATE_IEEE_MODE](https://learn.microsoft.com/windows-hardware/drivers/ddi/parallel/nc-parallel-pterminate_ieee_mode) callback routine that terminates the current IEEE mode and sets the mode to IEEE_COMPATIBILITY.

### `IeeeFwdToRevMode`

Pointer to the [PPARALLEL_IEEE_FWD_TO_REV](https://learn.microsoft.com/windows-hardware/drivers/ddi/parallel/nc-parallel-pparallel_ieee_fwd_to_rev) callback routine that changes the transfer mode from forward to reverse.

### `IeeeRevToFwdMode`

Pointer to the [PPARALLEL_IEEE_REV_TO_FWD](https://learn.microsoft.com/windows-hardware/drivers/ddi/parallel/nc-parallel-pparallel_ieee_rev_to_fwd) callback routine that changes the transfer mode from reverse to forward.

### `ParallelRead`

Pointer to the [PPARALLEL_READ](https://learn.microsoft.com/windows-hardware/drivers/ddi/parallel/nc-parallel-pparallel_read) callback routine that a client can use to read from a parallel device.

### `ParallelWrite`

Pointer to the [PPARALLEL_WRITE](https://learn.microsoft.com/windows-hardware/drivers/ddi/parallel/nc-parallel-pparallel_write) callback routine that a client can use to write to a parallel device.

### `ParclassContext`

Pointer to the device extension of a parallel device's physical device object ([PDO](https://learn.microsoft.com/windows-hardware/drivers/)).

### `HardwareCapabilities`

Specifies which hardware capabilities are present. **HardwareCapabilities** is a bitwise OR of one or more of the following flags:

#### PPT_NO_HARDWARE_PRESENT

#### PPT_ECP_PRESENT

#### PPT_EPP_PRESENT

#### PPT_EPP_32_PRESENT

32-bit reads and writes are supported.

#### PPT_BYTE_PRESENT

#### PPT_BIDI_PRESENT

#### PPT_1284_3_PRESENT

### `FifoDepth`

Specifies the size, in words, of the ECP FIFO. The ECP FIFO word size, in bits, is the value of **FifoWidth**.

### `FifoWidth`

Specifies the ECP FIFO word size, in bits, which is the number of bits handled in parallel.

### `ParallelTryselect`

### `ParallelDeSelect`

## Syntax

```cpp
typedef struct _PARCLASS_INFORMATION {
  PUCHAR                    Controller;
  ULONG                     SpanOfController;
  PDETERMINE_IEEE_MODES     DetermineIeeeModes;
  PNEGOTIATE_IEEE_MODE      NegotiateIeeeMode;
  PTERMINATE_IEEE_MODE      TerminateIeeeMode;
  PPARALLEL_IEEE_FWD_TO_REV IeeeFwdToRevMode;
  PPARALLEL_IEEE_REV_TO_FWD IeeeRevToFwdMode;
  PPARALLEL_READ            ParallelRead;
  PPARALLEL_WRITE           ParallelWrite;
  PVOID                     ParclassContext;
  ULONG                     HardwareCapabilities;
  ULONG                     FifoDepth;
  ULONG                     FifoWidth;
} PARCLASS_INFORMATION, *PPARCLASS_INFORMATION;
```

## Remarks

A kernel-mode driver can obtain this information from the system-supplied bus driver for parallel ports using an [IOCTL_INTERNAL_PARCLASS_CONNECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/parallel/ni-parallel-ioctl_internal_parclass_connect) request. The system-supplied bus driver for parallel ports supplies all the callback routines.

A client uses this information to operate a parallel port and to read and write a parallel device. The callback routines can only be used by a driver that holds a lock on the parent parallel port. A driver obtains a lock by using an [IOCTL_INTERNAL_LOCK_PORT](https://learn.microsoft.com/windows-hardware/drivers/ddi/parallel/ni-parallel-ioctl_internal_lock_port) request.

For more information, see [Connecting to a Parallel Device](https://learn.microsoft.com/previous-versions/ff543942(v=vs.85)).

## See also

[PPARALLEL_WRITE](https://learn.microsoft.com/windows-hardware/drivers/ddi/parallel/nc-parallel-pparallel_write)

[PPARALLEL_READ](https://learn.microsoft.com/windows-hardware/drivers/ddi/parallel/nc-parallel-pparallel_read)

[PTERMINATE_IEEE_MODE](https://learn.microsoft.com/windows-hardware/drivers/ddi/parallel/nc-parallel-pterminate_ieee_mode)

[PNEGOTIATE_IEEE_MODE](https://learn.microsoft.com/windows-hardware/drivers/ddi/parallel/nc-parallel-pnegotiate_ieee_mode)

[PPARALLEL_IEEE_FWD_TO_REV](https://learn.microsoft.com/windows-hardware/drivers/ddi/parallel/nc-parallel-pparallel_ieee_fwd_to_rev)

[PDETERMINE_IEEE_MODES](https://learn.microsoft.com/windows-hardware/drivers/ddi/parallel/nc-parallel-pdetermine_ieee_modes)

[IOCTL_INTERNAL_PARCLASS_CONNECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/parallel/ni-parallel-ioctl_internal_parclass_connect)

[IOCTL_INTERNAL_LOCK_PORT](https://learn.microsoft.com/windows-hardware/drivers/ddi/parallel/ni-parallel-ioctl_internal_lock_port)

[PPARALLEL_IEEE_REV_TO_FWD](https://learn.microsoft.com/windows-hardware/drivers/ddi/parallel/nc-parallel-pparallel_ieee_rev_to_fwd)