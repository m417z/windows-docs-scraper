# SafeArrayUnaccessData function

## Description

Decrements the lock count of an array, and invalidates the pointer retrieved by [SafeArrayAccessData](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-safearrayaccessdata).

## Parameters

### `psa` [in]

An array descriptor created by [SafeArrayCreate](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-safearraycreate).

## Return value

This function can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **E_INVALIDARG** | The argument *psa* is not valid. |
| **E_UNEXPECTED** | The array could not be unlocked. |