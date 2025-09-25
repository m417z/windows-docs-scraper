# LSA_AUTH_INFORMATION structure

## Description

The **LSA_AUTH_INFORMATION** structure contains authentication information for a trusted domain.

## Members

### `LastUpdateTime`

A
[LARGE_INTEGER](https://learn.microsoft.com/windows/win32/api/winnt/ns-winnt-large_integer-r1) structure that uses the Coordinated Universal Time (Greenwich Mean Time) format to indicate the time that this value was set. For more information about Coordinated Universal Time, see the
[FILETIME](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-filetime) structure.

### `AuthType`

Specifies one of the following values to indicate the type of authentication information in the **AuthInfo** buffer.

| Value | Meaning |
| --- | --- |
| **TRUST_AUTH_TYPE_NONE** | The format is unknown and will be ignored. |
| **TRUST_AUTH_TYPE_NT4OWF** | The Windows NT 4.0 one-way format (OWF) of a plaintext password. Note that you cannot derive the clear password back from the OWF form of the password. <br><br>The system sets this information. |
| **TRUST_AUTH_TYPE_CLEAR** | Plaintext password to use for the trust. |
| **TRUST_AUTH_TYPE_VERSION** | Plaintext password version number. |

### `AuthInfoLength`

Specifies the size, in bytes, of the **AuthInfo** member.

### `AuthInfo`

Pointer to an array of bytes that contains the type of authentication information indicated by the **AuthType** member.