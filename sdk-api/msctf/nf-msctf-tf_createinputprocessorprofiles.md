# TF_CreateInputProcessorProfiles function

## Description

The **TF_CreateInputProcessorProfiles** function is used to create a input processor profile object without having to initialize COM. Usage of this method is not recommended, because the calling process must maintain a proper reference count on an object that is owned by Msctf.dll.

It is instead recommended that input processor profile objects be created using [CoCreateInstance](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cocreateinstance) , as demonstrated in [ITfInputProcessorProfiles](https://learn.microsoft.com/windows/desktop/api/msctf/nn-msctf-itfinputprocessorprofiles).

## Parameters

### `ppipr` [out]

Pointer to an **ITfInputProcessorProfiles** interface pointer that receives the input processor profile object.

## Return value

| Value | Meaning |
| --- | --- |
| S_OK | The function was successful. |
| E_FAIL | An unspecified error occurred. |
| E_INVALIDARG | *ppipr* is invalid. |

## See also

[ITfInputProcessorProfiles](https://learn.microsoft.com/windows/desktop/api/msctf/nn-msctf-itfinputprocessorprofiles)