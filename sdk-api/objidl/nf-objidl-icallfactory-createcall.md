# ICallFactory::CreateCall

## Description

Creates an instance of the call object that corresponds to a specified asynchronous interface.

## Parameters

### `riid` [in]

A reference to the identifier for the asynchronous interface.

### `pCtrlUnk` [in]

A pointer to the controlling [IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown) of the call object. If this parameter is not **NULL**, the call object is aggregated in the specified object, and the *riid2* parameter must be IID_IUnknown.
If this parameter is **NULL**, the call object is not aggregated.

### `riid2` [in]

The identifier of an interface on the call object. Typical values are IID_IUnknown and IID_ISynchronize.

### `ppv` [out]

The address of a pointer to the interface specified by *riid2*. This parameter cannot be **NULL**.

## Return value

This method can return the standard return values E_INVALIDARG, E_OUTOFMEMORY, and E_UNEXPECTED, as well as the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The call object was created successfully. |
| **E_NOINTERFACE** | The *riid* parameter does not reference the identifier for the asynchronous interface, such as IID_AsyncIEventSourceCallback. |

## See also

[ICallFactory](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-icallfactory)