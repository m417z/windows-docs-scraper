## Description

The **OPLOCK_KEY_CONTEXT** structure is returned from [IoGetOplockKeyContextEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-iogetoplockkeycontextex). This structure contains oplock keys for a specific file object.

## Members

### `Version`

The oplock key version. The version is set to one of the following values:

| Value | Meaning |
|---|---|
| **OPLOCK_KEY_VERSION_WIN7** | This is a Windows 7 oplock key. |
| **OPLOCK_KEY_VERSION_WIN8** | This is a Windows 8 oplock key. |

### `Flags`

A set of flags that indicate the oplock key type. **Flags** is set to one or both of the following values:

| Value | Meaning |
|---|---|
| OPLOCK_KEY_FLAG_PARENT_KEY | A valid oplock key is present in **ParentOplockKey.** |
| OPLOCK_KEY_FLAG_TARGET_KEY | A valid oplock key is present in **TargetOplockKey.** |

### `ParentOplockKey`

A **GUID** that represents the parent oplock key value.

### `TargetOplockKey`

A **GUID** that represents the target oplock key value.

### `Reserved`

## Remarks

If an oplock is requested for a file during an [IRP_MJ_CREATE](https://learn.microsoft.com/windows-hardware/drivers/ifs/irp-mj-create) request, a file system that supports oplocks will attach an oplock key context to the file object created. The oplock key context is later available through a pointer to an **OPLOCK_KEY_CONTEXT** structure. The **OPLOCK_KEY_CONTEXT** structure is returned from a call to [IoGetOplockKeyContextEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-iogetoplockkeycontextex).

## See also

[IoGetOplockKeyContextEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-iogetoplockkeycontextex)

[Oplock Semantics](https://learn.microsoft.com/windows-hardware/drivers/ifs/oplock-semantics)