# IISDB_CDT::GetTableDescriptorByTag

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

Searches a subtable in
an Integrated Services Digital Broadcasting (ISDB)
common data table (CDT).

## Parameters

### `bTag` [in]

Specifies the descriptor tag for which to search.

### `pdwCookie` [in, out]

Pointer to a variable that specifies the start position
in the descriptor list. This parameter is optional.
If the value of *pdwCookie* is **NULL**, the search starts from the
first descriptor in the list. Otherwise, the search starts from
the position given in *pdwCookie*. When the method returns, the *pdwCookie* parameter contains the position of the next matching descriptor,
if any. You can use this parameter to iterate through the descriptor list,
looking for every instance of a particular descriptor tag.

### `ppDescriptor` [out]

Receives an [IGenericDescriptor](https://learn.microsoft.com/windows/desktop/api/mpeg2psiparser/nn-mpeg2psiparser-igenericdescriptor) interface pointer. Use this interface to retrieve the information
in the descriptor. The caller must release the interface.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IGenericDescriptor](https://learn.microsoft.com/windows/desktop/api/mpeg2psiparser/nn-mpeg2psiparser-igenericdescriptor)

[IISDB_CDT](https://learn.microsoft.com/previous-versions/windows/desktop/api/dvbsiparser/nn-dvbsiparser-iisdb_cdt)