# IEnumTfInputProcessorProfiles::Clone

## Description

The **IEnumTfInputProcessorProfiles::Clone** method creates a copy of the enumerator object.

## Parameters

### `ppEnum` [out]

[out] A pointer to an [IEnumTfInputProcessorProfiles](https://learn.microsoft.com/windows/desktop/api/msctf/nn-msctf-ienumtfinputprocessorprofiles) interface.

## Return value

This method can return one of these values.

| Value | Description |
| --- | --- |
| **S_OK** | The method was successful. |
| **E_FAIL** | An unspecified error occurred. |
| **E_INVALIDARG** | One or more parameters are invalid. |