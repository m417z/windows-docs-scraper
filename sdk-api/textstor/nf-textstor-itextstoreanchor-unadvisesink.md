# ITextStoreAnchor::UnadviseSink

## Description

Called by an application to indicate that it no longer requires notifications from the TSF manager.

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

Every call to the [ITextStoreAnchor::AdviseSink](https://learn.microsoft.com/windows/desktop/api/textstor/nf-textstor-itextstoreanchor-advisesink) method, which registers a new sink object, should be matched by a call to this method. If AdviseSink has only updated the *dwMask* parameter of a sink which was previously registered, a call to **UnadviseSink** is not required.

For example, to register a sink object, an application calls the **AdviseSink** method the first time. The application can then call the **AdviseSink** method again with the same sink object to change the *dwMask* parameter. To unregister the sink object, an application calls the **UnadviseSink** method.

The *punk* parameter must have the same COM identity as the pointer originally passed in the **AdviseSink** method.

## See also

[ITextStoreAnchor](https://learn.microsoft.com/windows/desktop/api/textstor/nn-textstor-itextstoreanchor)

[ITextStoreAnchor::AdviseSink](https://learn.microsoft.com/windows/desktop/api/textstor/nf-textstor-itextstoreanchor-advisesink)