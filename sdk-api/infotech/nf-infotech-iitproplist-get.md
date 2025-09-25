# IITPropList::Get

## Description

Returns the property object associated with the given property ID.

## Parameters

### `PropID` [in]

ID of the property object to get.

### `Property` [out, ref]

The property object returned.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | The property was successfully returned. |
| **E_NOTEXIST** | The requested property does not exist. |

## See also

[IITPropList](https://learn.microsoft.com/previous-versions/windows/desktop/api/infotech/nn-infotech-iitproplist)