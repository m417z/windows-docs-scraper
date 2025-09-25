## Description

Determines in which execution environment the application is running – a host or an Isolated Environment.

## Parameters

### `isProcessInIsolatedWindowsEnvironment`

`[out]`

A pointer to a boolean value that receives the result of the API. This parameter will be `true` if the process is in an Isolated Windows Environment, `false` otherwise.

## Return value

Returns `S_OK` if the function succeeds. If it fails, it returns an `HRESULT` error code.

## Remarks

Any application using [Microsoft Defender Application Guard (MDAG)](https://learn.microsoft.com/windows/security/threat-protection/microsoft-defender-application-guard/md-app-guard-overview) will require the ability to find which execution environment it is running in. This is needed so that the app can behave appropriately to protect user/enterprise data, user identity, and the business interests of the app.

#### Examples

The following example shows how to use the `IsProcessInIsolatedWindowsEnvironment` API to determine the execution environment of the app.

```cpp
#define PrintInfo wprintf

typedef HRESULT (*pIsProcessInIsolatedWindowsEnvironment)
                  (_Out_ BOOL *isProcessInIsolatedWindowsEnvironment);

int PrintError(unsigned int line, HRESULT hr)
{
  wprintf_s(L"ERROR: Line:%d HRESULT: 0x%X\n", line, hr);
  return hr;
}

HRESULT TakeActionAsPerExecutionEnvironment()
{
  //For instance the action could be saving changes to user settings for the app.
  //Lets assume the app has made a design decision to save change to user settings if
  //the app is running on the host, and discard the changes to user settings if they were
  //changed in an Isolated Environment.

  HMODULE dllInstance (LoadLibrary(L"IsolatedWindowsEnvironmentUtils.dll"));

  if (nullptr == dllInstance)
  {
    PrintInfo(L" Cannot load the library IsolatedWindowsEnvironmentUtils.dll \n");
    return E_FAIL;
  }

  auto pfn = reinterpret_cast<pIsProcessInIsolatedWindowsEnvironment>

  (GetProcAddress(dllInstance, "IsProcessInIsolatedWindowsEnvironment"));

  if (nullptr == pfn)
  {
    PrintInfo(L"Function definition IsProcessInIsolatedWindowsEnvironment() is not found.\n");
    FreeLibrary(dllInstance);
    return E_FAIL;
  }

  BOOL isInIsolatedWindowsEnvironment = FALSE;

  HRESULT hr = pfn(&isInIsolatedWindowsEnvironment);

  if (FAILED(hr))
  {
    FreeLibrary(dllInstance);
    return PrintError(__LINE__, hr);
  }

  if (isInIsolatedWindowsEnvironment == TRUE) //app is running in Isolated Environment
  {
    //do not save changes to the app’s user settings in this case
    PrintInfo(L"Discarding changes to app’s user settings.\n");

    //<TO-DO-Start>
    //Add app specific custom logic here
    //<TO-DO-End>
  }
  else
  {
    //Save changes to the app’s user settings in this case
    PrintInfo(L"Saving changes to app’s user settings.\n");

    //<TO-DO-Start>
    //Add app specific custom logic here
    //<TO-DO-End>
  }

  FreeLibrary(dllInstance);
  return S_OK;
}
```

## See also

[Microsoft Defender Application Guard overview](https://learn.microsoft.com/windows/security/threat-protection/microsoft-defender-application-guard/md-app-guard-overview)

[IsolatedWindowsEnvironment](https://learn.microsoft.com/uwp/api/windows.security.isolation.isolatedwindowsenvironment)

[IsolatedWindowsEnvironmentHost](https://learn.microsoft.com/uwp/api/windows.security.isolation.isolatedwindowsenvironmenthost)