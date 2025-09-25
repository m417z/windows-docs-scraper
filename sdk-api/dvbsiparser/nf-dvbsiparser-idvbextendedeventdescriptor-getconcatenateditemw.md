# IDvbExtendedEventDescriptor::GetConcatenatedItemW

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

Concatenates the bytes from the item in the current Digital Video Broadcast (DVB) extended event descriptor with the bytes from the item in the next DVB extended event descriptor and returns the concatenated data as a Unicode string.

## Parameters

### `pFollowingDescriptor` [in]

Pointer to the [IDvbExtendedEventDescriptor](https://learn.microsoft.com/previous-versions/windows/desktop/api/dvbsiparser/nn-dvbsiparser-idvbextendedeventdescriptor) interface for the next DVB extended event descriptor associated with the current one.

### `convMode` [in]

Specifies the string conversion mode to use. This parameter can have any of the following values.

* **STRCONV_MODE_DVB**
* **STRCONV_MODE_DVB_EMPHASIS**
* **STRCONV_MODE_DVB_WITHOUT_EMPHASIS**
* **STRCONV_MODE_ISDB**

### `pbstrDesc` [out]

Pointer to a buffer that receives the concatenated item descriptor. The caller is responsible for freeing this memory.

### `pbstrItem` [out]

Pointer to a buffer that receives the concatenated item string. The caller is responsible for freeing this memory.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IDvbExtendedEventDescriptor](https://learn.microsoft.com/previous-versions/windows/desktop/api/dvbsiparser/nn-dvbsiparser-idvbextendedeventdescriptor)