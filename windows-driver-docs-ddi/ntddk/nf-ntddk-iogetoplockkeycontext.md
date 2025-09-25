## Description

The **IoGetOplockKeyContext** routine returns a target oplock key context for a file object.

## Parameters

### `FileObject`

The file object to query for an oplock key context.

## Return value

A pointer to an [**OPLOCK_KEY_ECP_CONTEXT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-oplock_key_ecp_context) structure containing the target oplock key for *FileObject*. Otherwise, NULL if *FileObject* has no target oplock key.

## Remarks

Use the **IoGetOplockKeyContext** routine only in Windows 7. Because [IoGetOplockKeyContextEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-iogetoplockkeycontextex) returns a dual oplock key context, it should be used in Windows 8 and later versions of Windows.

## See also

[IoGetOplockKeyContextEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-iogetoplockkeycontextex)

[**OPLOCK_KEY_CONTEXT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/ns-ntddk-_oplock_key_context)

[**OPLOCK_KEY_ECP_CONTEXT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-oplock_key_ecp_context)