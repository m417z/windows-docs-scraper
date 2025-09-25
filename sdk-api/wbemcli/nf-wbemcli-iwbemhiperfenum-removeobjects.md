# IWbemHiPerfEnum::RemoveObjects

## Description

The
**IWbemHiPerfEnum::RemoveObjects** method removes objects (identified by their refresher identifiers) from a refresher.

## Parameters

### `lFlags`

Reserved. This parameter must be 0 (zero).

### `uNumObjects` [in]

Number of objects to remove.

### `apIds` [in]

Pointer to an array of integers that contains the refresher identifiers of the objects to remove.

## Return value

This method returns an **HRESULT** indicating the status of the method call. The following list lists the value contained within an **HRESULT**.

## See also

[IWbemHiPerfEnum](https://learn.microsoft.com/windows/desktop/api/wbemprov/nn-wbemprov-iwbemhiperfprovider)