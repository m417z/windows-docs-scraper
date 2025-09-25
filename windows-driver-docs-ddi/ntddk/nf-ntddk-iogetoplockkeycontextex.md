## Description

The **IoGetOplockKeyContext** routine returns a dual oplock key context for a file object.

## Parameters

### `FileObject`

The file object to query for an oplock key context.

## Return value

A pointer to an [**OPLOCK_KEY_CONTEXT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_oplock_key_context) structure containing the parent and target oplock keys for *FileObject*. Otherwise, NULL if *FileObject* has no oplock keys.

## Remarks

On Windows 8 and later versions of Windows, use **IoGetOplockKeyContextEx** instead of [IoGetOplockKeyContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-iogetoplockkeycontext), as the latter only returns a target oplock key context.

## See also

[IoGetOplockKeyContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-iogetoplockkeycontext)

[**OPLOCK_KEY_CONTEXT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_oplock_key_context)

[**OPLOCK_KEY_ECP_CONTEXT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-oplock_key_ecp_context)