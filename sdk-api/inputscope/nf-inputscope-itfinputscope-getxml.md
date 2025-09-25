# ITfInputScope::GetXML

## Description

Gets the custom XML string to be recognized.

## Parameters

### `pbstrXML` [out]

Pointer to a string containing the xml string. The calling function must call **SysFreeString()** to free the buffer.

## Return value

This method can return one of these values.

| Value | Description |
| --- | --- |
| **S_OK** | The method was successful. |