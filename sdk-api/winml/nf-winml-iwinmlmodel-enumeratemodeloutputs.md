# IWinMLModel::EnumerateModelOutputs

## Description

**These APIs have been deprecated and should no longer be used:** Please use [Windows.AI.MachineLearning](https://learn.microsoft.com/uwp/api/windows.ai.machinelearning) instead.

Enumerates the WinML model outputs.

## Parameters

### `Index` [in]

Output index value.

### `ppOutputDescriptor` [out]

A pointer to a [WINML_VARIABLE_DESC](https://learn.microsoft.com/windows/desktop/api/winml/ns-winml-winml_variable_desc) containing the model output description.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IWinMLModel](https://learn.microsoft.com/windows/desktop/api/winml/nn-winml-iwinmlmodel)