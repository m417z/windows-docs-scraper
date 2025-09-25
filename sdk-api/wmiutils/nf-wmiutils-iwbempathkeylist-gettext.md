# IWbemPathKeyList::GetText

## Description

The
**IWbemPathKeyList::GetText** method retrieves the key list as text.

## Parameters

### `lFlags` [in]

Flags which control the format of the text. The following list lists the valid flag values.

#### WBEMPATH_QUOTEDTEXT

Places quotes around the string key values.

#### WBEMPATH_TEXT

Not used.

### `puBuffLength` [in, out]

Caller sets this to the number of characters that the buffer can hold. Upon success, this is set to the number of characters copied into the buffer, including the **NULL** terminator.

### `pszText` [in, out]

Buffer into which the text is copied.

## Return value

This method returns an **HRESULT** indicating the status of the method call.

## Remarks

This method can be used to determine how big a buffer is needed by passing in a **NULL** pointer for the buffer and setting its size parameter to 0 (zero). Upon return, the buffer's size parameter indicates how large of a buffer is needed for the string and its **NULL** terminator.

## See also

[IWbemPath](https://learn.microsoft.com/windows/desktop/api/wmiutils/nn-wmiutils-iwbempath)

[IWbemPathKeyList](https://learn.microsoft.com/windows/desktop/api/wmiutils/nn-wmiutils-iwbempathkeylist)