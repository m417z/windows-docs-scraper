# IDVB_NIT::GetNextTable

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

This topic applies to Update Rollup 2 for Microsoft Windows XP Media Center Edition 2005 and later.

The **GetNextTable** method retrieves the *next* table that follows the current table.

## Parameters

### `ppNIT` [out]

Address of a variable that receives an **IDVB_NIT** interface pointer. The caller must release the interface.

## Return value

The method returns an **HRESULT**. Possible values include those in the following table.

| Return code | Description |
| --- | --- |
| **E_ACCESSDENIED** | This table is not current. |
| **E_FAIL** | Failure. |
| **S_OK** | The method succeeded. |

## Remarks

This method applies only to current tables. Otherwise, the method returns E_ACCESSDENIED.

## See also

[IDVB_NIT Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/dvbsiparser/nn-dvbsiparser-idvb_nit)