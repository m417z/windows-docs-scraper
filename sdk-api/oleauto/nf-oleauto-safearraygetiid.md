# SafeArrayGetIID function

## Description

Gets the GUID of the interface contained within the specified safe array.

## Parameters

### `psa` [in]

An array descriptor created by [SafeArrayCreate](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-safearraycreate).

### `pguid` [out]

The GUID of the interface.

## Return value

This function can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **E_INVALIDARG** | The argument *psa* is null or the array descriptor does not have the FADF_HAVEIID flag set. |