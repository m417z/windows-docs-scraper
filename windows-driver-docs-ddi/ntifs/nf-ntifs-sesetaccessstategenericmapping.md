# SeSetAccessStateGenericMapping function

## Description

The **SeSetAccessStateGenericMapping** routine sets the generic mapping field of an ACCESS_STATE structure.

## Parameters

### `AccessState` [in, out]

Pointer to the ACCESS_STATE structure to be modified.

### `GenericMapping` [in]

Pointer to a GENERIC**_**MAPPING structure to be copied into the ACCESS_STATE structure specified by *AccessState*.

## Remarks

**SeSetAccessStateGenericMapping** sets the **GenericMapping** field in the **AuxData** member of an ACCESS_STATE structure. If this field is not set when the ACCESS_STATE structure is created, **SeSetAccessStateGenericMapping** must be called to set this field before the structure is used to perform access validation.

The generic mapping structure defines the mapping of generic access rights to specific and standard access rights for an object. When a client requests generic access rights to an object, the desired access mask is mapped to one of the access masks defined in this structure.

For more information about security and access control, see [Windows security model for driver developers](https://learn.microsoft.com/windows-hardware/drivers/driversecurity/windows-security-model) and the documentation on these topics in the Windows SDK.

## See also

[ACCESS_STATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_access_state)

[GENERIC_MAPPING](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_generic_mapping)

[SeAppendPrivileges](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-seappendprivileges)