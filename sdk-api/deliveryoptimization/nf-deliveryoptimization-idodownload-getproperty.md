## Description

Retrieves a pointer to a **VARIANT** that contains a specific download property.

## Parameters

### `propId`

The required property ID to get (of type **DODownloadProperty**).

### `propVal`

The resulting property value, stored in a **VARIANT**.

## Return value

If the function succeeds, it returns **S_OK**. Otherwise, it returns an [**HRESULT**](https://learn.microsoft.com/windows/desktop/com/structure-of-com-error-codes) [error code](https://learn.microsoft.com/windows/desktop/com/com-error-codes-10).

|Return value|Description|
|-|-|
|DO_E_UNKNOWN_PROPERTY_ID|*propId* is unknown.|
|DO_E_WRITE_ONLY_PROPERTY|The property is write-only, and can't be read.|
|E_NOT_SET|No such property was set via **SetProperty**.|

## Remarks

## See also