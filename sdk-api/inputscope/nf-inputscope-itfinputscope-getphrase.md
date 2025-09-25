# ITfInputScope::GetPhrase

## Description

Gets the phrase list set to this context.

## Parameters

### `ppbstrPhrases` [out]

Pointer to an array of pointers to strings containing phrases. The calling function must call **SystFreeString()** to free the memory allocated to the strings and **CoTaskMemFree** to free the buffer.

### `pcCount` [out]

Pointer to the number of phrases returned.

## Return value

This method can return one of these values.

| Value | Description |
| --- | --- |
| **S_OK** | The method was successful. |