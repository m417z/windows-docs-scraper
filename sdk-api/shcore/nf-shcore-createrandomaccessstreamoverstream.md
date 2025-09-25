# CreateRandomAccessStreamOverStream function

## Description

Creates a Windows Runtime random access stream around an [IStream](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-istream) base implementation.

## Parameters

### `stream` [in]

The COM stream to encapsulate.

### `options` [in]

One of the [BSOS_OPTIONS](https://learn.microsoft.com/windows/desktop/api/shcore/ne-shcore-bsos_options) options that specify the behavior of the [RandomAccessStream](https://learn.microsoft.com/uwp/api/windows.storage.streams.randomaccessstream) that encapsulates *stream*.

### `riid` [in]

A reference to the IID of the interface to retrieve through *ppv*, typically IID_RandomAccessStream.

### `ppv` [out]

When this method returns successfully, contains the interface pointer to the [RandomAccessStream](https://learn.microsoft.com/uwp/api/windows.storage.streams.randomaccessstream) that encapsulates *stream* requested in *riid*.

## Return value

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

Use the **CreateRandomAccessStreamOverStream** function to create a [RandomAccessStream](https://learn.microsoft.com/uwp/api/windows.storage.streams.randomaccessstream) that encapsulates a COM [IStream](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-istream).

For info on utility classes that help with interoperation between Windows Runtime and COM streams, see the Remarks at **RandomAccessStreamOverStream**.

We recommend that you use the [IID_PPV_ARGS](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-iid_ppv_args) macro, defined in Objbase.h, to package the *riid* and *ppv* parameters. This macro provides the correct IID based on the interface pointed to by the value in *ppv*, which eliminates the possibility of a coding error in *riid* that could lead to unexpected results.

## See also

[CreateRandomAccessStreamOnFile](https://learn.microsoft.com/windows/desktop/api/shcore/nf-shcore-createrandomaccessstreamonfile)

[CreateStreamOverRandomAccessStream](https://learn.microsoft.com/windows/desktop/api/shcore/nf-shcore-createstreamoverrandomaccessstream)

[RandomAccessStream](https://learn.microsoft.com/uwp/api/windows.storage.streams.randomaccessstream)