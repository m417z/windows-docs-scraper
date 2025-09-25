# IWinMLEvaluationContext::GetValueByName

## Description

**These APIs have been deprecated and should no longer be used:** Please use [Windows.AI.MachineLearning](https://learn.microsoft.com/uwp/api/windows.ai.machinelearning) instead.

Returns the input/output description for the specific binding name.

## Parameters

### `Name` [in]

The name of the binding.

### `pDescriptor` [out]

A pointer to a [WINML_BINDING_DESC](https://learn.microsoft.com/windows/desktop/api/winml/ns-winml-winml_binding_desc) containing the specified (Name) binding description.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IWinMLEvaluationContext](https://learn.microsoft.com/windows/desktop/api/winml/nn-winml-iwinmlevaluationcontext)