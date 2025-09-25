# IHWEventHandler::Initialize

## Description

Initializes an object that contains an implementation of the [IHWEventHandler](https://learn.microsoft.com/windows/desktop/api/shobjidl/nn-shobjidl-ihweventhandler) interface.

## Parameters

### `pszParams` [in]

Type: **LPCWSTR**

A pointer to a string buffer that contains the string from the following registry value.

```
HKEY_LOCAL_MACHINE
   Software
      Microsoft
         Windows
            CurrentVersion
               Explorer
                  AutoPlayHandlers
                     Handlers
                        HandlerName
                           InitCmdLine = string
```

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

This method receives the registry string stored in the InitCmdLine value under the
**AutoPlayHandlers**\**Handlers**\*HandlerName* key. Applications that have registered with AutoPlay as event handlers place this string into the registry as part of the registration process.