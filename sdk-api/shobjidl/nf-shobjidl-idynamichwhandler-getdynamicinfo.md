# IDynamicHWHandler::GetDynamicInfo

## Description

Called by the system to determine whether a particular handler will be shown before the AutoPlay dialog is displayed.

## Parameters

### `pszDeviceID` [in]

Type: **LPCWSTR**

A pointer to a string that indicates the device path or drive root.

### `dwContentType` [in]

Type: **DWORD**

The content type.

### `ppszAction` [out]

Type: **LPWSTR***

A pointer to the new action string, or **NULL** if the default action string is to be used.

## Return value

Type: **HRESULT**

Returns S_OK if this handler is to be displayed, S_FALSE if it is to be hidden, or an error value otherwise.

## Remarks

To register a dynamic handler, add a REG_SZ named "DynamicHWHandlerCLSID" and assign it the CLSID of your IDynamicHWHandler implementation.

Example:

```
HKLM
   Software
      Microsoft
         Windows
            CurrentVersion
               Explorer
                  AutoplayHandlers
                     Handlers
                        YourHandler
                           DynamicHWHandlerCLSID = [REG_SZ] {xxxxxxxx-xxxx-xxxx-xxxx-xxxxxxxxxxxx}
```