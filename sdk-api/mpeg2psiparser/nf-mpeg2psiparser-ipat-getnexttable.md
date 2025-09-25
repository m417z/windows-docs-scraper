# IPAT::GetNextTable

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

The **GetNextTable** method retrieves the *next* table that follows the current table.

## Parameters

### `ppPAT` [out]

Address of a variable that receives an **IPAT** interface pointer. The caller must release the interface.

## Return value

The method returns an **HRESULT**. Possible values include those in the following table.

| Return code | Description |
| --- | --- |
| **E_ACCESSDENIED** | This table is not current. |
| **E_FAIL** | Failure. |
| **S_OK** | The method succeeded. |

## Remarks

This method applies only to *current* tables. Otherwise, the method returns E_ACCESSDENIED.

## See also

[IPAT Interface](https://learn.microsoft.com/windows/desktop/api/mpeg2psiparser/nn-mpeg2psiparser-ipat)