# IWiaItemExtras::GetExtendedErrorInfo

## Description

The **IWiaItemExtras::GetExtendedErrorInfo** method gets a string from the device driver that contains information about the most recent error. Call this method after an error during an operation on a Windows Image Acquisition (WIA) item (such as data transfer).

## Parameters

### `bstrErrorText` [out]

Type: **BSTR***

Pointer to a string that contains the error information.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

Applications must call the [SysFreeString](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-sysfreestring) function to free the string to which *bstrErrorText* points.

## See also

[IWiaItemExtras](https://learn.microsoft.com/windows/desktop/api/wia_xp/nn-wia_xp-iwiaitemextras)