# IContextCallback::ContextCallback

## Description

Enters the object context, executes the specified function, and returns.

## Parameters

### `pfnCallback` [in]

The function to be called inside the object context.

### `pParam` [in]

The data to be passed to the function when it is called in the context.

### `riid` [in]

The IID of the call that is being simulated. See Remarks for more information.

### `iMethod` [in]

The method number of the call that is being simulated. See Remarks for more information.

### `pUnk` [in]

This parameter is reserved and must be **NULL**.

## Return value

This method can return the standard return values E_INVALIDARG, E_OUTOFMEMORY, E_UNEXPECTED, and E_FAIL. If none of these failures occur, the return value of this function is the **HRESULT** value returned by the *pfnCallback* function.

## Remarks

This method simulates a method call on an object inside the context. It is intended for low-level operations, such as cleanup/lazy marshaling, that respect the application's reentrancy expectations.

To give the infrastructure information, an interface and method number must be specified. The parameter *riid* must not be IID_IUnknown, and the method number must not be less than 3.

If *riid* is set to IID_IEnterActivityWithNoLock, the function is executed without an activity lock.

If *riid* is set to IID_ICallbackWithNoReentrancyToApplicationSTA, the function does not reenter an ASTA arbitrarily. Most apps should set *riid* to this values for general purpose use.

## See also

[IContextCallback](https://learn.microsoft.com/windows/desktop/api/ctxtcall/nn-ctxtcall-icontextcallback)