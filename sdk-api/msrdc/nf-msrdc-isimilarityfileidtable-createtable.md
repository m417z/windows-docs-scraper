# ISimilarityFileIdTable::CreateTable

## Description

 Creates or opens a similarity file ID table.

## Parameters

### `path` [in]

A pointer to a null-terminated string that specifies the name of the file that will contain the similarity file ID table. The alternate stream name ":FileId" will be appended to the end of this file name. For more information, see [Naming a File](https://learn.microsoft.com/windows/desktop/FileIO/naming-a-file).

### `truncate` [in]

**TRUE** if a new similarity file ID table should always be created or truncated. If **FALSE** is specified and the table exists and is valid, it may be used; otherwise, if the table is not valid or does not exist, the existing table is overwritten.

### `securityDescriptor` [in]

A pointer to a security descriptor to use when opening the file. If this parameter is **NULL**, the file is assigned a default security descriptor. The access control lists (ACL) in the file's default security descriptor are inherited from the file's parent directory. For more information, see the *lpSecurityAttributes* parameter of the [CreateFile](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-createfilea) function.

### `recordSize` [in]

The size, in bytes, of the file IDs that will be stored in the similarity file ID table. All file IDs must be the same size. The valid range is from **SimilarityFileIdMinSize** to **SimilarityFileIdMaxSize**. If an existing similarity file ID table is being opened, the value of this parameter must match the file ID size of the existing table. Otherwise, the existing table is assumed to be not valid and will be overwritten.

### `isNew` [out]

A pointer to a variable that receives an [RdcCreatedTables](https://learn.microsoft.com/windows/win32/api/msrdc/ne-msrdc-rdccreatedtables) enumeration value that describes the state of the similarity file ID table. If a new table is created, this variable receives **RDCTABLE_New**. If an existing table is used, this variable receives **RDCTABLE_Existing**. If this method fails, this variable receives **RDCTABLE_InvalidOrUnknown**.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

If an existing table is being opened, the table must be valid, and the value of the *recordSize* parameter must match the record size of the existing table. Otherwise, the existing table is overwritten, even if **FALSE** is specified for the *truncate* parameter.

## See also

[ISimilarityFileIdTable](https://learn.microsoft.com/previous-versions/windows/desktop/api/msrdc/nn-msrdc-isimilarityfileidtable)