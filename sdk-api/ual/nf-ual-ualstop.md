# UalStop function

## Description

Stops a User Access Logging (UAL) session.

## Parameters

### `Data` [in]

A pointer to an [UAL_DATA_BLOB](https://learn.microsoft.com/windows/desktop/api/ual/ns-ual-ual_data_blob) structure that specifies session information.

Only the **RoleGuid** property of the [UAL_DATA_BLOB](https://learn.microsoft.com/windows/desktop/api/ual/ns-ual-ual_data_blob) structure is required. All other members can be null.

## Return value

If the function succeeds, it returns **S_OK**. If it fails, it returns an error code.

## See also

[UalInstrument](https://learn.microsoft.com/previous-versions/windows/desktop/api/ual/nf-ual-ualinstrument)

[UalStart](https://learn.microsoft.com/previous-versions/windows/desktop/api/ual/nf-ual-ualstart)