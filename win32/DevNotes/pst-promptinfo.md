# PST\_PROMPTINFO structure

\[Protected Storage (Pstore) is available for use in Windows Server 2003 and Windows XP. It is only available for read-only operations in Windows Server 2008 and Windows Vista, but may be unavailable in subsequent versions. Pstore uses an older implementation of data protection. Developers are strongly encouraged to take advantage of the stronger data protection provided by the [**CryptProtectData**](https://learn.microsoft.com/windows/win32/api/dpapi/nf-dpapi-cryptprotectdata) and [**CryptUnprotectData**](https://learn.microsoft.com/windows/win32/api/dpapi/nf-dpapi-cryptunprotectdata) functions.\]

Defines the prompting behavior of the Protected Store whenever it displays a user interface.

## Members

**cbSize**

The size of this structure.

**dwPromptFlags**

This flag is ignored.

| Value | Meaning |
|------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|-----------------------------------------------------------------------------------------------------------------------|
| **PST\_PF\_ALWAYS\_SHOW**<br>0x00000001 | Requests that the provider show the prompt dialog to the user even if it is not required for this access. <br> |
| **PST\_PF\_NEVER\_SHOW**<br>0x00000002 | Do not show the prompt dialog to the user.<br> |

**hwndApp**

The handle to the parent window for the user interface. The **hwndApp** member determines where the user interface appears. If **NULL** is passed, the desktop is considered to be the parent window.

**szPrompt**

The prompt string.

## Requirements

| Requirement | Value |
|-------------------|-------------------------------------------------------------------------------------|
| Header<br> | Pstore.h |

## See also

[**DeleteItem**](https://learn.microsoft.com/windows/win32/devnotes/ipstore-deleteitem)

[**OpenItem**](https://learn.microsoft.com/windows/win32/devnotes/ipstore-openitem)

[**ReadItem**](https://learn.microsoft.com/windows/win32/devnotes/ipstore-readitem)

[**WriteItem**](https://learn.microsoft.com/windows/win32/devnotes/ipstore-writeitem)

