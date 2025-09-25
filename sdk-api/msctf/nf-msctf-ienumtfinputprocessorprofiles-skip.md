# IEnumTfInputProcessorProfiles::Skip

## Description

The [IEnumTfInputProcessorProfiles::Skip](https://learn.microsoft.com/windows/desktop/api/msctf/nf-msctf-ienumtfinputprocessorprofiles-next) method moves the current position forward in the enumeration sequence by the specified number of elements.

## Parameters

### `ulCount` [in]

[in] Contains the number of elements to skip.

## Return value

This method can return one of these values.

| Value | Description |
| --- | --- |
| **S_OK** | The method was successful. |
| **E_FALSE** | The method reached the end of the enumeration before the specified number of elements could be skipped. |