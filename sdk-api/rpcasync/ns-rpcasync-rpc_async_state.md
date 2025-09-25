# RPC_ASYNC_STATE structure

## Description

The
**RPC_ASYNC_STATE** structure holds the state of an asynchronous remote procedure call. **RPC_ASYNC_STATE** is a handle to this structure, used to wait for, query, reply to, or cancel asynchronous calls.

## Members

### `Size`

Size of this structure, in bytes. The environment sets this member when
[RpcAsyncInitializeHandle](https://learn.microsoft.com/windows/desktop/api/rpcasync/nf-rpcasync-rpcasyncinitializehandle) is called. Do not modify this member.

### `Signature`

The run-time environment sets this member when
[RpcAsyncInitializeHandle](https://learn.microsoft.com/windows/desktop/api/rpcasync/nf-rpcasync-rpcasyncinitializehandle) is called. Do not modify this member.

### `Lock`

The run-time environment sets this member when
[RpcAsyncInitializeHandle](https://learn.microsoft.com/windows/desktop/api/rpcasync/nf-rpcasync-rpcasyncinitializehandle) is called. Do not modify this member.

### `Flags`

The **flags** member can be set to the following values.

| Constant | Meaning |
| --- | --- |
| **RPC_C_NOTIFY_ON_SEND_COMPLETE** | Posts a notification message when the asynchronous operation is complete. |

These flags are used with DCE pipes, which allow applications to send or receive data in multiple blocks. Programs can either send a continuous stream of data or wait for each block to be transmitted before it sends the next block. If it does not wait, the RPC run-time library will buffer the output until it can be sent. When the data transmission is complete, the RPC library sends the application a notification. If an application specifies the RPC_C_NOTIFY_ON_SEND_COMPLETE flag, the RPC library sends it a member of the
[RPC_NOTIFICATION_TYPES](https://learn.microsoft.com/windows/desktop/api/rpcasync/ne-rpcasync-rpc_notification_types) enumeration after it completes each send operation.

### `StubInfo`

Reserved for use by the stubs. Do not use this member.

### `UserInfo`

Use this member for any application-specific information that you want to keep track of in this structure.

### `RuntimeInfo`

Reserved for use by the RPC run-time environment. Do not use this member.

### `Event`

Type of event that occurred. The RPC run-time environment sets this field to a member of the
[RPC_ASYNC_EVENT](https://learn.microsoft.com/windows/desktop/api/rpcasync/ne-rpcasync-rpc_async_event) enumeration.

### `NotificationType`

Type of notification the RPC run time should use to notify the client for the occurrence of an event, such as completion of the call or completion of the event.

| Value | Meaning |
| --- | --- |
| **RpcNotificationTypeNone** | No notification is specified; [RPC_ASYNC_NOTIFICATION_INFO](https://learn.microsoft.com/windows/desktop/api/rpcasync/ns-rpcasync-rpc_async_notification_info) is not initialized. |
| **RpcNotificationTypeEvent** | The notification mechanism is a Windows event. |
| **RpcNotificationTypeApc** | The notification mechanism is a Windows asynchronous procedure call. |
| **RpcNotificationTypeIoc** | The notification mechanism is an I/O completion port. |
| **RpcNotificationTypeHwnd** | The notification mechanism is a Windows system message.<br><br>**Windows Server 2003 or later:** Notification via the HWND is deprecated. Do not use this value. |
| **RpcNotificationTypeCallback** | The notification mechanism is a function callback. |

### `u`

Contains asynchronous notification information formatted for the mechanism type specified in **NotificationType**.

**Note** Previous to Windows Vista, this member contained the specific syntax of the union currently specified by the [RPC_ASYNC_NOTIFICATION_INFO](https://learn.microsoft.com/windows/desktop/api/rpcasync/ns-rpcasync-rpc_async_notification_info) union.

### `Reserved`

Reserved for compatibility with future versions, if any. Do not use this member.

## Remarks

The client allocates space for the
**RPC_ASYNC_STATE** structure and an associated handle, and calls
[RpcAsyncInitializeHandle](https://learn.microsoft.com/windows/desktop/api/rpcasync/nf-rpcasync-rpcasyncinitializehandle) to initialize the structure. After the run-time environment has successfully initialized the structure, the client initializes the **NotificationType**, and exactly one of the following structures in the [RPC_ASYNC_NOTIFICATION_INFO](https://learn.microsoft.com/windows/desktop/api/rpcasync/ns-rpcasync-rpc_async_notification_info) union: **APC** for a Windows asynchronous procedure call, **IOC** for an I/O completion port, **HWND** for a Windows system message, or **hEvent** for a Windows event. If the chosen notification method is **RpcNotificationTypeNone**, no field of the union needs to be initialized. The RPC client may optionally initialize the **UserInfo** field as well.

## See also

[Asynchronous RPC](https://learn.microsoft.com/windows/desktop/Rpc/asynchronous-rpc)

[RpcAsyncAbortCall](https://learn.microsoft.com/windows/desktop/api/rpcasync/nf-rpcasync-rpcasyncabortcall)

[RpcAsyncCancelCall](https://learn.microsoft.com/windows/desktop/api/rpcasync/nf-rpcasync-rpcasynccancelcall)

[RpcAsyncCompleteCall](https://learn.microsoft.com/windows/desktop/api/rpcasync/nf-rpcasync-rpcasynccompletecall)

[RpcAsyncGetCallHandle](https://learn.microsoft.com/windows/desktop/api/rpcasync/nf-rpcasync-rpcasyncgetcallhandle)

[RpcAsyncGetCallStatus](https://learn.microsoft.com/windows/desktop/api/rpcasync/nf-rpcasync-rpcasyncgetcallstatus)

[RpcAsyncInitializeHandle](https://learn.microsoft.com/windows/desktop/api/rpcasync/nf-rpcasync-rpcasyncinitializehandle)

[RpcServerTestCancel](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-rpcservertestcancel)