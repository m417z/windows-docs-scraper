# PERSISTENT_RESERVE_COMMAND structure

## Description

The PERSISTENT_RESERVE_COMMAND structure is used together with the [**IOCTL_STORAGE_PERSISTENT_RESERVE_IN**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ni-ntddstor-ioctl_storage_persistent_reserve_in) and [**IOCTL_STORAGE_PERSISTENT_RESERVE_OUT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ni-ntddstor-ioctl_storage_persistent_reserve_out)
requests to obtain and control information about persistent reservations and reservation keys that are active within a device server.

## Members

### `Version`

The version of this structure.

### `Size`

The size of this structure.

### `DUMMYUNIONNAME`

### `DUMMYUNIONNAME.PR_IN`

### `DUMMYUNIONNAME.PR_IN.ServiceAction`

The service action code for this IOCTL_STORAGE_PERSISTENT_RESERVE_IN request. PR_IN.ServiceAction can be one of the following values:
RESERVATION_ACTION_READ_KEYS
RESERVATION_ACTION_READ_RESERVATIONS

### `DUMMYUNIONNAME.PR_IN.Reserved1`

Reserved. Must be zero.

### `DUMMYUNIONNAME.PR_IN.AllocationLength`

The number of bytes allocated for the returned parameter list.

### `DUMMYUNIONNAME.PR_OUT`

### `DUMMYUNIONNAME.PR_OUT.ServiceAction`

The service action code for this IOCTL_STORAGE_PERSISTENT_RESERVE_OUT request. PR_OUT.ServiceAction can be one of the following values:

* RESERVATION_ACTION_REGISTER
* RESERVATION_ACTION_RESERVE
* RESERVATION_ACTION_RELEASE
* RESERVATION_ACTION_CLEAR
* RESERVATION_ACTION_PREEMPT
* RESERVATION_ACTION_PREEMPT_ABORT
* RESERVATION_ACTION_REGISTER_IGNORE_EXISTING

### `DUMMYUNIONNAME.PR_OUT.Reserved1`

Reserved. Must be zero.

### `DUMMYUNIONNAME.PR_OUT.Type`

A value that specifies the characteristics of the persistent reservation. PR_OUT.Type can be one of the following values:

* RESERVATION_TYPE_WRITE_EXCLUSIVE
* RESERVATION_TYPE_EXCLUSIVE
* RESERVATION_TYPE_WRITE_EXCLUSIVE_REGISTRANTS
* RESERVATION_TYPE_EXCLUSIVE_REGISTRANTS

### `DUMMYUNIONNAME.PR_OUT.Scope`

A value that specifies whether the persistent reservation applies to the entire logical unit or a specific element of the logical unit. PR_OUT.Scope can be one of the following values:

* RESERVATION_SCOPE_LU
* RESERVATION_SCOPE_ELEMENT

### `DUMMYUNIONNAME.PR_OUT.ParameterList`

The space for additional SCSI Persistent Reserve Out command parameters.

## Remarks

The behavior of the storage device when a SCSI Persistent Reserve In command or a SCSI Persistent Reserve Out command is received is described in the SCSI Primary Commands - 2 (SPC-2) specification.

## See also

[**IOCTL_STORAGE_PERSISTENT_RESERVE_IN**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ni-ntddstor-ioctl_storage_persistent_reserve_in)

[**IOCTL_STORAGE_PERSISTENT_RESERVE_OUT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddstor/ni-ntddstor-ioctl_storage_persistent_reserve_out)