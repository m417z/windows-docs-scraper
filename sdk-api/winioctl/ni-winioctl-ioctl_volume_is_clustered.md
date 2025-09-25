# IOCTL_VOLUME_IS_CLUSTERED IOCTL

## Description

Determines whether the specified volume is clustered.

To perform this operation, call the [**DeviceIoControl**](https://learn.microsoft.com/windows/win32/api/ioapiset/nf-ioapiset-deviceiocontrol) function with the following parameters.

```cpp
BOOL DeviceIoControl(
  (HANDLE) hDevice,             // handle to device
  IOCTL_VOLUME_IS_CLUSTERED,    // dwIoControlCode
  NULL,                         // lpInBuffer
  0,                            // nInBufferSize
  NULL,                         // lpOutBuffer
  0,                            // nOutBufferSize
  (LPDWORD) lpBytesReturned,    // number of bytes returned
  (LPOVERLAPPED) lpOverlapped   // OVERLAPPED structure
);
```

## Parameters

### Input buffer

### Input buffer length

### Output buffer

### Output buffer length

### Input/output buffer

### Input/output buffer length

### Status block

Irp->IoStatus.Status is set to STATUS_SUCCESS if the request is successful.

Otherwise, Status to the appropriate error condition as a NTSTATUS code.

For more information, see [NTSTATUS Values](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values).

## Remarks

The **IOCTL_VOLUME_IS_CLUSTERED** control code is valid only if the Cluster service is running.

The **ERROR_GEN_FAILURE** error indicates that the computer that currently owns the disk on which the volume resides is a server cluster node, but either the disk is a Physical Disk resource currently in an offline state or the disk is not a Physical Disk resource. To determine which of these situations exists, use the following steps:

1. Call the [ClusterEnum](https://learn.microsoft.com/windows/win32/api/clusapi/nf-clusapi-clusterenum) function to enumerate all Physical Disk resources in the cluster.
1. Search each enumerated Physical Disk resource for the volume by calling the [ClusterResourceControl](https://learn.microsoft.com/windows/win32/api/clusapi/nf-clusapi-clusterresourcecontrol) function with [CLUSCTL_RESOURCE_STORAGE_GET_DISK_INFO](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/clusctl-resource-storage-get-disk-info). If you cannot find the volume among the Physical Disk resources in the cluster, the volume does not reside on a Physical Disk resource.

The **ERROR_INVALID_FUNCTION** error indicates that the computer that currently owns the disk on which the volume resides is not a server cluster node or the disk is not a Physical Disk resource. To determine whether a computer is a server cluster node, call the [GetNodeClusterState](https://learn.microsoft.com/windows/win32/api/clusapi/nf-clusapi-getnodeclusterstate) function.

In Windows 8 and Windows Server 2012, this code is supported by the following technologies.

Technology | Supported
-----------|----------
Server Message Block (SMB) 3.0 protocol | No
SMB 3.0 Transparent Failover (TFO) | No
SMB 3.0 with Scale-out File Shares (SO) | No
Cluster Shared Volume File System (CsvFS) | Yes

## See also

* [DeviceIoControl](https://learn.microsoft.com/windows/win32/api/ioapiset/nf-ioapiset-deviceiocontrol)
* [Volume Management Control Codes](https://learn.microsoft.com/windows/desktop/FileIO/volume-management-control-codes)