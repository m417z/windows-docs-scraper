# ITfInputProcessorProfileMgr::ReleaseInputProcessor

## Description

The **ITfInputProcessorProfileMgr::ReleaseInputProcessor** method deactivates the profiles belonging to the text services of the specified CLSID and releases the instance of [ITfTextInputProcessorEx](https://learn.microsoft.com/windows/desktop/api/msctf/nn-msctf-itftextinputprocessorex) interface.

## Parameters

### `rclsid` [in]

[in] CLSID of the textservice to be released.

### `dwFlags` [in]

[in]

| Value | Meaning |
| --- | --- |
| **TF_RIP_FLAG_FREEUNUSEDLIBRARIES** | If this bit is on, this method calls CoFreeUnusedLibrariesEx() so the text services DLL might be freed if it does not have any more COM/DLL reference. Warning: This flag could cause some other unrelated COM/DLL free. |

## Return value

This method can return one of these values.

| Value | Description |
| --- | --- |
| **S_OK** | The method was successful. |
| **E_FAIL** | An unspecified error occurred. |
| **E_INVALIDARG** | One or more parameters are invalid. |