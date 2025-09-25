# STGOPTIONS structure

## Description

The
**STGOPTIONS** structure specifies features of the storage object, such as sector size, in the
[StgCreateStorageEx](https://learn.microsoft.com/windows/desktop/api/coml2api/nf-coml2api-stgcreatestorageex) and
[StgOpenStorageEx](https://learn.microsoft.com/windows/desktop/api/coml2api/nf-coml2api-stgopenstorageex) functions.

## Members

### `usVersion`

Specifies the version of the
**STGOPTIONS** structure. It is set to **STGOPTIONS_VERSION**.

**Note** When **usVersion** is set to 1, the **ulSectorSize** member can be set. This is useful when creating a large-sector documentation file.
However, when **usVersion** is set to 1, the **pwcsTemplateFile** member cannot be used.

**In Windows 2000 and later:** **STGOPTIONS_VERSION** can be set to 1 for version 1.

**In Windows XP and later:** **STGOPTIONS_VERSION** can be set to 2 for version 2.

**For operating systems prior to Windows 2000:** **STGOPTIONS_VERSION** will be set to 0 for version 0.

### `reserved`

Reserved for future use; must be zero.

### `ulSectorSize`

Specifies the sector size of the storage object. The default is 512 bytes.

### `pwcsTemplateFile`

Specifies the name of a file whose Encrypted File System (EFS) metadata will be transferred to a newly created Structured Storage file. This member is valid only when **STGFMT_DOCFILE** is used with [StgCreateStorageEx](https://learn.microsoft.com/windows/desktop/api/coml2api/nf-coml2api-stgcreatestorageex).

**In Windows XP and later:** The **pwcsTemplateFile** member is only valid if version 2 or later is specified in the **usVersion** member.

## Remarks

**STGOPTIONS** is only supported on Unicode APIs.

## See also

[Compound File Implementation Limits](https://learn.microsoft.com/windows/desktop/Stg/structured-storage-interfaces)

[StgCreateStorageEx](https://learn.microsoft.com/windows/desktop/api/coml2api/nf-coml2api-stgcreatestorageex)

[StgOpenStorageEx](https://learn.microsoft.com/windows/desktop/api/coml2api/nf-coml2api-stgopenstorageex)