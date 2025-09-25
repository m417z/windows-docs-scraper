# ExUuidCreate function

## Description

The **ExUuidCreate** routine initializes a UUID (GUID) structure to a newly generated value.

## Parameters

### `Uuid` [out]

A pointer to a caller-allocated UUID (GUID) structure that is set to a new UUID value.

## Return value

Possible return values include the following status codes.

| return code | description |
|--|--|
| **status_success** | the routine successfully generated a uuid that is universally unique. |
| **rpc_nt_uuid_local_only** | the routine generated a uuid that is unique only to this computer. this can occur when the mac address is not an ieee universally-administered address or when no nics are present. |
| **status_retry** | the system is not ready to generate a new uuid. |

## Remarks

A UUID and a GUID are the same data type.

The caller can iteratively attempt to obtain a new UUID value.