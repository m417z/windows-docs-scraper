## Description

This API evaluates a specific requirement and returns a pass or fail result informing the caller whether the device meets the hardware requirement.

## Parameters

### `hardwareRequirement`

Specifies a single and specific requirement that is to be evaluated against.

### `evaluationResult`

The evaluation result. If the device meets hardware requirements, a value of `TRUE` is returned; otherwise, the value is `FALSE`.

### `constraintsEvaluated`

An optional `out` value that returns the list of constraints that were used to evaluate the specific *hardwareRequirement*. Each **HWREQCHK_DEVICE_HARDWARE_EVALUATION** in the array represents a single constraint that was evaluated.

>[!NOTE]
>Internally, the API allocates memory for this argument using **CoTaskMemAlloc** and it is the responsibility of the caller to free the memory using **CoTaskMemFree**.

### `constraintEvaluationCount`

The number of constraints evaluated that are returned in *constraintsEvaluated*.

## Return value

Returns an `HRESULT` value that indicates the success or failure of the call.

## Remarks

## See also