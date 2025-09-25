# QUEUE_USER_APC_FLAGS enumeration

## Description

Specifies the modifier flags for user-mode asynchronous procedure call (APC) objects.

## Constants

### `QUEUE_USER_APC_FLAGS_NONE`

No flags are passed. Behavior is identical to [QueueUserAPC function](https://learn.microsoft.com/windows/win32/api/processthreadsapi/nf-processthreadsapi-queueuserapc).

### `QUEUE_USER_APC_FLAGS_SPECIAL_USER_APC`

Queue a special user-mode APC instead of a regular user-mode APC.

### `QUEUE_USER_APC_CALLBACK_DATA_CONTEXT`

Receive the processor context that was interrupted when the thread was directed to call the APC function.

## Remarks

The *Parameter* argument of the [PAPCFUNC callback function](https://learn.microsoft.com/windows/win32/api/winnt/nc-winnt-papcfunc) is modified to point to an APC_CALLBACK_DATA structure (see below), which contains the original *Parameter* argument, a pointer to the interrupted processor context, and reserved fields.

```cpp
typedef struct _APC_CALLBACK_DATA {
    ULONG_PTR Parameter;
    PCONTEXT ContextRecord;
    ULONG_PTR Reserved0;
    ULONG_PTR Reserved1;
} APC_CALLBACK_DATA, *PAPC_CALLBACK_DATA;
```

## See also

[QueueUserAPC2](https://learn.microsoft.com/windows/win32/api/processthreadsapi/nf-processthreadsapi-queueuserapc2)