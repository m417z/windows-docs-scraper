# IRandomAccessStreamFileAccessMode::GetMode

## Description

Retrieves the file access mode that was used when the [StorageFile.OpenAsync](https://learn.microsoft.com/uwp/api/windows.storage.storagefile.openasync) method was called to open the random-access byte stream.

## Parameters

### `fileAccessMode` [out]

The file access mode that was used when the [StorageFile.OpenAsync](https://learn.microsoft.com/uwp/api/windows.storage.storagefile.openasync) method was called to open the random-access byte stream. Cast this value as a [Windows::Storage::FileAccessMode](https://learn.microsoft.com/uwp/api/Windows.Storage.FileAccessMode) enumeration value.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IRandomAccessStreamFileAccessMode](https://learn.microsoft.com/windows/desktop/api/windowsstoragecom/nn-windowsstoragecom-irandomaccessstreamfileaccessmode)

[StorageFile.OpenAsync](https://learn.microsoft.com/uwp/api/windows.storage.storagefile.openasync)

[Windows::Storage::FileAccessMode](https://learn.microsoft.com/uwp/api/Windows.Storage.FileAccessMode)