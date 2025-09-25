# PSLookupPropertyHandlerCLSID function

## Description

Gets the class identifier (CLSID) of a per-computer, registered file property handler.

## Parameters

### `pszFilePath` [in]

Type: **PCWSTR**

Pointer to a null-terminated, Unicode buffer that contains the absolute path of the file whose property handler CLSID is requested.

### `pclsid` [out]

Type: **CLSID***

When this function returns, contains the requested property handler CLSID.

## Return value

Type: **PSSTDAPI**

Returns **S_OK** if successful, or an error value otherwise.

## Remarks

For information on how to register your handler, see [Initializing Property Handlers](https://learn.microsoft.com/windows/desktop/properties/building-property-handlers-property-handlers).

This function returns only those handlers registered under **HKEY_LOCAL_MACHINE**.

Most calling applications should not need to call this method or use [CoCreateInstance](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cocreateinstance) to create a property handler directly. Instead, calling applications should use [IShellItem2::GetPropertyStore](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ishellitem2-getpropertystore) to create a property store for a Shell item on Windows Vista. **IShellItem2::GetPropertyStore** provides the largest set of available properties for a Shell item, and the most options for customizing exactly which properties to return.

If no property handler is registered for the specified file, this function returns an error code. When this happens, it might still be possible to read certain file system properties from the property store returned from [IShellItem2::GetPropertyStore](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ishellitem2-getpropertystore).

Applications that need to create a property handler from code and that must run both on Windows Vista and on Windows XP can call [PSGetItemPropertyHandler](https://learn.microsoft.com/windows/desktop/api/propsys/nf-propsys-psgetitempropertyhandler) to create a property store for a Shell item through the Microsoft Windows Desktop Search (WDS) redistributable.

#### Examples

The following example, to be included as part of a larger program, demonstrates how to use [PSLookupPropertyHandlerCLSID](https://learn.microsoft.com/windows/desktop/api/propsys/nf-propsys-pslookuppropertyhandlerclsid).

```cpp
CLSID clsid;

HRESULT hr = PSLookupPropertyHandlerCLSID(L"C:\\windows\\system32\\shell32.dll", &clsid);

if (SUCCEEDED(hr))
{
    // clsid contains the CLSID of the property handler used for
    // C:\windows\system32\shell32.dll.
}
```

## See also

[IShellItem2::GetPropertyStore](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ishellitem2-getpropertystore)

[PSGetItemPropertyHandler](https://learn.microsoft.com/windows/desktop/api/propsys/nf-propsys-psgetitempropertyhandler)