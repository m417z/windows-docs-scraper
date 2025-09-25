# IBrowserService2::OnFrameWindowActivateBS

## Description

Deprecated. Calls the derived class from the base class in response to a subframe window being activated or deactivated. The derived class determines what to do in response to the action.

## Parameters

### `fActive` [in]

Type: **BOOL**

The state of the subframe window.

#### TRUE

The frame window is activating.

#### FALSE

The frame window is deactivating.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.