# IWMDMStorage::GetDate

## Description

The **GetDate** method retrieves the date when the storage was last modified.

## Parameters

### `pDateTimeUTC` [out]

Pointer to a **WMDMDATETIME** structure specifying the date on which the storage object (file or folder) was last modified.

## Return value

The method returns an **HRESULT**. All the interface methods in Windows Media Device Manager can return any of the following classes of error codes:

* Standard COM error codes
* Windows error codes converted to HRESULT values
* Windows Media Device Manager error codes

For an extensive list of possible error codes, see [Error Codes](https://learn.microsoft.com/windows/desktop/WMDM/error-codes).

## Remarks

The time is specified in coordinated universal time.

#### Examples

The following C++ code gets the "last modified" value from a storage passed in.

```cpp

// Get the "Last Modified" date
WMDMDATETIME lastModified;
hr = pStorage->GetDate(&lastModified);
// TODO: Display the last modified month, day, and year.

```

## See also

[IWMDMStorage Interface](https://learn.microsoft.com/windows/desktop/api/mswmdm/nn-mswmdm-iwmdmstorage)