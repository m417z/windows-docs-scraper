# ITLocationInfo::get_Options

## Description

The
**get_Options** method gets an indicator of whether the current location supports pulse or tone dialing.

## Parameters

### `plOptions` [out]

Dialing options, as indicated by values from
[LINELOCATIONOPTION_ Constants](https://learn.microsoft.com/windows/desktop/Tapi/linelocationoption--constants).

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Method succeeded. |
| **E_POINTER** | The *plOptions* parameter is not a valid pointer. |
| **E_OUTOFMEMORY** | Insufficient memory exists to perform the operation. |

## Remarks

The value that this method returns corresponds to the **dwOptions** member of TAPI 2's
[LINELOCATIONENTRY](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-linelocationentry) structure.

## See also

[ITLocationInfo](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itlocationinfo)

[LINELOCATIONENTRY](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-linelocationentry)

[lineGetTranslateCaps](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linegettranslatecaps)