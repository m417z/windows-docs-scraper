# MTSCreateActivity function

## Description

[**MTSCreateActivity** is available for in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions. Instead, use the [CoCreateActivity](https://learn.microsoft.com/windows/desktop/api/comsvcs/nf-comsvcs-cocreateactivity) function.]

Creates an activity in a single-threaded apartment to do synchronous or asynchronous batch work.

## Parameters

### `riid` [in]

The ID of the interface to be returned by the *ppObj* parameter. This parameter should always be IID_IMTSActivity so that a pointer to [IMTSActivity](https://learn.microsoft.com/windows/desktop/api/comsvcs/nn-comsvcs-imtsactivity) is returned.

### `ppobj` [out]

A pointer to the interface of an activity object. The activity object is automatically created by the call to **MTSCreateActivity**.

## Return value

This method can return the standard return values E_INVALIDARG, E_OUTOFMEMORY, E_FAIL, and S_OK.

## Remarks

**MTSCreateActivity** creates an activity object that is used to submit batch work to the COM+ system. The batch work that is submitted through **MTSCreateActivity** can be either synchronous or asynchronous and runs in a single-threaded apartment (STA).

**MTSCreateActivity** returns a pointer to the [IMTSActivity](https://learn.microsoft.com/windows/desktop/api/comsvcs/nn-comsvcs-imtsactivity) interface of the object that is created by the call to **MTSCreateActivity**. By using the methods of **IMTSActivity**, you determine whether the batch work is done synchronously or asynchronously. The batch work itself is implemented through the [IMTSCall](https://learn.microsoft.com/windows/desktop/api/comsvcs/nn-comsvcs-imtscall) interface.

## See also

[CoCreateActivity](https://learn.microsoft.com/windows/desktop/api/comsvcs/nf-comsvcs-cocreateactivity)