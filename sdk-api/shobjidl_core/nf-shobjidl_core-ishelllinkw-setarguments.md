# IShellLinkW::SetArguments

## Description

Sets the command-line arguments for a Shell link object.

## Parameters

### `pszArgs` [in]

Type: **LPCTSTR**

A pointer to a buffer that contains the new command-line arguments. In the case of a Unicode string, there is no limitation on maximum string length. In the case of an ANSI string, the maximum length of the returned string varies depending on the version of Windows—MAX_PATH prior to Windows 2000 and INFOTIPSIZE (defined in Commctrl.h) in Windows 2000 and later.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

This method is useful when creating a link to an application that takes special flags as arguments, such as a compiler.

## See also

[IShellLink](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishelllinka)

[IShellLink::GetArguments](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ishelllinka-getarguments)

**IShellLinkA**

**IShellLinkW**