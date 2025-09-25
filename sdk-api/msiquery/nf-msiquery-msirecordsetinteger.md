# MsiRecordSetInteger function

## Description

The
**MsiRecordSetInteger** function sets a record field to an integer field.

## Parameters

### `hRecord` [in]

Handle to the record.

### `iField` [in]

Specifies the field of the record to set.

### `iValue` [in]

Specifies the value to which to set the field.

## Return value

This function returns UINT.

## Remarks

In the
**MsiRecordSetInteger** function, attempting to store a value in a nonexistent field causes an error. Note that the following code returns **ERROR_INVALID_PARAMETER**.

```cpp
MSIHANDLE hRecord;
UINT lReturn;

//create an msirecord with no fields
hRecord = MsiCreateRecord(0);

//attempting to set the first field's value gives you ERROR_INVALID_PARAMETER
lReturn = MsiRecordSetInteger(hRecord, 1, 0);

```

To set a record integer field to **NULL_INTEGER**, set *iValue* to **MSI_NULL_INTEGER**.

## See also

[Record Processing Functions](https://learn.microsoft.com/windows/desktop/Msi/database-functions)