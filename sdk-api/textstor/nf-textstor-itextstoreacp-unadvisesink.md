# ITextStoreACP::UnadviseSink

## Description

The **ITextStoreACP::UnadviseSink** method is called by an application to indicate that it no longer requires notifications from the TSF manager. The TSF manager will release the sink interface and stop notifications.

## Parameters

### `punk` [in]

Pointer to a sink object. Cannot be **NULL**.

## Return value

This method can return one of these values.

| Value | Description |
| --- | --- |
| **S_OK** | The method was successful. |
| **CONNECT_E_NOCONNECTION** | There is no active sink object. |

## Remarks

Every call to the [ITextStoreAnchor::AdviseSink](https://learn.microsoft.com/windows/desktop/api/textstor/nf-textstor-itextstoreanchor-advisesink) method, which registers a new sink object, should be matched by a call to this method. Calls to the **ITextStoreAnchor::AdviseSink** method that only update the *dwMask* parameter of a sink which was previously registered, do not require a call to the [ITextStoreAnchor::UnadviseSink](https://learn.microsoft.com/windows/desktop/api/textstor/nf-textstor-itextstoreanchor-unadvisesink) method.

For example, to register a sink object, an application calls the **ITextStoreAnchor::AdviseSink** method the first time. After registering the sink object, the application can call the **ITextStoreAnchor::AdviseSink** method again with the same sink object to change the *dwMask* parameter. To unregister the sink object, an application calls the **ITextStoreAnchor::UnadviseSink** method.

The *punk* parameter must have the same COM identity as the pointer originally passed in the **ITextStoreAnchor::AdviseSink** method.

## See also

[ITextStoreACP](https://learn.microsoft.com/windows/desktop/api/textstor/nn-textstor-itextstoreacp)

[ITextStoreACP::AdviseSink](https://learn.microsoft.com/windows/desktop/api/textstor/nf-textstor-itextstoreacp-advisesink)