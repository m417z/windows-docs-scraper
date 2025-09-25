# IMFSensorProfileCollection::GetProfile

## Description

Retrieves the specified profile.

## Parameters

### `Index` [in]

Index of the profile to retrieve.

### `ppProfile` [out]

On success, returns a double pointer to an [IMFSensorProfile](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfsensorprofile) object that describes the specified sensor profile.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IMFSensorProfileCollection](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfsensorprofilecollection)