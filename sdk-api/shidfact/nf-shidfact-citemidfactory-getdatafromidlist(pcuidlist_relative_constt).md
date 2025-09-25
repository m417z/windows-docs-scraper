# CItemIDFactory::GetDataFromIDList(PCUIDLIST_RELATIVE,const T)

## Description

Gets a read only pointer to the client provided structure in the first ItemID in the IDList.

## Parameters

### `pidl` [in]

A PIDL containing the data.

### `ppData` [out]

When this method returns, contains the address of a read only pointer to a client provided structure.

## Return value

If the method succeeds, it returns **S_OK**. If it fails, it returns **E_INVALIDARG**.

## See also

[CItemIDFactory](https://learn.microsoft.com/windows/desktop/api/shidfact/nl-shidfact-citemidfactory)