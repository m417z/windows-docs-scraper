# IEnumTfUIElements::Clone

## Description

The **IEnumTfUIElements::Clone** method creates a copy of the enumerator object.

## Parameters

### `ppEnum` [out]

[out] A pointer to a [IEnumTfUIElements](https://learn.microsoft.com/windows/desktop/api/msctf/nn-msctf-ienumtfuielements) interface.

## Return value

This method can return one of these values.

| Value | Description |
| --- | --- |
| **S_OK** | The method was successful. |
| **E_FAIL** | An unspecified error occurred. |
| **E_INVALIDARG** | One or more parameters are invalid. |