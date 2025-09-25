# PFND3DDDI_SIGNALSYNCHRONIZATIONOBJECTCB callback function

## Description

The **pfnSignalSynchronizationObjectCb** function inserts a signal on the specified synchronization objects in the specified context DMA stream.

## Parameters

### `hDevice`

A handle to a display device (that is, the graphics context).

### `unnamedParam2`

*pData* [in]

A pointer to a [D3DDDICB_SIGNALSYNCHRONIZATIONOBJECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddicb_signalsynchronizationobject) structure that describes the synchronization objects and context DMA stream that signaling is set up on.

## Return value

**pfnSignalSynchronizationObjectCb** returns one of the following values:

|Return code|Description|
|--- |--- |
|S_OK|The signaling was successfully set up.|
|E_INVALIDARG|Parameters were validated and determined to be incorrect.|

This function might also return other HRESULT values.

## Remarks

**Direct3D Version 11 Note:** For more information about how the driver calls **pfnSignalSynchronizationObjectCb**, see [Changes from Direct3D 10](https://learn.microsoft.com/windows-hardware/drivers/display/changes-from-direct3d-10).

#### Examples

The following code example shows how to insert a signal on synchronization objects.

```cpp
HRESULT CD3DContext::SyncEngines(DWORD dwEngineReleasingControl, DWORD dwEngineAcquiringControl) {
    HRESULT hr;
    D3DDDICB_WAITFORSYNCHRONIZATIONOBJECT   sWaitObject;
    D3DDDICB_SIGNALSYNCHRONIZATIONOBJECT    sSignalObject;

    sSignalObject.hContext = m_sContexts[dwEngineReleasingControl].hContext;
    sSignalObject.ObjectCount = 1;
    sSignalObject.ObjectHandleArray[0] = m_hEngineSyncObject;
    hr = m_d3dCallbacks.pfnSignalSynchronizationObjectCb(m_hD3D, &sSignalObject);
    if (FAILED(hr)) {
        DBG_BREAK;
        return hr;
    }
    sWaitObject.hContext = m_sContexts[dwEngineAcquiringControl].hContext;
    sWaitObject.ObjectCount = 1;
    sWaitObject.ObjectHandleArray[0] = m_hEngineSyncObject;
    hr = m_d3dCallbacks.pfnWaitForSynchronizationObjectCb(m_hD3D, &sWaitObject);
    if (FAILED(hr)) {
        DBG_BREAK;
    }
    return hr;
}
```

## See also

[D3DDDICB_SIGNALSYNCHRONIZATIONOBJECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddicb_signalsynchronizationobject)