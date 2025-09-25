# IWinMLModel::EnumerateMetadata

## Description

**These APIs have been deprecated and should no longer be used:** Please use [Windows.AI.MachineLearning](https://learn.microsoft.com/uwp/api/windows.ai.machinelearning) instead.

Gets the metadata of the model.

## Parameters

### `Index` [in]

The metadata index value.

### `pKey` [out]

A pointer to the metadata key for the given index.

### `pValue` [out]

A pointer to the metadata value for the given index.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IWinMLModel](https://learn.microsoft.com/windows/desktop/api/winml/nn-winml-iwinmlmodel)