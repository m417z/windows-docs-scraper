# VariantToFileTime function

## Description

Extracts a [FILETIME](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-filetime) structure from a variant structure.

## Parameters

### `varIn` [in]

Type: **REFVARIANT**

Reference to a source variant structure.

### `stfOut` [in]

Type: **PSTIME_FLAGS**

Specifies one of the following time flags:

#### PSTF_UTC (0)

Indicates coordinated universal time.

#### PSTF_LOCAL (1)

Indicates local time.

### `pftOut` [out]

Type: **FILETIME***

Pointer to the extracted [FILETIME](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-filetime) structure.

## Return value

Type: **HRESULT**

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

*stfOut* flags override any property description flags.