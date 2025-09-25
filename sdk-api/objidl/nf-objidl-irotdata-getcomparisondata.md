# IROTData::GetComparisonData

## Description

Retrieves data from a moniker that can be used to test the moniker for equality against another moniker.

## Parameters

### `pbData` [out]

A pointer to a buffer that receives the comparison data.

### `cbMax` [in]

The length of the buffer specified in *pbData*.

### `pcbData` [out]

A pointer to a variable that receives the length of the comparison data.

## Return value

This method can return the standard return values E_OUTOFMEMORY and S_OK.

## Remarks

The **GetComparisonData** method is primarily called by the running object table (ROT). The comparison data returned by the method is tested for binary equality against the comparison data returned by another moniker. The *pcbData* parameter enables the ROT to locate the end of the data retrieved.

### Notes to Implementers

The comparison data that you return must uniquely identify the moniker, while still being as short as possible. The comparison data should include information about the internal state of the moniker, as well as the moniker's CLSID. For example, the comparison data for a file moniker would include the path name stored within the moniker, as well as the CLSID of the file moniker implementation. This makes it possible to distinguish two monikers that happen to store similar state information but are instances of different moniker classes.

The comparison data for a moniker cannot exceed 2048 bytes in length. For composite monikers, the total length of the comparison data for all of its components cannot exceed 2048 bytes; consequently, if your moniker can be a component within a composite moniker, the comparison data you return must be significantly less than 2048 bytes.

If your comparison data is longer than the value specified by the *cbMax* parameter, you must return an error. Note that when **GetComparisonData** is called on the components of a composite moniker, the value of *cbMax* becomes smaller for each moniker in sequence.

## See also

[IROTData](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-irotdata)