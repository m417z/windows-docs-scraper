# IDMLObject::SetPrivateData

## Description

Sets application-defined data to a DirectML device object, and associates that data with an application-defined **GUID**. This method is thread-safe.

## Parameters

### `guid`

Type: **[REFGUID](https://learn.microsoft.com/openspecs/windows_protocols/ms-oaut/6e7d7108-c213-40bc-8294-ac13fe68fd50)**

The **GUID** to associate with the data.

### `dataSize` [in]

Type: [**UINT**](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)

The size in bytes of the data.

### `data` [in, optional]

Type: **const void***

A pointer to a memory block that contains the data to be stored with this DirectML device object. If *data* is **NULL**, then *dataSize* must be 0, and any data that was previously associated with the **GUID** specified in *guid* will be destroyed.

## Return value

Type: [**HRESULT**](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IDMLObject](https://learn.microsoft.com/windows/win32/api/directml/nn-directml-idmlobject)