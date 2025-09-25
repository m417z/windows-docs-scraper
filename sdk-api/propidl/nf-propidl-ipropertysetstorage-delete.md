# IPropertySetStorage::Delete

## Description

The **Delete** method deletes one of the property sets contained in the property set storage object.

## Parameters

### `rfmtid` [in]

FMTID of the property set to be deleted.

## Return value

This method supports the standard return value E_UNEXPECTED, in addition to the following:

## Remarks

**IPropertySetStorage::Delete** deletes the property set specified by its FMTID. Specifying a property set that does not exist returns an error. Open substorages and streams(opened through one of the storage- or stream-valued properties) are put into the reverted state.