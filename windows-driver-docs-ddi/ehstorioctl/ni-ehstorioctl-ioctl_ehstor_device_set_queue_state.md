# IOCTL_EHSTOR_DEVICE_SET_QUEUE_STATE IOCTL

## Description

The **IOCTL_EHSTOR_DEVICE_SET_QUEUE_STATE** request is sent by silo drivers and applications to change the state of a storage device queue. IO requests in the storage device queue are held when the device is temporarily unauthorized.

## Parameters

### Major code

### Input buffer

The input buffer at **Irp->AssociatedIrp.SystemBuffer** contains an  **ACT_QUEUE_STATE** structure. **ACT_QUEUE_STATE** is declared in *ehstorioctl.h* as the following.

```
typedef struct tagACT_QUEUE_STATE
{
    BOOLEAN fFrozen;
} ACT_QUEUE_STATE;
```

### Input buffer length

The length of an  **ACT_QUEUE_STATE** structure.

### Output buffer

None.

### Output buffer length

None.

### Input/output buffer

### Input/output buffer length

### Status block

One of the following values can be returned in the **Status** field.

| Status Value | Description |
| --- | --- |
| STATUS_SUCCESS | The queue state was changed successfully. |
| STATUS_INVALID_BUFFER_SIZE | The input buffer length is too small. |
| STATUS_ACCESS_DENIED | The IOCTL request was not issued by a silo driver. |

## -fFrozen

The freeze state of the IO request queue for a storage device. If set to TRUE, the queue is frozen and all IO requests sent to the storage device are held. Otherwise, IO requests in the device queue are processed.

## Remarks

Silo drivers or applications can freeze the storage device IO request queue if temporary unauthorization is needed. Normally, temporary unauthorization occurs during low power states or when a policy requires locking of Enhanced Storage devices such as a locked user session. In such a case, it is preferable to put pending IO requests on hold rather than fail the IO requests and cause data loss.

To prevent abuse of the **IOCTL_EHSTOR_DEVICE_SET_QUEUE_STATE** request by applications, only a driver can issue this IOCTL. If sent from a user mode application, this request will fail with STATUS_ACCESS_DENIED.

## See also

[IOCTL_EHSTOR_DEVICE_GET_QUEUE_STATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ehstorioctl/ni-ehstorioctl-ioctl_ehstor_device_get_queue_state)