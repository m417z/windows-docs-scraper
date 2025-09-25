# ISimilarity::CreateTable

## Description

Creates or opens a similarity traits table and a similarity file ID table.

## Parameters

### `path` [in]

A pointer to a null-terminated string that specifies the name of the file that will contain the tables. The similarity traits table and the similarity file ID table will be created in two alternate file streams of this file. For more information, see the *path* parameter of the [ISimilarityFileIdTable::CreateTable](https://learn.microsoft.com/previous-versions/windows/desktop/api/msrdc/nf-msrdc-isimilarityfileidtable-createtable) and [ISimilarityTraitsTable::CreateTable](https://learn.microsoft.com/previous-versions/windows/desktop/api/msrdc/nf-msrdc-isimilaritytraitstable-createtable) methods.

### `truncate` [in]

**TRUE** if a new similarity traits table and a new similarity file ID table should always be created or truncated. If **FALSE** is specified and these tables exist and are valid, they may be used; otherwise, if one of the tables is not valid or does not exist, any existing tables are overwritten.

### `securityDescriptor` [in]

A pointer to a security descriptor to use when opening the file. If this parameter is **NULL**, the file is assigned a default security descriptor. The access control lists (ACL) in the file's default security descriptor are inherited from the file's parent directory. For more information, see the *lpSecurityAttributes* parameter of the [CreateFile](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-createfilea) function.

### `recordSize` [in]

The size, in bytes, of each file ID to be stored in the similarity file id table. All similarity file IDs must be the same size. The valid range is from **SimilarityFileIdMinSize** to **SimilarityFileIdMaxSize**. If existing tables are being opened, the value of this parameter must match the file ID size of the existing similarity file ID table. Otherwise, the existing tables are assumed to be not valid and will be overwritten.

### `isNew` [out]

A pointer to a variable that receives an [RdcCreatedTables](https://learn.microsoft.com/windows/win32/api/msrdc/ne-msrdc-rdccreatedtables) enumeration value that describes the state of the tables. If new tables are created, this variable receives **RDCTABLE_New**. If existing tables are used, this variable receives **RDCTABLE_Existing**. If this method fails, this variable receives **RDCTABLE_InvalidOrUnknown**.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

If one of the tables can be created or opened successfully, but the other one cannot, both tables are marked as not valid, and the variable that the *isNew* parameter points to receives **RDCTABLE_InvalidOrUnknown**.

## See also

[ISimilarity](https://learn.microsoft.com/previous-versions/windows/desktop/api/msrdc/nn-msrdc-isimilarity)