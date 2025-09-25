# IOCTL_EHSTOR_DEVICE_GET_QUEUE_STATE IOCTL

## Description

The **IOCTL_EHSTOR_DEVICE_GET_QUEUE_STATE** request is sent by silo drivers and applications to determine the state of a storage device queue. IO requests in the storage device queue are held when the device is temporarily unauthorized. A storage device may become temporarily unauthorized in low power states or when there is a policy that requires locking Enhanced Storage devices such as when the user session is locked.

## Parameters

### Major code

### Input buffer

None.

### Input buffer length

None.

### Output buffer

The output buffer at **Irp->AssociatedIrp.SystemBuffer** contains an  **ACT_QUEUE_STATE** structure. **ACT_QUEUE_STATE** is declared in *ehstorioctl.h* as the following.

```
typedef struct tagACT_QUEUE_STATE
{
    BOOLEAN fFrozen;
} ACT_QUEUE_STATE;
```

### Output buffer length

The length of an  **ACT_QUEUE_STATE** structure.

### Input/output buffer

### Input/output buffer length

### Status block

One of the following values can be returned in the **Status** field.

| Status Value | Description |
| --- | --- |
| STATUS_SUCCESS | The queue state was returned successfully. |
| STATUS_BUFFER_TOO_SMALL | The output buffer length is too small. |

## -fFrozen

The freeze state of the IO request queue for a storage device. If set to TRUE, the queue is frozen and all IO requests sent to the storage device are held. Otherwise, IO requests in the device queue are processed.

## See also

[IOCTL_EHSTOR_DEVICE_SET_QUEUE_STATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ehstorioctl/ni-ehstorioctl-ioctl_ehstor_device_set_queue_state)