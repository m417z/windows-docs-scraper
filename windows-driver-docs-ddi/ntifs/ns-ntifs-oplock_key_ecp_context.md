## Description

The **OPLOCK_KEY_ECP_CONTEXT** structure is used to attach an oplock key to a file. This structure is obsolete for Windows 8 and later versions; filters should instead use [DUAL_OP_LOCK_KEY_ECP_CONTEXT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-dual_oplock_key_ecp_context).

## Members

### `OplockKey`

A GUID for the oplock key. This GUID is shared among different handles and identifies them as belonging to the same client cache. When two handles share the same oplock key, a request performed on one handle will not break an outstanding oplock on the other handle.

### `Reserved`

Reserved. Must be set to zero.

## Remarks

For information about how to use ECPs to associate extra information with a file when the file is created, see [Using Extra Create Parameters with an IRP_MJ_CREATE Operation](https://learn.microsoft.com/windows-hardware/drivers/ifs/using-ecps-to-process-irp-mj-create-operations-in-a-file-system-minifilter).

A minifilter should not alter the contents of the OPLOCK_KEY_ECP_CONTEXT structure when it sees the ECP coming down from above. You should use it to retrieve information about the oplock key ECP only. For more information about this issue, see [System-Defined ECPs](https://learn.microsoft.com/windows-hardware/drivers/ifs/system-defined-ecps).

The oplock key enables an application to open multiple handles to the same stream without breaking the application's own oplock. The oplock break only occurs after the application receives a sharing violation (STATUS_SHARING_VIOLATION).

Oplocks are granted on stream handles when a stream is opened. Such a stream handle can be associated with an oplock key. A caller can explicitly provide the oplock key to the [**IoCreateFileEx**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-iocreatefileex) routine to create the stream handle. If the caller does not explicitly specify an oplock key when the caller creates the handle, the operating system treats the handle as having a unique oplock key associated with the handle, so that the handle's key differs from any other key on any other handle. If a file operation is received on a handle other than the one on which the oplock was granted, and the oplock key that is associated with the oplock's handle differs from the key that is associated with the operation's handle, and that operation is incompatible with the currently granted oplock, then that oplock is broken. The oplock breaks even if it is the same process or thread performing the incompatible operation. For example, if a process opens a stream for which an exclusive oplock is granted and the same process then opens the same stream again, by using a different (or no) oplock key, the exclusive oplock is broken immediately.

Oplock keys are associated with handles when the handles are created. You can associate a handle with an oplock key even if no oplocks are granted.

For more information about oplocks and oplock keys, see [Oplock Semantics Overview](https://learn.microsoft.com/windows-hardware/drivers/ifs/oplock-overview).

## See also

[DUAL_OP_LOCK_KEY_ECP_CONTEXT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-dual_oplock_key_ecp_context)

[**IoCreateFileEx**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-iocreatefileex)