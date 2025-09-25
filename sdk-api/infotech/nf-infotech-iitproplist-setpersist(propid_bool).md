# IITPropList::SetPersist

## Description

Sets the persistence state on or off for a given property.

## Parameters

### `PropID` [in]

ID of the property to set.

### `fPersist` [in]

Persistence state. If TRUE, the persistence state is on; if FALSE, the state is off.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | The state was successfully set. |
| **E_NOTEXIST** | The requested property does not exist. |

## Remarks

By default, properties are created with a persistence state of TRUE.

## See also

[IITPropList](https://learn.microsoft.com/previous-versions/windows/desktop/api/infotech/nn-infotech-iitproplist)