# EVT_TR_QUERY_SERVICE_CALLBACKS callback function

## Description

## Parameters

### `MasterDevice`

### `ServiceGuid`

## Return value

Returns PTR_SECURE_SERVICE_CALLBACKS.

## Syntax

```cpp
//Declaration

EVT_TR_QUERY_SERVICE_CALLBACKS EvtTrQueryServiceCallbacks;

// Definition

PTR_SECURE_SERVICE_CALLBACKS EvtTrQueryServiceCallbacks
(
    WDFDEVICE MasterDevice
    LPGUID ServiceGuid
)
{...}

```

## Remarks

## See also