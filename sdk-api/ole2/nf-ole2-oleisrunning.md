# OleIsRunning function

## Description

Determines whether a compound document object is currently in the running state.

## Parameters

### `pObject` [in]

Pointer to the [IOleObject](https://learn.microsoft.com/windows/desktop/api/oleidl/nn-oleidl-ioleobject) interface on the object of interest.

## Return value

The return value is **TRUE** if the object is running; otherwise, it is **FALSE**.

## Remarks

You can use **OleIsRunning** and [IRunnableObject::IsRunning](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-irunnableobject-isrunning) interchangeably. **OleIsRunning** queries the object for a pointer to the [IRunnableObject](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-irunnableobject) interface and calls its **IRunnableObject::IsRunning** method. If successful, the function returns the results of the call to **IRunnableObject::IsRunning**.

## See also

[IRunnableObject::IsRunning](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-irunnableobject-isrunning)