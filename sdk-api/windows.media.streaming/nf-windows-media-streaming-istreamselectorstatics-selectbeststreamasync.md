# IStreamSelectorStatics::streaming

## Description

When implemented queries asynchronously for the best stream.

## Parameters

### `storageFile` [in]

Windows.Storage.StorageFile

### `selectorProperties` [in]

An IPropertySet containing any of the following allowed values.

* **STREAM_SELECTOR_PROPERTY_BEST_URL_ONLY**
* **STREAM_SELECTOR_PROPERTY_HTTP_ONLY**
* **STREAM_SELECTOR_PROPERTY_LINK_BANDWIDTH**
* **STREAM_SELECTOR_PROPERTY_PREFER_NO_TRANSCODING**
* **STREAM_SELECTOR_PROPERTY_MAX_HEIGHT**
* **STREAM_SELECTOR_PROPERTY_MAX_WIDTH**

### `value` [out, retval]

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## See also

[IStreamSelectorStatics](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/hh828953(v=vs.85))