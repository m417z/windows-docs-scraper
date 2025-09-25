# SafeArraySetIID function

## Description

Sets the GUID of the interface for the specified safe array.

## Parameters

### `psa` [in]

The safe array descriptor.

### `guid` [in]

The IID.

## Return value

This function can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **E_INVALIDARG** | The argument *psa* is null or the array descriptor does not have the FADF_HAVEIID flag set. |