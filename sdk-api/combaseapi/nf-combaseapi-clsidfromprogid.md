# CLSIDFromProgID function

## Description

Looks up a CLSID in the registry, given a ProgID.

## Parameters

### `lpszProgID` [in]

A pointer to the ProgID whose CLSID is requested.

### `lpclsid` [out]

Receives a pointer to the retrieved CLSID on return.

## Return value

This function can return the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The CLSID was retrieved successfully. |
| **CO_E_CLASSSTRING** | The registered CLSID for the ProgID is invalid. |
| **REGDB_E_WRITEREGDB** | An error occurred writing the CLSID to the registry. See Remarks below. |

## Remarks

Given a ProgID, **CLSIDFromProgID** looks up its associated CLSID in the registry. If the ProgID cannot be found in the registry, **CLSIDFromProgID** creates an OLE 1 CLSID for the ProgID and a CLSID entry in the registry. Because of the restrictions placed on OLE 1 CLSID values, **CLSIDFromProgID** and [CLSIDFromString](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-clsidfromstring) are the only two functions that can be used to generate a CLSID for an OLE 1 object.

## See also

[CLSIDFromProgIDEx](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-clsidfromprogidex)

[ProgIDFromCLSID](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-progidfromclsid)