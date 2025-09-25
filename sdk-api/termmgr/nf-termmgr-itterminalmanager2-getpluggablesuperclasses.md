# ITTerminalManager2::GetPluggableSuperclasses

## Description

The
**GetPluggableSuperclasses** method gets the public CLSIDs for all pluggable terminal superclasses in the registry.

## Parameters

### `pdwNumSuperclasses` [in, out]

The number of superclasses retrieved. If *pSuperclasses* is **NULL**, this argument is used to get the total number of pluggable terminal superclasses registered in the registry. If *pSuperclasses* is not **NULL**, this argument is used to pass the size, in IIDs, of the *pSuperclasses* buffer, and the method returns the number of IIDs copied into buffer memory.

### `pSuperclasses` [out]

Pointer to an IID buffer allocated by the user.

If the buffer is **NULL**, the method returns the count of superclasses in the buffer. Otherwise, the method returns the IIDs of the pluggable terminal superclasses registered on the system.

## Return value

This method can return one of these values.

| Value | Meaning |
| --- | --- |
| **S_OK** | Method succeeded. |
| **E_FAIL** | Method failed. |

## See also

[ITTerminalManager2](https://learn.microsoft.com/windows/desktop/api/termmgr/nn-termmgr-itterminalmanager2)