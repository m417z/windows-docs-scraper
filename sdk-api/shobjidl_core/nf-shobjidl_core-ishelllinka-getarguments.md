# IShellLinkA::GetArguments

## Description

Gets the command-line arguments associated with a Shell link object.

## Parameters

### `pszArgs` [out]

Type: **LPTSTR**

A pointer to the buffer that, when this method returns successfully, receives the command-line arguments.

### `cch` [in]

Type: **int**

The maximum number of characters that can be copied to the buffer supplied by the *pszArgs* parameter. In the case of a Unicode string, there is no limitation on maximum string length. In the case of an ANSI string, the maximum length of the returned string varies depending on the version of Windows—MAX_PATH prior to Windows 2000 and INFOTIPSIZE (defined in Commctrl.h) in Windows 2000 and later.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

In Windows 7 and later, it is recommended that you retrieve argument strings though [IPropertyStore](https://learn.microsoft.com/windows/desktop/api/propsys/nn-propsys-ipropertystore) (using the [PKEY_Link_Arguments](https://learn.microsoft.com/windows/desktop/properties/props-system-link-arguments) value) rather than this method, which can silently truncate the string if the provided buffer is not large enough. **IPropertyStore** allocates a string of the correct size.

## See also

[IShellLink](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishelllinka)

[IShellLink::SetArguments](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ishelllinka-setarguments)

**IShellLinkA**

**IShellLinkW**