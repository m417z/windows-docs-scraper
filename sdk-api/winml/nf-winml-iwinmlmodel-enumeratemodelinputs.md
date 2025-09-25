# IWinMLModel::EnumerateModelInputs

## Description

**These APIs have been deprecated and should no longer be used:** Please use [Windows.AI.MachineLearning](https://learn.microsoft.com/uwp/api/windows.ai.machinelearning) instead.

Enumerates the WinML model inputs.

## Parameters

### `Index`

Input index value.

### `ppInputDescriptor` [out]

A pointer to a [WINML_VARIABLE_DESC](https://learn.microsoft.com/windows/desktop/api/winml/ns-winml-winml_variable_desc) containing the model input description.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IWinMLModel](https://learn.microsoft.com/windows/desktop/api/winml/nn-winml-iwinmlmodel)