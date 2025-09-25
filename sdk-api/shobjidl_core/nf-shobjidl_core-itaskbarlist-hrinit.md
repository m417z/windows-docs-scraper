# ITaskbarList::HrInit

## Description

Initializes the taskbar list object. This method must be called before any other [ITaskbarList](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-itaskbarlist) methods can be called.

## Return value

Type: **HRESULT**

Returns S_OK if successful, or an error value otherwise. If the method fails, no other methods can be called. The calling application should release the interface pointer.