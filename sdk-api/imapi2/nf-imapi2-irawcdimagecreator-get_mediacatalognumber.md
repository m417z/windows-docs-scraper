# IRawCDImageCreator::get_MediaCatalogNumber

## Description

Sets the Media Catalog Number (MCN) for the entire audio disc.

## Parameters

### `value` [out]

Pointer to a **BSTR** value that represents the current MCN associated with the audio disc.

## Return value

S_OK is returned on success, but other success codes may be returned as a result of implementation.

## Remarks

The MCN returned by this method is formatted as a 13-digit decimal number and must also be provided by the [IRawCDImageCreator::put_MediaCatalogNumber](https://learn.microsoft.com/windows/desktop/api/imapi2/nf-imapi2-irawcdimagecreator-put_mediacatalognumber) method in the same form. Additionally, the provided a MCN value provided via **IRawCDImageCreator::put_MediaCatalogNumber** must have a valid checksum digit (least significant digit), or it will be rejected. For improved compatibility with scripting, leading zeros may be excluded. For example, "0123456789012" can be expressed as "123456789012".

Please refer to the MMC specification for details regarding the MCN value.

This method is supported in Windows Server 2003 with Service Pack 1 (SP1), Windows XP with Service Pack 2 (SP2), and Windows Vista via the Windows Feature Pack for Storage. All features provided by this update package are supported natively in Windows 7 and Windows Server 2008 R2.

## See also

[IRawCDImageCreator](https://learn.microsoft.com/windows/desktop/api/imapi2/nn-imapi2-irawcdimagecreator)

[IRawCDImageCreator::put_MediaCatalogNumber](https://learn.microsoft.com/windows/desktop/api/imapi2/nf-imapi2-irawcdimagecreator-put_mediacatalognumber)