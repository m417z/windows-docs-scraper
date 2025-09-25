## Description

Begins an asynchronous request to get an [IMFRelativePanelReport](https://learn.microsoft.com/windows/win32/api/mfidl/nn-mfidl-imfrelativepanelreport) interface that represents the relative panel location.

## Parameters

### `pCallback`

Pointer to the [IMFAsyncCallback](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfasynccallback) interface of a callback object. The caller must implement this interface.

### `pState`

Pointer to the IUnknown interface of a state object, defined by the caller. This parameter can be NULL. You can use this object to hold state information. The object is returned to the caller when the callback is invoked.

## Return value

The function returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
|--------------|------------------------|
|S_OK | The function succeeded.|

## Remarks

## See also