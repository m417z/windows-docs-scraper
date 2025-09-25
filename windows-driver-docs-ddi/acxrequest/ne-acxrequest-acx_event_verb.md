## Description

The **ACX_EVENT_VERB** enumeration describes the type of verb operations supported on ACX events.

## Constants

### `AcxEventVerbNone`

No verb support.

### `AcxEventVerbEnable`

Verb Support is enabled.

### `AcxEventVerbDisable`

Verb Support is disabled.

### `AcxEventVerbBasicSupport`

Basic Verb support is available.

### `AcxEventVerbSetSupport`

Event Verb support is available.

### `AcxEventVerbMax`

For internal validation, do not use.

## Remarks

### Example

Example usage is shown below.

```cpp
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