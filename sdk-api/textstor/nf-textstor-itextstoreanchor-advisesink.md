# ITextStoreAnchor::AdviseSink

## Description

The **ITextStoreAnchor::AdviseSink** method installs a new advise sink from the [ITextStoreAnchorSink](https://learn.microsoft.com/windows/desktop/api/textstor/nn-textstor-itextstoreanchorsink) interface or modifies an existing advise sink.

## Parameters

### `riid` [in]

Specifies the sink interface. The only supported value is IID_ITextStoreAnchorSink.

### `punk` [in]

Pointer to the sink interface to advise. Cannot be **NULL**.

### `dwMask` [in]

Specifies the events that notify the advise sink. For more information about possible parameter values, see [TS_AS_* Constants](https://learn.microsoft.com/windows/desktop/TSF/ts-as--constants).

## Return value

This method can return one of these values.

| Value | Description |
| --- | --- |
| **S_OK** | The method was successful. |
| **E_FAIL** | The specified sink interface *riid* could not be obtained. |
| **E_INVALIDARG** | The specified sink interface is unsupported. |
| **E_UNEXPECTED** | The specified sink object could not be obtained. |

## Remarks

Subsequent calls with the same interface, represented by the *punk* parameter, are handled as requests to update the *dwMask* parameter. Servers should not call the **AddRef** method on the sink in response to such a request.

Servers only maintain a single connection point. Attempts to advise a second sink object fail until the original sink object is removed. Applications should use the [ITextStoreAnchor::UnadviseSink](https://learn.microsoft.com/windows/desktop/api/textstor/nf-textstor-itextstoreanchor-unadvisesink) method to unregister the sink object when notifications are not required.

## See also

[ITextStoreAnchor](https://learn.microsoft.com/windows/desktop/api/textstor/nn-textstor-itextstoreanchor)

[ITextStoreAnchor::UnadviseSink](https://learn.microsoft.com/windows/desktop/api/textstor/nf-textstor-itextstoreanchor-unadvisesink)

[TS_AS_* Constants](https://learn.microsoft.com/windows/desktop/TSF/ts-as--constants)