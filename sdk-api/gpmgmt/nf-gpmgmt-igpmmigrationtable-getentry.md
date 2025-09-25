# IGPMMigrationTable::GetEntry

## Description

The **GetEntry** method gets the entry in the migration table for a specified source field.

## Parameters

### `bstrSource` [in]

Source field of the entry to retrieve.

### `ppEntry` [out]

A pointer to an [IGPMMapEntry](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nn-gpmgmt-igpmmapentry) interface.

## Return value

### C++

Returns **S_OK** if successful. Returns a failure code if an error occurs.

### JScript

Returns a reference to a [GPMMapEntry](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nn-gpmgmt-igpmmapentry) object.

### VB

Returns a reference to a [GPMMapEntry](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nn-gpmgmt-igpmmapentry) object.

## See also

[IGPMMigrationTable](https://learn.microsoft.com/previous-versions/windows/desktop/api/gpmgmt/nn-gpmgmt-igpmdomain)