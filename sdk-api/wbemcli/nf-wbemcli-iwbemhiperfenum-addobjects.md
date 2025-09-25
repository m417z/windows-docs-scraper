# IWbemHiPerfEnum::AddObjects

## Description

The **IWbemHiPerfEnum::AddObjects** method adds the supplied instance objects to the enumerator.

## Parameters

### `lFlags`

Reserved. This parameter must be 0.

### `uNumObjects` [in]

Number of items in the object and the number of identifiers in the parameter.

### `apIds` [in]

Pointer to an array of integers that contains a unique identifier for each object in the object array.

### `apObj` [in]

Pointer to an array of instance objects to add to the enumerator.

## Return value

This method returns an **HRESULT** indicating the status of the method call. The following list lists the value contained within an **HRESULT**.

## Remarks

If an identifier already exists, **WBEM_E_FAILED** is returned. The refresher identifiers can be used to remove objects later.

## See also

[IWbemHiPerfEnum](https://learn.microsoft.com/windows/desktop/api/wbemcli/nn-wbemcli-iwbemhiperfenum)