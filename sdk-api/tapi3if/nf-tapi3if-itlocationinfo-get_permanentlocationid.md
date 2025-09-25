# ITLocationInfo::get_PermanentLocationID

## Description

The
**get_PermanentLocationID** method gets the permanent location identifier.

## Parameters

### `plLocationID` [out]

Pointer to the permanent location identifier.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Method succeeded. |
| **E_POINTER** | The *plLocationID* parameter is not a valid pointer. |
| **E_OUTOFMEMORY** | Insufficient memory exists to perform the operation. |

## Remarks

The value that this method returns corresponds to the **dwPermanentLocationID** member of TAPI 2's
[LINELOCATIONENTRY](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-linelocationentry) structure.

## See also

[ITLocationInfo](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itlocationinfo)

[LINELOCATIONENTRY](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-linelocationentry)

[lineGetTranslateCaps](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linegettranslatecaps)