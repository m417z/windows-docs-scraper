## Description

The **ACX_REQUEST_PARAMETERS_INIT_METHOD** function initializes an ACX_REQUEST_PARAMETERS struct with ACX method parameters.

## Parameters

### `Params`

A pointer to [ACX_REQUEST_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxrequest/ns-acxrequest-acx_request_parameters) structure that is used to store method parameters.

### `Set`

A method Set ID (GUID).

### `Id`

A method ID (ULONG) within the method Set ID.

### `Verb`

The ACX method verb to send as defined by the [ACX_METHOD_VERB](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxrequest/ne-acxrequest-acx_method_verb) enumeration.

### `ItemType`

The [ACX_ITEM_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxrequest/ne-acxrequest-acx_item_type) type of item being sent, for example AcxItemTypeCircuit.

### `ItemId`

The item ID of the ItemType, for example the pin ID if the ItemType is a pin.

### `Args`

An optional Args buffer holding additional parameters for the specified method. Set to null if not present.

### `ArgsCb`

The count in bytes (size) of the Args buffer. Set to 0 if Args field is not used.

### `Result`

An optional Result buffer to old the result of the operation. Set to null if not present or if *SendMethod needs to allocate it when ResultCb is not zero. Caller is responsible for freeing the allocated buffer.

### `ResultCb`

The count in bytes (size) of the Result buffer. Set to 0 if Result is not used.

## Remarks

### Example

Example usage is shown below.

```cpp
            arg     = circuitArg;
            result  = 0;

            //
            // Format and send the request.
            //
            ACX_REQUEST_PARAMETERS_INIT_METHOD(
                &params,
                methodsTests[i].MethodSet,
                methodsTests[i].MethodId,
                AcxMethodVerbSend,
                AcxItemTypeCircuit,
                AcxItemIdNone,
                &arg, sizeof(arg),      // Args & size
                &result, sizeof(result) // Result & size
                );
```

### ACX requirements

**Minimum ACX version:** 1.0

For more information about ACX versions, see [ACX version overview](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-version-overview).

## See also

- [acxrequest.h header](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxrequest/)