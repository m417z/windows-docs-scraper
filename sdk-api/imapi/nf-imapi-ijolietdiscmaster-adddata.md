# IJolietDiscMaster::AddData

## Description

Adds the contents of a root storage to the staged image file. This storage will be enumerated to place all substorages and streams in the root file system of the stage image file. Substorages become folders and streams become files. Multiple calls to this method can be repeated to slowly stage an image file without wasting undue amounts of hard drive space building up a storage file.

## Parameters

### `pStorage` [in]

Path to the storage whose subitems are to be added to the root of the staged image file.

### `lFileOverwrite` [in]

If this parameter is nonzero, overwrite existing files with the same name. Otherwise, the last file added appears in the directory.

## Return value

S_OK is returned on success, but other success codes may be returned as a result of implementation. The following error codes are commonly returned on operation failure, but do not represent the only possible error values:

## Remarks

When you repeat an
**AddData** operation, folders with duplicate files cause a test of *lFileOverwrite*. If the flag is nonzero, the file is overwritten. Earlier files with conflicting names are still written to disc from the image file. If *lFileOverwrite* is zero and a file with the same name exists,
**AddData** fails with IMAPI_E_FILEEXISTS.

While
**AddData** can be called multiple times after calling
[IDiscMaster::SetActiveDiscRecorder](https://learn.microsoft.com/windows/desktop/api/imapi/nf-imapi-idiscmaster-setactivediscrecorder),
**SetActiveDiscRecorder** must be called any time a new image is started, and immediately before the first
**AddData** call, regardless of whether the burner is the same one used in the previous image creation.

If a call to this method would overrun the number of available data blocks, the method returns IMAPI_E_DISCFULL and ignores all data that was to be added. This ensures that the final Joliet file system is not corrupted.

## See also

[IJolietDiscMaster](https://learn.microsoft.com/windows/desktop/api/imapi/nn-imapi-ijolietdiscmaster)