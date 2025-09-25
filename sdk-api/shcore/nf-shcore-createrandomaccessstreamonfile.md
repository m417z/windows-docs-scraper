# CreateRandomAccessStreamOnFile function

## Description

Creates a Windows Runtime random access stream for a file.

## Parameters

### `filePath` [in]

The fully qualified path of the file to encapsulate.

### `accessMode` [in]

An [AccessMode](https://learn.microsoft.com/uwp/api/Windows.Storage.FileAccessMode) value that specifies the behavior of the [RandomAccessStream](https://learn.microsoft.com/uwp/api/windows.storage.streams.randomaccessstream) that encapsulates the file.

### `riid` [in]

A reference to the IID of the interface to retrieve through *ppv*, typically IID_RandomAccessStream.

### `ppv` [out]

When this method returns successfully, contains the interface pointer requested in *riid*, typically the [IRandomAccessStream](https://learn.microsoft.com/previous-versions/hh438400(v=vs.85)) that encapsulates the file.

## Return value

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

Use the **CreateRandomAccessStreamOnFile** function to create a [RandomAccessStream](https://learn.microsoft.com/uwp/api/windows.storage.streams.randomaccessstream) that encapsulates a file.

We recommend that you use the [IID_PPV_ARGS](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-iid_ppv_args) macro, defined in Objbase.h, to package the *riid* and *ppv* parameters. This macro provides the correct IID based on the interface pointed to by the value in *ppv*, which eliminates the possibility of a coding error in *riid* that could lead to unexpected results.

## See also

[CreateRandomAccessStreamOverStream](https://learn.microsoft.com/windows/desktop/api/shcore/nf-shcore-createrandomaccessstreamoverstream)

[CreateStreamOverRandomAccessStream](https://learn.microsoft.com/windows/desktop/api/shcore/nf-shcore-createstreamoverrandomaccessstream)

[RandomAccessStream](https://learn.microsoft.com/uwp/api/windows.storage.streams.randomaccessstream)