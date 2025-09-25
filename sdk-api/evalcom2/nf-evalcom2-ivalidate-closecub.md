# IValidate::CloseCUB

## Description

The **CloseCUB** method closes an open [Internal Consistency Evaluator (ICE)](https://learn.microsoft.com/windows/desktop/Msi/internal-consistency-evaluators-ices) .cub file. Internal Consistency Evaluator (ICE) .cub files can be opened using the [OpenCUB](https://learn.microsoft.com/windows/desktop/api/evalcom2/nf-evalcom2-ivalidate-opencub) method.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **S_FALSE** | The method failed. |

## Remarks

The method returns S_FALSE if no .cub file has been opened using the [OpenCUB](https://learn.microsoft.com/windows/desktop/api/evalcom2/nf-evalcom2-ivalidate-opencub) method.

## See also

[IValidate](https://learn.microsoft.com/windows/desktop/api/evalcom2/nn-evalcom2-ivalidate)

[Using Evalcom2](https://learn.microsoft.com/windows/desktop/Msi/using-evalcom2)

[Validation Callback Functions](https://learn.microsoft.com/windows/desktop/Msi/validation-callback-functions)