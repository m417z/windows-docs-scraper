# IDXGIInfoQueue::GetMessage

## Description

Gets a message from the message queue.

## Parameters

### `Producer` [in]

 A [DXGI_DEBUG_ID](https://learn.microsoft.com/windows/desktop/direct3ddxgi/dxgi-debug-id) value that identifies the entity that gets the message.

### `MessageIndex` [in]

An index into the message queue after an optional retrieval filter has been applied. This can be between 0 and the number of messages in the message queue that pass through the retrieval filter. Call [IDXGIInfoQueue::GetNumStoredMessagesAllowedByRetrievalFilters](https://learn.microsoft.com/windows/desktop/api/dxgidebug/nf-dxgidebug-idxgiinfoqueue-getnumstoredmessagesallowedbyretrievalfilters) to obtain this number. 0 is the message at the beginning of the message queue.

### `pMessage` [out, optional]

A pointer to a [DXGI_INFO_QUEUE_MESSAGE](https://learn.microsoft.com/windows/desktop/api/dxgidebug/ns-dxgidebug-dxgi_info_queue_message) structure that describes the message.

### `pMessageByteLength` [in, out]

A pointer to a variable that receives the size, in bytes, of the message description that *pMessage* points to. This size includes the size of the [DXGI_INFO_QUEUE_MESSAGE](https://learn.microsoft.com/windows/desktop/api/dxgidebug/ns-dxgidebug-dxgi_info_queue_message) structure in bytes.

## Return value

Returns S_OK if successful; an error code otherwise. For a list of error codes, see [DXGI_ERROR](https://learn.microsoft.com/windows/desktop/direct3ddxgi/dxgi-error).

## Remarks

This method doesn't remove any messages from the message queue.

This method gets a message from the message queue after an optional retrieval filter has been applied.

Call this method twice to retrieve a message, first to obtain the size of the message and second to get the message. Here is a typical example:

```

// Get the size of the message.
SIZE_T messageLength = 0;
HRESULT hr = pInfoQueue->GetMessage(DXGI_DEBUG_ALL, 0, NULL, &messageLength);
if(hr == S_FALSE){

    // Allocate space and get the message.
    DXGI_INFO_QUEUE_MESSAGE * pMessage = (DXGI_INFO_QUEUE_MESSAGE*)malloc(messageLength);
    hr = pInfoQueue->GetMessage(DXGI_DEBUG_ALL, 0, pMessage, &messageLength);

    // Do something with the message and free it
    if(hr == S_OK){

        // ...
        // ...
        // ...
        free(pMessage);
    }
}
```

**Note** This API requires the Windows Software Development Kit (SDK) for Windows 8.

## See also

[IDXGIInfoQueue](https://learn.microsoft.com/windows/desktop/api/dxgidebug/nn-dxgidebug-idxgiinfoqueue)