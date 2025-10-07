# InetGetAutodial function

\[This function is unsupported and may be altered or unavailable in future versions of Windows. \]

The **InetGetAutodial** function returns the autodial settings from the registry.

## Parameters

*lpfEnable* \[out\]

Indicates whether autodial is enabled. A value of **TRUE** upon return indicates autodial is enabled.

*lpszEntryName* \[out\]

On return, contains the name of the phone book entry that is set for autodial.

*cbEntryNameSize* \[in\]

Size of the buffer allocated by the caller for the phone book entry name.

## Return value

This function can return one of these values.

| Return code | Description |
|------------------------------------------------------------------------------------------------------------|-----------------------------------------------------------------------------------------------------------------------------------------------------------|
| **ERROR\_SUCCESS** | The call was successful.<br> |
| **ERROR\_BAD\_ARGUMENTS** | *lpfEnable* or *lpszEntryName* contains a **NULL** pointer, or the value of *cbEntryNameSize* is zero.<br> |
| **ERROR\_NOT\_ENOUGH\_MEMORY** | There was insufficient memory to allocate internal buffers.<br> |
| **ERROR\_INSUFFICIENT\_BUFFER** | *cbEntryNameSize* does not indicate that the buffer pointed to by *lpszEntryName* is large enough to receive the name of the phone book entry.<br> |

## Remarks

This function has no associated import library or header file; you must call it using the [**LoadLibrary**](https://learn.microsoft.com/windows/win32/api/libloaderapi/nf-libloaderapi-loadlibrarya) and [**GetProcAddress**](https://learn.microsoft.com/windows/win32/api/libloaderapi/nf-libloaderapi-getprocaddress) functions.

## Requirements

| Requirement | Value |
|----------------|----------------------------------------------------------------------------------------|
| DLL<br> | Inetcfg.dll |

