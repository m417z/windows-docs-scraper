# ACTRL_PROPERTY_ENTRYW structure

## Description

Contains a list of access-control entries for an object or a specified property on an object.

## Members

### `lpProperty`

The GUID of a property on an object. Use the [UuidToString](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-uuidtostring) function to generate a string representation of a property GUID.

### `pAccessEntryList`

A pointer to an [ACTRL_ACCESS_ENTRY_LIST](https://learn.microsoft.com/windows/desktop/api/accctrl/ns-accctrl-actrl_access_entry_lista) structure that contains a list of access-control entries.

### `fListFlags`

Flags that specify information about the **pProperty** property. This member can be 0 or the following value.

| Value | Meaning |
| --- | --- |
| **ACTRL_ACCESS_PROTECTED**<br><br>0x00000001 | Protects the object or property from inheriting access-control entries. |

## Remarks

To create an **ACTRL_PROPERTY_ENTRY** structure that grants everyone full access to an object, set the **pAccessEntryList** member to **NULL**.

To create an **ACTRL_PROPERTY_ENTRY** structure that denies all access to an object, set the **pAccessEntryList** member to point to an [ACTRL_ACCESS_ENTRY_LIST](https://learn.microsoft.com/windows/desktop/api/accctrl/ns-accctrl-actrl_access_entry_lista) structure whose **cEntries** member is 0 and **pAccessList** member is **NULL**.

> [!NOTE]
> The accctrl.h header defines ACTRL_PROPERTY_ENTRY as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[ACTRL_ACCESS_ENTRY_LIST](https://learn.microsoft.com/windows/desktop/api/accctrl/ns-accctrl-actrl_access_entry_lista)

[UuidToString](https://learn.microsoft.com/windows/desktop/api/rpcdce/nf-rpcdce-uuidtostring)