# IWICComponentFactory::CreateEncoderPropertyBag

## Description

Creates an encoder property bag.

## Parameters

### `ppropOptions` [in]

Type: **[PROPBAG2](https://learn.microsoft.com/previous-versions/windows/internet-explorer/ie-developer/platform-apis/aa768188(v=vs.85))***

Pointer to an array of [PROPBAG2](https://learn.microsoft.com/previous-versions/windows/internet-explorer/ie-developer/platform-apis/aa768188(v=vs.85)) options used to create the encoder property bag.

### `cCount` [in]

Type: **UINT**

The number of [PROPBAG2](https://learn.microsoft.com/previous-versions/windows/internet-explorer/ie-developer/platform-apis/aa768188(v=vs.85)) structures in the *ppropOptions* array.

### `ppIPropertyBag` [out]

Type: **[IPropertyBag2](https://learn.microsoft.com/previous-versions/windows/internet-explorer/ie-developer/platform-apis/aa768192(v=vs.85))****

A pointer that receives a pointer to an encoder [IPropertyBag2](https://learn.microsoft.com/previous-versions/windows/internet-explorer/ie-developer/platform-apis/aa768192(v=vs.85)).

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.