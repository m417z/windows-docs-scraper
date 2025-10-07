# LsaManageSidNameMapping function

## Description

The **LsaManageSidNameMapping** function adds or removes SID/name mappings from the mapping set registered with the LSA Lookup Service.

```cpp
void WINAPI LsaManageSidNameMapping(
  _In_  LSA_SID_NAME_MAPPING_OPERATION_TYPE    OpType,
  _In_  PLSA_SID_NAME_MAPPING_OPERATION_INPUT  OpInput,
  _Out_ PLSA_SID_NAME_MAPPING_OPERATION_OUTPUT *OpOutput
);
```

## Parameters

### OpType [in]

Indicates if a this function is being called to add or remove an SID/name mapping.

### OpInput [in]

Indicates the domain, account, and SID values to use during this operation. Additional flags can also be set within this structure.

### OpOutput [out]

Contains a value of [LSA_SID_NAME_MAPPING_OPERATION_ERROR](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/dn280707(v=vs.85)) that indicates operation success or failure.

| Value | Meaning |
|-------|---------|
| **Success** | Operation is complete without error. |
| **NonMappingError** | An error unrelated to SID-name mapping has occurred. |
| **NameCollision** | Operation failure due to name collision. |
| **SidCollision** | Operation failure due to SID collision. |
| **DomainNotFound** | Corresponding domain not found. |
| **DomainSidPrefixMismatch** | Provided SID doesn't have the correct domain prefix. |
| **MappingNotFound** | Mapping not found in the cache. |

## Returns

If the mapping is inserted successfully, the return value is STATUS_SUCCESS.
Otherwise, if the function fails due to SID or name conflicts, STATUS_INVALID_PARAMETER error will be returned.

## Remarks

## See also