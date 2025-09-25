# IProcessInitializer::Startup

## Description

Called when Dllhost.exe starts.

## Parameters

### `punkProcessControl` [in]

A pointer to the [IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown) interface of the COM component starting up.

**Windows XP/2000:** This parameter is always **NULL**.

## Return value

This method can return the standard return values E_INVALIDARG, E_OUTOFMEMORY, E_UNEXPECTED, E_FAIL, and S_OK.

## Remarks

The [IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown) interface referenced by *punkProcessControl* must belong to a COM component that implements an [IProcessInitControl](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-iprocessinitcontrol) interface; this interface supports the single method [ResetInitializerTimeout](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-iprocessinitcontrol-resetinitializertimeout). The initialization code in **Startup** can call the **ResetInitializerTimeout** method, with *dwSecondsRemaining* set equal to the number of seconds remaining before the startup of the component times out.

## See also

[IProcessInitializer](https://learn.microsoft.com/windows/desktop/api/comsvcs/nn-comsvcs-iprocessinitializer)