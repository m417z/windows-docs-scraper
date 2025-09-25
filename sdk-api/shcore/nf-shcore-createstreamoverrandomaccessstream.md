# CreateStreamOverRandomAccessStream function

## Description

Creates an [IStream](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-istream) around a Windows Runtime [IRandomAccessStream](https://learn.microsoft.com/previous-versions/hh438400(v=vs.85)) object.

## Parameters

### `randomAccessStream` [in]

The source [IRandomAccessStream](https://learn.microsoft.com/previous-versions/hh438400(v=vs.85)).

### `riid` [in]

A reference to the IID of the interface to retrieve through *ppv*, typically IID_IStream. This object encapsulates *randomAccessStream*.

### `ppv` [out]

When this method returns successfully, contains the interface pointer requested in *riid*, typically [IStream](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-istream).

## Return value

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

We recommend that you use the [IID_PPV_ARGS](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-iid_ppv_args) macro, defined in Objbase.h, to package the *riid* and *ppv* parameters. This macro provides the correct IID based on the interface pointed to by the value in *ppv*, which eliminates the possibility of a coding error in *riid* that could lead to unexpected results.

## See also

[CreateRandomAccessStreamOnFile](https://learn.microsoft.com/windows/desktop/api/shcore/nf-shcore-createrandomaccessstreamonfile)

[CreateRandomAccessStreamOverStream](https://learn.microsoft.com/windows/desktop/api/shcore/nf-shcore-createrandomaccessstreamoverstream)

[RandomAccessStream](https://learn.microsoft.com/uwp/api/windows.storage.streams.randomaccessstream)