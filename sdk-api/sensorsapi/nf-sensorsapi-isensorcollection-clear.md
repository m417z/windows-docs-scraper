# ISensorCollection::Clear

## Description

Empties the sensor collection.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

This method calls **Release** on all sensor interface pointers in the collection and frees any memory used by the collection.

## See also

[ISensorCollection](https://learn.microsoft.com/windows/desktop/api/sensorsapi/nn-sensorsapi-isensorcollection)