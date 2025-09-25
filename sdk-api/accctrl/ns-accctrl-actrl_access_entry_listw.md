# ACTRL_ACCESS_ENTRY_LISTW structure

## Description

Contains a list of access entries.

## Members

### `cEntries`

The number of entries in the **pAccessList** array.

### `pAccessList`

A pointer to an array of [ACTRL_ACCESS_ENTRY](https://learn.microsoft.com/windows/desktop/api/accctrl/ns-accctrl-actrl_access_entrya) structures. Each structure specifies access-control information for a specified trustee.

### `pAccessList.size_is`

### `pAccessList.size_is.cEntries`

## Remarks

To create an empty access list, set **cEntries** to zero and **pAccessList** to **NULL**. An empty list does not grant access to any trustee, and thus, denies all access to an object.

To create a null access list, set the **pAccessEntryList** member of the [ACTRL_PROPERTY_ENTRY](https://learn.microsoft.com/windows/desktop/api/accctrl/ns-accctrl-actrl_property_entrya) structure to **NULL**. A null access list grants everyone full access to the object.

> [!NOTE]
> The accctrl.h header defines ACTRL_ACCESS_ENTRY_LIST as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[ACTRL_PROPERTY_ENTRY](https://learn.microsoft.com/windows/desktop/api/accctrl/ns-accctrl-actrl_property_entrya)