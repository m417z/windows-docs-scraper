# IContactPropertyCollection::Reset

## Description

Resets enumeration of properties.

## Return value

Type: **HRESULT**

Returns one of the following values:

| Return code | Description |
| --- | --- |
| **S_OK** | Reset is successful. |

## Remarks

**Note** Collection has been reset to the location before the first element (if any elements are present),
so you must call [IContactPropertyCollection::Next](https://learn.microsoft.com/previous-versions/windows/desktop/api/icontact/nf-icontact-icontactpropertycollection-next) to begin querying data.