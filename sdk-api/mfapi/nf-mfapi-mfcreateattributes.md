# MFCreateAttributes function

## Description

Creates an empty attribute store.

## Parameters

### `ppMFAttributes` [out]

Receives a pointer to the [IMFAttributes](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfattributes) interface. The caller must release the interface.

### `cInitialSize` [in]

The initial number of elements allocated for the attribute store. The attribute store grows as needed.

## Return value

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

Attributes are used throughout Microsoft Media Foundation to configure objects, describe media formats, query object properties, and other purposes. For more information, see [Attributes in Media Foundation](https://learn.microsoft.com/windows/desktop/medfound/attributes-and-properties).

For a complete list of all the defined attribute GUIDs in Media Foundation, see [Media Foundation Attributes](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-attributes).

## See also

[Attributes in Media Foundation](https://learn.microsoft.com/windows/desktop/medfound/attributes-and-properties)

[Media Foundation Functions](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-functions)