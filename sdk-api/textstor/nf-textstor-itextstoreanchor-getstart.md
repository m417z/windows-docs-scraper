# ITextStoreAnchor::GetStart

## Description

The **ITextStoreAnchor::GetStart** method returns an anchor positioned at the start of the text stream.

## Parameters

### `ppaStart` [out]

Pointer to an anchor object located at the start of the text stream.

## Return value

This method can return one of these values.

| Value | Description |
| --- | --- |
| **S_OK** | The method was successful. |
| **E_INVALIDARG** | *ppaStart* is invalid. |
| **E_OUTOFMEMORY** | The attempt to instantiate an anchor at the start of the text stream failed. |