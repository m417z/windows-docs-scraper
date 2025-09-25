# CreateControlInput function

## Description

Creates a [CoreComponentInputSource](https://learn.microsoft.com/uwp/api/windows.ui.core.corecomponentinputsource) object in the caller’s UI thread.

## Parameters

### `riid` [in]

Interface ID of the object. Must to be set to the UUID for [ICoreInputSourceBase](https://learn.microsoft.com/uwp/api/windows.ui.core.icoreinputsourcebase), the default interface of [CoreComponentInputSource](https://learn.microsoft.com/uwp/api/windows.ui.core.corecomponentinputsource), which is `9F488807-4580-4BE8-BE68-92A9311713BB`.

### `ppv` [out]

Pointer to receive the [CoreComponentInputSource](https://learn.microsoft.com/uwp/api/windows.ui.core.corecomponentinputsource) object.

## Return value

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

This API must be called from the UI thread to create [CoreComponentInputSource](https://learn.microsoft.com/uwp/api/windows.ui.core.corecomponentinputsource) object. The object created using this API can be used only in that thread in which it was created.

If the call is successful, the caller can call **QueryInterface** on the returned [ICoreInputSourceBase](https://learn.microsoft.com/uwp/api/windows.ui.core.icoreinputsourcebase) object to obtain the [ICoreInputInterop](https://learn.microsoft.com/windows/desktop/api/corewindow/nn-corewindow-icoreinputinterop) object that created it.

## See also

[ICoreInputSourceBase](https://learn.microsoft.com/uwp/api/windows.ui.core.icoreinputsourcebase)

[CoreComponentInputSource](https://learn.microsoft.com/uwp/api/windows.ui.core.corecomponentinputsource)