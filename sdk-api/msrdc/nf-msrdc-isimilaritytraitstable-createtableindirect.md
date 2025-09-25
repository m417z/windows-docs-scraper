# ISimilarityTraitsTable::CreateTableIndirect

## Description

Creates or opens a similarity traits table using the RDC application's implementation of the [ISimilarityTraitsMapping](https://learn.microsoft.com/previous-versions/windows/desktop/api/msrdc/nn-msrdc-isimilaritytraitsmapping) interface.

## Parameters

### `mapping` [in]

An [ISimilarityTraitsMapping](https://learn.microsoft.com/previous-versions/windows/desktop/api/msrdc/nn-msrdc-isimilaritytraitsmapping) interface pointer initialized to write the similarity traits table to the file.

### `truncate` [in]

**TRUE** if a new similarity traits table should always be created or truncated. If **FALSE** is specified and the table exists and is valid, it may be used; otherwise, if the table is not valid or does not exist, the existing table is overwritten.

### `isNew` [out]

A pointer to a variable that receives an [RdcCreatedTables](https://learn.microsoft.com/windows/win32/api/msrdc/ne-msrdc-rdccreatedtables) enumeration value that describes the state of the similarity traits table. If a new table is created, this variable receives **RDCTABLE_New**. If an existing table is used, this variable receives **RDCTABLE_Existing**. If this method fails, this variable receives **RDCTABLE_InvalidOrUnknown**.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

If an existing similarity traits table is being opened, the table must be valid. Otherwise, the existing table is overwritten, even if **FALSE** is specified for the *truncate* parameter.

## See also

[ISimilarityTraitsTable](https://learn.microsoft.com/previous-versions/windows/desktop/api/msrdc/nn-msrdc-isimilaritytraitstable)