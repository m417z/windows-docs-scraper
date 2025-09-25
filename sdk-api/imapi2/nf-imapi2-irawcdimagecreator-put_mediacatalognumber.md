# IRawCDImageCreator::put_MediaCatalogNumber

## Description

Retrieves the Media Catalog Number (MCN) for the entire audio disc.

## Parameters

### `value` [in]

A **BSTR** value that represents the MCN to associate with the audio disc.

## Return value

S_OK is returned on success, but other success codes may be returned as a result of implementation.

## Remarks

The returned MCN is formatted as a 13-digit decimal number and must also be provided in the same form. Additionally, the provided MCN value must have a valid checksum digit (least significant digit), or it will be rejected. For improved compatibility with scripting, leading zeros may be excluded. For example, "0123456789012" can be expressed as "123456789012".

Please refer to the MMC specification for details regarding the MCN value.

This method is supported in Windows Server 2003 with Service Pack 1 (SP1), Windows XP with Service Pack 2 (SP2), and Windows Vista via the Windows Feature Pack for Storage. All features provided by this update package are supported natively in Windows 7 and Windows Server 2008 R2.

## See also

[IRawCDImageCreator](https://learn.microsoft.com/windows/desktop/api/imapi2/nn-imapi2-irawcdimagecreator)

[IRawCDImageCreator::get_MediaCatalogNumber](https://learn.microsoft.com/windows/desktop/api/imapi2/nf-imapi2-irawcdimagecreator-get_mediacatalognumber)