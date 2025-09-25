# IDiscMaster::EnumDiscMasterFormats

## Description

Retrieves an enumerator for all disc mastering formats supported by this disc master object. A disc master format specifies the structure of the content in a staged image file (data/audio) and the interface that manages the staged image.

## Parameters

### `ppEnum` [out]

Address of a pointer to the **IEnumDiscMasterFormats** enumerator.

## Return value

S_OK is returned on success, but other success codes may be returned as a result of implementation. The following error codes are commonly returned on operation failure, but do not represent the only possible error values:

## Remarks

**MSDiscMasterObj** returns an enumerator that identifies the supported formats by their interface IDs. Currently, there are two formats: IID_IRedbookDiscMaster (
[IRedbookDiscMaster](https://learn.microsoft.com/windows/desktop/api/imapi/nn-imapi-iredbookdiscmaster)) and IID_IJolietDiscMaster (
[IJolietDiscMaster](https://learn.microsoft.com/windows/desktop/api/imapi/nn-imapi-ijolietdiscmaster)).

**IEnumDiscMasterFormats** is standard COM enumerator, as documented in
**IEnumXXXX**. Each call to **Next** returns an array of IIDs, one IID per supported disc master format. To select the active format and retrieve a pointer to a format specific interface, use
[SetActiveDiscMasterFormat](https://learn.microsoft.com/windows/desktop/api/imapi/nf-imapi-idiscmaster-setactivediscmasterformat). (Do not use **QueryInterface**, because the interface will not be associated with the active format).

## See also

[IDiscMaster](https://learn.microsoft.com/windows/desktop/api/imapi/nn-imapi-idiscmaster)