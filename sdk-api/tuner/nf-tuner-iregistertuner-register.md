# IRegisterTuner::Register

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

This feature is expected to be available on a future version of the Windows operating system.

The **Register** method registers an apartment-threaded tuner with the tuner marshaller and registers the tuner marshaller with the graph service provider.

## Parameters

### `pTuner` [in]

Pointer to a variable that specifies the tuner.

### `pGraph` [in]

Pointer to a variable that specifies the graph filter provider.

## Return value

When the method succeeds, it returns S_OK. Otherwise it returns an **HRESULT** error code.

## See also

[IRegisterTuner Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/tuner/nn-tuner-iregistertuner)