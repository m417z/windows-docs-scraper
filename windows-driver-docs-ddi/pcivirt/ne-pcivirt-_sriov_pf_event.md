# _SRIOV_PF_EVENT enumeration

## Description

Defines event values for the SR-IOV device.

## Constants

### `SriovEventPfQueryStopDevice`

The SR-IOV device is stopped.

### `SriovEventPfRestart`

The SR-IOV device is restarted

### `SriovEventPfMaximum`

Reserved.

## Syntax

```cpp
typedef enum _SRIOV_PF_EVENT {
  SriovEventPfQueryStopDevice,
  SriovEventPfRestart,
  SriovEventPfMaximum
} SRIOV_PF_EVENT;
```

## See also

[IOCTL_SRIOV_EVENT_COMPLETE](https://learn.microsoft.com/windows-hardware/drivers/ddi/pcivirt/ni-pcivirt-ioctl_sriov_event_complete)

[IOCTL_SRIOV_NOTIFICATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/pcivirt/ni-pcivirt-ioctl_sriov_notification)