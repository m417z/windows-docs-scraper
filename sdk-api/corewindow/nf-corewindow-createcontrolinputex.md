# CreateControlInputEx function

## Description

Creates a [CoreComponentInputSource](https://learn.microsoft.com/uwp/api/windows.ui.core.corecomponentinputsource) object in a worker thread or the UI thread.

## Parameters

### `pCoreWindow` [in]

Pointer to the parent [CoreWindow](https://msdn.microsoft.com/60b1c8c6-c136-4c4c-8e46-69a792d58ed0) to which the [CoreComponentInputSource](https://learn.microsoft.com/uwp/api/windows.ui.core.corecomponentinputsource) object will be attached. This parameter can’t be NULL.

### `riid` [in]

Interface ID of the object. Must to be set to the UUID for [ICoreInputSourceBase](https://learn.microsoft.com/uwp/api/windows.ui.core.icoreinputsourcebase), the default interface of [CoreComponentInputSource](https://learn.microsoft.com/uwp/api/windows.ui.core.corecomponentinputsource), which is `9F488807-4580-4BE8-BE68-92A9311713BB`.

### `ppv` [out]

Pointer to receive the [CoreComponentInputSource](https://learn.microsoft.com/uwp/api/windows.ui.core.corecomponentinputsource) object.

## Return value

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

This API must be called from the UI thread or worker thread to create [ICoreInputSourceBase](https://learn.microsoft.com/uwp/api/windows.ui.core.icoreinputsourcebase) object. The object created using this API can be used only in that thread in which it was created.

If the call is successful, the caller can call **QueryInterface** on the returned [ICoreInputSourceBase](https://learn.microsoft.com/uwp/api/windows.ui.core.icoreinputsourcebase) object to obtain the [ICoreInputInterop](https://learn.microsoft.com/windows/desktop/api/corewindow/nn-corewindow-icoreinputinterop) object that created it.

This API will fail if the following scenarios occur:

* The *pCoreWindow* parameter is **NULL**.
* If the [CoreWindow](https://msdn.microsoft.com/60b1c8c6-c136-4c4c-8e46-69a792d58ed0) passed is not same as the **CoreWindow** present in the calling thread.

## See also

[ICoreInputSourceBase](https://learn.microsoft.com/uwp/api/windows.ui.core.icoreinputsourcebase)

[CoreComponentInputSource](https://learn.microsoft.com/uwp/api/windows.ui.core.corecomponentinputsource)