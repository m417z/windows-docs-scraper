# IEnumTfInputProcessorProfiles::Next

## Description

The **IEnumTfInputProcessorProfiles::Next** method obtains, from the current position, the specified number of elements in the enumeration sequence.

## Parameters

### `ulCount` [in]

[in] Specifies the number of elements to obtain.

### `pProfile` [out]

[out] Pointer to an array of [TF_INPUTPROCESSORPROFILE](https://learn.microsoft.com/windows/desktop/api/msctf/ns-msctf-tf_inputprocessorprofile) structures. This array must be at least *ulCount* elements in size.

### `pcFetch` [out]

[out] Pointer to a ULONG value that receives the number of elements actually obtained. This value can be less than the number of items requested. This parameter can be **NULL**.

## Return value

This method can return one of these values.

| Value | Description |
| --- | --- |
| **S_OK** | The method was successful. |
| **E_FAIL** | An unspecified error occurred. |
| **E_INVALIDARG** | One or more parameters are invalid. |