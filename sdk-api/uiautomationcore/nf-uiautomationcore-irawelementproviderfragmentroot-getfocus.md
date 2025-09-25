# IRawElementProviderFragmentRoot::GetFocus

## Description

Retrieves the element in this fragment that has the input focus.

## Parameters

### `pRetVal` [out, retval]

Type: **[IRawElementProviderFragment](https://learn.microsoft.com/windows/desktop/api/uiautomationcore/nn-uiautomationcore-irawelementproviderfragment)****

Receives a pointer to the [IRawElementProviderFragment](https://learn.microsoft.com/windows/desktop/api/uiautomationcore/nn-uiautomationcore-irawelementproviderfragment)
interface of the
element in this fragment that has the input focus, if any; otherwise **NULL**.
This parameter is passed uninitialized.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IRawElementProviderFragmentRoot](https://learn.microsoft.com/windows/desktop/api/uiautomationcore/nn-uiautomationcore-irawelementproviderfragmentroot)