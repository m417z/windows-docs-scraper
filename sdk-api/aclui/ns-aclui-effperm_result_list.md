# EFFPERM_RESULT_LIST structure

## Description

The **EFFPERM_RESULT_LIST** structure lists the effective permissions.

## Members

### `fEvaluated`

Indicates if the effective permissions results have been evaluated.

### `cObjectTypeListLength`

The number of elements in both the **pObjectTypeList** and **pGrantedAccessList** members.

### `pObjectTypeList`

A pointer to an array of [OBJECT_TYPE_LIST](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-object_type_list) structures that specifies the properties and property sets for which access was evaluated.

### `pGrantedAccessList`

A pointer to an array of [ACCESS_MASK](https://learn.microsoft.com/windows/desktop/SecAuthZ/access-mask) values that specifies the access rights granted for each corresponding object type.