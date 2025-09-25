# IWinMLRuntime::LoadModel

## Description

**These APIs have been deprecated and should no longer be used:** Please use [Windows.AI.MachineLearning](https://learn.microsoft.com/uwp/api/windows.ai.machinelearning) instead.

Loads a WinML model.

## Parameters

### `Path` [in]

Path name for the model.

### `ppModel` [out]

A double pointer to an [IWinMLModel](https://learn.microsoft.com/windows/desktop/api/winml/nn-winml-iwinmlmodel) describing a WinML model.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IWinMLRuntime](https://learn.microsoft.com/windows/desktop/api/winml/nn-winml-iwinmlruntime)