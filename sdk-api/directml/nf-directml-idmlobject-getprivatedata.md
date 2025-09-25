## Description

Gets application-defined data from a DirectML device object. This method is thread-safe.

## Parameters

### `guid` [in]

Type: **[REFGUID](https://learn.microsoft.com/openspecs/windows_protocols/ms-oaut/6e7d7108-c213-40bc-8294-ac13fe68fd50)**

The **GUID** that is associated with the data.

### `dataSize` [in, out]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)***

A pointer to a variable that on input contains the size, in bytes, of the buffer that *data* points to, and on output contains the size, in bytes, of the amount of data that **GetPrivateData** retrieved.

### `data` [out, optional]

Type: **void***

A pointer to a memory block that receives the data from the device object if *dataSize* points to a value that specifies a buffer large enough to hold the data.

## Return value

Type: [**HRESULT**](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

If the data returned is a pointer to an [IUnknown](https://learn.microsoft.com/windows/win32/api/unknwn/nn-unknwn-iunknown) (or derived interface) that was previously set by [SetPrivateDataInterface](https://learn.microsoft.com/windows/win32/api/directml/nf-directml-idmlobject-setprivatedatainterface), then that interface will have its reference count incremented before the private data is returned.

## See also

[IDMLObject](https://learn.microsoft.com/windows/win32/api/directml/nn-directml-idmlobject)