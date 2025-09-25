# IMFPMPHostApp::ActivateClassById

## Description

Creates a Windows Runtime object in the protected media path (PMP) process.

## Parameters

### `id` [in]

Id of object to create.

### `pStream` [in]

Data to be passed to the object by way of a [IPersistStream](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-ipersiststream).

### `riid` [in]

The interface identifier (IID) of the interface to retrieve.

### `ppv` [out]

Receives a pointer to the created object.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IMFPMPHostApp](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfpmphostapp)