## Description

Sets a download property. The method accepts a pointer to a **VARIANT** that contains a specific property to apply to the download.

## Parameters

### `propId`

The required property ID to set (of type **DODownloadProperty**).

### `propVal`

The property value to set, stored in a **VARIANT**.

## Return value

If the function succeeds, it returns **S_OK**. Otherwise, it returns an [**HRESULT**](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes) [error code](https://learn.microsoft.com/windows/win32/com/com-error-codes-10).

|Return value|Description|
|-|-|
|DO_E_UNKNOWN_PROPERTY_ID|*propId* is unknown.|
|DO_E_INVALID_STATE|The download is not currently in a state that allows setting properties.|

## Remarks

## See also