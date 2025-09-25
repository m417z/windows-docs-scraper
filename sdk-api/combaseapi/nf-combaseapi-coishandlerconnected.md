# CoIsHandlerConnected function

## Description

Determines whether a remote object is connected to the corresponding in-process object.

## Parameters

### `pUnk` [in]

A pointer to the controlling [IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown) interface on the remote object.

## Return value

If the object is not remote or if it is remote and still connected, the return value is **TRUE**; otherwise, it is **FALSE**.

## Remarks

The **CoIsHandlerConnected** function determines the status of a remote object. You can use it to determine when to release a remote object. You specify the remote object by giving the function a pointer to its controlling [IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown) interface (the *pUnk* parameter). A value of **TRUE** returned from the function indicates either that the specified object is not remote, or that it is remote and is still connected to its remote handler. A value of **FALSE** returned from the function indicates that the object is remote but is no longer connected to its remote handler; in this case, the caller should respond by releasing the object.