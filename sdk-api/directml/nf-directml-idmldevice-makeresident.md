# IDMLDevice::MakeResident

## Description

Causes one or more pageable objects to become resident in GPU memory. Also see [IDMLDevice::Evict](https://learn.microsoft.com/windows/win32/api/directml/nf-directml-idmldevice-evict).

## Parameters

### `count`

Type: **UINT**

This parameter determines the number of elements in the array passed in the *ppObjects* parameter.

### `ppObjects` [in]

Type: **[IDMLPageable](https://learn.microsoft.com/windows/win32/api/directml/nn-directml-idmlpageable)***

A pointer to a constant array of [IDMLPageable](https://learn.microsoft.com/windows/win32/api/directml/nn-directml-idmlpageable) pointers containing the pageable objects to make resident in GPU memory.

## Return value

Type: [**HRESULT**](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IDMLDevice](https://learn.microsoft.com/windows/win32/api/directml/nn-directml-idmldevice)

[IDMLDevice::Evict](https://learn.microsoft.com/windows/win32/api/directml/nf-directml-idmldevice-evict)