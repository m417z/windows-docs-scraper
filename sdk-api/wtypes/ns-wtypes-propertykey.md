# PROPERTYKEY structure

## Description

Specifies the FMTID/PID identifier that programmatically identifies a property. Replaces [SHCOLUMNID](https://learn.microsoft.com/windows/desktop/shell/objects).

## Members

### `fmtid`

Type: **GUID**

A unique GUID for the property.

### `pid`

Type: **DWORD**

A property identifier (PID). This parameter is not used as in [SHCOLUMNID](https://learn.microsoft.com/windows/desktop/shell/objects). It is recommended that you set this value to PID_FIRST_USABLE. Any value greater than or equal to 2 is acceptable.

**Note** Values of 0 and 1 are reserved and should not be used.

## Remarks

As of Windows Vista, the [SHCOLUMNID](https://learn.microsoft.com/windows/desktop/shell/objects) structure is simply an alias for [PROPERTYKEY](https://learn.microsoft.com/windows/desktop/api/wtypes/ns-wtypes-propertykey), as shown in this declaration from Shobjidl.h.

```cpp
typedef PROPERTYKEY SHCOLUMNID;
```

[SHCOLUMNID](https://learn.microsoft.com/windows/desktop/shell/objects) can be considered a legacy structure with [PROPERTYKEY](https://learn.microsoft.com/windows/desktop/api/wtypes/ns-wtypes-propertykey) being the new, preferred form. **PROPERTYKEY** has a broader purpose than **SHCOLUMNID**, and the new name is more descriptive of its uses.