# IShellLinkW::SetIDList

## Description

Sets the pointer to an item identifier list (PIDL) for a Shell link object.

## Parameters

### `pidl` [in]

Type: **PCIDLIST_ABSOLUTE**

The object's fully qualified PIDL.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

This method is useful when an application needs to set a Shell link to an object that is not a file, such as a Control Panel application, a printer, or another computer.