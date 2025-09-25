# IRunningObjectTable::IsRunning

## Description

Determines whether the object identified by the specified moniker is currently running.

## Parameters

### `pmkObjectName` [in]

A pointer to the [IMoniker](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-imoniker) interface on the moniker.

## Return value

If the object is in the running state, the return value is **TRUE**. Otherwise, it is **FALSE**.

## Remarks

This method simply indicates whether a object is running. To retrieve a pointer to a running object, use the [IRunningObjectTable::GetObject](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-irunningobjecttable-getobject) method.

### Notes to Callers

Generally, you call the **IsRunning** method only if you are writing your own moniker class (that is, implementing the [IMoniker](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-imoniker) interface). You typically call this method from your implementation of [IMoniker::IsRunning](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-imoniker-isrunning). However, you should do so only if the *pmkToLeft* parameter of **IMoniker::IsRunning** is **NULL**. Otherwise, you should call **IMoniker::IsRunning** on your *pmkToLeft* parameter instead.

## See also

[IMoniker::IsRunning](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-imoniker-isrunning)

[IRunningObjectTable](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-irunningobjecttable)