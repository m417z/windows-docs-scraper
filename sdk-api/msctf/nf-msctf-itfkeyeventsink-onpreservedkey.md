# ITfKeyEventSink::OnPreservedKey

## Description

Called when a preserved key event occurs.

## Parameters

### `pic` [in]

Pointer to the input context that receives the key event.

### `rguid` [in]

Contains the command GUID of the preserved key.

### `pfEaten` [out]

Pointer to a BOOL value that, on exit, indicates if the preserved key event was handled. If this value receives **TRUE**, the preserved key event was handled. If this value receives **FALSE**, the preserved key event was not handled.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.