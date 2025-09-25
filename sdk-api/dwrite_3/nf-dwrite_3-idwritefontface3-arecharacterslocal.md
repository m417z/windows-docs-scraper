# IDWriteFontFace3::AreCharactersLocal

## Description

Determines whether the specified characters are local.

## Parameters

### `characters` [in]

Type: **WCHAR**

Array of characters.

### `characterCount`

Type: **UINT32**

The number of elements in the character array.

### `enqueueIfNotLocal`

Type: **BOOL**

Specifies whether to enqueue a download request
if any of the specified characters are not local.

### `isLocal` [out]

Type: **BOOL***

Receives TRUE if all of the specified characters are local,
FALSE if any of the specified characters are remote.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IDWriteFontFace3](https://learn.microsoft.com/windows/win32/api/dwrite_3/nn-dwrite_3-idwritefontface3)