# ID3D12ProtectedSession::GetStatusFence

## Description

Retrieves the fence for the protected session. From the fence, you can retrieve the current uniqueness validity value (using [ID3D12Fence::GetCompletedValue](https://learn.microsoft.com/windows/desktop/api/d3d12/nf-d3d12-id3d12fence-getcompletedvalue)), and add monitors for changes to its value. This is a read-only fence.

## Parameters

### `riid`

The GUID of the interface to a fence. Most commonly, [ID3D12Fence](https://learn.microsoft.com/windows/desktop/api/d3d12/nn-d3d12-id3d12fence), although it may be any GUID for any interface. If the protected session object doesn’t support the interface for this GUID, the function returns **E_NOINTERFACE**.

### `ppFence` [optional]

A pointer to a memory block that receives a pointer to the fence for the given protected session.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[ID3D12ProtectedSession](https://learn.microsoft.com/windows/desktop/api/d3d12/nn-d3d12-id3d12protectedsession)