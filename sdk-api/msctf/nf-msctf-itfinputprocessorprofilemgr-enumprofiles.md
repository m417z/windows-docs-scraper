# ITfInputProcessorProfileMgr::EnumProfiles

## Description

The **ITfInputProcessorProfileMgr::EnumProfiles** method returns profiles to be enumerated.

## Parameters

### `langid` [in]

[in] langid of the profiles to be enumerated. If langid is 0, all profiles will be enumerated.

### `ppEnum` [out]

[out] The pointer to receive a pointer of [IEnumTfInputProcessorProfiles](https://learn.microsoft.com/windows/desktop/api/msctf/nn-msctf-ienumtfinputprocessorprofiles) interface.

## Return value

This method can return one of these values.

| Value | Description |
| --- | --- |
| **S_OK** | The method was successful. |
| **E_FAIL** | An unspecified error occurred. |
| **E_INVALIDARG** | One or more parameters are invalid. |