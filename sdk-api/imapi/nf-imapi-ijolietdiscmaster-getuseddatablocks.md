# IJolietDiscMaster::GetUsedDataBlocks

## Description

Retrieves the total number of data blocks that are in use. The data returned from this method is valid only after a
[SetActiveDiscRecorder](https://learn.microsoft.com/windows/desktop/api/imapi/nf-imapi-idiscmaster-setactivediscrecorder) call, especially in a multi-session burn.

## Parameters

### `pnBlocks` [out]

Total number of data blocks in use in the staged image.

## Return value

S_OK is returned on success, but other success codes may be returned as a result of implementation. The following error codes are commonly returned on operation failure, but do not represent the only possible error values:

## See also

[IJolietDiscMaster](https://learn.microsoft.com/windows/desktop/api/imapi/nn-imapi-ijolietdiscmaster)