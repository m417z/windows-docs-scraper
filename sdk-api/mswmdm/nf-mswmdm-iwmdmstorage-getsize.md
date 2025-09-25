# IWMDMStorage::GetSize

## Description

The **GetSize** method retrieves the size of the storage, in bytes.

## Parameters

### `pdwSizeLow` [out]

Pointer to a **DWORD** specifying the low-order part of the storage object size, in bytes.

### `pdwSizeHigh` [out]

Pointer to a **DWORD** specifying the high-order part of the storage object size, in bytes.

## Return value

The method returns an **HRESULT**. All the interface methods in Windows Media Device Manager can return any of the following classes of error codes:

* Standard COM error codes
* Windows error codes converted to HRESULT values
* Windows Media Device Manager error codes

For an extensive list of possible error codes, see [Error Codes](https://learn.microsoft.com/windows/desktop/WMDM/error-codes).

## Remarks

For folders or abstract objects (such as abstract playlists), the size is zero.

#### Examples

The following C++ code retrieves the size of a file, in kilobytes.

```cpp

// Get size of file in kilobytes.
DWORD lowSize = 0;
DWORD highSize = 0;
hr = pStorage->GetSize(&lowSize, &highSize);
//TODO: Display the file size.

```

## See also

[IWMDMStorage Interface](https://learn.microsoft.com/windows/desktop/api/mswmdm/nn-mswmdm-iwmdmstorage)

[IWMDMStorage::GetDate](https://learn.microsoft.com/windows/desktop/api/mswmdm/nf-mswmdm-iwmdmstorage-getdate)

[IWMDMStorage::GetName](https://learn.microsoft.com/windows/desktop/api/mswmdm/nf-mswmdm-iwmdmstorage-getname)