# IMFNetCrossOriginSupport::GetSourceOrigin

## Description

Returns the W3C origin of the HTML5 media element.

## Parameters

### `wszSourceOrigin` [out]

The W3C origin of the HTML5 media element.

## Return value

Returns S_OK upon successful completion.

## Remarks

Use **CoTaskMemFree** to free the string.

## See also

[IMFNetCrossOriginSupport](https://learn.microsoft.com/windows/win32/api/mfidl/nn-mfidl-imfnetcrossoriginsupport)