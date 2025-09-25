# IDvbNetworkNameDescriptor::GetNetworkNameW

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

Gets the network name, in Unicode string format, from a Digital Video Broadcast (DVB) network name descriptor.

## Parameters

### `convMode` [in]

Specifies the string conversion mode to use. This parameter can have any of the following values.

* **STRCONV_MODE_DVB**
* **STRCONV_MODE_DVB_EMPHASIS**
* **STRCONV_MODE_DVB_WITHOUT_EMPHASIS**
* **STRCONV_MODE_ISDB**

### `pbstrName` [out]

Pointer to a string buffer that receives the network name. The caller is responsible for freeing this memory.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IDvbNetworkNameDescriptor](https://learn.microsoft.com/previous-versions/windows/desktop/api/dvbsiparser/nn-dvbsiparser-idvbnetworknamedescriptor)