# CF_OPEN_FILE_FLAGS enumeration

## Description

Flags to request various permissions on opening a file.

## Constants

### `CF_OPEN_FILE_FLAG_NONE:0x00000000`

No open file flags.

### `CF_OPEN_FILE_FLAG_EXCLUSIVE:0x00000001`

When specified, [CfOpenFileWithOplock](https://learn.microsoft.com/windows/win32/api/cfapi/nf-cfapi-cfopenfilewithoplock) returns a *share none* handle and requests an RH (OPLOCK_LEVEL_CACHE_READ \| OPLOCK_LEVEL_CACHE_HANDLE) oplock on the file.

A normal [CreateFile](https://learn.microsoft.com/windows/win32/api/fileapi/nf-fileapi-createfilea) call that opens for any of FILE_EXECUTE \| FILE_READ_DATA \| FILE_WRITE_DATA \| FILE_APPEND_DATA \| DELETE (or either/both GENERIC_READ \| GENERIC_WRITE) will break the oplock due to the sharing conflict, as described in the **Remarks** section. *The oplock owner will get to finish and acknowledge.*

### `CF_OPEN_FILE_FLAG_WRITE_ACCESS:0x00000002`

When specified, [CfOpenFileWithOplock](https://learn.microsoft.com/windows/win32/api/cfapi/nf-cfapi-cfopenfilewithoplock) attempts to open the file or directory with FILE_READ_DATA/FILE_LIST_DIRECTORY and FILE_WRITE_DATA/FILE_ADD_FILE access; otherwise it attempts to open the file or directory with FILE_READ_DATA/FILE_LIST_DIRECTORY.

### `CF_OPEN_FILE_FLAG_DELETE_ACCESS:0x00000004`

When specified, [CfOpenFileWithOplock](https://learn.microsoft.com/windows/win32/api/cfapi/nf-cfapi-cfopenfilewithoplock) attempts to open the file or directory with DELETE access; otherwise it opens the file normally.

### `CF_OPEN_FILE_FLAG_FOREGROUND:0x00000008`

When this flag is used, [CfOpenFileWithOplock](https://learn.microsoft.com/windows/win32/api/cfapi/nf-cfapi-cfopenfilewithoplock) does not request an oplock. This should be used when the caller is acting as a foreground application. i.e., they don’t care whether the file handle created by this API causes sharing violations for other callers, and they don’t care about breaking any oplocks that may already be on the file. So, they open the handle without requesting an oplock.

**Note:** The default *background* behavior requests an oplock when opening the file handle so that their call fails if there’s already an oplock, and they can be told to close their handle if they need to get out of the way to avoid causing a sharing violation later.\
Unless the caller specifies CF_OPEN_FILE_FLAG_EXCLUSIVE to **CfOpenFileWithOplock**, the oplock they get will be only OPLOCK_LEVEL_CACHE_READ, not (OPLOCK_LEVEL_CACHE_READ \| OPLOCK_LEVEL_CACHE_HANDLE), so there won’t be the sharing violation protection a background app might normally want.

## Remarks

A background application typically wants to operate transparently on files. In particular, they want to avoid causing sharing violations to other (foreground) openers. To do that, they take a (OPLOCK_LEVEL_CACHE_READ \| OPLOCK_LEVEL_CACHE_HANDLE) oplock, such as would be granted by using CF_OPEN_FILE_FLAG_EXCLUSIVE with [CfOpenFileWithOplock](https://learn.microsoft.com/windows/win32/api/cfapi/nf-cfapi-cfopenfilewithoplock). Then, if some other opener comes along whose requested share/access modes conflict with the background application's mode, the background application's oplock breaks. This prompts the background app to close its file handle (for a Cf handle, that causes it to become invalid – the real underlying handle has been closed). Once the background app closes its handle, the other request to open proceeds without encountering the sharing violation. This all works because of the OPLOCK_LEVEL_CACHE_HANDLE part of the oplock. Without CF_OPEN_FILE_FLAG_EXCLUSIVE, the oplock only has OPLOCK_LEVEL_CACHE_READ protection, so the sharing violation protection is not provided.

When CF_OPEN_FILE_FLAG_EXCLUSIVE is not specified, the open is *share all* and it gets a OPLOCK_LEVEL_CACHE_READ oplock.

A normal [CreateFile](https://learn.microsoft.com/windows/win32/api/fileapi/nf-fileapi-createfilea) call will not break the oplock. If the normal **CreateFile** specifies a sharing mode that conflicts with the Cf handle's access (for instance, if the normal **CreateFile** does not specify FILE_SHARE_READ), the normal **CreateFile** will fail with ERROR_SHARING_VIOLATION. The oplock doesn't break until the other caller issues a conflicting I/O, such as a write. When that happens *the oplock break is advisory only*.

## See also

[CfOpenFileWithOplock](https://learn.microsoft.com/windows/win32/api/cfapi/nf-cfapi-cfopenfilewithoplock)

[CreateFile](https://learn.microsoft.com/windows/win32/api/fileapi/nf-fileapi-createfilea)