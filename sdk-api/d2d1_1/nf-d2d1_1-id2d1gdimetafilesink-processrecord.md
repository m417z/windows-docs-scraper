# ID2D1GdiMetafileSink::ProcessRecord

## Description

 This method is called once for each record stored in a metafile.

## Parameters

### `recordType`

Type: **DWORD**

The type of the record.

### `recordData` [out]

Type: **void***

The data for the record.

### `recordDataSize`

Type: **UINT**

The byte size of the record data.

## Return value

Type: **BOOL**

Return true if the record is successfully.

## See also

[ID2D1GdiMetafileSink](https://learn.microsoft.com/windows/desktop/api/d2d1_1/nn-d2d1_1-id2d1gdimetafilesink)