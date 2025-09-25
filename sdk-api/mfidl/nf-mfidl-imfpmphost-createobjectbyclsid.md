# IMFPMPHost::CreateObjectByCLSID

## Description

Creates an object in the protect media path (PMP) process, from a CLSID.

## Parameters

### `clsid` [in]

The CLSID of the object to create.

### `pStream` [in]

A pointer to the **IStream** interface. This parameter can be **NULL**. If this parameter is not **NULL**, the PMP host queries the created object for the [IPersistStream](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-ipersiststream) interface and calls **IPersistStream::Load**, passing in the *pStream* pointer.

### `riid` [in]

The interface identifier (IID) of the interface to retrieve.

### `ppv` [out]

Receives a pointer to the requested interface. The caller must release the interface.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

You can use the *pStream* parameter to initialize the object after it is created.

## See also

[IMFPMPHost](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfpmphost)

[PMP Media Session](https://learn.microsoft.com/windows/desktop/medfound/pmp-media-session)

[Protected Media Path](https://learn.microsoft.com/windows/desktop/medfound/protected-media-path)