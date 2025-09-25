## Description

Indicates whether the specified string has embedded null characters.

## Parameters

### `string`

Type: [in] **[HSTRING](https://learn.microsoft.com/windows/win32/winrt/hstring)**

The string to test for embedded null characters.

### `hasEmbedNull`

Type: [out] **BOOL***

**TRUE** if *string* has one or more embedded null characters; otherwise, **FALSE**. **FALSE** if *string* is **NULL** or the empty string.

## Return value

Type: **HRESULT**

This function can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | The test completed successfully. |
| **E_INVALIDARG** | *hasEmbedNull* is **NULL**. |