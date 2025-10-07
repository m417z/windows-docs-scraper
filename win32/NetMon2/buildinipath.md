# BuildINIPath function

The **BuildINIPath** function returns a fully qualified path to an INI file that corresponds to information you enter.

## Parameters

*FullPath*

Buffer that receives the fully qualified INI file name.

*IniFileName*

Name of the INI file (the full file name minus the filename extension).

## Return value

If the function is successful, the return value is a pointer to the fully qualified INI file name.

If the function is unsuccessful, the return value is **NULL**.

## Remarks

The path that this function returns is a fully qualified path to an INI file that corresponds to information you enter. For example, if you enter XNS or TCP, the function generates a path to Xns.ini or Tcp.ini, respectively.

## Requirements

| Requirement | Value |
|-------------------------------------|---------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 2000 Professional \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows 2000 Server \[desktop apps only\]<br> |
| Header<br> | Netmon.h |
| Library<br> | Parser.lib |
| DLL<br> | Nmapi.dll |

