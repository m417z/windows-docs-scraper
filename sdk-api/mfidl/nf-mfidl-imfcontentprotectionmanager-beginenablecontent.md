# IMFContentProtectionManager::BeginEnableContent

## Description

Begins an asynchronous request to perform a content enabling action.

This method requests the application to perform a specific step needed to acquire rights to the content, using a content enabler object.

## Parameters

### `pEnablerActivate` [in]

Pointer to the [IMFActivate](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfactivate) interface of a content enabler object. To create the content enabler, call [IMFActivate::ActivateObject](https://learn.microsoft.com/windows/desktop/api/mfobjects/nf-mfobjects-imfactivate-activateobject) and request the [IMFContentEnabler](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfcontentenabler) interface. The application should use the methods in **IMFContentEnabler** to complete the content enabling action.

### `pTopo` [in]

Pointer to the [IMFTopology](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imftopology) interface of the pending topology.

### `pCallback` [in]

Pointer to the [IMFAsyncCallback](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfasynccallback) interface of a callback object. When the operation is complete, the application should call [IMFAsyncCallback::Invoke](https://learn.microsoft.com/windows/desktop/api/mfobjects/nf-mfobjects-imfasynccallback-invoke) on the callback.

### `punkState` [in]

Reserved. Currently this parameter is always **NULL**.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| ****S_OK**** | The method succeeded. |

## Remarks

Do not block within this callback method. Instead, perform the content enabling action asynchronously on another thread. When the operation is finished, notify the protected media path (PMP) through the *pCallback* parameter.

If you return a success code from this method, you must call [Invoke](https://learn.microsoft.com/windows/desktop/api/mfobjects/nf-mfobjects-imfasynccallback-invoke) on the callback. Conversely, if you return an error code from this method, you must not call **Invoke**. If the operation fails after the method returns a success code, use status code on the [IMFAsyncResult](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfasyncresult) object to report the error.

After the callback is invoked, the PMP will call the application's [IMFContentProtectionManager::EndEnableContent](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-imfcontentprotectionmanager-endenablecontent) method to complete the asynchronous call.

This method is not necessarily called every time the application plays protected content. Generally, the method will not be called if the user has a valid, up-to-date license for the content. Internally, the input trust authority (ITA) determines whether **BeginEnableContent** is called, based on the content provider's DRM policy. For more information, see [Protected Media Path](https://learn.microsoft.com/windows/desktop/medfound/protected-media-path).

## See also

[IMFActivate](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfactivate)

[IMFContentProtectionManager](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfcontentprotectionmanager)