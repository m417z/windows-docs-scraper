# IQueueCommand::InvokeAtStreamTime

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `InvokeAtStreamTime` method queues a method or property change for execution at a specified stream time (that is, presentation time relative to the current stream time offset).

## Parameters

### `pCmd` [out]

Address of a variable that receives an [IDeferredCommand](https://learn.microsoft.com/windows/desktop/api/control/nn-control-ideferredcommand) interface pointer.

### `time` [in]

Time at which to invoke the command.

### `iid` [in]

Pointer to the interface identifier (IID) of interface.

### `dispidMethod` [in]

Dispatch identifier (DISPID) of a method or property on the interface. Equivalent to the *dispIdMember* parameter of the **IDispatch::Invoke** method.

### `wFlags` [in]

Flags describing the context of the call. Equivalent to the *wFlags* parameter of the **IDispatch::Invoke** method.

### `cArgs` [in]

Number of arguments in *pDispParams*. Equivalent to the **cArgs** member of the **DISPPARAMS** structure.

### `pDispParams` [in]

Pointer to an array that contains the arguments. Equivalent to the **rgvarg** member of the **DISPPARAMS** structure.

### `pvarResult` [in, out]

Pointer to a VARIANT that receives the result. Equivalent to the *pVarResult* parameter of the **IDispatch::Invoke** method.

### `puArgErr` [out]

Pointer to a variable that receives the index of the first argument that has an error. Equivalent to the *puArgErr* parameter of the **IDispatch::Invoke** method.

## Return value

Returns an **HRESULT** value.

## Remarks

Use the **IDispatch::GetIDsOfNames** method to retrieve the DISPID for the *dispidMember* parameter.

#### Examples

The following example queues an [IMediaControl::Stop](https://learn.microsoft.com/windows/desktop/api/control/nf-control-imediacontrol-stop) command for 3.0 seconds.

```cpp

IQueueCommand *pQ = 0;
IMediaControl *pControl = 0;

// Query for IQueueCommand.
pGraph->QueryInterface(IID_IQueueCommand, reinterpret_cast<void**>(&pQ));

// Query for IMediaControl.
pGraph->QueryInterface(IID_IMediaControl, reinterpret_cast<void**>(&pControl));

// Find the DISPID of the IMediaControl::Stop method.
OLECHAR *szMethod = OLESTR("Stop");

long dispid;
hr = pControl->GetIDsOfNames(IID_NULL, &szMethod, 1, 0, &dispid);

// Invoke the command.
IDeferredCommand *pCmd = 0;
hr = pQ->InvokeAtPresentationTime(&pCmd, 3.0,
    const_cast<GUID*>(&IID_IMediaControl), dispid, DISPATCH_METHOD,
    0, 0, 0, 0);
if (SUCCEEDED(hr))
{
    pControl->Run();
    pCmd->Release();
}

```

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IQueueCommand Interface](https://learn.microsoft.com/windows/desktop/api/control/nn-control-iqueuecommand)