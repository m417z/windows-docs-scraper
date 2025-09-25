# NtNotifyChangeMultipleKeys function

## Description

[This function may be changed or removed from Windows without further notice. ]

Requests notification when a registry key or any of its subkeys changes.

## Parameters

### `MasterKeyHandle` [in]

A handle to an open key. The handle must be opened with the **KEY_NOTIFY** access right.

### `Count` [in, optional]

The number of keys objects provided in the *SubordinateObjects* parameter. This parameter must be 1.

### `SubordinateObjects` [in, optional]

Pointer to an array of [OBJECT_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/wudfwdm/ns-wudfwdm-_object_attributes) structures, one for each key. This array can contain one **OBJECT_ATTRIBUTES** structure and must not be a key in the same hive as the *MasterKeyHandle* key.

### `Event` [in, optional]

A handle to an event created by the caller. If *Event* is not **NULL**, the caller waits until the operation succeeds, at which time the event is signaled.

### `ApcRoutine` [in, optional]

A pointer to an asynchronous procedure call (APC) function supplied by the caller. If *ApcRoutine* is not **NULL**, the specified APC function executes after the operation completes. A [WORK_QUEUE_ITEM](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_work_queue_item) must be provided instead of ApcRoutine in the *ZwNotifyChangeMultipleKeys* variant.

### `ApcContext` [in, optional]

A pointer to a context supplied by the caller for its APC function. This value is passed to the APC function when it is executed. The *Asynchronous* parameter must be **TRUE**. If *ApcContext* is specified, the *Event* parameter must be **NULL**. A [WORK_QUEUE_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ne-wdm-_work_queue_type) must be provided instead of ApcContext in the *ZwNotifyChangeMultipleKeys* variant.

### `IoStatusBlock` [out]

A pointer to an [IO_STATUS_BLOCK](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/wdm/ns-wdm-_io_status_block) structure that contains the final status and information about the operation. For successful calls that return data, the number of bytes written to the *Buffer* parameter is supplied in the **Information** member of the **IO_STATUS_BLOCK** structure.

### `CompletionFilter` [in]

A bitmap of operations that trigger notification. This parameter can be one or more of the following flags.

| Value | Meaning |
| --- | --- |
| **REG_NOTIFY_CHANGE_NAME** | Notify the caller if a subkey is added or deleted. |
| **REG_NOTIFY_CHANGE_ATTRIBUTES** | Notify the caller of changes to the attributes of the key, such as the security descriptor information. |
| **REG_NOTIFY_CHANGE_LAST_SET** | Notify the caller of changes to a value of the key. This can include adding or deleting a value, or changing an existing value. |
| **REG_NOTIFY_CHANGE_SECURITY** | Notify the caller of changes to the security descriptor of the key. |

### `WatchTree` [in]

If this parameter is **TRUE**, the caller is notified about changes to all subkeys of the specified key. If this parameter is **FALSE**, the caller is notified only about changes to the specified key.

### `Buffer` [out, optional]

Reserved for system use. This parameter must be **NULL**.

### `BufferSize` [in]

Reserved for system use. This parameter must be zero.

### `Asynchronous` [in]

If this parameter is **TRUE**, the function returns immediately. If this parameter is **FALSE**, the function does not return until the specified event occurs.

## Return value

Returns an **NTSTATUS** or error code.

If the *Asynchronous* parameter is **TRUE** and the specified event has not yet occurred, the function returns **STATUS_PENDING**.

The forms and significance of **NTSTATUS** error codes are listed in the Ntstatus.h header file available in the WDK, and are described in the WDK documentation.

## Remarks

This function has no associated header file. You can also use the [LoadLibrary](https://learn.microsoft.com/windows/desktop/DevNotes/-loadlibrary) and [GetProcAddress](https://learn.microsoft.com/windows/desktop/DevNotes/-getprocaddress-) functions to dynamically link to Ntdll.dll.

## See also

[Registry Key Security and Access Rights](https://learn.microsoft.com/windows/desktop/SysInfo/registry-key-security-and-access-rights)