# RegNotifyChangeKeyValue function

## Description

Notifies the caller about changes to the attributes or contents of a specified registry key.

## Parameters

### `hKey` [in]

A handle to an open registry key. This handle is returned by the
[RegCreateKeyEx](https://learn.microsoft.com/windows/desktop/api/winreg/nf-winreg-regcreatekeyexa) or [RegOpenKeyEx](https://learn.microsoft.com/windows/desktop/api/winreg/nf-winreg-regopenkeyexa) function. It can also be one of the following
[predefined keys](https://learn.microsoft.com/windows/desktop/SysInfo/predefined-keys):

**HKEY_CLASSES_ROOT**
**HKEY_CURRENT_CONFIG**
**HKEY_CURRENT_USER**
**HKEY_LOCAL_MACHINE**
**HKEY_USERS**
This parameter must be a local handle. If
**RegNotifyChangeKeyValue** is called with a remote handle, it returns ERROR_INVALID_HANDLE.

The key must have been opened with the KEY_NOTIFY access right. For more information, see
[Registry Key Security and Access Rights](https://learn.microsoft.com/windows/desktop/SysInfo/registry-key-security-and-access-rights).

### `bWatchSubtree` [in]

If this parameter is TRUE, the function reports changes in the specified key and its subkeys. If the parameter is **FALSE**, the function reports changes only in the specified key.

### `dwNotifyFilter` [in]

A value that indicates the changes that should be reported. This parameter can be one or more of the following values.

| Value | Meaning |
| --- | --- |
| **REG_NOTIFY_CHANGE_NAME**<br><br>0x00000001L | Notify the caller if a subkey is added or deleted. |
| **REG_NOTIFY_CHANGE_ATTRIBUTES**<br><br>0x00000002L | Notify the caller of changes to the attributes of the key, such as the security descriptor information. |
| **REG_NOTIFY_CHANGE_LAST_SET**<br><br>0x00000004L | Notify the caller of changes to a value of the key. This can include adding or deleting a value, or changing an existing value. |
| **REG_NOTIFY_CHANGE_SECURITY**<br><br>0x00000008L | Notify the caller of changes to the security descriptor of the key. |
| **REG_NOTIFY_THREAD_AGNOSTIC**<br><br>0x10000000L | Indicates that the lifetime of the registration must not be tied to the lifetime of the thread issuing the **RegNotifyChangeKeyValue** call.<br><br>**Note** This flag value is only supported in Windows 8 and later. |

### `hEvent` [in, optional]

A handle to an event. If the *fAsynchronous* parameter is **TRUE**, the function returns immediately and changes are reported by signaling this event. If *fAsynchronous* is **FALSE**, *hEvent* is ignored.

### `fAsynchronous` [in]

If this parameter is **TRUE**, the function returns immediately and reports changes by signaling the specified event. If this parameter is **FALSE**, the function does not return until a change has occurred.

If *hEvent* does not specify a valid event, the *fAsynchronous* parameter cannot be **TRUE**.

## Return value

If the function succeeds, the return value is ERROR_SUCCESS.

If the function fails, the return value is a nonzero error code defined in Winerror.h. You can use the
[FormatMessage](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-formatmessage) function with the FORMAT_MESSAGE_FROM_SYSTEM flag to get a generic description of the error.

## Remarks

This function detects a single change. After the caller receives a notification event, it should call the function again to receive the next notification.

**Note** On Windows NT, Windows 2000, and Windows XP calling **RegNotifyChangeKeyValue** for a particular key handle causes change notifications to continue to occur for as long as the key handle is valid. This causes a second call to **RegNotifyChangeKeyValue** to return immediately, if any changes have occurred in the interim period between the first and second calls. If the API is being used asynchronously, the passed event handle will be signaled immediately if any interim changes have occurred.

This function cannot be used to detect changes to the registry that result from using the [RegRestoreKey](https://learn.microsoft.com/windows/desktop/api/winreg/nf-winreg-regrestorekeya) function.

If the specified key is closed, the event is signaled. This means that an application should not depend on the key being open after returning from a wait operation on the event.

The **REG_NOTIFY_THREAD_AGNOSTIC** flag introduced in Windows 8 enables the use of **RegNotifyChangeKeyValue** for ThreadPool threads.

If the thread that called
**RegNotifyChangeKeyValue** exits, the event is signaled. To continue to monitor additional changes in the value of the key, call
**RegNotifyChangeKeyValue** again from another thread.

With the exception of **RegNotifyChangeKeyValue** calls with **REG_NOTIFY_THREAD_AGNOSTIC** set, this function must be called on persistent threads. If the calling thread is from a thread pool and it is not persistent, the event is signaled every time the thread terminates, not just when there is a registry change. To ensure accurate results, run the thread pool work in a persistent thread by using the [SetThreadpoolCallbackPersistent](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-setthreadpoolcallbackpersistent) function, or create your own thread using the [CreateThread](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-createthread) function. (For the original thread pool API, specify WT_EXECUTEINPERSISTENTTHREAD using the [QueueUserWorkItem](https://learn.microsoft.com/windows/desktop/api/threadpoollegacyapiset/nf-threadpoollegacyapiset-queueuserworkitem) function.)

This function should not be called multiple times with the same value for the *hKey* but different values for the *bWatchSubtree* and *dwNotifyFilter* parameters. The function will succeed but the changes will be ignored. To change the
watch parameters, you must first close the key handle by calling
[RegCloseKey](https://learn.microsoft.com/windows/desktop/api/winreg/nf-winreg-regclosekey), reopen the key handle by calling
[RegOpenKeyEx](https://learn.microsoft.com/windows/desktop/api/winreg/nf-winreg-regopenkeyexa), and then call **RegNotifyChangeKeyValue** with the new parameters.

Each time a process calls **RegNotifyChangeKeyValue** with the same set of parameters, it establishes another wait operation, creating a resource leak. Therefore, check that you are not calling **RegNotifyChangeKeyValue** with the same parameters until the previous wait operation has completed.

To monitor registry operations in more detail, see [Registry](https://learn.microsoft.com/windows/desktop/ETW/registry).

**Windows XP/2000:** When **RegNotifyChangeKeyValue** is called for a particular key handle, change notifications occur for as long as the key handle is valid. This causes a second call to **RegNotifyChangeKeyValue** to return immediately, if any changes occur in the interim between the first and second calls. If the function is being used asynchronously, the passed event handle will be signaled immediately if any changes occur in the interim.

#### Examples

The following program illustrates how to use **RegNotifyChangeKeyValue**.

```cpp
#include <windows.h>
#include <tchar.h>
#include <stdio.h>

//void main(int argc, char *argv[])
void __cdecl _tmain(int argc, TCHAR *argv[])
{
   DWORD  dwFilter = REG_NOTIFY_CHANGE_NAME |
                     REG_NOTIFY_CHANGE_ATTRIBUTES |
                     REG_NOTIFY_CHANGE_LAST_SET |
                     REG_NOTIFY_CHANGE_SECURITY;

   HANDLE hEvent;
   HKEY   hMainKey;
   HKEY   hKey;
   LONG   lErrorCode;

   // Display the usage error message.
   if (argc != 3)
   {
      _tprintf(TEXT("Usage: notify [HKLM|HKU|HKCU|HKCR|HCC] [<subkey>]\n"));
      return;
   }

   // Convert parameters to appropriate handles.
   if (_tcscmp(TEXT("HKLM"), argv[1]) == 0) hMainKey=HKEY_LOCAL_MACHINE;
   else if(_tcscmp(TEXT("HKU"), argv[1]) == 0) hMainKey=HKEY_USERS;
   else if(_tcscmp(TEXT("HKCU"), argv[1]) == 0) hMainKey=HKEY_CURRENT_USER;
   else if(_tcscmp(TEXT("HKCR"), argv[1]) == 0) hMainKey=HKEY_CLASSES_ROOT;
   else if(_tcscmp(TEXT("HCC"), argv[1]) == 0) hMainKey=HKEY_CURRENT_CONFIG;
   else
   {
      _tprintf(TEXT("Usage: notify [HKLM|HKU|HKCU|HKCR|HCC] [<subkey>]\n"));
      return;
   }

   // Open a key.
    lErrorCode = RegOpenKeyEx(hMainKey, argv[2], 0, KEY_NOTIFY, &hKey);
   if (lErrorCode != ERROR_SUCCESS)
   {
      _tprintf(TEXT("Error in RegOpenKeyEx (%d).\n"), lErrorCode);
      return;
   }

   // Create an event.
   hEvent = CreateEvent(NULL, TRUE, FALSE, NULL);
   if (hEvent == NULL)
   {
      _tprintf(TEXT("Error in CreateEvent (%d).\n"), GetLastError());
      return;
   }

   // Watch the registry key for a change of value.
   lErrorCode = RegNotifyChangeKeyValue(hKey,
                                        TRUE,
                                        dwFilter,
                                        hEvent,
                                        TRUE);
   if (lErrorCode != ERROR_SUCCESS)
   {
      _tprintf(TEXT("Error in RegNotifyChangeKeyValue (%d).\n"), lErrorCode);
      return;
   }

   // Wait for an event to occur.
   _tprintf(TEXT("Waiting for a change in the specified key...\n"));
   if (WaitForSingleObject(hEvent, INFINITE) == WAIT_FAILED)
   {
      _tprintf(TEXT("Error in WaitForSingleObject (%d).\n"), GetLastError());
      return;
   }
   else _tprintf(TEXT("\nChange has occurred.\n"));

   // Close the key.
   lErrorCode = RegCloseKey(hKey);
   if (lErrorCode != ERROR_SUCCESS)
   {
      _tprintf(TEXT("Error in RegCloseKey (%d).\n"), GetLastError());
      return;
   }

   // Close the handle.
   if (!CloseHandle(hEvent))
   {
      _tprintf(TEXT("Error in CloseHandle.\n"));
      return;
   }
}

```

## See also

[RegCloseKey](https://learn.microsoft.com/windows/desktop/api/winreg/nf-winreg-regclosekey)

[RegDeleteKey](https://learn.microsoft.com/windows/desktop/api/winreg/nf-winreg-regdeletekeya)

[RegEnumKeyEx](https://learn.microsoft.com/windows/desktop/api/winreg/nf-winreg-regenumkeyexa)

[RegEnumValue](https://learn.microsoft.com/windows/desktop/api/winreg/nf-winreg-regenumvaluea)

[RegQueryInfoKey](https://learn.microsoft.com/windows/desktop/api/winreg/nf-winreg-regqueryinfokeya)

[RegQueryValueEx](https://learn.microsoft.com/windows/desktop/api/winreg/nf-winreg-regqueryvalueexa)

[Registry Functions](https://learn.microsoft.com/windows/desktop/SysInfo/registry-functions)