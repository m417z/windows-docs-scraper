# _SRIOV_PROXY_QUERY_LUID_OUTPUT structure

## Description

Stores the local unique
identifier of the SR_IOV device implementing the interface. This structure is the output buffer for the [IOCTL_SRIOV_PROXY_QUERY_LUID](https://learn.microsoft.com/windows-hardware/drivers/ddi/pcivirt/ni-pcivirt-ioctl_sriov_proxy_query_luid) request.

## Members

### `DeviceLuid`

Local unique
identifier of the SR_IOV device implementing the interface.

## Syntax

```cpp
typedef struct _SRIOV_PROXY_QUERY_LUID_OUTPUT {
  LUID  DeviceLuid;
} SRIOV_PROXY_QUERY_LUID_OUTPUT, SRIOV_PROXY_QUERY_LUID_OUTPUT;
```

## See also

[IOCTL_SRIOV_PROXY_QUERY_LUID](https://learn.microsoft.com/windows-hardware/drivers/ddi/pcivirt/ni-pcivirt-ioctl_sriov_proxy_query_luid)