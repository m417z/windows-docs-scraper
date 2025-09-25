# ITokenCollection::GetToken

## Description

Retrieves the position, length, and any overriding string of an individual token.

## Parameters

### `i` [in]

Type: **ULONG**

The zero-based index of the desired token within the collection.

### `pBegin` [out]

Type: **ULONG***

Receives the zero-based starting position of the specified token, in characters. This parameter can be **NULL**.

### `pLength` [out]

Type: **ULONG***

Receives the number of characters spanned by the token. This parameter can be **NULL**.

### `ppsz` [out]

Type: **LPWSTR***

Receives the overriding text for this token if available, or **NULL** if there is none.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.