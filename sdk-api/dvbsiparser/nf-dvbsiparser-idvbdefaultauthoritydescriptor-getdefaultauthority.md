# IDvbDefaultAuthorityDescriptor::GetDefaultAuthority

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

Gets the string identifying the default authority from a Digital Video Broadcast (DVB)
content reference identifier (CRID).

## Parameters

### `pbLength` [out]

Receives the length of the default authority string in bytes.

### `ppbBytes` [out]

Pointer to a buffer that receives the default authority string. The caller is responsible for releasing this memory.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IDvbDefaultAuthorityDescriptor](https://learn.microsoft.com/previous-versions/windows/desktop/api/dvbsiparser/nn-dvbsiparser-idvbdefaultauthoritydescriptor)