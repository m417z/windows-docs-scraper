# IDiscMaster::GetActiveDiscMasterFormat

## Description

Retrieves the active disc recorder format. The active format specifies both the structure of the staged image file content (audio/data) and the COM interface that must be used to manipulate that staged image.

## Parameters

### `lpiid` [out]

IID of the currently active format.

## Return value

S_OK is returned on success, but other success codes may be returned as a result of implementation. The following error codes are commonly returned on operation failure, but do not represent the only possible error values:

## Remarks

**MSDiscMasterObj** supports the IIDs for two formats: IID_IRedbookDiscMaster ([IRedbookDiscMaster](https://learn.microsoft.com/windows/desktop/api/imapi/nn-imapi-iredbookdiscmaster)) and IID_IJolietDiscMaster ([IJolietDiscMaster](https://learn.microsoft.com/windows/desktop/api/imapi/nn-imapi-ijolietdiscmaster)). To select the active format and retrieve a pointer to a format-specific interface, use
[SetActiveDiscMasterFormat](https://learn.microsoft.com/windows/desktop/api/imapi/nf-imapi-idiscmaster-setactivediscmasterformat).

## See also

[IDiscMaster](https://learn.microsoft.com/windows/desktop/api/imapi/nn-imapi-idiscmaster)