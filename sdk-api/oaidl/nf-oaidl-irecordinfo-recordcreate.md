# IRecordInfo::RecordCreate

## Description

Allocates memory for a new record, initializes the instance and returns a pointer to the record.

## Return value

This method returns a pointer to the created record.

## Remarks

The memory is set to zeros before it is returned.

The records created must be freed by calling [RecordDestroy](https://learn.microsoft.com/previous-versions/windows/desktop/api/oaidl/nf-oaidl-irecordinfo-recorddestroy).

## See also

[IRecordInfo](https://learn.microsoft.com/previous-versions/windows/desktop/api/oaidl/nn-oaidl-irecordinfo)