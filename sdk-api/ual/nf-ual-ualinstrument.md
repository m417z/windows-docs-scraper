# UalInstrument function

## Description

Records the specified data to the User Access Logging (UAL) framework by using information from a [UAL_DATA_BLOB](https://learn.microsoft.com/windows/desktop/api/ual/ns-ual-ual_data_blob) structure.

You must call the [UalStart](https://learn.microsoft.com/previous-versions/windows/desktop/api/ual/nf-ual-ualstart) function before calling the **UalInstrument** function. When you have finished calling this function, call the [UalStop](https://learn.microsoft.com/previous-versions/windows/desktop/api/ual/nf-ual-ualstop) function to clean up resources.

## Parameters

### `Data` [in]

A pointer to a [UAL_DATA_BLOB](https://learn.microsoft.com/windows/desktop/api/ual/ns-ual-ual_data_blob) structure that specifies session information.

## Return value

If the function succeeds, it returns **S_OK**. If it fails, it returns an error code.

## See also

[UalStart](https://learn.microsoft.com/previous-versions/windows/desktop/api/ual/nf-ual-ualstart)

[UalStop](https://learn.microsoft.com/previous-versions/windows/desktop/api/ual/nf-ual-ualstop)