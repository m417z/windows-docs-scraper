# IDMLDevice::Evict

## Description

Evicts one or more pageable objects from GPU memory. Also see [IDMLDevice::MakeResident](https://learn.microsoft.com/windows/win32/api/directml/nf-directml-idmldevice-makeresident).

## Parameters

### `count`

Type: [**UINT**](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)

This parameter determines the number of elements in the array passed in the *ppObjects* parameter.

### `ppObjects` [in]

Type: **[IDMLPageable](https://learn.microsoft.com/windows/win32/api/directml/nn-directml-idmlpageable)***

A pointer to a constant array of [IDMLPageable](https://learn.microsoft.com/windows/win32/api/directml/nn-directml-idmlpageable) pointers containing the pageable objects to evict from GPU memory.

## Return value

Type: [**HRESULT**](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IDMLDevice](https://learn.microsoft.com/windows/win32/api/directml/nn-directml-idmldevice)

[IDMLDevice::MakeResident](https://learn.microsoft.com/windows/win32/api/directml/nf-directml-idmldevice-makeresident)