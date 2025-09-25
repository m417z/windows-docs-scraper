## Description

Ends an asynchronous request to get an [IMFRelativePanelReport](https://learn.microsoft.com/windows/win32/api/mfidl/nn-mfidl-imfrelativepanelreport) interface that represents the relative panel location.

## Parameters

### `pResult`

Pointer to the [IMFAsyncResult](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfasyncresult) interface. Pass in the same pointer that your callback object received in the Invoke method.

### `ppRelativePanelReport`

A pointer to he [IMFRelativePanelReport](https://learn.microsoft.com/windows/win32/api/mfidl/nn-mfidl-imfrelativepanelreport) interface that represents the relative panel location.

## Return value

The function returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
|--------------|------------------------|
|S_OK | The function succeeded.|

## Remarks

## See also