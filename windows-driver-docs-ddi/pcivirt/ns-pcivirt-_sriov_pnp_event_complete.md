# _SRIOV_PNP_EVENT_COMPLETE structure

## Description

Stores the status for an event that the SR-IOV Physical Function (PF) driver should set for Plug and Play even completion. This structure is used in the input buffer of the [IOCTL_SRIOV_EVENT_COMPLETE](https://learn.microsoft.com/windows-hardware/drivers/ddi/pcivirt/ni-pcivirt-ioctl_sriov_event_complete) request.

## Members

### `QueryStatus`

Indicates the status to be returned in the PnP query IRP that is currently pended in the PF driver.

## Syntax

```cpp
typedef struct _SRIOV_PNP_EVENT_COMPLETE {
  NTSTATUS  QueryStatus;
} SRIOV_PNP_EVENT_COMPLETE, SRIOV_PNP_EVENT_COMPLETE;
```

## See also

[IOCTL_SRIOV_EVENT_COMPLETE](https://learn.microsoft.com/windows-hardware/drivers/ddi/pcivirt/ni-pcivirt-ioctl_sriov_event_complete)