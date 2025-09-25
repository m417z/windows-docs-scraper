# SHCreateDefaultExtractIcon function

## Description

Creates a standard icon extractor, whose defaults can be further configured via the [IDefaultExtractIconInit](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-idefaultextracticoninit) interface.

## Parameters

### `riid`

Type: **REFIID**

A reference to interface ID.

### `ppv` [out]

Type: **void****

The address of [IDefaultExtractIconInit](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-idefaultextracticoninit) interface pointer.

## Return value

Type: **HRESULT**

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The intended usage for this function is as follows:

```
IExtractIcon *pxi;

IDefaultExtractIconInit *pdxi;

HRESULT hr = SHCreateDefaultExtractIcon(IID_PPV_ARGS(&pdxi);

 if (SUCCEEDED(hr)) &&

      SUCCEEDED(hr = pdxi->SetFlags(GIL_PERCLASS)) &&

      SUCCEEDED(hr = pdxi->SetKey(hkey)) &&   // optional

      SUCCEEDED(hr = pdxi->SetNormalIcon(L"this.dll", 1)) &&

      SUCCEEDED(hr = pdxi->SetOpenIcon(NULL, SIID_FOLDEROPEN)) && // optional

      SUCCEEDED(hr = pdxi->SetDefaultIcon(NULL, SIID_FOLDER)) && // optional

      SUCCEEDED(hr = pdxi->SetShortcutIcon(L"this.dll", 2))) // optional

{

      hr = pdxi->QueryInterface(IID_PPV_ARGS(&pxi))

}

 if (pdxi)

{

    pdxi->Release();

}
```