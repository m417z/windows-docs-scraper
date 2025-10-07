# Configure callback function

The **Configure** function configures the expert within the expert DLL.

The expert must implement the **Configure** function. When the function call is received, the expert displays a dialog box that enables the user to change any configurable item.

## Parameters

*hExpertKey* \[in\]

Unique expert identifier.

The unique identifier is passed back on all expert-specific Network Monitor functions. Be aware that the identifier may not be the same expert key as the one passed to the [**Run**](https://learn.microsoft.com/windows/win32/netmon2/run) function. Do not store the expert key from the **Configure** call.

*ppConfig* \[in, out\]

A pointer to a pointer to an [**EXPERTCONFIG**](https://learn.microsoft.com/windows/win32/netmon2/expertconfig) structure upon entry.

After a successful exit, the referenced [**EXPERTCONFIG**](https://learn.microsoft.com/windows/win32/netmon2/expertconfig) structure contains the new configuration data.

*pExpertStartupInfo* \[in\]

A pointer to the capture element with focus when the expert started.

*StartupFlags* \[in\]

The flags that indicate how the expert should use the *pExpertStartupInfo* parameter. The only flag defined is **EXPERT\_STARTUP\_FLAG\_USE\_STARTUP\_DATA\_OVER\_CONFIG\_DATA**. The flag indicates that the expert will use the *pExpertStartupInfo* parameter rather than the *ppConfig* parameter that passed in. Typically, you set the flag when you start the expert from a context menu.

*hWnd* \[in\]

A handle to the parent window. Use the handle to open a dialog box.

## Return value

If the function is successful (that is, if a current configuration exists), the return value is **TRUE**.

If the function is unsuccessful, the return value is **FALSE**.

## Remarks

Network Monitor calls the **Configure** function with the current configuration of the expert, if one exists. The expert displays a dialog box, with which you can change any configurable item.

When *ppConfig* is passed in and Network Monitor does not have a configuration stored for the specified expert, the parameter value can be **NULL**. In this case, the **Configure** function assumes hard-coded default values (or, uses the startup information) to open the dialog box.

The configuration data can also be **NULL** when the **Configure** function returns, and a **NULL** was passed-in. This situation occurs when Network Monitor does not have a stored default, and the user presses **Cancel**.

The beginning of the [**EXPERTCONFIG**](https://learn.microsoft.com/windows/win32/netmon2/expertconfig) data structure includes a Private section that stores the structure size information. The size of the **EXPERTCONFIG** structure should include the reserved **DWORD** length that appears at the beginning of the structure. For example, if your configuration data requires 20 bytes of storage space, allocate 24 bytes to store the data. If a *ppConfig* is **NULL**, the **Configure** function calls the [**ExpertAllocMemory**](https://learn.microsoft.com/windows/win32/netmon2/expertallocmemory) function to allocate a new configuration that is the correct size. If the buffer is not enough to hold the expert data, the expert should call the [**ExpertReallocMemory**](https://learn.microsoft.com/windows/win32/netmon2/expertreallocmemory) function.

## Requirements

| Requirement | Value |
|-------------------------------------|-------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 2000 Professional \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows 2000 Server \[desktop apps only\]<br> |
| Header<br> | Netmon.h |

