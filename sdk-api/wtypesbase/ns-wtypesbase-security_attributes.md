## Description

The **SECURITY\_ATTRIBUTES** structure contains the [*security descriptor*](https://learn.microsoft.com/windows/win32/api/winnt/ns-winnt-security_descriptor) for an object and specifies whether the handle retrieved by specifying this structure is inheritable. This structure provides security settings for objects created by various functions, such as [**CreateFile**](https://learn.microsoft.com/windows/win32/api/fileapi/nf-fileapi-createfilew), [**CreatePipe**](https://learn.microsoft.com/windows/win32/api/namedpipeapi/nf-namedpipeapi-createpipe), [**CreateProcess**](https://learn.microsoft.com/windows/win32/api/processthreadsapi/nf-processthreadsapi-createprocessa), [**RegCreateKeyEx**](https://learn.microsoft.com/windows/win32/api/winreg/nf-winreg-regcreatekeyexw), or [**RegSaveKeyEx**](https://learn.microsoft.com/windows/win32/api/winreg/nf-winreg-regsavekeyexa).

## Members

### `nLength`

The size, in bytes, of this structure. Set this value to the size of the **SECURITY\_ATTRIBUTES** structure.

### `lpSecurityDescriptor`

A pointer to a [**SECURITY\_DESCRIPTOR**](https://learn.microsoft.com/windows/win32/api/winnt/ns-winnt-security_descriptor) structure that controls access to the object. If the value of this member is **NULL**, the object is assigned the default security descriptor associated with the [*access token*](https://learn.microsoft.com/windows/win32/secauthz/access-tokens) of the calling process. This is not the same as granting access to everyone by assigning a **NULL** [*discretionary access control list*](https://learn.microsoft.com/windows/win32/secauthz/dacls-and-aces) (DACL). By default, the default DACL in the access token of a process allows access only to the user represented by the access token.
For information about creating a security descriptor, see [Creating a Security Descriptor](https://learn.microsoft.com/windows/win32/secauthz/creating-a-security-descriptor-for-a-new-object-in-c--).

### `bInheritHandle`

A Boolean value that specifies whether the returned handle is inherited when a new process is created. If this member is **TRUE**, the new process inherits the handle.

## Remarks

## See also