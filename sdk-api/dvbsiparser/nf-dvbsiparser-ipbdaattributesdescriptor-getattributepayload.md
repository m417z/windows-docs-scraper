# IPBDAAttributesDescriptor::GetAttributePayload

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

Gets the descriptor body from an attributes descriptor in a Protected Broadcast Device Architecture (PBDA) transport stream.

## Parameters

### `ppbAttributeBuffer` [out]

Pointer to a buffer that receives the descriptor body. The caller must free this memory after use.

### `pdwAttributeLength` [out]

Receives the descriptor body length.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IPBDAAttributesDescriptor](https://learn.microsoft.com/previous-versions/windows/desktop/api/dvbsiparser/nn-dvbsiparser-ipbdaattributesdescriptor)