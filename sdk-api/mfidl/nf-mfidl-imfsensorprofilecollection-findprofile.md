# IMFSensorProfileCollection::FindProfile

## Description

Finds a profile based on the specified profile ID.

## Parameters

### `ProfileId` [in]

Pointer to the The ID of the profile to find.

### `ppProfile` [out]

On success, returns a double pointer to the profile.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IMFSensorProfileCollection](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfsensorprofilecollection)