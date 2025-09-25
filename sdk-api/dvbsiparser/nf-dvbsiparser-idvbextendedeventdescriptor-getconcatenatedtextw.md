# IDvbExtendedEventDescriptor::GetConcatenatedTextW

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

Gets the concatenation of the text description in the current item with the text description in the next item (both in Unicode format) of a Digital Video Broadcast (DVB) extended event descriptor.

## Parameters

### `FollowingDescriptor` [in]

Pointer to the [IDvbExtendedEventDescriptor](https://learn.microsoft.com/previous-versions/windows/desktop/api/dvbsiparser/nn-dvbsiparser-idvbextendedeventdescriptor) interface for the next extended event descriptor that is associated with the current event descriptor.

### `convMode` [in]

Specifies the string conversion mode to use. This parameter can have any of the following values.

* **STRCONV_MODE_DVB**
* **STRCONV_MODE_DVB_EMPHASIS**
* **STRCONV_MODE_DVB_WITHOUT_EMPHASIS**
* **STRCONV_MODE_ISDB**

### `pbstrText` [out]

Pointer to the buffer that receives the concatenated item text. The caller is responsible for freeing this memory.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IDvbExtendedEventDescriptor](https://learn.microsoft.com/previous-versions/windows/desktop/api/dvbsiparser/nn-dvbsiparser-idvbextendedeventdescriptor)