# IBrowserService::OnHttpEquiv

## Description

Deprecated. Called when the document object responds to an [HTTP-EQUIV](https://developer.mozilla.org/en-US/docs/Web/HTML/Attributes) metatag by issuing either the **OLECMDID_HTTPEQUIV** or **OLECMDID_HTTPEQUIV_DONE** command through [IOleCommandTarget::Exec](https://learn.microsoft.com/windows/desktop/api/docobj/nf-docobj-iolecommandtarget-exec).

## Parameters

### `psv`

Type: **[IShellView](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellview)***

A pointer to an [IShellView](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellview) that indicates the browser's view. The view must be either the browser's current view or the pending view.

### `fDone`

Type: **BOOL**

A value of type **BOOL** that indicates which command to issue.

#### TRUE

**OLECMDID_HTTPEQUIV_DONE**

#### FALSE

**OLECMDID_HTTPEQUIV**

### `pvarargIn` [in]

Type: **VARIANT***

=A pointer to an object of type **VARIANT**. This is the equivalent of the [IOleCommandTarget::Exec](https://learn.microsoft.com/windows/desktop/api/docobj/nf-docobj-iolecommandtarget-exec) parameter *pvaIn*.

### `pvarargOut` [out]

Type: **VARIANT***

A pointer to an object of type **VARIANT**. This is the equivalent of the [IOleCommandTarget::Exec](https://learn.microsoft.com/windows/desktop/api/docobj/nf-docobj-iolecommandtarget-exec) parameter *pvaOut*.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.