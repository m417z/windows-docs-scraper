# ITLocationInfo::get_CityCode

## Description

The
**get_CityCode** method gets the code for the city.

## Parameters

### `ppCode` [out]

Pointer to the **BSTR** representation of the city code.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Method succeeded. |
| **E_POINTER** | The *ppCode* parameter is not a valid pointer. |
| **E_OUTOFMEMORY** | Insufficient memory exists to perform the operation. |

## Remarks

The application must use
[SysFreeString](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-sysfreestring) to free the memory allocated for the *ppCode* parameter.

The value that this method returns corresponds to the **dwCityCodeSize** and **dwCityCodeOffset** members of TAPI 2's
[LINELOCATIONENTRY](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-linelocationentry) structure.

## See also

[ITLocationInfo](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itlocationinfo)

[LINELOCATIONENTRY](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-linelocationentry)

[lineGetTranslateCaps](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linegettranslatecaps)