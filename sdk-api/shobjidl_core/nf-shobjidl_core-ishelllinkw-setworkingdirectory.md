# IShellLinkW::SetWorkingDirectory

## Description

Sets the name of the working directory for a Shell link object.

## Parameters

### `pszDir`

Type: **LPCTSTR**

The address of a buffer that contains the name of the new working directory.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The working directory is optional unless the target requires a working directory. For example, if an application creates a Shell link to a Microsoft Word document that uses a template residing in a different directory, the application would use this method to set the working directory.