# IWinMLRuntime::CreateEvaluationContext

## Description

**These APIs have been deprecated and should no longer be used:** Please use [Windows.AI.MachineLearning](https://learn.microsoft.com/uwp/api/windows.ai.machinelearning) instead.

Creates a WinML evaluation context object.

## Parameters

### `device` [in]

A pointer to an [ID3D12Device](https://learn.microsoft.com/windows/desktop/api/d3d12/nn-d3d12-id3d12device) describing a D3D12 device input.

### `ppContext` [out]

On success, returns a double pointer to the newly-created [WinMLEvaluationContext](https://learn.microsoft.com/windows/desktop/api/winml/nn-winml-iwinmlevaluationcontext) object.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IWinMLRuntime](https://learn.microsoft.com/windows/desktop/api/winml/nn-winml-iwinmlruntime)