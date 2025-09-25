# ID3D10InfoQueue::GetMessage

## Description

Get a message from the message queue.

## Parameters

### `MessageIndex` [in]

Type: **[UINT64](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Index into message queue after an optional retrieval filter has been applied. This can be between 0 and the number of messages in the message queue that pass through the retrieval filter (which can be obtained with [ID3D10InfoQueue::GetNumStoredMessagesAllowedByRetrievalFilter](https://learn.microsoft.com/windows/desktop/api/d3d10sdklayers/nf-d3d10sdklayers-id3d10infoqueue-getnumstoredmessagesallowedbyretrievalfilter)). 0 is the message at the front of the message queue.

### `pMessage` [out]

Type: **[D3D10_MESSAGE](https://learn.microsoft.com/windows/desktop/api/d3d10sdklayers/ns-d3d10sdklayers-d3d10_message)***

Returned message (see [D3D10_MESSAGE](https://learn.microsoft.com/windows/desktop/api/d3d10sdklayers/ns-d3d10sdklayers-d3d10_message)).

### `pMessageByteLength` [in, out]

Type: **[SIZE_T](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)***

Size of pMessage in bytes, including the size of the message string that the pMessage points to.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

This method returns one of the following [Direct3D 10 Return Codes](https://learn.microsoft.com/windows/desktop/direct3d10/d3d10-graphics-reference-returnvalues).

## Remarks

This method does not remove any messages from the message queue.

This method gets messages from the message queue after an optional retrieval filter has been applied.

Applications should call this method twice to retrieve a message - first to obtain the size of the message and second to get the message. Here is a typical example:

```

// Get the size of the message
SIZE_T messageLength = 0;
HRESULT hr = pInfoQueue->GetMessage(0, NULL, &messageLength);

// Allocate space and get the message
D3D10_MESSAGE * pMessage = (D3D10_MESSAGE*)malloc(messageLength);
hr = pInfoQueue->GetMessage(0, pMessage, &messageLength);

```

For an overview see [Information Queue Overview](https://learn.microsoft.com/windows/desktop/api/d3d10sdklayers/nn-d3d10sdklayers-id3d10infoqueue).

## See also

[ID3D10InfoQueue Interface](https://learn.microsoft.com/windows/desktop/api/d3d10sdklayers/nn-d3d10sdklayers-id3d10infoqueue)