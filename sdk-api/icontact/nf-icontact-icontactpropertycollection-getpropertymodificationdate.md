# IContactPropertyCollection::GetPropertyModificationDate

## Description

Retrieves the last modification date for the current property in the enumeration.
If not modified, contact creation date is returned.

## Parameters

### `pftModificationDate` [in, out]

Type: **[FILETIME](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-filetime)***

Specifies the last modified date as a UTC FILETIME.

## Return value

Type: **HRESULT**

Returns one of the following values:

| Return code | Description |
| --- | --- |
| **S_OK** | Query is successful. |