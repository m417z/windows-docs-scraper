# IDataModelScriptManager::EnumerateScriptProviders

## Description

The EnumerateScriptProviders method will return an enumerator which will enumerate every script provider that has been registered with the script manager via a prior call to the RegisterScriptProvider method.

## Parameters

### `enumerator`

An enumerator which will enumerate every script provider registered via a prior call to the RegisterScriptProvider method will be returned here.

## Return value

This method returns HRESULT that indicates success or failure.

## Remarks

The EnumerateScriptProviders method will return an enumerator of the following form:

```cpp
DECLARE_INTERFACE_(IDataModelScriptProviderEnumerator, IUnknown)
{
    STDMETHOD(Reset)() PURE;

    STDMETHOD(GetNext)(_COM_Outptr_ IDataModelScriptProvider **provider) PURE;
}

```

## See also

[IDataModelScriptManager interface](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-idatamodelscriptmanager)