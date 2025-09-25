## Description

The **ACX_PROPERTY_VERB** enumeration describes the type of verb operations supported on ACX properties.

## Constants

### `AcxPropertyVerbNone`

No verb support.

### `AcxPropertyVerbGet`

Get Verb Support is enabled.

### `AcxPropertyVerbSet`

Set Verb Support is enabled.

### `AcxPropertyVerbBasicSupport`

Basic Verb support is available.

### `AcxPropertyVerbSetSupport`

Verb Set support is available.

### `AcxPropertyVerbMax`

For internal validation, do not use.

## Remarks

### Example

Example usage is shown below.

```cpp
(
    _In_ WDFDEVICE Device,
    _In_ ACXTARGETCIRCUIT TargetCircuit,
    _In_ GUID PropertySet,
    _In_ ULONG PropertyId,
    _In_ ACX_PROPERTY_VERB Verb,
    _Inout_ PVOID Value,
    _In_ ULONG ValueCb
)
{
    PAGED_CODE();

    ACX_REQUEST_PARAMETERS requestParams;
    ACX_REQUEST_PARAMETERS_INIT_PROPERTY(
        &requestParams,
        PropertySet,
        PropertyId,
        Verb,
        AcxItemTypeCircuit,
        0,
        NULL, 0,
        Value, ValueCb
    );

```

### ACX requirements

**Minimum ACX version:** 1.0

For more information about ACX versions, see [ACX version overview](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-version-overview).

## See also

- [acxrequest.h header](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxrequest/)