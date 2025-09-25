## Description

**LUID_AND_ATTRIBUTES** represents a locally unique identifier (LUID) and its attributes.

## Members

### `Luid`

An LUID value.

### `Attributes`

Specifies attributes of the LUID. This value contains up to 32 one-bit flags. Its meaning depends on the definition and use of the LUID.

The following attributes are defined for privileges:

| Attribute | Description |
|---|---|
| SE_PRIVILEGE_ENABLED | The privilege is enabled. |
| SE_PRIVILEGE_ENABLED_BY_DEFAULT | The privilege is enabled by default. |
| SE_PRIVILEGE_USED_FOR_ACCESS | The privilege was used to gain access to an object or service. This flag is used to identify the relevant privileges in a set passed by a client application that may contain unnecessary privileges. |

## Remarks

An LUID_AND_ATTRIBUTES structure can represent an LUID whose attributes change frequently, such as when it is used to represent privileges in the PRIVILEGE_SET structure. Privileges are represented by LUIDs and have attributes indicating whether they are currently enabled or disabled.

Be aware of the following derived types:

```cpp
typedef LUID_AND_ATTRIBUTES LUID_AND_ATTRIBUTES_ARRAY[ANYSIZE_ARRAY];
typedef LUID_AND_ATTRIBUTES_ARRAY *PLUID_AND_ATTRIBUTES_ARRAY;
```

## See also

[**LUID**](https://learn.microsoft.com/windows-hardware/drivers/ddi/igpupvdev/ns-igpupvdev-_luid)

[**PRIVILEGE_SET**](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff551860(v=vs.85))

[SeFilterToken](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-sefiltertoken)

[SePrivilegeCheck](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-seprivilegecheck)