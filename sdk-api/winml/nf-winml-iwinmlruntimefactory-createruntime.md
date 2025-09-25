# IWinMLRuntimeFactory::CreateRuntime

## Description

**These APIs have been deprecated and should no longer be used:** Please use [Windows.AI.MachineLearning](https://learn.microsoft.com/uwp/api/windows.ai.machinelearning) instead.

Creates a WinML runtime.

## Parameters

### `RuntimeType` [in]

A [WINML_RUNTIME_TYPE](https://learn.microsoft.com/windows/desktop/api/winml/ne-winml-winml_runtime_type) that describes the type of WinML runtime.

### `ppRuntime` [out]

A pointer to the created [IWinMLRuntime](https://learn.microsoft.com/windows/desktop/api/winml/nn-winml-iwinmlruntime).

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IWinMLRuntimeFactory](https://learn.microsoft.com/windows/desktop/api/winml/nn-winml-iwinmlruntimefactory)