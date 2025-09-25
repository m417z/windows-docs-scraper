# IValidate::OpenCUB

## Description

The **OpenCUB** method opens an [Internal Consistency Evaluator (ICE)](https://learn.microsoft.com/windows/desktop/Msi/internal-consistency-evaluators-ices) file that is to be used for validation.

## Parameters

### `szCUBFile` [in]

The fully qualified path to the [Internal Consistency Evaluator (ICE)](https://learn.microsoft.com/windows/desktop/Msi/internal-consistency-evaluators-ices) file to be used for validation.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_POINTER** | The value of *szDatabase* is invalid. |
| **E_OUTOFMEMORY** | Failed to allocate memory. |
| **E_FAIL** | The method failed. |

## Remarks

The [Internal Consistency Evaluator (ICE)](https://learn.microsoft.com/windows/desktop/Msi/internal-consistency-evaluators-ices) file typically has a .cub file name extension.

## See also

[IValidate](https://learn.microsoft.com/windows/desktop/api/evalcom2/nn-evalcom2-ivalidate)

[Using Evalcom2](https://learn.microsoft.com/windows/desktop/Msi/using-evalcom2)

[Validation Callback Functions](https://learn.microsoft.com/windows/desktop/Msi/validation-callback-functions)